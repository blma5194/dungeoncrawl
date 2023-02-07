//Libby Bianchi & Blake Martinez
//CSCI 1300
//Project 3

#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "Item.h"
#include "Weapon.h"
using namespace std;

class Enemy
{
    public:
    Enemy();
    Enemy(string enemyName, int enemyHealth, int enemyMovement, Weapon enemyWeapon);
    
    string getEnemyName();
    char getEnemyCharacter();
    int getEnemyHealth();
    int getMovementSquares();
    Weapon getWeapon();

    void setEnemyName(string newName);
    void setEnemyHealth(int badGuyHealth);
    void setMovementSquares(int badGuyMovement);
    
    private:
    static const int sizeOfHeldItems = 2;
    Weapon enemyWeapon;
    Item heldItems[sizeOfHeldItems];
    string enemyName;
    int enemyHealth;
    int enemyMovement;
};
#endif