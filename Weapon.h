//Libby Bianchi & Blake Martinez
//CSCI 1300
//Project 3

#ifndef WEAPON_H
#define WEAPON_H
#include <string>

using namespace std;

class Weapon
{
    public:
    Weapon();
    Weapon(string weaponName, int damage);
    
    void setWeaponName(string name);
    void setDamage(int damage);
    
    int getWeaponDamage();
    string getWeaponName();
    
    private:
    string weaponName;
    int damage;
};
#endif