#include "game.hpp"
#include "player.hpp"

#include "chrono"
#include "random"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
namespace ariel{
Game::Game(Player &p1, Player &p2): player1(&p1),player2(&p2)
{
    this->player1->clearlastgame();
    this->player2->clearlastgame();
    this->lastturn=0;


    vector<int> deck;
    for (int i = 0; i < 52; i++)
    {
        deck.push_back(i);
    }
     // get a time-based seed
     //learned and followed by example of https://www.techiedelight.com/shuffle-vector-cpp/
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle (deck.begin(), deck.end(), default_random_engine(seed));
    for (int i = 0; i < 26; i++)
    {
        player1->addtostack(Card(deck.back()));
        deck.pop_back();
        player2->addtostack(Card(deck.back()));
        deck.pop_back();
    }

}
void Game::playTurn(){
    if (this->player1->stacksize()!=player2->stacksize())
    {
         throw logic_error("players should have the same size deck");
    }
    if (this->player1->stacksize()==0)
    {
        throw out_of_range("no cards left to play");
    }
    if (this->player1->stacksize()>26)
    {
        throw logic_error("players shouldnt get more than 26 cards,check you didnt sign up the same player");
    }
    
    
    this->lastturn=P1turns.size();
    Card P1draw = this->player1->drawCard(); 
    Card P2draw = this->player2->drawCard(); 
    //compare cards
    int cmp =P1draw.cmp(P2draw);
    int Numdraws=0;
    P1turns.push_back(P1draw);
    P2turns.push_back(P2draw);
    while (cmp==0)
    {
        
        //handle distirbuting the remaining cards evenly if theres not enough cards
        if (this->player1->stacksize()==0)
        {
            this->player2->takecards(Numdraws*2+1);
            this->player1->takecards(Numdraws*2+1);
            return;
        }
         if (this->player1->stacksize()==1)
        {
            this->player1->drawCard();
            this->player2->drawCard();
            this->player2->takecards(Numdraws*2+2);
            this->player1->takecards(Numdraws*2+2);
            return;
        }
        Numdraws++;
        //draw a hidden card from each player then play again
        this->player1->drawCard(); 
        this->player2->drawCard(); 
        //play again
        P1draw = this->player1->drawCard(); 
        P2draw = this->player2->drawCard(); 
        int cmp =P1draw.cmp(P2draw);
        P1turns.push_back(P1draw);
        P2turns.push_back(P2draw);
    }
    //give the cards to whoever won
    if (cmp==1)
    {
       
        this->player1->takecards(2*(Numdraws*2+1));
    }
    if (cmp==-1)
    {
        this->player1->takecards(2*(Numdraws*2+1));
    }
}
void Game::printplay(size_t drawnum){
    Card P1draw = this->P1turns[drawnum]; 
    Card P2draw = this->P2turns[drawnum];
    string toprint = "";
    //print what each player played
    toprint+= this->player1->getname()+" played "+P1draw.str()+" ";
    toprint+= this->player2->getname()+" played "+P2draw.str()+". ";
    int cmp =P1draw.cmp(P2draw);
    if (cmp==1)
    {
        toprint+= this->player1->getname() +" won. ";
    }
    if (cmp==-1)
    {
        toprint+= this->player2->getname() +" won. ";
    }
    if (cmp==0)
    {
        toprint+= "Draw. ";
    }
    cout<< toprint<<endl;

}
void Game::printLastTurn(){
    for (size_t i = this->lastturn; i < this->P1turns.size(); i++)
    {
        this->printplay(i);
    }
    
}
void Game::playAll(){
    while (this->player1->stacksize()!=0)
    {
        this->playTurn();
    }
}

void Game::printWiner(){
    if (this->player1->stacksize()==0)
    {
        if (this->player1->cardesTaken()>this->player2->cardesTaken())
        {
            cout<<player1->getname() +" won!"<<endl;
            return;
        }
         if (this->player1->cardesTaken()<this->player2->cardesTaken())
        {
            cout<<player2->getname() +" won!"<<endl;
            return;
        }
        cout<< "Draw"<<endl;
        return;
    }
    cout<< "no winner yet"<<endl;
    
}
void Game::printLog(){
    for (size_t i = 0; i < this->P1turns.size(); i++)
    {
        this->printplay(i);
    }
    
}
void Game::printStats(){
    int P1wins=0,P2wins=0;
    //count how many wins each player got(all the other stats can be deduced by this)
    for (size_t i = 0; i < P1turns.size(); i++)
    {
        //compare cards
        int cmp = P1turns[i].cmp(P2turns[i]);
        if (cmp==1)
        {
            P1wins++;
        }
         if (cmp==-1)
        {
            P2wins++;
        }
    }
    
    //calculate winrate
    double P1winrate= P1wins/(double)(P2wins+P1wins);
    double P2winrate= P2wins/(double)(P2wins+P1wins);
    //calculate drawrate
     double drawrate = ((int)this->P1turns.size()-P2wins-P1wins)/(double)(this->P1turns.size());
     cout<< player1->getname()<<": Winrate: "<<P1winrate<<" cards won: "<<player1->cardesTaken()<<endl
     <<player2->getname()<<": Winrate: "<<P2winrate<<" cards won: "<<player2->cardesTaken()<<endl
     <<" overall drawrate:"<<drawrate<< "amount of draws:"<<(int)this->P1turns.size()-P2wins-P1wins<<endl;
}
}
 // namespace ariel
