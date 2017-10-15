#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main() {
	int bet;
	char keep_playing = 'y';
	Player person = Player(100);

	cout << "You have $" << person.get_money() << ". Enter bet: ";
	cin >> bet;
	Hand p = person.get_hand();
	
	while (keep_playing == 'y') {
		Card player_card = Card();
		p.draw(player_card);

		cout << "New card:" << endl << '\t';
		cout << player_card.get_spanish_rank() << " de " << player_card.get_spanish_suit();
		cout << " (" << player_card.get_english_rank() << " of " << player_card.get_english_suit() << ")." << endl << endl;

		cout << "Your cards:";
		p.display();

	
		cout << "Your total is " << p.get_sum() << ". Do you want another card (y/n)? ";
		cin >> keep_playing;
	}

	Hand d = Hand();
	cout << "Dealer's cards: " << endl;
	double dealer_total = d.get_sum();

	while (dealer_total < 7.5) {
		Card dealer_card = Card();
		d.draw(dealer_card);

		cout << "New card:" << endl << '\t';
		cout << dealer_card.get_spanish_rank() << " de " << dealer_card.get_spanish_suit();
		cout << " (" << dealer_card.get_english_rank() << " of " << dealer_card.get_english_suit() << ")." << endl << endl;

		cout << "Dealer's cards:" << endl;
		d.display();
		cout << "The dealer's total is " << d.get_sum() << "." << endl << endl;
		dealer_total = d.get_sum();
	}


	string s;
	cin >> s;

	return 0;
}