/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

int main() {

   Player p1("Alice");
    Player p2("Bob");
    Game game1(p1, p2);
    game1.playAll();
    cout<< p1.stacksize()<<" "<< p1.cardesTaken()<<" " << p2.stacksize()<<" " << p2.cardesTaken()<<endl;

   //Create two players with their names 

   Game game2(p1,p2); 
   cout << p1.stacksize() << endl; 
   cout << p2.cardesTaken() << endl;  
   game2.playAll(); 
   game2.printWiner(); 
   game2.printLog(); 
   game2.printStats();
}