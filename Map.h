#ifndef MAP_H
#define MAP_H

using namespace std;

class Map
{
    private:
    static const int x = 22;
    static const int y = 10;
    char terminalMap[y][x];
    char playerChar = 'X';
    char enemyChar = '-';
    //Index of player ([0][])
    //Index of enemy ([1][])
    //takes an object on map and stores it's x,y coordinate.
    int coordinatesOfObjects[2][2];
    //coordinatesOfObjects[player or enemy][x,y]
    int enemies;

    public:
    Map();
    Map(char player, char enemy,int objectCoordinates[][2], int enemies);
    
    //sets player character and enemy character.
    void setPlayerCharacter(char newC);
    void setEnemyCharacter(char newC);
    //sets player and enemy cooridnates
    void setPlayerXY(int x, int y);
    void setEnemyXY(int x, int y);
    void setNumberOfEnemies();
    //returns enemy index at x and y position
    int getEnemyXIndex();
    int getEnemyYIndex();
    
    //edits coordinates of player
    void movePlayerTo(int x_pos, int y_pos);
   
    //edits enemy x y coordinates.
    void moveEnemyX(int xPos);
    void moveEnemyY(int yPos);
    //returns player x y coordinates
    int getPlayerXIndex();
    int getPlayerYIndex();
    
    //checks next to player
    bool nextToPlayer();
    //outputs the whole map
    void outputMap();
    //checks for an empty room.
    bool emptyRoom();
};
#endif