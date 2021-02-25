// BinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.

// All relevant inclusions.
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

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
		int hold = arr[start];
		arr[start] = arr[end];
		arr[end] = hold;

		// Advance the start and end points towards eachother.
		start += 1;
		end -= 1;
	}
}

// A function using bubble/sinking sort to sift numbers from lowest to highest. 
void sortArray(int unorderedArray[], int len, bool reverse = false)
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
				if (unorderedArray[i + 1] < unorderedArray[i])
				{
					// Swap them.
					swapValues(unorderedArray[i], unorderedArray[i + 1]);
					// Set the loop to continue once more, to check if everything is sorted.
					sorted = false;
				}
			}
		}
	}

	// If the user wants the array in descending order, reverse the order.
	if (reverse)
	{
		reverseArray(unorderedArray, 0, len - 1);
	}
}

int binarySearch(int arr[], int len, int search, bool findLast = false)
{

	int place = -1;
	bool foundSearch = false;

	for (int i = 0; i < len; i++)
	{
		if (arr[i] == search)
		{
			foundSearch = true;
			place = i;
			if (!findLast)
			{
				break;
			}
		}
	}

	if (!foundSearch)
	{
		cout << "\nNo value \"" << search << "\" was found.  Returning -1.\n";
	}

	return place;
}

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


// The main loop
int main()
{
	// A greeting and explanation of the program.
	cout << "BINARY SEARCH\n";
	cout << "by Zachary Morritt\n\n";

	cout << "This program is meant to take a chosen amount of numbers as an input, then sort them in either ascending or descending order.\n";
	cout << "The only accepted inputs will be numbers.  If an incorrect input is entered, you will be ask to re-enter new values.\n";
	cout << "If you wish, you can also choose a .txt file with numbers on each line, which will also be sorted.\n";
	cout << "If you have any questions, don't hesitate to ask me for support.\n\n";

	// Ask the user to press enter in order to continue after they've finished reading.
	cout << "PRESS ANY KEY TO CONTINUE...\n";
	cin.ignore();

	// Create a placeholder array, then find its length.
	int list1[] = { 4, 2, 2, 8, 7 };
	int len = sizeof(list1) / sizeof(list1[0]);

	// Show the user the array.
	cout << "The array is as follows: " << formatArray(list1, len) + ".\n";
	cout << "The array length is " + std::to_string(len) + ".\n\n";

	// Sort the user's array.
	sortArray(list1, len);

	// Show the user the sorted array.
	cout << "The array is as follows: " << formatArray(list1, len) + ".\n";
	cout << "The array length is " + std::to_string(len) + ".\n\n";

	cout << "7 first appears at index " << binarySearch(list1, len, 7) << ".\n";
	cout << "2 first appears at index " << binarySearch(list1, len, 2) << ".\n";
	cout << "2 last appears at index " << binarySearch(list1, len, 2, true) << ".\n\n";

	// Reverse the order of the sorted array.
	reverseArray(list1, 0, len - 1);

	// Show the user the reversed and sorted array.
	cout << "The array is as follows: " << formatArray(list1, len) + ".\n";
	cout << "The array length is " + std::to_string(len) + ".\n\n";

	cout << "7 first appears at index " << binarySearch(list1, len, 7) << ".\n";
	cout << "2 first appears at index " << binarySearch(list1, len, 2) << ".\n";
	cout << "2 last appears at index " << binarySearch(list1, len, 2, true) << ".\n\n";
}