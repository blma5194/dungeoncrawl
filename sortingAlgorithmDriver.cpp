#include <iostream>
#include <string>
#include "Item.h"
#include "Player.h"
#include "Weapon.h"

using namespace std;

void fillAllItems(Item allItems[])
{
    allItems[0] = Item("Small Health Potion", 2, 0);
    allItems[1] = Item("Medium Health Potion", 4, 0);
    allItems[2] = Item("Big HealthPotion", 6, 0);
    allItems[3] = Item("Splashing Acid", 0, 3);
    allItems[4] = Item("Boiling Tar", 0, 5);
    allItems[5] = Item("Minitour Blood", 0, 7);
}


int main()
{
    Item all[6];

    Player me;

    fillAllItems(all);

    me.addItemAtIndex(0, all[0]);
    me.addItemAtIndex(1, all[0]);
    me.addItemAtIndex(2, all[5]);
    me.addItemAtIndex(3, all[2]);
    me.addItemAtIndex(4, all[0]);
    me.addItemAtIndex(5, all[3]);
    me.addItemAtIndex(6, all[5]);
    me.addItemAtIndex(7, all[2]);

    // for(int i = 0 ; i < 8; i++)
    // {
    //     cout << me.getItemAtIndex(i).getItemName() << endl;
    // }
    for(int i = 0 ; i < 8; i++)
    {
        cout << me.getItemAtIndex(i).getItemName() << endl;
    }
    me.itemSort();
    // cout << endl;
    cout << endl;
    for(int i = 0 ; i < 8; i++)
    {
        cout << me.getItemAtIndex(i).getItemName() << endl;
    }
    return 0;
}