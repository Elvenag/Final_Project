/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 
TradeArea CLASS HEADER FILE
*/

#ifndef TradeArea_H
#define TradeArea_H
#include <string>
#include <iostream>
#include "Gemstones.h"
#include <list>
#include "CardFactory.h"

using namespace std;

class TradeArea{
	
	public:
		TradeArea() = default;
		list<Card*> area;
		TradeArea(istream& is, CardFactory* cf);
		TradeArea& operator+=(Card* c);
		bool legal(Card* c);
		Card* trade(string s);
		int numCards();
		~TradeArea();
		ostream& printTrade(ostream &os);
		friend ostream& operator<<(ostream& os, const TradeArea& ta);
};

#endif
