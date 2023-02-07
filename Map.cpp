#include <iostream>
#include <string.h>
#include "Map.h"

using namespace std;

//private:
// static const int x = 22;
// static const int y = 10;
// char terminalMap[y][x];
// char storedObjectsInMap[6];
// //Index of player ([0][])
// //Index of enemies ([1-5][])
// //takes an object on map and stores it's x,y coordinate.
// int coordinatesOfObjects[6][2];
// int enemies;

Map::Map()
{
    for(int i = 0; i < y; i++)
    {
        for(int k = 0; k < x; k++)
        {
            terminalMap[i][k] = '-';
        }
    }
    enemyChar = ' ';
    enemies = 0;
}

Map::Map(char player, char enemy,int objectCoordinates[][2], int enemyNumber)
{
    for(int i = 0; i < y; i++)
    {
        for(int k = 0; k < x; k++)
        {
            terminalMap[i][k] = '-';
        }
    }
    playerChar = player;
    enemyChar = enemy;
    for(int i = 0; i < 2; i++)
    {
        coordinatesOfObjects[i][0] = objectCoordinates[i][0];
        coordinatesOfObjects[i][1] = objectCoordinates[i][1];
    }

    enemies = enemyNumber;
}

void Map::setPlayerCharacter(char newC)
{
    playerChar = newC;
}

void Map::setEnemyCharacter(char newC)
{
    enemyChar = newC;
}

void Map::setPlayerXY(int inX, int inY)
{
    if((inX >= x || inX < 0) && (inY >= y || inY < 0))
    {
        cout << " Error: out of bounds" << endl;
    }
    else
    {
    coordinatesOfObjects[0][0] = inX;
    coordinatesOfObjects[0][1] = inY;
    terminalMap[inY][inX] = playerChar;
    }
}

void Map::setEnemyXY(int inX, int inY)
{
    if((inX >= x || inX < 0) && (inY >= y || inY < 0))
    {
        cout << " Error: out of bounds" << endl;
    }
    else
    {
    coordinatesOfObjects[1][0] = inX;
    coordinatesOfObjects[1][1] = inY;
    terminalMap[inY][inX] = enemyChar;
    }
}
//returns number of enemies
//adds an enemy.
void Map::setNumberOfEnemies()
{
    enemies = 1;
}
//returns enemy index at x and y position
int Map::getEnemyXIndex()
{
    return coordinatesOfObjects[1][0];
}

int Map::getEnemyYIndex()
{
    return coordinatesOfObjects[1][1];
}

void Map::movePlayerTo(int x_pos, int y_pos)
{
    int xCoordinate =coordinatesOfObjects[0][0];
    int yCoordinate =coordinatesOfObjects[0][1];
    terminalMap[yCoordinate][xCoordinate] = '-';
    //Y coordinate editing if branches
    if(yCoordinate + y_pos < y && yCoordinate + y_pos > 0)
    {
    yCoordinate += y_pos;
    }
    else if(yCoordinate + y_pos >= y)
    {
    yCoordinate = y-1;
    }
    else
    {
    yCoordinate = 0;
    }
    //X coordinate editing if branches
    if(xCoordinate + x_pos < x && xCoordinate + x_pos > 0)
    {
    xCoordinate += x_pos;
    }
    else if(xCoordinate+ x_pos >= x)
    {
        xCoordinate = x-1;
    }
    else
    {
        xCoordinate = 0;
    }
    coordinatesOfObjects[0][0] = xCoordinate;
    coordinatesOfObjects[0][1] = yCoordinate;
    terminalMap[yCoordinate][xCoordinate] = 'X';
}

int Map::getPlayerXIndex()
{   
    //returns the players x index on the map
    return coordinatesOfObjects[0][0];
}

int Map::getPlayerYIndex()
{   
    //returns the players x index on the map
    return coordinatesOfObjects[0][1];
}

void Map::outputMap()
{
    for(int i = 0; i < y; i++)
    {
        for(int k = 0; k < x; k++)
        {
           cout<< terminalMap[i][k];
        }
        cout << endl;
    }
    cout << endl;
}

bool Map::emptyRoom()
{
    bool empty = false;
    if(enemies == 0)
    {
        empty = true;
    }
    return empty;
}

//for enemies use to see if theyre next to eachother
bool Map::nextToPlayer()
{
    //above player
    if(coordinatesOfObjects[0][0] == coordinatesOfObjects[1][0] &&
       coordinatesOfObjects[0][1] == coordinatesOfObjects[1][1]-1)
    {
        return true;
    }
    //below player
    else if(coordinatesOfObjects[0][0] == coordinatesOfObjects[1][0] &&
       coordinatesOfObjects[0][1] == coordinatesOfObjects[1][1]+1)
    {
        return true;
    }
    //to the right of player
    else if(coordinatesOfObjects[0][0] == coordinatesOfObjects[1][0]+1 &&
       coordinatesOfObjects[0][1] == coordinatesOfObjects[1][1])
    {
        return true;
    }
    //to the left of player
    else if(coordinatesOfObjects[0][0] == coordinatesOfObjects[1][0]-1 &&
       coordinatesOfObjects[0][1] == coordinatesOfObjects[1][1])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Map::moveEnemyX(int xPos)
{
    int xCoordinate =coordinatesOfObjects[1][0];
    int yCoordinate =coordinatesOfObjects[1][1];
    terminalMap[yCoordinate][xCoordinate] = '-';
    if(xCoordinate + xPos < x && xCoordinate + xPos > 0)
    {
    xCoordinate += xPos;
    }
    else if(xCoordinate+ xPos >= x)
    {
        xCoordinate = x-1;
    }
    else
    {
        xCoordinate = 0;
    }
    coordinatesOfObjects[1][0] = xCoordinate;
    terminalMap[yCoordinate][xCoordinate] = enemyChar;

}

void Map::moveEnemyY(int yPos)
{
    int xCoordinate =coordinatesOfObjects[1][0];
    int yCoordinate =coordinatesOfObjects[1][1];
    terminalMap[yCoordinate][xCoordinate] = '-';
    if(yCoordinate + yPos < y && yCoordinate + yPos > 0)
    {
    yCoordinate += yPos;
    }
    else if(yCoordinate + yPos >= y)
    {
    yCoordinate = y-1;
    }
    else
    {
    yCoordinate = 0;
    }
    coordinatesOfObjects[1][1] = yCoordinate;
    terminalMap[yCoordinate][xCoordinate] = enemyChar;
}