//the game engine 
#include <iostream>
#include "Dice.h"
using namespace std;

//define objects used in the class
Die DiceOne(6); //creates dice one
Die DiceTwo(6); //creates dice two

//define variables for the game
int cPoints;  //the computers points
int pPoints;  //the players points
int gameOver = 0;
int playerFailed =0;



//rolls the dice for the computer
//the computer will keep rolling untill it has at least 12 points
//because after 12 points it could go over 21
void computerRoll() {
	cPoints = 0;
	while (cPoints <= 9) {
		DiceOne.roll();
		DiceTwo.roll();
		cPoints = cPoints + DiceOne.getValue() + DiceTwo.getValue();
		//cout << cPoints << endl;
	}

	//the computer has rolled and points are calculated
}

//rolls the dice twice and adds it to player's points
void playerRoll() {
	DiceOne.roll();
	DiceTwo.roll();
	pPoints = pPoints + DiceOne.getValue() + DiceTwo.getValue();

}



void playerRoundLoop()
{
	playerFailed = 0;
	playerRoll();
	cout << "You rolled and have a total of " << pPoints << endl;
	char input;

	int round = 0;
	while (round == 0) {
		//offer to roll again
		cout << "Would you like to....." << "\n1: Roll again" << "\n2: Hold" << "\nInput:" << endl;
		cin >> input;
		switch (input) {
		case '1':
			//they decided to roll again
			playerRoll();
			cout << "\nYou rolled a total of " << pPoints << endl;
			if (pPoints > 21) {
				//failed
				cout << "\nYou rolled over 21 and have failed." << endl;
				playerFailed = 1;
				round = 1;
			}
			else if (pPoints == 21) {
				cout << "\nYou rolled 21, you win!" << endl;
				round = 1;
					
			}
			//within valid number offer to roll again or hold
			break;

		case '2':
			//they choice to hold
			round = 1;
			break;

		default:
			cout << "Invalid input, try again!" << endl;
			break;

		}

	}
}


void gameLoop() {
	cout << "Welcome to Game of 21." << endl;

	while (gameOver == 0) {
		pPoints = 0;
		cPoints = 0;
	//first round iteration
		cout << "1: Would you like to roll the dice?"
			<< "\n2: Quit the program\n"
			<< "Input:" << endl;
		char choice;
		cin >> choice;
		switch (choice) {
		case '1':
			//computer rolls its dice
			computerRoll();
			//Player rolls dice
			playerRoundLoop();
			//player round finished check for who won
			if (cPoints <= pPoints) {
				if (playerFailed == 0) {
					//player won
					cout << "You won!" << endl;
				}
				else {
					cout << "The computer won!" << endl;
				}
			}
			else {
				cout << "The computer won!" << endl;
			}

			cout << "Player Points:" << pPoints << "\nComputer Points:" << cPoints << endl;
			cout << "\n\n\nNew Round!\n\n\n" << endl;
			//display stats
			break;

		case '2':
			//quits
			gameOver = 1;
			break;

		default:
			//invalid input
			cout << "You entered an incorrect input, try again!" << endl;

			break;
		}


	}


}







//runs the program
void main() {
	gameLoop();


}


