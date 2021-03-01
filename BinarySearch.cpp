// BinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.

// All relevant inclusions.
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

// Remove need for writing std::
using namespace std;

// A function for formatting an array of integers into a string.
// Given the array, and its length.
string formatArray(int arr[], int arrLength)
{
	// Create the string to which the numbers will be added.
	string arrayAsString = "";

	// For every item in the array,
	for (int i = 0; i < arrLength; ++i)
	{
		// Convert a number to a string,
		arrayAsString += to_string(arr[i]);
		// and if the number is not the last in the array,
		if (i + 1 < arrLength)
		{
			// add a comma.
			arrayAsString += ", ";
		}
	}

	// Return the final array, formatted as a string and separated by commas.
	return arrayAsString;
}

// A function for swapping a pair of values by their references.
// Given the references for each value.
void swapValues(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

// A function for reversing an array's contents.
// Given the array, a start point, and end point.
void reverseArray(int arr[], int start, int end)
{
	// While the start point of the array remains below the end point,
	while (start < end)
	{
		// Swap the values at the start and end point.
		swapValues(arr[start], arr[end]);

		// Advance the start and end points towards eachother.
		start += 1;
		end -= 1;
	}
}

// A function for testing if an integer value appears in an integer array.
// Takes the array, its length, and the item being searched for.
// Returns TRUE or FALSE depending if the item appears in the array.
bool isInIntArr(int arr[], int len, int key)
{
	// For every value in the array,
	for (int i = 0; i < len; ++i)
	{
		// If the value equals to what we're looking for,
		if (key == arr[i])
		{
			// Return that we've found the integer.
			return true;
		}
	}
	// We didn't find the integer. Let's say so!
	return false;
}

// A function using bubble/sinking sort to sift numbers from lowest to highest.
// Takes the array, its length, and optionally whether the sorted array should be flipped.
// Directly modifies the array passed as an argument.
void sortArray(int arr[], int len, bool reverse = false)
{
	// Assume that the array is unsorted,
	bool sorted = false;

	// While the array is unsorted,
	while (!sorted)
	{
		// Assume that this iteration will be the final iteration.
		sorted = true;

		// For every number in the array,
		for (int i = 0; i < len; ++i)
		{
			// Is there a number after this one in the list?
			if (i != len - 1)
			{
				// Is it smaller than the current one?
				if (arr[i + 1] < arr[i])
				{
					// Swap them.
					swapValues(arr[i], arr[i + 1]);
					// Set the loop to continue once more, to check if everything is sorted.
					sorted = false;
				}
			}
		}
	}

	// If the user wants the array in descending order, reverse the order.
	if (reverse)
	{
		reverseArray(arr, 0, len - 1);
	}
}

// A function for searching for an integer in an integer array.
// Takes an array, its length, the number being searched for, and whether to return the last appearance.
// Returns the index of the number's place.  Returns -1 if it cannot find the number.
int binarySearch(int arr[], int len, int search, bool findLast = false)
{
	// Initialize variable for wherever we find the place of the key.
	int place = -1;
	// Initialize variable with false because we haven't yet found the key.
	bool foundSearch = false;

	// For every value in the array,
	for (int i = 0; i < len; i++)
	{
		// If the value equals the value we're searching for,
		if (arr[i] == search)
		{
			// Note that we've found the variable, and the place we found it.
			foundSearch = true;
			place = i;
			// If we're trying to find the first value, we're done.
			if (!findLast)
			{
				// Let's get out of here!
				break;
			}
		}
	}

	// If, for whatever reason, we can't find the value in the array,
	if (!foundSearch)
	{
		// Warn the user.
		cout << "\nNo value \"" << search << "\" was found.  Returning -1.\n";
	}

	// Return the place of the value in the array.
	// NOTE: If the value was not found, this will return -1 because we initialized place with -1.
	return place;
}

// A simple function for clearing the screen's contents.
// Optionally takes the number of lines to clear the screen with.
// Prints directly to the terminal.
void clearScreen(int lines = 50) {
	cout << string(lines, '\n');
}

// Function for prompting a user to input a yes or no.
// Takes the prompt to the user and optionally the exception prompt.
// Returns the TRUE or FALSE respective to input YES or NO.
bool boolInput( const char* prompt, const char* exception = "Sorry, that's an invalid answer.  Please answer with a yes or no." )
{
	// Initialize input variable and a place to store its length later on.
	string input = "";
	signed int length = 0;

	// Continue looping until the innter return is struck.
	while (true)
	{
		// Prompt the user for input, then take it.
		cout << prompt << " ";
		cin >> input;
		cout << "\n";

		length = input.length();

		// Iterate through each character in the input, forcing it to lowercase.
		for (int i = 0; i < length; ++i)
		{
			input[i] = (char) tolower(input[i]);
		}

		// If the user answers some variant of yes,
		if (input == "yes" || input == "y" || input == "sure" || input == "ok" || input == "true")
		{
			// Return true.
			return true;
		}
		// If the user answers some variant of no,
		else if (input == "no" || input == "n" || input == "nope" || input == "false")
		{
			// Return false.
			return false;
		}

		// If the user's input doesn't match the above conditionals, tell them to re-input.
		cout << exception << "\n\n";
	}
	// Will not be hit - here just to appease the compiler.
	return false;
}

// Function for prompting user to pass an integer.
// Takes the prompt to the user and optionally the exception prompt.
// Returns the input integer.
int intInput( const char* prompt, const char* exception = "Sorry, that's an invalid answer.  Please enter an integer.")
{
	// Initialize input variable.
	int input = 0;

	// Keep looping until the inner return is struck.
	while (true)
	{
		// Prompt the user for input, then take it.
		cout << prompt << " ";
		cin >> input;
		cout << "\n";
	
		// If the user inputs something that cannot be turned into an integer (a letter, for example),
		if (cin.fail())
		{
			// Force cin out of its fail state and clear its buffer.
			cin.clear(); cin.ignore();
			// Tell the user that there was a problem getting the integer,
			cout << exception << "\n\n";
			// Start from the top of the while loop to gather input again.
			continue;
		}
		
		// Return the valid input.
		return input;
	}
	// Will not be hit - here just to appease the compiler.
	return 0;
}

// NOTE: The largest function in this program.
// A function for gathering numbers from the user, split along spaces.
// Requires an array and the user prompt.
// Optionally takes the 
int intArrayInput(int arr[], const char* prompt, signed int max = 100)
{
	// Initialize all necessary string and string-stream variables/objects.
	string input = "";
	string strBuffer = "";
	stringstream ss;

	// Initialize all integer variables.
	int ints = 0;
	int buffer = 0;
	signed int strBufferLength = 0;
	int inputLength = 0;

	// Initialize all boolean variables.
	bool overflow = false;
	bool nonDigits = false;
	bool firstLoop = true;

	// Continue looping until conditions create a break.
	while (true)
	{
		// Advise the user to input their numbers.
		cout << prompt << " ";
		
		// If this is the first loop, clear any trailing \n's from any cin earlier in the program.
		if (firstLoop)
		{
			// Ignore all '\n's.
			cin.clear(); cin.ignore(INT_MAX, '\n');
			firstLoop = false;
		}

		// Get the user's input by the entire line and place in input variable.
		getline(cin, input);
		input += " ";
		inputLength = input.length();

		// If the user has input any more than 256 characters, tell them not to, and repeat.
		if (inputLength > 256)
		{
			cout << "Sorry, please keep your input to 256 characters or under." << "\n\n";
			continue;
		}
		else if (inputLength == 0)
		{
			cout << "You didn't enter any numbers!  Please enter at least one number to continue.\n" << endl;
			continue;
		}
		
		// Inject the input string into a stringstream.
		ss.str(input);

		// Obligatory aesthetics :)
		cout << "\n";

		// Iterate through the stringstream.  Because we're using a stream, the delimiters will be the spaces between numbers.
		while (ss >> strBuffer)
		{
			// Assess how long this particular block is in characters.
			strBufferLength = strBuffer.length();

			// NOTE: Because each block will be passed into an array if it checks out,
			//       we need to make sure that the user has not input more integers
			//       than can fit in the array.
			//
			// If we've hit the max number of integers,
			if (ints == max)
			{
				// Set the overflow condition to true.
				overflow = true;
				// Break the loop.
				break;
			}
				
			// For each character in the block,
			for (int i = 0; i < strBufferLength; ++i)
			{
				// Is it not a digit?
				if (!isdigit(strBuffer[i]))
				{
					// If it isn't, break this testing loop and set the nonDigits condition to true.
					nonDigits = true;
					break;
				}
			}

			// If there were nonDigits in this block, break.
			if (nonDigits) break;

			// Now that we know that all characters in this block are digits ...
			// ... convert the block to an integer.
			buffer = stoi(strBuffer);

			// For the corresponding slot in the array, place the inputted integer.
			arr[ints] = buffer;
			// Increase the count of integers that have been inputted by the user by one.
			ints++;
		}

		// If the user had put too many integers for the array to handle,
		if (overflow)
		{
			// Let them know!  Reset the overflow condition.  Rinse and repeat.
			cout << "You included too many integers in your input.  Please keep your number of integers under " << max << "." << "\n\n";
			overflow = false;
			strBuffer = "";
			ss.str("");
			continue;
		}
		// If the user input a character that was not a digitm
		else if (nonDigits)
		{
			// Tell them you're disappointed.  Reset the nonDigits condition.  Pick yourself up and try again.
			cout << "You included a character that is not a number.  Please stick to numbers.\n\n";
			nonDigits = false;
			strBuffer = "";
			ss.str("");
			continue;
		}
		// If there were no exceptions, we can escape!
		break;
	}
	// Return the number of integers the user inputted.
	return ints;
}

// The main loop (driver function).
int main()
{
	// Align all future text to bottom of the screen for continuity.
	clearScreen();
	// A greeting and explanation of the program.
	cout << "BINARY SEARCH\n";
	cout << "by Zachary Morritt\n\n";
	
	cout << "This program is meant to take a chosen amount of numbers as an input, then sort them in either ascending or descending order.\n";
	cout << "The only accepted inputs will be numbers.  If an incorrect input is entered, you will be ask to re-enter new values.\n";
	cout << "If you wish, you can also choose a .txt file with numbers on each line, which will also be sorted.\n";
	cout << "If you have any questions, don't hesitate to ask me for support.\n\n";

	// Ask the user to press enter to continue after they've finished reading.
	cout << "PRESS RETURN TO CONTINUE...\n";
	cout << flush; cin.ignore(); clearScreen();

	// Ask the user whether or not they'd like to provide their own values.
	cout << "First off, would you like to insert your own series of numbers?\n";
	bool manualInput = boolInput("(y/n):", "Please answer with either yes or no.");
	cout << "\n\n";

	clearScreen();

	// Set all integeral variables and initialize them!
	int arr[100] = {};
	int len = 0;
	string stringArr = "";
	int key = 0;
	int place = 0;

	// Initialize all the conditionals.  Assume that we're sorting in ascending order and finding the first values in binary search.
	bool ascending = true;
	bool included = false; // The conditional that will let us know if the value we're searching for was not found.
	bool findFirst = true;

	// Managing if a user decides to provide their own values.
	if (manualInput)
	{
		// Inform the user how to input their numbers, then nab them.
		cout << "Sure!  Please insert a list of numbers, separated by spaces. (ex. \"245 34 1 25 29 28\" etc.)\n";
		cout << "Also, make sure you keep to under 100 integers, and under 256 characters.\n\n";
		len = intArrayInput(arr, "Please insert your numbers below:\n");

		// Format their array of numbers nice and neatly.
		stringArr = formatArray(arr, len);

		clearScreen();

		// Tell the user what monster they've created.
		cout << "\n Ok, you have " << len << " numbers and they are as follows:\n" << stringArr << "\n\n";
	}
	// Managing if the user decides to use the stock values.
	else
	{
		// Set all the defaults if the user is boring and doesn't input their own values.
		int stockArray[7] = { 2, 53, 6, 1, 2, 2, 100 };
		len = 7;

		// Copy the values of the default array to the working one.
		for (int i = 0; i < len; i++)
		{
			arr[i] = stockArray[i];
		}
		
		// Format the default array nice and neatly.
		stringArr = formatArray(arr, len);

		clearScreen();

		// Let the boring user know what the boring array they've chosen is.
		cout << "Ok, we'll use the stock array [" << stringArr << "] which is " << len << " characters long.\n\n";
	}

	// Ask the user if the want to sort their array in ascending order.
	cout << "Would you like to sort your array in ascending order?\n";
	ascending = boolInput("Please answer here (y/n):");

	// If the user wants the array in ascending order, sort it as such.
	if (ascending)
	{
		sortArray(arr, len);
	}
	// If the user wants the array in descending order, sort it as such.
	else
	{
		sortArray(arr, len, true);
	}

	// Create a string of the array even nicer and neatlier.
	stringArr = formatArray(arr, len);

	clearScreen();

	// Show the user the beautifully sorted array.
	cout << "\n\nYour sorted array is now [" << stringArr << "].\n\n";

	// Tell the user we're moving on.
	cout << "Ok, now it's time to choose an integer to search for.\n\n";

	// While the searched for value is not included in the array,
	while (!included)
	{
		// Ask the user for a value that is included in the array.
		cout << "Please enter an integer you wish to search the array for.\n";
		key = intInput("Please enter a number:");

		// If the value is found in the array,
		if (isInIntArr(arr, len, key))
		{
			// Rejoice!
			included = true;
		}
		// If the value is NOT found in the array,
		else
		{
			// Be very upset.
			cout << "\nYour integer isn't included in the array.  Please choose another.\n\n";
		}
	}

	clearScreen();

	// Ask the user if they want to find the first appearance or not.  Warn them that if they don't, we'll find the last for them instead.
	cout << "\nWould you like to find the first appearance of your integer? (y/n)\nIf you reply no, we'll find the last appearance for you.\n";
	cout << "This might not matter if your integer appears only once.\n\n";

	// Retrieve the user's preference of the above.
	findFirst = boolInput("Please answer here (y/n):");
	
	// Search the user's array for the value, returning its index.
	place = binarySearch(arr, len, key, !findFirst);

	clearScreen();

	// Let the user know that its value X was found at place X in their array X.
	cout << "\n\nYour value " << key << " appears at place " << place + 1 <<" (or arr[" << place << "]) in the following array:\n[" << stringArr <<"].\n\n";

	// We're all done!

	// Ask the user to press enter to exit.
	cout << flush;
	// Clear any trailing '\n's that would otherwise immediatly close the program.
	cin.ignore(INT_MAX, '\n');
	cout << "PRESS RETURN TO EXIT...\n";
	cin.ignore();

	// It's not about the array, but about the values you meet along the way.
	return 0;
}