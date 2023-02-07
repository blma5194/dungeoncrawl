#include <iostream>
#include "Player.h"
#include "Map.h"
#include "Item.h"
#include "Weapon.h"
#include <string>

//g++ -std=c++11 movement.cpp Player.cpp Map.cpp Item.cpp Weapon.cpp -o julien

using namespace std;

int wasdMovement(Player object, string input, int x_pos, int y_pos, int reamainingMovement)
{
    int movedSquares = 0;
    int newRemainingMovement = reamainingMovement;

    if(input.length() > reamainingMovement)
    {
    cout << "Invalid Input or no movement left." << endl;
    return newRemainingMovement;
    }
    else
    {
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == 'w' || input[i] == 'W')
        {
            y_pos--;
            movedSquares += 1;
        }
        else if(input[i] == 'a' || input[i] == 'A')
        {
            x_pos--;
            movedSquares += 1;
        }
        else if(input[i] == 's' || input[i] == 'S')
        {
            y_pos++;
            movedSquares += 1;
        }
        else if(input[i] == 'd' || input[i] == 'D')
        {
            x_pos++;
            movedSquares += 1;
        }
        else
        {
            continue;
        }
    }
    newRemainingMovement = newRemainingMovement-movedSquares;
    return newRemainingMovement;
    }
}

int main()
 {
     
    Player swagatron;
    int x_pos = 0;
    int y_pos = 0;
    string input;
    cout << "enter thing: ";
    cin>> input;
    int remainingMovement = swagatron.getMovementSquares();
    int movedSquares = 0;
    int newRemainingMovement = remainingMovement;
    
    if(input.length() > remainingMovement)
    {
    cout << "Invalid Input or no movement left." << endl;
    }
    else
    {
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == 'w' || input[i] == 'W')
        {
            y_pos--;
            movedSquares += 1;
        }
        else if(input[i] == 'a' || input[i] == 'A')
        {
            x_pos--;
            movedSquares += 1;
        }
        else if(input[i] == 's' || input[i] == 'S')
        {
            y_pos++;
            movedSquares += 1;
        }
        else if(input[i] == 'd' || input[i] == 'D')
        {
            x_pos++;
            movedSquares += 1;
        }
        else
        {
            continue;
        }
    }
    newRemainingMovement = newRemainingMovement-movedSquares;
    }

    cout << remainingMovement << endl;
    cout << "x edit: " << x_pos << endl;
    cout << "y edit: " << y_pos << endl; 
    return 0;
 }