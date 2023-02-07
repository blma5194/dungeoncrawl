//Libby Bianchi & Blake Martinez
//CSCI 1300
//Project 3

//g++ -std=c++11 finalDungeonCrawlDriver.cpp Player.cpp Enemy.cpp Weapon.cpp Item.cpp Map.cpp -o dungeonCrawl
//./dungeonCrawl

#include <iostream>
#include <string>
#include <fstream>
#include "Player.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Item.h"
#include "Map.h"

using namespace std;
/*
A function that returns nothing and fills up an enemy array of constant size 12 with every enemy
in the game. It is important that we use an array of size 12 as it fills in every index of the enemies.
implimented by force in main.
*/
void fillAllEnemies(Enemy inputArray[])
{
    //Constant Array size 12

    //easyEnemies
    inputArray[0] = Enemy(); //slime
    inputArray[1] = Enemy("goblin", 2, 3,Weapon());
    inputArray[2] = Enemy("skeleton", 2, 2,Weapon());
    inputArray[3] = Enemy("boar", 2, 4, Weapon("Tusks", 1));
    //mediumEnemies
    inputArray[4] = Enemy("hobgoblin", 4, 3, Weapon("Dagger", 2));
    inputArray[5] = Enemy("wolf", 3, 5, Weapon("Teeth", 2));
    inputArray[6] = Enemy("zombie", 7, 2, Weapon("Fist", 1));
    inputArray[7] = Enemy("Giant Beetle", 6, 5, Weapon("Horn", 1));
    //hardEnemies
    inputArray[8] = Enemy("Cyclops", 8, 4, Weapon("Giant Club", 3));
    inputArray[9] = Enemy("Mother slime", 12, 1, Weapon("Acid Touch", 2));
    inputArray[10] = Enemy("Shadow Knight", 8, 3, Weapon("Shadow Sword", 2));
    inputArray[11] = Enemy("Minitour", 8, 5, Weapon("Giant Axe", 4));

}
/*
The purpose of this function is to fill a weapon array with every weapon in the game.
implimented by force in main.
*/
void fillAllWeapons(Weapon allWeapons[])
{
    allWeapons[0] = Weapon("Dagger",2);
    allWeapons[1] = Weapon("Club", 2);
    allWeapons[2] = Weapon("Chair leg", 2);
    allWeapons[3] = Weapon("Wrench", 2);
    allWeapons[4] = Weapon("Shortsword",3);
    allWeapons[5] = Weapon("Whip", 3);
    allWeapons[6] = Weapon("Shovel", 3);
    allWeapons[7] = Weapon("Scythe", 4);
    allWeapons[8] = Weapon("Longsword", 4);
    allWeapons[9] = Weapon("Yklwa", 4);
    allWeapons[10] = Weapon("Battle Axe", 5); 
    allWeapons[11] = Weapon("Greatsword", 5);
    allWeapons[12] = Weapon("Explosive Hands", 5);
    allWeapons[13] = Weapon("Claymore",8);
}

/*
The purpose of this function is to fill an item array with every item in the game.
implimented by force in main.
*/
void fillAllItems(Item allItems[])
{
    allItems[0] = Item("Small Health Potion", 2, 0);
    allItems[1] = Item("Medium Health Potion", 4, 0);
    allItems[2] = Item("Big HealthPotion", 6, 0);
    allItems[3] = Item("Splashing Acid", 0, 3);
    allItems[4] = Item("Boiling Tar", 0, 5);
    allItems[5] = Item("Minitour Blood", 0, 7);
}
/*
The purpose of this function is to read straight from a txt file, and output what is in that txt file.
implimented by force in main.
*/
void readText(string filename)
{
    string line; // initialize line = the input (unecassary)
    ifstream my_file; // fstream class of ifstream, read stuff
    my_file.open(filename); 

    if(my_file.fail()) // if the txt.files didnt open 
    {
        cout << "Warning! File Not found" << endl; //warning
    }
    while(getline(my_file,line)) // just goes through every line in a text file and reads it 
    {
        cout << line << endl;
    }
    cout << endl;
    my_file.close();

}
/*
    will take in an input string, then use that string to move the character a desired distance <= 5
    returns the new movement left for the player.
*/
int wasdMovement(Player object, string wasd, int x_pos, int y_pos, int reamainingMovement)
{
    int movedSquares = 0;
    int newRemainingMovement = reamainingMovement;
    //length needs to be less than movement speed
    if(wasd.length() > reamainingMovement)
    {
    cout << "Invalid Input or no movement left." << endl;
    return newRemainingMovement;
    }
    //only w a s and d will be counted toward movemnt
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
    This function returns a random number that will correspond to an appropriate weapon index in a 
    fully populated array of weapons.
*/
int randomWeapon(int lowerBound, int upperBound)
    {
  int randomWeapon = lowerBound + rand() % (upperBound-lowerBound);
  return randomWeapon;
}
/*
    This function returns a random number that will correspond to an appropriate item index in a 
    fully populated array of items.
*/
int randomItem(int lowerBound, int upperBound)
{
int randomItem = lowerBound + rand() % (upperBound-lowerBound); // lowest index of all items and add the rand function taking the upper and lower bounds and spitting out a number between those 
  return randomItem;
}
/*
This function returns a random number that will correspond to an appropriate enemy index in a 
fully populated array of enemies.
*/
int randomEnemy(int lowerBound, int upperBound)
{

  int randomEnemy = lowerBound + rand() % (lowerBound - upperBound);
  return randomEnemy;
}
/*
this function will allow the player to look for items in the room, it will either add the item and weapon found 
or it will throw them away.
*/
void checkRoom(Player& X, Item allItems[], Weapon allWeapons[], int upperItemBound, int lowerItemBound, int upperWeaponBound, int lowerWeaponBound)

{
    int storeGetlineNumber =0;
    Weapon newWeapon;
    Item newItem;
    string input; // user input
    cout << "Would you like to pilage the room?" << endl;
    cout << "1. yes 2. no" << endl;
    getline(cin,input); //using getline to use the user input
    if(input == "1")
    {
    newWeapon = allWeapons[randomWeapon(lowerWeaponBound, upperWeaponBound)]; // calling the random weapon function
    cout << "You found a: " << newWeapon.getWeaponName() << endl; // matching number index with the name 
    cout << "Damage: " << newWeapon.getWeaponDamage() << endl;
    cout << "Would you like to keep this weapon?"<< endl;
    cout << "1. yes 2. no" << endl;
    
    getline(cin,input); // retrieving user input
        if(input == "1")
        {
            cout << "You equip " << newWeapon.getWeaponName() << "!" << endl;
            X.setWeapon(newWeapon); // set the players weapon as the new weapon
            input = "";
        }
        else if(input == "2")
        {
            cout << "The weapon fades from your hand almost as if it were a ghost" << endl;
            input = "";
        }
        else
        {
            cout << "You drop the weapon, it shatters into a million shards." << endl; // user gets one chance to click yes or no
            cout << "The weapon is now completly unrecoverable." << endl;
            input = "";
        }
       cout << endl;

    newItem = allItems[randomItem(lowerItemBound, upperItemBound)]; // calling the random item funciton 
    cout << "You also find: " << newItem.getItemName() << endl;// matching the item index numbers and names
    if(newItem.isHealingItem())
    {
        cout << "Healing Value: " << newItem.getHealingValue() << endl;
    }
    else
    {
        cout << "Damage Value: " << newItem.getDamage() << endl;
    }
    cout << "Would you like to keep this item?"<< endl;
    cout << "1. yes 2. no" << endl;
    getline(cin, input);

        if(input == "1")
        {
            cout <<"select which item you'd like to replace: " << endl;
            for(int i = 0; i < 8; i++)
            {
                cout << i+1 << ". " << X.getItemAtIndex(i).getItemName() << endl; // outputting all of the players items names (index of the array +1)
            }
            getline(cin, input);
            if(input > "0" && input < "9") // 1-8
            {
               storeGetlineNumber = stoi(input);
               cout << newItem.getItemName() << " has been added to your inventory." << endl;
               X.addItemAtIndex(storeGetlineNumber-1, newItem);
               X.itemSort();
               input = "";
            } // adds item to their inventory 
            else
            {
                cout << "you fumbled breaking the item on the ground" << endl;
                input = "";
            }
        }
        else if(input == "2")
        {
            cout << "you leave the item behind." << endl;
            input = "";
        }
    cout << endl;
    }
    else if(input == "2")
    {
        cout << "No new weaopons or items were added to your inventory." << endl;
        input = "";
        
    }
    else
    {
        cout << "Invalid input. The riches before you turn to dust and blow away in the wind." << endl;
        input = "";
    }
    
}
/*
the enemies turn, goes through cases in which the enemy may encounter as it plays the game.
returns true if the player has died.
*/
//enemy index refers to the index of the enemy within the enemy array not the coordinates.
bool enemyTurn(Player& player, Enemy& enemy, Map& terminalMap)
{
    int disX = (terminalMap.getPlayerXIndex() - terminalMap.getEnemyXIndex());
    int disY = (terminalMap.getPlayerYIndex() - terminalMap.getEnemyYIndex());
    int disTot = (abs(disX) + abs(disY));
    int remainingMovement = enemy.getMovementSquares();
    //cases for if the enemy is already next to the player
    if(terminalMap.nextToPlayer())
    {
        if(player.getDodge())
        {
            cout << "You dodge the attack!" << endl; 
            return false;
        }
        else
        {
            cout << "The " << enemy.getEnemyName() << " swings with its "<< enemy.getWeapon().getWeaponName()<< 
            "! Doing " <<enemy.getWeapon().getWeaponDamage() <<" damage!" << endl;
            player.setHealth(player.getHealth()-enemy.getWeapon().getWeaponDamage());

            if(player.getHealth() <= 0)
            {
                terminalMap.outputMap();
                return true;
            }
            else
            {
                terminalMap.outputMap();
                return false;
            }
        }
    }
    //Movement cases
    if(disTot < enemy.getMovementSquares())
    {
        if(disX == 0)
        {
            disY-=1;
            terminalMap.moveEnemyY(disY);
        }
        else if(disY == 0)
        {
            disX-=1;
            terminalMap.moveEnemyX(disX);
        }
        else
        {
            terminalMap.moveEnemyX(disX);
            terminalMap.moveEnemyY(disY);
        }
        if(terminalMap.getPlayerXIndex() == terminalMap.getEnemyXIndex() && 
            terminalMap.getPlayerYIndex() == terminalMap.getEnemyYIndex())
            {   
            cout << "the enemy lands on you and pushes you!" << endl;
            cout << "you take 1 damage from the push." << endl;
            player.setHealth(player.getHealth()-1);
            if(terminalMap.getPlayerXIndex() == 21)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()-1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerXIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()+1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerYIndex() == 9)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()-1);
            }
            else if(terminalMap.getPlayerYIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()+1);
            }
            else
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex() + 1, terminalMap.getPlayerYIndex()-1);
            }
            terminalMap.setEnemyXY(terminalMap.getEnemyXIndex(),terminalMap.getEnemyYIndex());
            }
        if(player.getDodge())
        {
            cout << "You dodge the attack!" << endl; 
            return false;
        }
        else
        {
        cout << "The " << enemy.getEnemyName() << " swings with its "<< enemy.getWeapon().getWeaponName()<< 
        "! Doing " <<enemy.getWeapon().getWeaponDamage() <<" damage!" << endl;
        player.setHealth(player.getHealth()-enemy.getWeapon().getWeaponDamage());
        if(player.getHealth() <= 0)
        {
            terminalMap.outputMap();
            return true;
        }
        else
        {
            terminalMap.outputMap();
            return false;
        }
        }
    }
    
    if(disTot == enemy.getMovementSquares()+1 || disTot == enemy.getMovementSquares())
    {
        if(disX == 0)
        {
            if(disY < 0)
            {
                disY-=1;
            }
            else if(disY > 0)
            {
                disY+=1;
            }
            terminalMap.moveEnemyY(disY);
        }
        else if(disY == 0)
        {
            if(disX < 0)
            {
                disX+=1;
            }
            else
            {
                disX-=1;
            }
            terminalMap.moveEnemyX(disX);
        }
        else if(disX == 1)
        {
            disX-=1;
            terminalMap.moveEnemyX(disX);
            terminalMap.moveEnemyY(disY);
        }
        else if(disY == 1)
        {
            disY-=1;
            terminalMap.moveEnemyY(disY);
            terminalMap.moveEnemyX(disX);
        }
        else
        {
            terminalMap.moveEnemyX(disX);
            terminalMap.moveEnemyY(disY);
        }
            if(terminalMap.getPlayerXIndex() == terminalMap.getEnemyXIndex() && 
            terminalMap.getPlayerYIndex() == terminalMap.getEnemyYIndex())
            {   
            cout << "the enemy lands on you and pushes you!" << endl;
            cout << "you take 1 damage from the push." << endl;
            player.setHealth(player.getHealth()-1);
            if(terminalMap.getPlayerXIndex() == 21)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()-1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerXIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()+1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerYIndex() == 9)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()-1);
            }
            else if(terminalMap.getPlayerYIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()+1);
            }
            else
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex() + 1, terminalMap.getPlayerYIndex()-1);
            }
            terminalMap.setEnemyXY(terminalMap.getEnemyXIndex(),terminalMap.getEnemyYIndex());
            }
        if(player.getDodge())
        {
            cout << "You dodge the attack!" << endl; 
            return false;
        }
        else
        {
        cout << "The " << enemy.getEnemyName() << " swings with its "<< enemy.getWeapon().getWeaponName()<< 
        "! Doing " <<enemy.getWeapon().getWeaponDamage() <<" damage!" << endl;
        player.setHealth(player.getHealth()-enemy.getWeapon().getWeaponDamage());
        if(player.getHealth() <= 0)
        {
            terminalMap.outputMap();
            return true;
        }
        else
        {
            if(terminalMap.getPlayerXIndex() == terminalMap.getEnemyXIndex() && 
            terminalMap.getPlayerYIndex() == terminalMap.getEnemyYIndex())
            {   
            cout << "the enemy lands on you and pushes you!" << endl;
            cout << "you take 1 damage from the push." << endl;
            player.setHealth(player.getHealth()-1);
            if(terminalMap.getPlayerXIndex() == 21)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()-1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerXIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()+1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerYIndex() == 9)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()-1);
            }
            else if(terminalMap.getPlayerYIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()+1);
            }
            else
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex() + 1, terminalMap.getPlayerYIndex()-1);
            }
            terminalMap.setEnemyXY(terminalMap.getEnemyXIndex(),terminalMap.getEnemyYIndex());
            }
            terminalMap.outputMap();
            return false;
        }
        }
    }
    else if(abs(disX) > enemy.getMovementSquares())
    {
        if(disX < 0)
        {
            terminalMap.moveEnemyX(-enemy.getMovementSquares());
        }
        else
        {
            terminalMap.moveEnemyX(enemy.getMovementSquares());
        }
        
        if(terminalMap.getPlayerXIndex() == terminalMap.getEnemyXIndex() && 
        terminalMap.getPlayerYIndex() == terminalMap.getEnemyYIndex())
        {
            cout << "the enemy lands on you and pushes you!" << endl;
            cout << "you take 1 damage from the push." << endl;
            player.setHealth(player.getHealth()-1);
            if(terminalMap.getPlayerXIndex() == 21)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()-1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerXIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()+1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerYIndex() == 9)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()-1);
            }
            else if(terminalMap.getPlayerYIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()+1);
            }
            else
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex() + 1, terminalMap.getPlayerYIndex()-1);
            }
            terminalMap.setEnemyXY(terminalMap.getEnemyXIndex(),terminalMap.getEnemyYIndex());
        }
        terminalMap.outputMap();
        return false;
    }
    else
    {

        terminalMap.moveEnemyX(disX);
        if(remainingMovement > 0)
        {
            remainingMovement -= abs(disX)-1;
        }
        else
        {
            remainingMovement += abs(disX)-1;
        }

        if(disY > 0)
        {
        terminalMap.moveEnemyY(remainingMovement);
        }
        else
        {
        terminalMap.moveEnemyY(-remainingMovement);
        }

        if(terminalMap.getPlayerXIndex() == terminalMap.getEnemyXIndex() && 
        terminalMap.getPlayerYIndex() == terminalMap.getEnemyYIndex())
        {
            cout << "the enemy lands on you and pushes you!" << endl;
            cout << "you take 1 damage from the push." << endl;
            player.setHealth(player.getHealth()-1);
            if(terminalMap.getPlayerXIndex() == 21)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()-1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerXIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()+1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerYIndex() == 9)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()-1);
            }
            else if(terminalMap.getPlayerYIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()+1);
            }
            else
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex() + 1, terminalMap.getPlayerYIndex()-1);
            }
            terminalMap.setEnemyXY(terminalMap.getEnemyXIndex(),terminalMap.getEnemyYIndex());
        }
        terminalMap.outputMap();

        return false;
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
        else if(!theMap.nextToPlayer() && action == false)
        {
            cout << "You swing your " << player.getWeapon().getWeaponName() << " and miss wildly." << endl;
            action = true;
        }
        else
        {
            input = "";
            continue;
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
            if(input != "")
            {
                integerInput = stoi(input);
            }
            
            if(integerInput <= 0 || integerInput > player.getItemsHeld())
            {
                cout << "Invalid input. please enter an item number." << endl;
                integerInput = 0;
            }
            
            else
            {
                //heal the player.
                if(player.getItemAtIndex(integerInput-1).isHealingItem())
                {
                    cout << "You were healed for " << player.getItemAtIndex(integerInput-1).getHealingValue() << "." << endl;
                    player.healPlayer(integerInput-1);
                    player.removeItemAtIndex(integerInput-1);
                    player.itemSort();
                    action = true;
                }
                
                //use a damaging item
                else
                {
                    if(theMap.nextToPlayer())
                    {
                        //damage the enemy
                        cout << "You splash the " << player.getItemAtIndex(integerInput-1).getItemName() << " on the enemy melting" << endl;
                        cout <<"flesh from bone doing " << player.getItemAtIndex(integerInput-1).getDamage() << " damage!" << endl;
                        enemy.setEnemyHealth(enemy.getEnemyHealth()-player.getItemAtIndex(integerInput-1).getDamage());
                        cout << "Leaving the enemy with " << enemy.getEnemyHealth() << " health." << endl;
                        if(enemy.getEnemyHealth() <= 0)
                        {
                            enemy = Enemy("",0,0,Weapon("",0));
                            activeEnemy--;
                            player.removeItemAtIndex(integerInput-1);
                            player.itemSort();
                            integerInput = 0;
                            break;
                        }
                        player.removeItemAtIndex(integerInput-1);
                        player.itemSort();
                    }
                    else if(!theMap.nextToPlayer())
                    {
                        if(player.getItemAtIndex(integerInput-1).isHealingItem())
                        {
                            continue;
                        }
                        else
                        {
                            cout << "The item did nothing" << endl;
                            player.removeItemAtIndex(integerInput-1);
                            player.itemSort();
                        }

                    }
                    else
                    {
                        continue;
                    }
                }
            }
        input = "";
        integerInput = 0;
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
/*
    this function takes in a winners name, only done after completing the game and appends it to the
    winners text file, the function returns nothing.
*/
void writeWinner(string winnerName)
{
    ofstream my_file("winners.txt", std::ios::app);
    my_file << winnerName << endl;
}

int main()
{
    //storage for all enemies, items, and weapons in the game. THESE ARE CONSTANT
    //They are just to grab from not to be edited. 
    Weapon allWeapons[14];
    
    allWeapons[0] = Weapon("Dagger",1);
    allWeapons[1] = Weapon("Club", 1);
    allWeapons[2] = Weapon("Chair leg", 1);
    allWeapons[3] = Weapon("Wrench", 1);
    allWeapons[4] = Weapon("Shortsword",2);
    allWeapons[5] = Weapon("Whip", 2);
    allWeapons[6] = Weapon("Shovel", 2);
    allWeapons[7] = Weapon("Scythe", 3);
    allWeapons[8] = Weapon("Longsword", 3);
    allWeapons[9] = Weapon("Yklwa", 3);
    allWeapons[10] = Weapon("Battle Axe", 4); 
    allWeapons[11] = Weapon("Greatsword", 4);
    allWeapons[12] = Weapon("Explosive Hands", 4);
    allWeapons[13] = Weapon("Claymore",7);
    
    Item allItems[6];
    
    allItems[0] = Item("Small Health Potion", 1, 0);
    allItems[1] = Item("Medium Health Potion", 3, 0);
    allItems[2] = Item("Big HealthPotion", 5, 0);
    allItems[3] = Item("Splashing Acid", 0, 2);
    allItems[4] = Item("Boiling Tar", 0, 4);
    allItems[5] = Item("Minitour Blood", 0, 6);
    
    Enemy allEnemies[12];
    
    //easyEnemies
    allEnemies[0] = Enemy(); //slime
    allEnemies[1] = Enemy("goblin", 5, 5,Weapon());
    allEnemies[2] = Enemy("skeleton", 5, 4,Weapon());
    allEnemies[3] = Enemy("boar", 5, 6, Weapon("Tusks", 1));
    //mediumEnemies
    allEnemies[4] = Enemy("hobgoblin", 8, 4, Weapon("Dagger", 2));
    allEnemies[5] = Enemy("wolf", 8, 6, Weapon("Teeth", 2));
    allEnemies[6] = Enemy("zombie", 10, 3, Weapon("Fist", 2));
    allEnemies[7] = Enemy("Giant Beetle", 10, 6, Weapon("Horn", 2));
    //hardEnemies
    allEnemies[8] = Enemy("Cyclops", 12, 5, Weapon("Giant Club", 4));
    allEnemies[9] = Enemy("Mother slime", 12, 3, Weapon("Acid Touch", 3));
    allEnemies[10] = Enemy("Shadow Knight", 12, 6, Weapon("Shadow Sword", 3));
    allEnemies[11] = Enemy("Minitour", 15, 7, Weapon("Black Forged Axe", 6));

    //Bounds for the random functions.
    const int itemsUpperBound = 6;
    const int itemsLowerBound = 0;

    int weaponUpperBound = 7;
    int weaponLowerBound = 0;

    int enemyUpperBound = 4;
    int enemyLowerBound = 0;


    //Program termination conditions.
    const int errorReturn = -1;
    const int quitGame = 2;
    const int lostGame = 1;
    const int wonGame = 0;
    const int forceQuitGame = -9;

    //Enemy stats.
    Enemy enemy;
    //used only for the for loop for setting enemies in the map.
    int tempEnemyX = 0;
    int tempEnemyY = 0;
    //will be used before combat.

    //Objects used by the person playing the game
    Player player;
    string userInput = "";
    int menuOption = 0;
    bool action = false;
    bool forceQuit = false;
    bool playerDeath = false;
    int activeEnemy = 0;
    Map terminalMap;
    
    //Counters for the game to keep track of things
    int roomsVisited = 1;

    srand(time(NULL)); // random seed, makes all other random functions extra random.
    while(menuOption != 1)
    {
        cout << "Welcome to Dungeon Crawl!" << endl;
        cout << "1. Begin Adventure." << endl;
        cout << "2. Quit." << endl;
        cout << "Select an option: ";
        getline(cin, userInput);
        if(userInput == "1" || userInput == "2")
        {
            menuOption = stoi(userInput);
        }
        else
        {
            menuOption = 0;
        }

        if(menuOption == 2)
        {
            readText("quit.txt");
            return quitGame;
        }
        else if(menuOption == 1)
        {
            cout << endl;
            readText("tutorial.txt");        
            
            break;
        }
        else
        {
            cout << "Invalid Input. Please enter 1 or 2." << endl;
        }
    }
    cout << endl;

    readText("intro.txt");
    while(roomsVisited <= 6)
    {
        //sets up new room with enemy and player, the player starts in the same place every time.
        enemy = allEnemies[randomEnemy(enemyLowerBound,enemyUpperBound)];
        terminalMap.setPlayerCharacter('X');
        terminalMap.setPlayerXY(11,9);
        terminalMap.setEnemyCharacter(enemy.getEnemyCharacter());
        //random x y coordinates for enemy.
        tempEnemyX = rand()%22; //somewhere random
        tempEnemyY = rand()%8;
        terminalMap.setEnemyXY(tempEnemyX,tempEnemyY);
        activeEnemy = 1;
        cout << "You find a dangerous " << enemy.getEnemyName() << "!" << endl;
        
        // the bulk of the game is played within this while loop 
        while(!playerDeath)
        {
            player.setDodge(false); // making sure their action is false 
            action = false;
            combatMenu(action, player, enemy, activeEnemy, terminalMap, forceQuit); 
            if(forceQuit)
            {
                readText("quit.txt");
                return forceQuitGame;
            }
            if(activeEnemy == 0)
            {
                break;
            }
            enemyTurn(player, enemy, terminalMap);
            if(player.getHealth() <= 0)
            {
                playerDeath = true; 
                break;
            }
        }
        if(playerDeath)
        {
            readText("deathMessage.txt");
            return lostGame;
        }
        // going to the next room, change the enemy bounds for more difficult enemies
        enemyLowerBound ++; 
        enemyUpperBound ++;

        //resets the map so that the map doesnt get cluttered.
        terminalMap.setEnemyCharacter('-');
        terminalMap.setPlayerCharacter('-');
        terminalMap.setEnemyXY(terminalMap.getEnemyXIndex(),terminalMap.getEnemyYIndex());
        terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex());
        if(roomsVisited == 3)
        {
            weaponUpperBound = 13;
            weaponLowerBound = 7;
        }
        //opportunity for player to get items.
        checkRoom(player, allItems, allWeapons, itemsUpperBound, itemsLowerBound, weaponUpperBound, weaponLowerBound);
        
        roomsVisited++;
        cout << "A door opens, at the back wall. You walk through" << endl;
    }
        //Boss fight
        enemy = allEnemies[11];
        terminalMap.setPlayerCharacter('X');
        terminalMap.setPlayerXY(11,9);
        terminalMap.setEnemyCharacter(enemy.getEnemyCharacter());
        terminalMap.setEnemyXY(11,5);
        activeEnemy = 1;
        readText("finalboss.txt");
        while(!playerDeath)
        {
            player.setDodge(false);
            action = false;
            combatMenu(action, player, enemy, activeEnemy, terminalMap, forceQuit);
            if(forceQuit)
            {
                readText("quit.txt");
                return forceQuitGame;
            }
            if(activeEnemy == 0)
            {
                break;
            }
            enemyTurn(player, enemy, terminalMap);
            if(player.getHealth() <= 0)
            {
                playerDeath = true;
                break;
            }
        }
        if(playerDeath)
        {
            readText("deathMessage.txt");
            return lostGame;
        }
    readText("mercy.txt");

    readText("theEnd.txt");
    cout << endl;
    cout << "Please enter the name of the winner to be showcased in our winners file!";
    getline(cin, userInput);
    writeWinner(userInput);
    readText("winners.txt");

    return wonGame;
}