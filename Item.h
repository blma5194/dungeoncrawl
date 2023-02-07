//Libby Bianchi & Blake Martinez
//CSCI 1300
//Project 3

#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class Item
{
    public:
    Item();
    Item(string itemName, int healing, int damage);
    
    string getItemName();
    int getHealingValue();
    int getDamage();

    void setItemName(string itemsName);
    void setHealingValue(int healingValue);
    void setDamage(int itemDamage);

    bool isHealingItem();
    private:
    string itemName;
    int healing;
    int damage;
};
#endif