#include <string>
#include "Item.h"
#include <iostream>

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
    Item allItems[6];
    fillAllItems(allItems);

    for(int i = 0; i < 6; i++)
    {
        cout << allItems[i].getItemName() << ", Healing value: " << allItems[i].getHealingValue()<< ", Damage Value: " << allItems[i].getDamage()<< endl; 
    }
return 0;
}