/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
Player CLASS CPP FILE
*/
#include "Player.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Player::Player(string& s):PlayerName(s),coins(0),MaxNumChains(2){
}

Player::Player(istream & is, CardFactory * cf)
{
	string s;
	is >> s;
	size_t pos = s.find(" ");
	this->PlayerName = s.substr(0, pos);
	pos = s.find(" ", pos+1);
	stringstream ss;
	size_t pos2 = s.find(" ", pos + 1);
	ss << s.substr(pos + 1, pos2);
	ss>>this->coins;
	pos = s.find(" ", pos2 + 1);
	ss << s.substr(pos2 + 1, pos);
	ss >> this->MaxNumChains;
	pos2 = s.find(" ", pos + 1);
	ss << s.substr(pos2 + 1);
	int numChains = 0;
	ss >> numChains;
	for (int i = 0; i < numChains; i++) {

	}
}

string Player::getName(){
	return PlayerName;
}

int Player::getNumCoins(){
	return coins;
}

int Player::getMaxNumChains(){
	return MaxNumChains;
}

Player& Player::operator+=(int num){
	coins += num;
	return *this;
}

int Player::getNumChains(){
	return PlayerChains.size();
}

Chain_Base<Card>& Player::operator[](int i){
	return PlayerChains[i];
}

void Player::buyThirdChain(){
	if(MaxNumChains == 2 && coins >= 2){
		MaxNumChains++;
		coins -= 2;
		PlayerChains.push_back(Chain<Card>());
	}
}

void Player::printHand(ostream& os, bool b){
	if(b){
		os << PlayerHand;
	}else{
		os << PlayerHand.top();
	}
}

ostream& operator<<(ostream& os,const Player& p){
	os << p.PlayerName << " " << p.coins << " coins" << endl;
	for(int i = 0; i < p.PlayerChains.size(); i++){
		os << p.PlayerChains.at(i) << endl;
	}
	return os;
}

void Player::addChain(Card* c) {
	Chain<class Card> newChain;
	Quartz q;
	Hematite h;
	Obsidian o;
	Malachite m;
	Turquoise t;
	Ruby r;
	Amethyst a;
	Card * cardType;
	if (c->getName() == q.getName()) {
		Chain<Quartz> newChain;
		cardType = &q;
	}
	else if (c->getName() == h.getName()) {
		Chain<Hematite> newChain;
		cardType = &h;
	}
	else if (c->getName() == o.getName()) {
		Chain<Obsidian> newChain;
		cardType = &o;
	}
	else if (c->getName() == m.getName()) {
		Chain<Malachite> newChain;
		cardType = &m;
	}
	else if (c->getName() == t.getName()) {
		Chain<Turquoise> newChain;
		cardType = &t;
	}
	else if (c->getName() == r.getName()) {
		Chain<Ruby> newChain;
		cardType = &r;
	}
	else if (c->getName() == a.getName()) {
		Chain<Amethyst> newChain;
		cardType = &a;
	}
	else {
		Chain<Emerald> newChain;
		cardType = new Emerald;
	}
	newChain.cardType = cardType->getName();
	newChain+=c;
	PlayerChains.push_back(newChain);
}

void Player::addCardAndMakeChain(Card* c) {
	if (getNumChains() < getMaxNumChains()) {
		addChain(c);
	}
	else {
		cout << "Which chain will be sold? (1-" << getNumChains() << ")" << endl;
		for (std::size_t i = 0; i < PlayerChains.size(); i++) {
			cout << ' ' << PlayerChains[i] << endl;
		}
		while (true) {
			int ianswer;
			cin >> ianswer;
			if ((ianswer <= getMaxNumChains()) && (ianswer > 0)) {
				*this += PlayerChains[ianswer-1].sell();
				PlayerChains.erase(PlayerChains.begin() + ianswer - 1);
				break;
			}
		}
		addChain(c);
	}
}
