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
	Player person = Player(100);
	Player dealer = Player(900);
	Hand p = person.get_hand();
	Hand d = dealer.get_hand();

	while (person.get_money() != 0 && dealer.get_money() > 0) {
		char keep_playing = 'y';

		cout << "You have $" << person.get_money() << ". Enter bet: ";
		cin >> bet;
		while (bet > person.get_money()) {
			cout << "You cannot bet more money than you currently have." << endl << "Enter bet: ";
			cin >> bet;
		}
		p.clear_hand();

		while (keep_playing == 'y') {
			Card player_card = Card();
			p.draw(player_card);

			cout << "New card:" << endl << '\t';
			cout << player_card.get_spanish_rank() << " de " << player_card.get_spanish_suit();
			cout << " (" << player_card.get_english_rank() << " of " << player_card.get_english_suit() << ")." << endl << endl;

			cout << "Your cards:" << endl;
			p.display();


			cout << "Your total is " << p.get_sum() << ". Do you want another card (y/n)? ";
			cin >> keep_playing;
		}

		d.clear_hand();
		cout << "Dealer's cards: " << endl;
		double dealer_total = d.get_sum();

		while (dealer_total < 5.5) {
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

		double player_total = p.get_sum();
		bool player_win = false;
		bool tie = false;

		if (dealer_total > 7.5) {
			player_win = true;
		}
		else if (player_total == dealer_total) {
			tie = true;
		}
		else if (player_total > dealer_total && player_total < 8.0) {
			player_win = true;
		}

		if (player_win) {
			cout << "You win " << bet << "!!!" << endl;
			person.adjust_money(bet);
			dealer.adjust_money(-bet);
		}
		else if (tie) {
			cout << "Nobody wins!" << endl;
		}
		else {
			cout << "Too bad. You loose " << bet << " :(" << endl;
			person.adjust_money(-bet);
			dealer.adjust_money(bet);
		}
	}

	if (person.get_money() == 0) {
		cout << "You have $0. GAME OVER!" << endl << "Come back when you have more money.";
	}
	else {
		cout << "Congratulations, you beat the casino!";
	}

	string s;
	cin >> s;

	return 0;
}