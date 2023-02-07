//Libby Bianchi & Blake Martinez
//CSCI 1300
//Project 3

#include <string>
#include "Player.h"
#include <iostream>

using namespace std;


Player::Player()
{
    playerWeapon = Weapon();
    for(int i = 0; i < sizeOfHeldItems; i++)
    {
        playerHeldItems[i] = Item();
    }
}
Player::Player(int playerHealth, int playerMovementSquares, Weapon playersWeapon, Item playersHeldItems[], int itemsAlreadyHeld)
{
    health = playerHealth;
    movementSquares = playerMovementSquares;
    playerWeapon = playersWeapon;
    for(int i = 0; i < sizeOfHeldItems; i++)
    {
        playerHeldItems[i] = playersHeldItems[i];
    }
}
int Player::getHealth()
{
    return health;
}
int Player::getMovementSquares()
{
    return movementSquares;
}
int Player::getItemsHeld()
{
    return itemsAlreadyHeld; 
}
int Player::healPlayer(int itemIndex)
{

    health += playerHeldItems[itemIndex].getHealingValue();
    return health;

}
Weapon Player::getWeapon()
{
    return playerWeapon;
}
Item Player::getItemAtIndex(int index)
{
    return playerHeldItems[index];
}
void Player::setWeapon(Weapon newWeapon)
{
    playerWeapon = newWeapon;
}
void Player::setItemAtIndex(int index, Item newItem)
{
    playerHeldItems[index] = newItem;
}
void Player::addItemAtIndex(int index, Item newItem)
{
    if(itemsAlreadyHeld < 8)
    {
    playerHeldItems[index] = newItem;
    itemsAlreadyHeld++;
    }
}
//Sorts the stored items a player holds by healing type then by magnitude of healing value
//then my damage type, then by damage value.
void Player::itemSort()
{
    int healingIndex = 0;
    int damageIndex = 0;
    
    int playersItems = 0;
    
    Item healingItems[8];
    Item damagingItems[8];
    for(int i = 0; i < 8; i++)
    {
        if(playerHeldItems[i].isHealingItem())
        {
            healingItems[healingIndex] = playerHeldItems[i]; // storing healing items in a temporary array 
            playerHeldItems[i] = Item();
            healingIndex++;// increasing the healing item array index(temporary)
        }
        else// if not a healing item 
        {
            damagingItems[damageIndex] = playerHeldItems[i]; // storing damaging items in a temp array
            playerHeldItems[i] = Item();
            damageIndex++;// increasing the damage item array index(tempoaray)
        }
    }
    for(int i  = 0; i <  healingIndex; i++)
    {
        if(healingItems[i].getItemName() != Item().getItemName())
        {
            playerHeldItems[playersItems] = healingItems[i];
            playersItems++;
        }
    }
    for(int i = 0; i< damageIndex;i++)
    {
        if(damagingItems[i].getItemName() != Item().getItemName())
        {
            playerHeldItems[playersItems] = damagingItems[i];
            playersItems++;
        }
    }
}

void Player::setDodge(bool in)
{
    dodge = in;
}

void Player::setMovementSquares(int move)
{
    movementSquares = move;
}
void Player::setHealth(int newHealth)
{
    health = newHealth;
}
bool Player::getDodge()
{
    return dodge;
}
void Player::removeItemAtIndex(int index)
{
    if(itemsAlreadyHeld > 0)
    {
        playerHeldItems[index] = Item();
        itemsAlreadyHeld--;
    }
}