#include <iostream>
#include <string.h>

class Player{

private:
    char name[100];
    vector<Card> hand;
    int sum, cash, bet;
    int wins, loses;

public:
    Player(){
        strcpy(name, "Unknown");
        sum = 0;
        bet = 0;
        cash = 1000;
        wins = 0;
        loses = 0;
    }

    Player(char pname[100]){
        strcpy(name, pname);
        sum = 0;
        bet = 0;
        cash = 1000;
        wins = 0;
        loses = 0;
    }
    
    char *getName(){
        return name;
    }

    int getBet(){
        return bet;
    }

    int getCash(){
        return cash;
    }

    int getSum(){
        switchAce();
        return sum;
    }
    int getWins(){
        return wins;
    }
    int getLoses(){
        return loses;
    }
    void incrementWins(){
        wins+=1;
    }
    void incrementLoses(){
        loses+=1;
    }

    bool setBet(int b){
        if(b<=cash){
            cash-=b;
            bet=b;
            return true;
        }
        else{
            return false;
        }
    }
    void addCash(int c){
        cash+=c;
    }
    void addCard(Card C);
    void clearCards(){
        hand.clear();
        sum=0;
    }
    void printCards();
    void switchAce();
};

void Player::addCard(Card c){
    hand.push_back(c);
    if(c.getNumber()>10){
        c.setNumber(10);
    }
    else if (c.getNumber()==1){
        c.setNumber(11);
    }
    sum+= c.getNumber();
}

void Player::printCards(){
    cout<<endl;
    // │ ─ └ ┐ ┘ ┌
    for(int i=0;i<hand.size();i++){
        //cout<<" ┌───────┐ ";
        cout<<" +-------+ ";
    }
    cout<<endl;
    for(int i=0;i<hand.size();i++){
        cout<<" |       | ";
    }
    cout<<endl;
    for(int i=0;i<hand.size();i++){
        cout<<" |       | ";
    }
    cout<<endl;
    for(int i=0;i<hand.size();i++){
        hand[i].printCard();
    }
    cout<<endl;
    for(int i=0;i<hand.size();i++){
        cout<<" |       | ";
    }
    cout<<endl;
    for(int i=0;i<hand.size();i++){
        cout<<" |       | ";
    }
    cout<<endl;
    for(int i=0;i<hand.size();i++){
        //cout<<" └───────┘ ";
        cout<<" +-------+ ";
    }
    cout<<endl;
}

void Player::switchAce(){
    if(sum>21){
        for(int i=0;i<hand.size();i++){
                if(hand[i].getNumber()==1 && !(hand[i].getBlock())){
                    hand[i].setBlock(true);
                    sum-=10;
                    return;
                }
        }
    }
}