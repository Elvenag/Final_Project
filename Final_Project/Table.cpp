/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
Table CLASS CPP FILE
*/
#include "Table.h"
#include <iostream>
#include <string>
using namespace std;

bool Table::win(std::string& s){
	if(Library.empty()){
		if(Players[0].getNumCoins() > Players[1].getNumCoins()){
			s = Players[0].getName();
			cout << "The winner is : " << s << endl;
			return true;
		}else if(Players[0].getNumCoins() < Players[1].getNumCoins()){
			s = Players[1].getName();
			cout << "The winner is : " << s << endl;
			return true;
		}else{
			s = Players[0].getName() +" and "+ Players[1].getName();
			cout << "The winner is : " << s << endl;
			return false;
		}
	}
	exit(0);
}


void Table::print(ostream& os){
	for(int i = 0; i < 2; i++){
		os << Players[i] << endl;
	}
	os << Library << endl;
	os << Grave << endl;
	os << GTS << endl;
}



ostream& operator<<(ostream &os,const Table& t){
	for(auto i : t.Players){
		os << i << endl;
	}
	os << t.Grave << endl;
	os << t.GTS << endl;
	return os;
}

Table::Table(istream& is, CardFactory* cf){
	this->Players[0] = Player(is, cf);
	this->Players[1] = Player(is, cf);
	this->Library = Deck(is,cf);
	this->Grave = DiscardPile(is,cf);
	this->GTS = TradeArea(is,cf);
}

