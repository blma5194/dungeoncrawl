#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include <iostream>
 using namespace std;
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
    cout << "Damage: " << newWeapon.getWeaponDamage() << endl;
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

        if(input == "1")
        {
            cout <<"select which item you'd like to replace: " << endl;
            for(int i = 0; i < 8; i++)
            {
                cout << i+1 << ". " << X.getItemAtIndex(i).getItemName() << endl;

            }
            getline(cin, input);
            if(input > "0" && input < "9")
            {
               storeGetlineNumber = stoi(input);
               cout << newItem.getItemName() << " has been added to your inventory." << endl;
               X.addItemAtIndex(storeGetlineNumber-1, newItem);
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

}