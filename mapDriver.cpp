#include <iostream>
#include <string>
#include "Map.h"
#include "Item.h"
#include "Weapon.h"
#include "Enemy.h"
#include "Player.h"

//g++ -std=c++11 mapDriver.cpp Map.cpp Item.cpp Weapon.cpp Enemy.cpp Player.cpp -o mapD

using namespace std;

int main()
{
    Player player;
    Map map;
    map.setCharacterXY(13,6,0);
    cout << "x: "<<map.getPlayerXIndex() << endl;
    cout << "y: " << map.getPlayerYIndex() << endl;
    //sets characterCoordinates[0][13(x),6(y)]
    map.outputMap();
    map.movePlayerTo(-4,2);
    cout << "x: "<<map.getPlayerXIndex() << endl;
    cout << "y: " << map.getPlayerYIndex() << endl;
    map.outputMap();
    map.movePlayerTo(8,4);
    cout << "x: "<<map.getPlayerXIndex() << endl;
    cout << "y: " << map.getPlayerYIndex() << endl;
    //for y, + is down - is up. moving player arround.
    map.outputMap();
}