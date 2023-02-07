HOW TO COMPILE AND RUN
------------------------
Compile: g++ -std=c++11 finalDungeonCrawlDriver.cpp Player.cpp Enemy.cpp Weapon.cpp Item.cpp Map.cpp -o dungeonCrawl
Run: ./dungeonCrawl
(it is already compiled within the directory.)
------------------------
DEPENDENCIES
------------------------
Map.h, Item.h, Player.h, Weapon.h, Enemy.h and their corresponding .cpp files
must be in the same directory.
------------------------
SUBMISSION INFORMATION
------------------------
CSCI1300 Fall 2021 Project 2
Authors: Blake Martinez & Libby Bianchi
Recitation: 210 - Praganda Mandadi
Date: Demcember 2, 2021
------------------------
ABOUT THIS PROJECT
------------------------
This is a turn based game that a player can play for 6 turns + a boss fight (this is constant). It impliments
map , enemy, player, item, and weapon classes to make a cool little terminal game.