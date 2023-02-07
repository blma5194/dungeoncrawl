#include <iostream>
#include <string>
#include "Weapon.h"
#include "Item.h"
#include "Player.h"
#include "Map.h"
#include "Enemy.h"

using namespace std;
//g++ -std=c++11 combatMenuDriver.cpp Weapon.cpp Item.cpp Player.cpp Map.cpp Enemy.cpp -o cd

/*
    will take in an input string, then use that string to move the character a desired distance <= 5
    returns the new movement left for the player.
*/
int wasdMovement(Player object, string wasd, int x_pos, int y_pos, int reamainingMovement)
{
    int movedSquares = 0;
    int newRemainingMovement = reamainingMovement;

    if(wasd.length() > reamainingMovement)
    {
    cout << "Invalid Input or no movement left." << endl;
    return newRemainingMovement;
    }
    else
    {
    for(int i = 0; i < wasd.length(); i++)
    {
        if(wasd[i] == 'w' || wasd[i] == 'W')
        {
            y_pos--;
            movedSquares += 1;
        }
        else if(wasd[i] == 'a' || wasd[i] == 'A')
        {
            x_pos--;
            movedSquares += 1;
        }
        else if(wasd[i] == 's' || wasd[i] == 'S')
        {
            y_pos++;
            movedSquares += 1;
        }
        else if(wasd[i] == 'd' || wasd[i] == 'D')
        {
            x_pos++;
            movedSquares += 1;
        }
        else
        {
            continue;
        }
    }
    newRemainingMovement = newRemainingMovement-movedSquares;
    return newRemainingMovement;
    }
}

/*
    this is the function associated with the combat that the player has to go through in order to
    do  their turn. It's inputs are, an action boolean variable that states if the player has made
    an action, a player object, an array of enemy objects, the number of active enemies, and a map object.
    returns nothing.
*/
void combatMenu(bool& action, Player& player, Enemy& enemy, int& activeEnemy, Map& theMap, bool& forceQuit)
{
string input = "";
int integerInput = 0;
bool endTurn = true;
int remainingMovement = player.getMovementSquares();
int newRemainingMovement = remainingMovement;
int x_pos = 0;
int y_pos = 0;
while(remainingMovement > 0 || action == false)
{
    theMap.outputMap();

    cout << "|Health: " <<player.getHealth() <<  "     |" << endl;
    cout << "|Movement:" << newRemainingMovement << "     |" << endl;
    cout << "_________________" << endl;
    cout << "|Combat Menu:   |" << endl;
    cout << "_________________" << endl;
    cout << "|Enter Action:  |" << endl;
    cout << "|1.Move         |" << endl;
    cout << "|2.Attack       |" << endl;
    cout << "|3.Use Item     |" << endl;
    cout << "|4.Dodge        |" << endl;
    cout << "|5.Weapon Stats |" << endl;
    cout << "|               |" << endl;
    cout << "|6.End turn     |" << endl;
    cout << "_________________" << endl;
    cout << "How will you survive?:";
    getline(cin, input);
    if(input == "1")
    {
        cout << "Enter path: " << endl;
        getline(cin, input);
        int movedSquares = 0;
        if(input.length() > remainingMovement || input.length() > newRemainingMovement)
        {
        cout << "Invalid Input or no movement left." << endl;
        }
        else
        {
        for(int i = 0; i < input.length(); i++)
        {
            if(input[i] == 'w' || input[i] == 'W')
            {
                y_pos--;
                movedSquares += 1;
            }
            else if(input[i] == 'a' || input[i] == 'A')
            {
                x_pos--;
                movedSquares += 1;
            }
            else if(input[i] == 's' || input[i] == 'S')
            {
                y_pos++;
                movedSquares += 1;
            }
            else if(input[i] == 'd' || input[i] == 'D')
            {
                x_pos++;
                movedSquares += 1;
            }
            else
            {
                continue;
            }
        }
        newRemainingMovement = newRemainingMovement-movedSquares;
        }

    theMap.movePlayerTo(x_pos,y_pos);
    if(theMap.getPlayerXIndex() == theMap.getEnemyXIndex() && 
    theMap.getPlayerYIndex() == theMap.getEnemyYIndex())
    {
        cout << "you land on the enemy and it pushes you off!" << endl;
        cout << "you take 1 damage from the push." << endl;
        player.setHealth(player.getHealth()-1);
        if(theMap.getPlayerXIndex() == 21)
        {
            theMap.setPlayerXY(theMap.getPlayerXIndex()-1, theMap.getPlayerYIndex());
        }
        else if(theMap.getPlayerXIndex() == 0)
        {
            theMap.setPlayerXY(theMap.getPlayerXIndex()+1, theMap.getPlayerYIndex());
        }
        else if(theMap.getPlayerYIndex() == 9)
        {
            theMap.setPlayerXY(theMap.getPlayerXIndex(), theMap.getPlayerYIndex()-1);
        }
        else if(theMap.getPlayerYIndex() == 0)
        {
            theMap.setPlayerXY(theMap.getPlayerXIndex(), theMap.getPlayerYIndex()+1);
        }
        else
        {
            theMap.setPlayerXY(theMap.getPlayerXIndex() + 1, theMap.getPlayerYIndex()-1);
        }
        theMap.setEnemyXY(theMap.getEnemyXIndex(),theMap.getEnemyYIndex());
    }
    x_pos = 0;
    y_pos = 0;
    input = "";
    }
    else if(input == "2")
    {   
        if(action)
        {
            cout << "You have already used your action." << endl;
            input = "";
        }
        //if the player is next to the enemy
        if(theMap.nextToPlayer() && action == false)
        {
            enemy.setEnemyHealth(enemy.getEnemyHealth()-player.getWeapon().getWeaponDamage());
            cout << "you swing your " << player.getWeapon().getWeaponName() << " doing " << player.getWeapon().getWeaponDamage() << " damage."<<endl;
            cout << endl;
            cout << "Leaving the enemy with " << enemy.getEnemyHealth() << " health." << endl;
            if(enemy.getEnemyHealth() <= 0)
            {
                enemy = Enemy("",0,0,Weapon("",0));
                activeEnemy--;
                break;
            }
            action = true;
        }
        else
        {
            cout << "You swing your " << player.getWeapon().getWeaponName() << " and miss wildly." << endl;
        }
        input = "";
    }
    else if(input == "3")
    {
        if(action)
        {
            cout << "You have already used your action." << endl;
            input = "";
        }
        else if(player.getItemsHeld() > 0)
        {
            for(int i = 0; i < player.getItemsHeld(); i++)
            {
                cout << i+1 << ". " <<  player.getItemAtIndex(i).getItemName() << endl;
            }
            cout << endl;
            cout << "Enter Item number:" << endl;
            getline(cin, input);
            integerInput = stoi(input);
            if(integerInput <= 0 || integerInput > player.getItemsHeld())
            {
                cout << "Invalid input. please enter an item number." << endl;
            }
            
            else
            {
                //heal the player.
                if(player.getItemAtIndex(integerInput-1).isHealingItem())
                {
                    player.healPlayer(integerInput-1);
                    action = true;
                }
                
                //use a damaging item
                if(theMap.nextToPlayer())
                {
                    //damage the enemy
                    cout << "You splash the " << player.getItemAtIndex(integerInput-1).getItemName() << " on the enemy melting" << endl;
                    cout <<"flesh from bone doing " << player.getItemAtIndex(integerInput-1).getDamage() << " damage!" << endl;
                    enemy.setEnemyHealth(enemy.getEnemyHealth()-player.getItemAtIndex(integerInput-1).getDamage());
                    if(enemy.getEnemyHealth() <= 0)
                    {
                        enemy = Enemy("",0,0,Weapon("",0));
                        activeEnemy--;
                        break;
                    }
                    else
                    {
                        cout << "The item did nothing." << endl;
                    }
                    player.setItemAtIndex(integerInput-1, Item());
                    player.itemSort();
                }
            
            }
        input = "";
        }
        else
        {
        cout << "You reach into your pockets only to find they are empty" << endl;
        input = "";
        }    
    }

    else if(input == "4")
    {
        if(action)
        {
            cout << "You have already used your action." << endl;
        }
        else
        {
        player.setDodge(true);
        action = true;
        }
        input = "";
    }
    else if(input == "5")
    {
        cout << "======================" << endl;
        cout << "You wield " << player.getWeapon().getWeaponName() << endl;
        cout << "Damage Output: " << player.getWeapon().getWeaponDamage() << endl;
        cout << "======================" << endl;
        input = "";
        cout << endl;
    }
    else if(input == "6")
    {
        input = "";
        break;
    }
    else if(input == "quit")
    {
        forceQuit = true;
        break;
    }
    else
    {
        cout << "Only enter numbers 1-6." << endl;
        input = "";
        continue;
    }
}
}

int main()
{
    bool action =false;
    Player x;
    bool forceQuit = 0;
    int enemiesAlive = 1;
    Map theMap;
    Enemy aa;
    theMap.setPlayerXY(11,9);
    theMap.setEnemyCharacter(aa.getEnemyCharacter());
    theMap.setEnemyXY(11,7);
    x.addItemAtIndex(0, Item("nuke", 0, 99));
    combatMenu(action , x, aa, enemiesAlive, theMap, forceQuit);
    if(forceQuit)
    {
        return 2;
    }
    return 0;
}