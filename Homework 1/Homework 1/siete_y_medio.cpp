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
	Hand h = person.get_hand();
	
	while (keep_playing == 'y') {
		Card c = Card();
		h.draw(c);

		cout << "New card:" << endl << '\t';
		cout << c.get_spanish_rank() << " de " << c.get_spanish_suit();
		cout << " (" << c.get_english_rank() << " of " << c.get_english_suit() << ")." << endl << endl;

		h.display();
		cout << "Your total is " << h.get_sum() << ". Do you want another card (y/n)? ";
		cin >> keep_playing;
	}


	string s;
	cin >> s;

	return 0;
}