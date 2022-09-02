//Guess the Number
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void guess(int);
int easy();
int medium();
int hard();

int MIN_VALUE;
int MAX_VALUE;

int main() {

	bool running = true;
	int difficulty;

	while (running == true) {
		cout << "Welcome to Guess the Number! Choose your difficulty: \n";
		cout << "1. Easy\n2. Medium\n3. Hard\n\n4. Quit\n";
		cin >> difficulty;
		if (difficulty < 0 || difficulty > 4) {
			cout << "Select a listed difficulty.\n";
		}
		else if (difficulty <= 3) {
			guess(difficulty);
		}
		else if (difficulty == 4) {
			cout << "Thanks for playing!\n";
			running = false;
		}
	}

	return 0;
}

void guess(int difficulty) {
	int answer;
	int playerGuess;
	int chances = 5;

	while (chances != 0) {
		cout << "Alright, I'm thinking of a number between ";
		switch (difficulty) {
		case 1: answer = easy();
			break;
		case 2: answer = medium();
			break;
		case 3: answer = hard();
			break;
		}
		cout << MIN_VALUE << " and " << MAX_VALUE << ". What is it?\n";
		cout << "You have " << chances << " chances.\n";
		cin >> playerGuess;
		if (playerGuess == answer) {
			cout << "Correct! You win!\n";
			chances = 0;
		}
		else if (playerGuess != answer) {
			cout << "Incorrect! Try again!\n";
			--chances;
		}

	}
}

int easy() {
	MIN_VALUE = 1;
	MAX_VALUE = 10;
	int answer;

	unsigned seed = time(0);
	srand(seed);

	answer = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	return answer;
}

int medium() {
	MIN_VALUE = 1;
	MAX_VALUE = 100;
	int answer;

	unsigned seed = time(0);
	srand(seed);

	answer = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	return answer;
}

int hard() {
	MIN_VALUE = 1;
	MAX_VALUE = 1000;
	int answer;

	unsigned seed = time(0);
	srand(seed);

	answer = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	return answer;
}