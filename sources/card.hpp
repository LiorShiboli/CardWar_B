#include "string"
using namespace std;

namespace ariel
{
    #ifndef CARD_
    #define CARD_
    class Card
    {
    private:
        int card;
    public:
        Card();
        Card(int cardNum);
        int cmp(Card card);
        string str();

    };
    
    #endif
    
} // namespace ariel
