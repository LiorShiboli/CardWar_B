#include <string>
#include <vector>
#include "card.hpp"

using namespace std;
namespace ariel
{
    #ifndef PLAYER_
    #define PLAYER_
    class Player
    {
    private:
    string name;
    vector<Card> stack;
    int cardstaken;
    public:
        Player(std::string name);
        int stacksize();
        int cardesTaken();
        void addtostack(Card card);
        Card drawCard();
        void clearlastgame();
        void takecards(int cardamount);
        string getname();
    };
    #endif
    
} // namespace ariel
