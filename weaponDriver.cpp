//Libby Bianchi & Blake Martinez
//CSCI 1300
//Project 3

#include "Weapon.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    Weapon defaultWeapon;
    cout << defaultWeapon.getWeaponDamage() << endl;
    cout << defaultWeapon.getWeaponName() << endl;
    return 0;
}