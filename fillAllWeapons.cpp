#include "Weapon.h"
#include <string.h>
#include <iostream>

using namespace std;

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

int main()
{
    Weapon allWeapons[14];
    fillAllWeapons(allWeapons);
    for(int i = 0; i < 14; i++)
    {
        cout << allWeapons[i].getWeaponName()<< " Damage: " << allWeapons[i].getWeaponDamage() << endl;
    }
    return 0;
}