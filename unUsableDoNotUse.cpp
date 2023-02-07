//Libby Bianchi & Blake Martinez
//CSCI 1300
//Project 3

//g++ -std=c++11 DungeonCrawlDriver.cpp Player.cpp Enemy.cpp Weapon.cpp Item.cpp Map.cpp -o dungeonCrawl
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
in the game. It is important that we use an array of size 12 as it fills in every index of the enemy
MANUALLY.
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
*/
void readText(string filename)
{
    string line;
    ifstream my_file;
    my_file.open(filename);

    if(my_file.fail())
    {
        cout << "Warning! File Not found" << endl;
    }
    while(getline(my_file,line))
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
void combatMenu(bool& action, Player& player, Enemy enemies[], int& activeEnemies, Map& terminalMap)
{
string input = "";
int integerInput = 0;
const int maxSplitArraySize = 10;
string splitArray[maxSplitArraySize];
bool endTurn = true;
int remainingMovement = player.getMovementSquares();
int newRemainingMovement = remainingMovement;
int x_pos = 0;
int y_pos = 0;
int enemyIndex = 0;
terminalMap.setCharacterXY(10,9,0);
while(remainingMovement > 0 || action == false)
{
    terminalMap.outputMap();

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
        int newRemainingMovement = remainingMovement;
        if(input.length() > remainingMovement)
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

    terminalMap.movePlayerTo(x_pos,y_pos);
    x_pos = 0;
    y_pos = 0;
    terminalMap.outputMap();
    input = "";
    }
    else if(input == "2")
    {
        if(action)
        {
            cout << "You hace already used your action." << endl;
            input = "";
        }
        else
        {
        //if the player is next to the enemy
        if(terminalMap.nextToEnemy() != -1)
        {
            enemyIndex = terminalMap.nextToEnemy();
            enemies[enemyIndex].setEnemyHealth(enemies[enemyIndex].getEnemyHealth()-player.getWeapon().getWeaponDamage());
            if(enemies[enemyIndex].getEnemyHealth()-player.getWeapon().getWeaponDamage() <= 0)
            {
                enemies[enemyIndex] = Enemy("",0,0,Weapon("",0));
                terminalMap.setCharacterAt(enemyIndex+1, '-');
                terminalMap.setCharacterXY(terminalMap.getEnemyXIndex(enemyIndex+1),terminalMap.getEnemyYIndex(enemyIndex+1),enemyIndex+1);
                activeEnemies--;
            }
            action = true;
        }
        else
        {
            cout << "You swing your " << player.getWeapon().getWeaponName() << " and miss wildly." << endl;
        }
        input = "";
        }
    }
    else if(input == "3")
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
            if(terminalMap.nextToEnemy() != -1)
            {
                //damage the enemy
                enemyIndex = terminalMap.nextToEnemy();
                enemies[enemyIndex].setEnemyHealth(enemies[enemyIndex].getEnemyHealth()-player.getItemAtIndex(integerInput-1).getDamage());
                if(enemies[enemyIndex].getEnemyHealth() <= 0)
                {
                    enemies[enemyIndex] = Enemy("",0,0,Weapon("",0));
                    activeEnemies--;
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
    else if(input == "4")
    {
        if(action)
        {
            cout << "You hace already used your action." << endl;
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
    else
    {
        cout << "Only enter numbers 1-6." << endl;
        input = "";
        continue;
    }
}
}
/*
the enemies turn, goes through cases in which the enemy may encounter as it plays the game.
returns true if the player has died. (returning simply means setting a variable equal to as to save progress
from the combat ongoing.)
*/
//enemy index refers to the index of the enemy within the enemy array not the coordinates.
bool enemyTurn(Player& player, Enemy enemies[], Map& terminalMap, int enemyArrIndex)
{
    terminalMap.outputMap();
    int disX = (terminalMap.getPlayerXIndex() - terminalMap.getEnemyXIndex(enemyArrIndex+1));
    int disY = (terminalMap.getPlayerYIndex() - terminalMap.getEnemyYIndex(enemyArrIndex+1));
    int disTot = (abs(disX) + abs(disY));
    cout << disX << disY << disTot << endl;
    int remainingMovement = enemies[enemyArrIndex].getMovementSquares();
    //cases for if the enemy is already next to the player
    if(terminalMap.nextToPlayer(enemyArrIndex))
    {
        if(player.getDodge())
        {
            cout << "You dodge the attack!" << endl; 
            return false;
        }
        else
        {
            cout << "The " << enemies[enemyArrIndex].getEnemyName() << " swings with its "<< enemies[enemyArrIndex].getWeapon().getWeaponName()<< 
            "! Doing " <<enemies[enemyArrIndex].getWeapon().getWeaponDamage() <<" damage!" << endl;
            player.setHealth(player.getHealth()-enemies[enemyArrIndex+1].getWeapon().getWeaponDamage());

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
    if(disTot < enemies[enemyArrIndex].getMovementSquares())
    {
        if(disX == 0)
        {
            disY-=1;
        }
        else if(disY == 0)
        {
            disX-=1;
        }
        else
        {
            terminalMap.moveEnemyX(disX, enemyArrIndex+1);
            terminalMap.moveEnemyY(disY, enemyArrIndex+1);
        }
        if(player.getDodge())
        {
            cout << "You dodge the attack!" << endl; 
            return false;
        }
        else
        {
        cout << "The " << enemies[enemyArrIndex].getEnemyName() << " swings with its "<< enemies[enemyArrIndex].getWeapon().getWeaponName()<< 
        "! Doing " <<enemies[enemyArrIndex].getWeapon().getWeaponDamage() <<" damage!" << endl;
        player.setHealth(player.getHealth()-enemies[enemyArrIndex].getWeapon().getWeaponDamage());
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
    if(disTot == enemies[enemyArrIndex].getMovementSquares()+1 || disTot == enemies[enemyArrIndex].getMovementSquares())
    {
        if(disX == 0)
        {
            disY-=1;
            terminalMap.moveEnemyY(disY, enemyArrIndex+1);
        }
        else if(disY == 0)
        {
            disX-=1;
            terminalMap.moveEnemyX(disX, enemyArrIndex+1);
        }
        else if(disX == 1)
        {
            disX-=1;
            terminalMap.moveEnemyX(disX, enemyArrIndex+1);
            terminalMap.moveEnemyY(disY, enemyArrIndex+1);
        }
        else if(disY == 1)
        {
            disY-=1;
            terminalMap.moveEnemyY(disY, enemyArrIndex+1);
            terminalMap.moveEnemyX(disX, enemyArrIndex+1);
        }
        else
        {
            terminalMap.moveEnemyX(disX, enemyArrIndex+1);
            terminalMap.moveEnemyY(disY, enemyArrIndex+1);
        }

        if(player.getDodge())
        {
            cout << "You dodge the attack!" << endl; 
            return false;
        }
        else
        {
        cout << "The " << enemies[enemyArrIndex].getEnemyName() << " swings with its "<< enemies[enemyArrIndex].getWeapon().getWeaponName()<< 
        "! Doing " <<enemies[enemyArrIndex].getWeapon().getWeaponDamage() <<" damage!" << endl;
        player.setHealth(player.getHealth()-enemies[enemyArrIndex].getWeapon().getWeaponDamage());
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
    else if(abs(disX) > enemies[enemyArrIndex].getMovementSquares())
    {
        terminalMap.moveEnemyX(enemies[enemyArrIndex].getMovementSquares(), enemyArrIndex+1);
        terminalMap.outputMap();
        return false;
    }
    else
    {
        terminalMap.moveEnemyX(disX, enemyArrIndex+1);
        remainingMovement -= disX;
        if(disY > 0)
        {
        terminalMap.moveEnemyY(remainingMovement, enemyArrIndex+1);
        }
        else
        {
        terminalMap.moveEnemyY(-remainingMovement, enemyArrIndex+1);
        }
        terminalMap.outputMap();
        return false;
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
int randomItem = lowerBound + rand() % (upperBound-lowerBound);
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
    cout << "Would you like to keep this weapon?"<< endl;
    cout << "1. yes 2. no" << endl;
    
    getline(cin,input); // retrieving user input
        if(input == "1")
        {
            cout << "You equip " << newWeapon.getWeaponName() << "!" << endl;
            X.setWeapon(newWeapon); // set the players weapon as the new weapon
        }
        else if(input == "2")
        {
            cout << "The weapon fades from your hand almost as if it were a ghost" << endl;
        }
        else
        {
            cout << "You drop the weapon, it shatters into a million shards." << endl; // user gets one chance to click yes or no
            cout << "The weapon is now completly unrecoverable." << endl;
        }
       cout << endl;

    newItem = allItems[randomItem(lowerItemBound, upperItemBound)]; // calling the random item funciton 
    cout << "You also find: " << newItem.getItemName() << endl;// matching the item index numbers and names
    cout << "Would you like to keep this item?"<< endl;
    cout << "1. yes 2. no" << endl;

        if(input == "1")
        {
            cout <<"select which index you'd like to replace: " << endl;
            for(int i = 0; i < 8; i++)
            {
                cout << i+1 << ". " << X.getItemAtIndex(i).getItemName() << endl;

            }
            getline(cin, input);
            if(input > "0" && input < "9")
            {
               storeGetlineNumber = stoi(input);
               cout << newItem.getItemName() << " has been added to your inventory." << endl;
               X.setItemAtIndex(storeGetlineNumber-1, newItem);
               X.itemSort();
            } // adds item to their inventory 
            else
            {
                cout << "you fumbled breaking the item on the ground" << endl;
            }
        }
        else if(input == "2")
        {
            cout << "you leave the item behind." << endl;
        }
    cout << endl;
    }
    else if(input == "2")
    {
        cout << "No new weaopons or items were added to your inventory." << endl;
        
    }
    
}


int main()
{
    //storage for all enemies, items, and weapons in the game. THESE ARE CONSTANT
    //They are just to grab from not to be edited. 
    Weapon allWeapons[14];
    
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
    
    Item allItems[6];
    
    allItems[0] = Item("Small Health Potion", 2, 0);
    allItems[1] = Item("Medium Health Potion", 4, 0);
    allItems[2] = Item("Big HealthPotion", 6, 0);
    allItems[3] = Item("Splashing Acid", 0, 3);
    allItems[4] = Item("Boiling Tar", 0, 5);
    allItems[5] = Item("Minitour Blood", 0, 7);
    
    Enemy allEnemies[12];
    
    //easyEnemies
    allEnemies[0] = Enemy(); //slime
    allEnemies[1] = Enemy("goblin", 2, 3,Weapon());
    allEnemies[2] = Enemy("skeleton", 2, 2,Weapon());
    allEnemies[3] = Enemy("boar", 2, 4, Weapon("Tusks", 1));
    //mediumEnemies
    allEnemies[4] = Enemy("hobgoblin", 4, 3, Weapon("Dagger", 2));
    allEnemies[5] = Enemy("wolf", 3, 5, Weapon("Teeth", 2));
    allEnemies[6] = Enemy("zombie", 7, 2, Weapon("Fist", 1));
    allEnemies[7] = Enemy("Giant Beetle", 6, 5, Weapon("Horn", 1));
    //hardEnemies
    allEnemies[8] = Enemy("Cyclops", 8, 4, Weapon("Giant Club", 3));
    allEnemies[9] = Enemy("Mother slime", 12, 1, Weapon("Acid Touch", 2));
    allEnemies[10] = Enemy("Shadow Knight", 8, 3, Weapon("Shadow Sword", 2));
    allEnemies[11] = Enemy("Minitour", 8, 5, Weapon("Giant Axe", 4));

    //Bounds for the random functions.
    const int itemsUpperBound = 6;
    const int itemsLowerBound = 0;

    int weaponUpperBound = 7;
    int weaponLowerBound = 0;

    int enemyUpperBound = 3;
    int enemyLowerBound = 0;


    //Program termination conditions.
    const int errorReturn = -1;
    const int quitGame = 2;
    const int lostGame = 1;
    const int wonGame = 0;
    const int forceQuitGame = -9;

    //Enemy stats.
    const int maxEnemies = 5;
    const int minEnemies = 1;
    int totalenemies = 0;
    int activeEnemies = totalenemies;
    Enemy enemies[maxEnemies];
    int enemyArrIndex = 0;
    //used only for the for loop for setting enemies in the map.
    int tempEnemyX = 0;
    int tempEnemyY = 0;
    //will be set when 

    //Objects used by the person playing the game
    Player player;
    string userInput = "";
    int menuOption = 0;
    bool action = false;
    bool playerDeath = false;

    Map terminalMap;
    
    //Counters for the game to keep track of things
    int roomsVisited = 1;

    srand(time(NULL));
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
            cout << "Thank you for playing" << endl;
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

    //anything above this point is good!
    while(roomsVisited <= 4)
    {
        totalenemies = rand() % maxEnemies+minEnemies;
        cout << totalenemies;
        activeEnemies = totalenemies;
        //player always starts at the edge in the middle of the room.
        //index 0 signifies the players character index.
        terminalMap.setCharacterXY(11,9,0);
        //could potentially land on someone with the same coordinate.
        for(int i = 0; i < totalenemies; i++)
        {
            enemies[i] = allEnemies[randomEnemy(enemyLowerBound,enemyUpperBound)];
        }
        for(int i = 1; i<= totalenemies; i++)
        {
            terminalMap.setCharacterAt(i,enemies[i-1].getEnemyCharacter());
            tempEnemyX = rand()%22;
            tempEnemyY = rand()%8;
            terminalMap.setCharacterXY(tempEnemyX,tempEnemyY,enemies[i-1].getEnemyCharacter());
            for(int i = 1; i <= totalenemies; i++)
            {
                if(tempEnemyX == terminalMap.getEnemyXIndex(i))
                {

                    if(tempEnemyY == terminalMap.getEnemyYIndex(i))
                    {
                        tempEnemyX = rand()%22;
                        tempEnemyY = rand()%8;
                        i--;
                    }
                    else
                    {
                        terminalMap.setCharacterXY(tempEnemyX,tempEnemyY,enemies[i-1].getEnemyCharacter());
                    }
                }
                else
                {
                    terminalMap.setCharacterXY(tempEnemyX,tempEnemyY,enemies[i-1].getEnemyCharacter());
                }
            }
        }

        while(totalenemies > 0)
        {
            if(player.getHealth() == 0)
            {
                playerDeath = true;
            }
            if(totalenemies == 0)
            {
                break;
            }
            //combatMenu(bool action, Player player, Enemy enemies[], int activeEnemies, Map terminalMap)
            if(!playerDeath)
            {
                player.setDodge(false);
                string input = "";
                int integerInput = 0;
                const int maxSplitArraySize = 10;
                string splitArray[maxSplitArraySize];
                bool endTurn = true;
                int remainingMovement = player.getMovementSquares();
                int newRemainingMovement = remainingMovement;
                int x_pos = 0;
                int y_pos = 0;
                int enemyIndex = 0;
                while(remainingMovement > 0 || action == false)
                {
                    terminalMap.outputMap();
                    cout << "|Health: " <<player.getHealth() <<  "     |" << endl;
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
                        int newRemainingMovement = remainingMovement;
                        if(input.length() > remainingMovement)
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

                    terminalMap.movePlayerTo(x_pos,y_pos);
                    x_pos = 0;
                    y_pos = 0;
                    terminalMap.outputMap();
                    input = "";
                    }
                    else if(input == "2")
                    {
                        if(action)
                        {
                            cout << "You have already used your action." << endl;
                            input = "";
                        }
                        else
                        {
                        //if the player is next to the enemy
                        if(terminalMap.nextToEnemy() != -1)
                        {
                            enemyIndex = terminalMap.nextToEnemy();
                            enemies[enemyIndex].setEnemyHealth(enemies[enemyIndex].getEnemyHealth()-player.getWeapon().getWeaponDamage());
                            if(enemies[enemyIndex].getEnemyHealth()-player.getWeapon().getWeaponDamage() <= 0)
                            {
                                enemies[enemyIndex] = Enemy("",0,0,Weapon("",0));
                                terminalMap.setCharacterAt(enemyIndex+1, '-');
                                terminalMap.setCharacterXY(terminalMap.getEnemyXIndex(enemyIndex+1),terminalMap.getEnemyYIndex(enemyIndex+1),enemyIndex+1);
                                activeEnemies--;
                            }
                            action = true;
                        }
                        else
                        {
                            cout << "You swing your " << player.getWeapon().getWeaponName() << " and miss wildly." << endl;
                        }
                        input = "";
                        }
                    }
                    else if(input == "3")
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
                            if(terminalMap.nextToEnemy() != -1)
                            {
                                //damage the enemy
                                enemyIndex = terminalMap.nextToEnemy();
                                enemies[enemyIndex].setEnemyHealth(enemies[enemyIndex].getEnemyHealth()-player.getItemAtIndex(integerInput-1).getDamage());
                                if(enemies[enemyIndex].getEnemyHealth() <= 0)
                                {
                                    enemies[enemyIndex] = Enemy("",0,0,Weapon("",0));
                                    activeEnemies--;
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
                    else
                    {
                        cout << "Only enter numbers 1-6." << endl;
                        input = "";
                        continue;
                    }
                }   
            }           
            else
            {
                readText("deathMessage.txt");
                return lostGame;
            }

            for(int i = enemyArrIndex; i < totalenemies;i++)
            {
                if(activeEnemies == 0)
                {
                    break;
                }
                
                if(i == totalenemies-1 && enemies[i].getEnemyCharacter() == '-')
                {
                    i = 0;
                }
                if(enemies[i].getEnemyCharacter() != '-')
                {
                    enemyArrIndex = i;
                }
            }
                      
            //checks to see if there are any enemies left to fight, and breaks combat once all of the enemies have died.
            //does combat
            if(activeEnemies > 0)
            {
                //enemyTurn(Player player, Enemy enemies[], int activeEnemies, Map terminalMap, int enemyIndex)
                int disX = (terminalMap.getPlayerXIndex() - terminalMap.getEnemyXIndex(enemyArrIndex+1));
                int disY = (terminalMap.getPlayerYIndex() - terminalMap.getEnemyYIndex(enemyArrIndex+1));
                int disTot = (abs(disX) + abs(disY));
                int remainingMovement = enemies[enemyArrIndex].getMovementSquares();
                //cases for if the enemy is already next to the player
                if(terminalMap.nextToPlayer(enemyArrIndex))
                {
                    if(player.getDodge())
                    {
                        cout << "You dodge the attack!" << endl; 
                        playerDeath = false;
                    }
                    else
                    {
                        cout << "The " << enemies[enemyArrIndex].getEnemyName() << " swings with its "<< enemies[enemyArrIndex].getWeapon().getWeaponName()<< 
                        "! Doing " <<enemies[enemyArrIndex].getWeapon().getWeaponDamage() <<" damage!" << endl;
                        player.setHealth(player.getHealth()-enemies[enemyArrIndex+1].getWeapon().getWeaponDamage());

                        if(player.getHealth() <= 0)
                        {
                            terminalMap.outputMap();
                            playerDeath = true;
                        }
                        else
                        {
                            terminalMap.outputMap();
                            playerDeath = false;
                        }
                    }
                }
                //Movement cases
                if(disTot < enemies[enemyArrIndex].getMovementSquares())
                {
                    if(disX == 0)
                    {
                        disY-=1;
                    }
                    else if(disY == 0)
                    {
                        disX-=1;
                    }
                    else
                    {
                        cout << "the " << enemies[enemyArrIndex].getEnemyName() << " moves closer." << endl;
                        terminalMap.moveEnemyX(disX, enemyArrIndex+1);
                        terminalMap.moveEnemyY(disY, enemyArrIndex+1);
                    }
                    if(player.getDodge())
                    {
                        cout << "You dodge the attack!" << endl; 
                        playerDeath = false;
                    }
                    else
                    {
                    cout << "The " << enemies[enemyArrIndex].getEnemyName() << " swings with its "<< enemies[enemyArrIndex].getWeapon().getWeaponName()<< 
                    "! Doing " <<enemies[enemyArrIndex].getWeapon().getWeaponDamage() <<" damage!" << endl;
                    player.setHealth(player.getHealth()-enemies[enemyArrIndex].getWeapon().getWeaponDamage());
                    if(player.getHealth() <= 0)
                    {
                        terminalMap.outputMap();
                        playerDeath = true;
                    }
                    else
                    {
                        terminalMap.outputMap();
                        playerDeath = false;
                    }
                    }
                }
                if(disTot == enemies[enemyArrIndex].getMovementSquares()+1 || disTot == enemies[enemyArrIndex].getMovementSquares())
                {
                    if(disX == 0)
                    {
                        disY-=1;
                        cout << "the " << enemies[enemyArrIndex].getEnemyName() << " moves closer." << endl;
                        terminalMap.moveEnemyY(disY, enemyArrIndex+1);
                    }
                    else if(disY == 0)
                    {
                        disX-=1;
                        cout << "the " << enemies[enemyArrIndex].getEnemyName() << " moves closer." << endl;
                        terminalMap.moveEnemyX(disX, enemyArrIndex+1);
                    }
                    else if(disX == 1)
                    {
                        disX-=1;
                        cout << "the " << enemies[enemyArrIndex].getEnemyName() << " moves closer." << endl;
                        terminalMap.moveEnemyX(disX, enemyArrIndex+1);
                        terminalMap.moveEnemyY(disY, enemyArrIndex+1);
                    }
                    else if(disY == 1)
                    {
                        disY-=1;
                        cout << "the " << enemies[enemyArrIndex].getEnemyName() << " moves closer." << endl;
                        terminalMap.moveEnemyY(disY, enemyArrIndex+1);
                        terminalMap.moveEnemyX(disX, enemyArrIndex+1);
                    }
                    else
                    {
                        cout << "the " << enemies[enemyArrIndex].getEnemyName() << " moves closer." << endl;
                        terminalMap.moveEnemyX(disX, enemyArrIndex+1);
                        terminalMap.moveEnemyY(disY, enemyArrIndex+1);
                    }

                    if(player.getDodge())
                    {
                        cout << "You dodge the attack!" << endl; 
                        playerDeath = false;
                    }
                    else
                    {
                    cout << "The " << enemies[enemyArrIndex].getEnemyName() << " swings with its "<< enemies[enemyArrIndex].getWeapon().getWeaponName()<< 
                    "! Doing " <<enemies[enemyArrIndex].getWeapon().getWeaponDamage() <<" damage!" << endl;
                    player.setHealth(player.getHealth()-enemies[enemyArrIndex].getWeapon().getWeaponDamage());
                    if(player.getHealth() <= 0)
                    {
                        terminalMap.outputMap();
                        playerDeath = true;
                    }
                    else
                    {
                        terminalMap.outputMap();
                        playerDeath = false;
                    }
                    }
                }
                else if(abs(disX) > enemies[enemyArrIndex].getMovementSquares())
                {
                    cout << "the " << enemies[enemyArrIndex].getEnemyName() << " moves closer." << endl;
                    terminalMap.moveEnemyX(enemies[enemyArrIndex].getMovementSquares(), enemyArrIndex+1);
                    terminalMap.outputMap();
                    playerDeath = false;
                }
                else
                {
                    terminalMap.moveEnemyX(disX, enemyArrIndex+1);
                    remainingMovement -= disX;
                    if(disY > 0)
                    {
                    terminalMap.moveEnemyY(remainingMovement, enemyArrIndex+1);
                    }
                    else
                    {
                    terminalMap.moveEnemyY(-remainingMovement, enemyArrIndex+1);
                    }
                    cout << "the " << enemies[enemyArrIndex].getEnemyName() << " moves closer." << endl;
                    terminalMap.outputMap();
                    playerDeath = false;
                }
            }
            
            else
            {
                break;
            }
            enemyArrIndex++;
            if(enemyArrIndex == totalenemies)
            {
            enemyArrIndex = 0;        
            }
        }
        roomsVisited++;
        if(roomsVisited == 2)
        {
            enemyUpperBound += 2;
            enemyLowerBound += 2;
        }
        if(roomsVisited == 3)
        {
            enemyUpperBound += 2;
            enemyLowerBound += 2;
            weaponUpperBound = 13;
            weaponLowerBound = 7;
        }
        if(roomsVisited == 4)
        {
            enemyUpperBound += 2;
            enemyLowerBound += 2;
        }
        terminalMap = Map();
    }
    enemyUpperBound = 11;
    enemyLowerBound = 8;
    //boss fight goes here.
    
    return wonGame;
}