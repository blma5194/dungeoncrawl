#include <iostream>
#include "Enemy.h"
#include "Item.h"
#include "Weapon.h"
#include <string>


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

int main()
{

}