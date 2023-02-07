//Libby Bianchi & Blake Martinez
//CSCI 1300
//Project 3

#include <string>
#include "Item.h"

using namespace std;

Item::Item()
{
    itemName = "<None>";
    healing = 0;
    damage = 0;
}
Item::Item(string iName, int healingVal, int damg)
{
    itemName = iName;
    healing = healingVal;
    damage = damg;

}
string Item::getItemName()
{
    return itemName;
}
int Item::getHealingValue()
{
    return healing;
}
void Item::setItemName(string itemsName)
{
    itemName = itemsName;
}
void Item::setHealingValue(int newHealing)
{
    healing = newHealing;
}
int Item::getDamage()
{
    return damage;
}
void Item::setDamage(int itemDamage)
{
    damage = itemDamage;
}
bool Item::isHealingItem()
{
    bool isHeal = false;
    if(healing > 0 && damage == 0)
    {
        isHeal = true;
    }
    return isHeal;
}