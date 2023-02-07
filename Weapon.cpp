//Libby Bianchi & Blake Martinez
//CSCI 1300
//Project 3

#include <string>
#include "Weapon.h"

using namespace std;

Weapon::Weapon()
{
    weaponName = "Tomohawk";
    damage = 1;
}
Weapon::Weapon(string wName, int wDamage)
{
    weaponName = wName;
    damage = wDamage;
}

void Weapon::setWeaponName(string name)
{
    weaponName = name;
}
void Weapon::setDamage(int newDamage)
{
    damage = newDamage;
}

int Weapon::getWeaponDamage()
{
    return damage;
}
string Weapon::getWeaponName()
{
    return weaponName;
}