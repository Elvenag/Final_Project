#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include "Gemstones.h"
#include "CardFactory.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Hand.h"
#include "Player.h"
#include "Chain.h"
#include "Table.h"
#include "TradeArea.h"

int main(){
	string answer;
	while (true) {
		cout << "Load game or new? (load or new)" << endl;
		cin >> answer;
		if (answer == "load") {
			//load game
			break;
		}
		else if (answer == "new") {
			cout << "Player 1's name: " << endl;
			cin >> answer;
			Player P1(answer);
			cout << "Player 2's name: " << endl;
			cin >> answer;
			Player P2(answer);
			CardFactory cf;
			Deck d = cf.getDeck();
			for (int i = 1; i <= 5; i++) {
				P1.
			}
			break;
		}
	}


}