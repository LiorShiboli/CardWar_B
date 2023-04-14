#include "card.hpp"
//define special cards and the offset in which we store regular cards(since we want to store them from 0 to 12 based on general order)
#define ACE 12
#define KING 11
#define QUEEN 10
#define JACK 9
#define OFFSET 2
namespace ariel
{
    Card::Card(){
        this->card=0;
    }
    //store the card as a number between 0 and 51
    Card::Card(int cardNum)
    {
        card = cardNum;
        
    }
    string Card::str()
    {
        string card="";
        int cardtype = this->card%4;
        int cardvalue = this->card/4;
        
        switch (cardvalue)
        {
            case ACE:
                card = card+ "Ace";
                break;
            case JACK:
                card = card+ "Jack";
                break;
            case QUEEN:
                card = card+ "Queen";
                break;
            case KING:
                card = card+ "King";
                break;
            
            default:
                card = card +to_string(cardvalue+OFFSET);
                break;
        }
        card= card+"of";
            //concat the type
        switch (cardtype)
        {
            case 0:
                card= card+ "Hearts";
                break;
            case 1:
                card= card+ "Diamonds";
                break;
            case 2:
                card= card+ "Clubs";
                break;
            case 3:
                card= card+ "Spades";
                break;
        
            default:
                break;
        }
        
        
    return card;    
    }
int Card::cmp(Card card2){
    int cardValue1=this->card/4;
    int cardValue2=card2.card/4;
    int result=0;
    if (cardValue1<cardValue2)
    {
        result = -1;
    }
    if (cardValue1>cardValue2)
    {
        result = 1;
    }
    if (cardValue1==0&&cardValue2==12||cardValue2==0&&cardValue1==12)
    {
        result*=-1;
    }
    return result;
    
    
}
} // namespace ariel
