//Libby Bianchi & Blake Martinez
//CSCI 1300
//Project 3

#include <string>
#include "Enemy.h"

using namespace std;

Enemy::Enemy()
{
    enemyHealth = 1;
    enemyName = "Slime";
    enemyMovement = 2;
    enemyWeapon = Weapon();
}
Enemy::Enemy(string badName, int badHealth, int movement, Weapon enemiesWeapon)
{
    enemyName = badName;
    enemyHealth = badHealth;
    enemyMovement = movement;
    enemyWeapon = enemiesWeapon;
}

string Enemy:: getEnemyName()
{
    return enemyName;
}
Weapon Enemy::getWeapon()
{
    return enemyWeapon;
}
char Enemy::getEnemyCharacter()
{
    return enemyName[0];
}
int Enemy:: getEnemyHealth()
{
    return enemyHealth;
}
int Enemy::getMovementSquares()
{
    return enemyMovement;
}
void Enemy::setEnemyName(string newName)
{
    enemyName = newName;
}
void Enemy::setEnemyHealth(int newHealth)
{
    enemyHealth = newHealth;
}
void Enemy::setMovementSquares(int newMovement)
{
    enemyMovement = newMovement;
}