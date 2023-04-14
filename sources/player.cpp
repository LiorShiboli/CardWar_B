#include "player.hpp"
#include <string>


   
 namespace ariel
 {
    Player::Player(std::string name):name(name){
      this->cardstaken=0;
      this->stack= vector<Card>{};
    }
   int Player::cardesTaken(){
      return cardstaken;
   }
   int Player::stacksize(){
      return (int)this->stack.size();
   }
   //reset the stack and the counter for howmany cards are taken
   void Player::clearlastgame()
   {
      this->stack.resize(0);
      this->cardstaken=0;
   }
   //add a card to the top of the stack
   void Player::addtostack(Card card){
      this->stack.push_back(card);
   }

   // remove and return the top card from the stack
   Card Player::drawCard(){
      Card drawn = this->stack.back();
      this->stack.pop_back();
      return drawn;
   }
   void Player::takecards(int cardamount){
      
      this->cardstaken+=cardamount;
   }
   string Player::getname(){
      return this->name;
   }

 }// namespace ariel
 