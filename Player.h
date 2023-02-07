//Libby Bianchi & Blake Martinez
//CSCI 1300
//Project 3

using namespace std;
#ifndef PLAYER_H
#define PLAYER_H
#include "Item.h"
#include "Weapon.h"
class Player
{
    public:
    Player();
    Player(int health, int movementSquares, Weapon playerWeapon, Item playerHeldItems[], int itemsAlreadyHeld);
    
    int getHealth();
    int getMovementSquares();
    Weapon getWeapon();
    Item getItemAtIndex(int index);
    int getItemsHeld();
    
    int healPlayer(int itemIndex);

    void setWeapon(Weapon newWeapon);
    void setItemAtIndex(int index, Item newItem);
    void addItemAtIndex(int index, Item newItem);
    void removeItemAtIndex(int index);
    void itemSort();
    void setMovementSquares(int move);
    void setDodge(bool input);
    bool getDodge();
    void setHealth(int newHealth);


    private:
    int movementSquares = 8;
    int health = 13;
    static const int sizeOfHeldItems = 8;
    Item playerHeldItems[sizeOfHeldItems];
    Weapon playerWeapon;
    int itemsAlreadyHeld = 0;
    bool dodge = false;
};
#endif