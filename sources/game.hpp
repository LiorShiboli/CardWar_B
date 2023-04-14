#include "player.hpp"
namespace ariel
{
    #ifndef GAME_
    #define GAME_
    class Game
    {
    private:
        Player *player1;
        Player *player2;
        vector<Card> P1turns;
        vector<Card> P2turns;
        size_t lastturn;

    public:
        Game(Player &player1, Player &player2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        void printplay(size_t drawnum);
    };
    
    #endif
    
} // namespace ariel
