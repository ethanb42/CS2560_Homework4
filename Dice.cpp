//The Die class
//It was taken from the book as suggested by the homework question
#include <iostream>
#include <cstdlib> // For rand and srand 
#include <ctime>   // For the time function 
#include "Dice.h"//the die class
using namespace std;

Die::Die(int x){ //default constructor
	sides = x;
}

//******************************************************* 
// The roll member function simulates the rolling of   * 
// the die.                                         * 
//******************************************************* 
void Die::roll()
{
	// Constant for the minimum die value 
	const int MIN_VALUE = 1; // Minimum die value 

	// Get a random value for the die. 
	value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;
}

//******************************************************* 
// The getSides member function returns the number of  * 
 // for this die.                                    * 
 //******************************************************* 
int Die::getSides()
{
	return sides;
}

//******************************************************** 
// The getValue member function returns the die's value.* 
//******************************************************** 
int Die::getValue()
{
	return value;
}

