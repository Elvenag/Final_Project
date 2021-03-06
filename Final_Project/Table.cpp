/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
Table CLASS CPP FILE
*/
#include "Table.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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
		os << Players[i].getMaxNumChains() << " " << Players[i].getNumChains() << " " << Players[i] << Players[i].PlayerHand.printHand() << endl;
		os << "^^^^^^^^" << endl;
	}
	os << Library << endl;
	os << "^^^^^^^^" << endl;
	Grave.print(os);
	os<< endl;
	os << "^^^^^^^^" << endl;
	GTS.printTrade(os) ;
	os << endl;
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
	//Player1 load
	string loading;
	string lcontent;
	while(getline(is,loading)){
		if(loading == "^^^^^^^^"){
			break;
		}
		lcontent+=loading;
		lcontent.push_back('\n');
	}
	istringstream player1(lcontent);
	this->Players[0] = Player(player1, cf);
	loading.clear();
	lcontent.clear();
	
	//Player2 load
	while(getline(is,loading)){
		if(loading == "^^^^^^^^"){
			break;
		}
		lcontent+=loading;
		lcontent.push_back('\n');
	}
	istringstream player2(lcontent);
	this->Players[1] = Player(player2, cf);
	loading.clear();
	lcontent.clear();
	
	//Deck load
	while(getline(is,loading)){
		if(loading == "^^^^^^^^"){
			break;
		}
		lcontent+=loading;
		lcontent.push_back('\n');
	}
	istringstream Lib(lcontent);
	cf->gameDeck = Deck(Lib,cf);
	this->Library = cf->getDeck();
	loading.clear();
	lcontent.clear();
	
	//DiscardPile load
	while(getline(is,loading)){
		if(loading == "^^^^^^^^"){
			break;
		}
		lcontent+=loading;
		lcontent.push_back('\n');
	}
	istringstream exile(lcontent);
	this->Grave = DiscardPile(exile,cf);
	loading.clear();
	lcontent.clear();

	//TradeArea load
	while(getline(is,loading)){
		if(loading == "^^^^^^^^"){
			break;
		}
		lcontent+=loading;
		lcontent.push_back('\n');
	}
	istringstream trader(lcontent);
	this->GTS = TradeArea(trader,cf);
	loading.clear();
	lcontent.clear();
	
	while(getline(is,loading)){
		cout << "LOOP :" << loading << endl;
	}
}

