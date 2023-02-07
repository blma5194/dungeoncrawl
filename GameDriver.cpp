//Libby Bianchi & Blake Martinez
//CSCI 1300
//Project 3

#include <iostream>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "Weapon.h"
#include "Map.h"

using namespace std;

int main()
{
    Item heldItems[] = {Item(),Item(),Item()};
    Weapon coolWeapon = Weapon("Excalibur", 10);
    Weapon defaultWeapon;
    Player a;
    Item x;
    Item healingPotion = Item("Small healing pot", 3,0);
    Enemy defaultEnemy;
    Enemy goblin = Enemy("goblin", 3, 5, Weapon());

    cout << "Weapon Name: " << defaultWeapon.getWeaponName() << endl;
    cout << "Weapon Damage: " << defaultWeapon.getWeaponDamage() << endl;
    cout << "Weapon Name: " << coolWeapon.getWeaponName() << endl;
    cout << "Weapon Damage: " << coolWeapon.getWeaponDamage() << endl;
    cout << "Player Health: " << a.getHealth() << endl;
    cout << "Player Movement: " << a.getMovementSquares() << endl;
    cout << "Healing Item Name: " << healingPotion.getItemName() << endl;
    cout << "Healing Value: " << healingPotion.getHealingValue() << endl;
    cout << "Healing Item Name: " << x.getItemName() << endl;
    cout << "Healing Value: " << x.getHealingValue() << endl;
    cout << "Enemy Name: " << defaultEnemy.getEnemyName() << endl;
    cout << "Enemy Health: " << defaultEnemy.getEnemyHealth() << endl;
    cout << "Enemy Movement: " << defaultEnemy.getMovementSquares() << endl;
    cout << "Enemy Name: " << goblin.getEnemyName() << endl;
    cout << "Enemy Health: " << goblin.getEnemyHealth() << endl;
    cout << "Enemy Movement: " << goblin.getMovementSquares() << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "You feel the cold bite of steel bring you to your knees." << endl;
    cout << "The monsters surround you carving into your flesh." << endl;
    cout << "The screams of utter disembowlment fill the room" << endl;
    cout << "A heavenly figure appears before you with its hand extended." << endl;
    cout << "You feel your final breath escape your lungs." << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << " " << endl;
    cout << "_________________" << endl;
    cout << "|               |" << endl;
    cout << "| YOU HAVE DIED |" << endl;
    cout <<  "_________________" << endl;
    
    cout << "________________" << endl;
    cout << "|Combat Menu:  |" << endl;
    cout << "________________" << endl;
    cout << "|Enter Action: |" << endl;
    cout << "|1.Move        |" << endl;
    cout << "|2.Attack      |" << endl;
    cout << "|3.Heal        |" << endl;
    cout << "|4.Weapon Stats|" << endl;
    cout << "|5.End turn    |" << endl;
    cout << "________________" << endl;
    return 0;   
}


