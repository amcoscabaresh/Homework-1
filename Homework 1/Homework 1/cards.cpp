#include "cards.h"
#include <cstdlib>
#include <iostream>

/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
Card class
************************************************* */

/*
Default constructor for the Card class.
It could give repeated cards. This is OK.
Most variations of Blackjack are played with
several decks of cards at the same time.
*/
Card::Card() {
	int r = 1 + rand() % 4;
	switch (r) {
	case 1: suit = OROS; break;
	case 2: suit = COPAS; break;
	case 3: suit = ESPADAS; break;
	case 4: suit = BASTOS; break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; break;
	case  2: rank = DOS; break;
	case  3: rank = TRES; break;
	case  4: rank = CUATRO; break;
	case  5: rank = CINCO; break;
	case  6: rank = SEIS; break;
	case  7: rank = SIETE; break;
	case  8: rank = SOTA; break;
	case  9: rank = CABALLO; break;
	case 10: rank = REY; break;
	default: break;
	}
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "oros";
		break;
	case COPAS:
		suitName = "copas";
		break;
	case ESPADAS:
		suitName = "espadas";
		break;
	case BASTOS:
		suitName = "bastos";
		break;
	default: break;
	}
	return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}
	return rankName;
}



// Accessor: returns a string with the suit of the card in English 
string Card::get_english_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "golds";
		break;
	case COPAS:
		suitName = "cups";
		break;
	case ESPADAS:
		suitName = "swords";
		break;
	case BASTOS:
		suitName = "clubs";
		break;
	default: break;
	}
	return suitName;
}

// Accessor: returns a string with the rank of the card in English 
string Card::get_english_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "Ace";
		break;
	case DOS:
		rankName = "Two";
		break;
	case TRES:
		rankName = "Three";
		break;
	case CUATRO:
		rankName = "Four";
		break;
	case CINCO:
		rankName = "Five";
		break;
	case SEIS:
		rankName = "Six";
		break;
	case SIETE:
		rankName = "Seven";
		break;
	case SOTA:
		rankName = "Jack";
		break;
	case CABALLO:
		rankName = "Knight";
		break;
	case REY:
		rankName = "King";
		break;
	default: break;
	}
	return rankName;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
	return static_cast<int>(rank) + 1;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}



/* *************************************************
Hand class
************************************************* */
// Implemente the member functions of the Hand class here.

// Creates a basic hand with no cards and card sum = 0
Hand::Hand() {
	sum = 0;
}

// Accessor function to get sum of cards played
double Hand::get_sum() const {
	return sum;
}

// Accessor function to get vector of cards
vector<Card> Hand::get_cards() const {
	return cards;
}

// Mutator function, adds a card to the deck
void Hand::draw(Card c) {
	cards.push_back(c);
	if (7 < c.get_rank()) {
		sum += .5;
	} else {
		sum += c.get_rank();
	}
}

// Lists out the current cards in your deck
void Hand::display() const {
	std::vector<Card>::const_iterator i;
	vector<Card> c = get_cards();

	cout << "Your cards:" << endl;
	for (i = c.begin(); i != c.end(); ++i) {
		cout << '\t';
		cout << i->get_spanish_rank() << " de " << i->get_spanish_suit();
		cout << " (" << i->get_english_rank() << " of " << i->get_english_suit() << ")." << endl;
	}

	return;
}



/* *************************************************
Player class
************************************************* */

// Constructor for a player, requires an int and sets this as the player's starting money
Player::Player(int m) {
	money = m;
	player_cards = Hand();
}

//Accessor, returns amount of money player has
int Player::get_money() const {
	return money;
}

// Accessor, returns hand
Hand Player::get_hand() const {
	return player_cards;
}
