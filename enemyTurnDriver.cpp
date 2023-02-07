#include <iostream>
#include <string>
#include "Weapon.h"
#include "Item.h"
#include "Player.h"
#include "Map.h"
#include "Enemy.h"

using namespace std;
//g++ -std=c++11 enemyTurnDriver.cpp Weapon.cpp Item.cpp Player.cpp Map.cpp Enemy.cpp -o enemyTurnD

/*
the enemies turn, goes through cases in which the enemy may encounter as it plays the game.
returns true if the player has died.
*/
//enemy index refers to the index of the enemy within the enemy array not the coordinates.
bool enemyTurn(Player& player, Enemy& enemy, Map& terminalMap)
{
    terminalMap.outputMap();
    int disX = (terminalMap.getPlayerXIndex() - terminalMap.getEnemyXIndex());
    int disY = (terminalMap.getPlayerYIndex() - terminalMap.getEnemyYIndex());
    int disTot = (abs(disX) + abs(disY));
    int remainingMovement = enemy.getMovementSquares();
    //cases for if the enemy is already next to the player
    if(terminalMap.nextToPlayer())
    {
        if(player.getDodge())
        {
            cout << "You dodge the attack!" << endl; 
            return false;
        }
        else
        {
            cout << "The " << enemy.getEnemyName() << " swings with its "<< enemy.getWeapon().getWeaponName()<< 
            "! Doing " <<enemy.getWeapon().getWeaponDamage() <<" damage!" << endl;
            player.setHealth(player.getHealth()-enemy.getWeapon().getWeaponDamage());

            if(player.getHealth() <= 0)
            {
                terminalMap.outputMap();
                return true;
            }
            else
            {
                terminalMap.outputMap();
                return false;
            }
        }
    }
    //Movement cases
    if(disTot < enemy.getMovementSquares())
    {
        if(disX == 0)
        {
            disY-=1;
            terminalMap.moveEnemyY(disY);
        }
        else if(disY == 0)
        {
            disX-=1;
            terminalMap.moveEnemyX(disX);
        }
        else
        {
            terminalMap.moveEnemyX(disX);
            terminalMap.moveEnemyY(disY);
        }
        if(terminalMap.getPlayerXIndex() == terminalMap.getEnemyXIndex() && 
            terminalMap.getPlayerYIndex() == terminalMap.getEnemyYIndex())
            {   
            cout << "the enemy lands on you and pushes you!" << endl;
            cout << "you take 1 damage from the push." << endl;
            player.setHealth(player.getHealth()-1);
            if(terminalMap.getPlayerXIndex() == 21)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()-1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerXIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()+1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerYIndex() == 9)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()-1);
            }
            else if(terminalMap.getPlayerYIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()+1);
            }
            else
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex() + 1, terminalMap.getPlayerYIndex()-1);
            }
            terminalMap.setEnemyXY(terminalMap.getEnemyXIndex(),terminalMap.getEnemyYIndex());
            }
        if(player.getDodge())
        {
            cout << "You dodge the attack!" << endl; 
            return false;
        }
        else
        {
        cout << "The " << enemy.getEnemyName() << " swings with its "<< enemy.getWeapon().getWeaponName()<< 
        "! Doing " <<enemy.getWeapon().getWeaponDamage() <<" damage!" << endl;
        player.setHealth(player.getHealth()-enemy.getWeapon().getWeaponDamage());
        if(player.getHealth() <= 0)
        {
            terminalMap.outputMap();
            return true;
        }
        else
        {
            terminalMap.outputMap();
            return false;
        }
        }
    }
    
    if(disTot == enemy.getMovementSquares()+1 || disTot == enemy.getMovementSquares())
    {
        if(disX == 0)
        {
            if(disY < 0)
            {
                disY-=1;
            }
            else if(disY > 0)
            {
                disY+=1;
            }
            terminalMap.moveEnemyY(disY);
        }
        else if(disY == 0)
        {
            if(disX < 0)
            {
                disX+=1;
            }
            else
            {
                disX-=1;
            }
            terminalMap.moveEnemyX(disX);
        }
        else if(disX == 1)
        {
            disX-=1;
            terminalMap.moveEnemyX(disX);
            terminalMap.moveEnemyY(disY);
        }
        else if(disY == 1)
        {
            disY-=1;
            terminalMap.moveEnemyY(disY);
            terminalMap.moveEnemyX(disX);
        }
        else
        {
            terminalMap.moveEnemyX(disX);
            terminalMap.moveEnemyY(disY);
        }
            if(terminalMap.getPlayerXIndex() == terminalMap.getEnemyXIndex() && 
            terminalMap.getPlayerYIndex() == terminalMap.getEnemyYIndex())
            {   
            cout << "the enemy lands on you and pushes you!" << endl;
            cout << "you take 1 damage from the push." << endl;
            player.setHealth(player.getHealth()-1);
            if(terminalMap.getPlayerXIndex() == 21)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()-1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerXIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()+1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerYIndex() == 9)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()-1);
            }
            else if(terminalMap.getPlayerYIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()+1);
            }
            else
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex() + 1, terminalMap.getPlayerYIndex()-1);
            }
            terminalMap.setEnemyXY(terminalMap.getEnemyXIndex(),terminalMap.getEnemyYIndex());
            }
        if(player.getDodge())
        {
            cout << "You dodge the attack!" << endl; 
            return false;
        }
        else
        {
        cout << "The " << enemy.getEnemyName() << " swings with its "<< enemy.getWeapon().getWeaponName()<< 
        "! Doing " <<enemy.getWeapon().getWeaponDamage() <<" damage!" << endl;
        player.setHealth(player.getHealth()-enemy.getWeapon().getWeaponDamage());
        if(player.getHealth() <= 0)
        {
            terminalMap.outputMap();
            return true;
        }
        else
        {
            if(terminalMap.getPlayerXIndex() == terminalMap.getEnemyXIndex() && 
            terminalMap.getPlayerYIndex() == terminalMap.getEnemyYIndex())
            {   
            cout << "the enemy lands on you and pushes you!" << endl;
            cout << "you take 1 damage from the push." << endl;
            player.setHealth(player.getHealth()-1);
            if(terminalMap.getPlayerXIndex() == 21)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()-1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerXIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()+1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerYIndex() == 9)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()-1);
            }
            else if(terminalMap.getPlayerYIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()+1);
            }
            else
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex() + 1, terminalMap.getPlayerYIndex()-1);
            }
            terminalMap.setEnemyXY(terminalMap.getEnemyXIndex(),terminalMap.getEnemyYIndex());
            }
            terminalMap.outputMap();
            return false;
        }
        }
    }
    else if(abs(disX) > enemy.getMovementSquares())
    {
        if(disX < 0)
        {
            terminalMap.moveEnemyX(-enemy.getMovementSquares());
        }
        else
        {
            terminalMap.moveEnemyX(enemy.getMovementSquares());
        }
        
        if(terminalMap.getPlayerXIndex() == terminalMap.getEnemyXIndex() && 
        terminalMap.getPlayerYIndex() == terminalMap.getEnemyYIndex())
        {
            cout << "the enemy lands on you and pushes you!" << endl;
            cout << "you take 1 damage from the push." << endl;
            player.setHealth(player.getHealth()-1);
            if(terminalMap.getPlayerXIndex() == 21)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()-1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerXIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()+1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerYIndex() == 9)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()-1);
            }
            else if(terminalMap.getPlayerYIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()+1);
            }
            else
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex() + 1, terminalMap.getPlayerYIndex()-1);
            }
            terminalMap.setEnemyXY(terminalMap.getEnemyXIndex(),terminalMap.getEnemyYIndex());
        }
        terminalMap.outputMap();
        return false;
    }
    else
    {

        terminalMap.moveEnemyX(disX);
        if(remainingMovement > 0)
        {
            remainingMovement -= abs(disX)-1;
        }
        else
        {
            remainingMovement += abs(disX)-1;
        }

        if(disY > 0)
        {
        terminalMap.moveEnemyY(remainingMovement);
        }
        else
        {
        terminalMap.moveEnemyY(-remainingMovement);
        }

        if(terminalMap.getPlayerXIndex() == terminalMap.getEnemyXIndex() && 
        terminalMap.getPlayerYIndex() == terminalMap.getEnemyYIndex())
        {
            cout << "the enemy lands on you and pushes you!" << endl;
            cout << "you take 1 damage from the push." << endl;
            player.setHealth(player.getHealth()-1);
            if(terminalMap.getPlayerXIndex() == 21)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()-1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerXIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex()+1, terminalMap.getPlayerYIndex());
            }
            else if(terminalMap.getPlayerYIndex() == 9)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()-1);
            }
            else if(terminalMap.getPlayerYIndex() == 0)
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex(), terminalMap.getPlayerYIndex()+1);
            }
            else
            {
                terminalMap.setPlayerXY(terminalMap.getPlayerXIndex() + 1, terminalMap.getPlayerYIndex()-1);
            }
            terminalMap.setEnemyXY(terminalMap.getEnemyXIndex(),terminalMap.getEnemyYIndex());
        }
        terminalMap.outputMap();

        return false;
    }
    
}


int main()
{
    bool action =false;
    Player x;

    int enemiesAlive = 1;
    Map terminalMap;
    Enemy aa;
    terminalMap.setPlayerXY(11,9);
    terminalMap.setEnemyCharacter(aa.getEnemyCharacter());
    terminalMap.setEnemyXY(15,7);
    enemyTurn(x, aa,  terminalMap);
    return 0;
    
    cout << enemyTurn(x, aa,  terminalMap) << endl;

    return 0;
}