/*	Engineer: Janneth Guarcas Garcia		    
	Assignment: Programming Assignment 6 (part 3/3)
	Date: 4/24/18
	Description: passByPointer.cpp
    
    "Write 3 Programs to play with pass by value, pass by reference, 
	and pass by pointer. Each program will:
		Prompt for 3 int values
		Order the values
		Display the lowest value
		Display the highest value
	Use functions to perform each item. The functions must use pass by value, pass 
	by reference, or pass by pointer."          
*/


#include<iostream>
using namespace std;
bool validateValues(int, int, int);
int findMin(int*, int*, int*);	// OKAY SO DONT "RETURN BY POINTER",
				// RETURN AN INT VALUE NOT POINTER,
				// ONLY PASS BY POINTER.
int findMax(int*, int*, int*);
int isMid(int*, int*, int*, int*, int*);
void displayReport(int*, int*, int*);

int main()
{
	int value1, value2, value3;
    cout << "Enter 3 different integers: ";
	cin >> value1 >> value2 >> value3;

	bool continueAlong = validateValues(value1, value2, value3);
	if (continueAlong)
		{
		int low = findMin(&value1, &value2, &value3);
		int high = findMax(&value1, &value2, &value3);
		int mid = isMid(&low, &high, &value1, &value2, &value3);

		displayReport(&low, &mid, &high);
		}
	return 0;
}

bool validateValues(int value1, int value2, int value3)
{
	bool continueSorting = true;
	if (value1 ==  value2 || value1 == value3 || value2 == value3)
	{	
		continueSorting = false;
		cout << "Please try again, the three numbers you entered are "
			 << "not different." << endl;
	}
	return continueSorting;
}

int findMin(int *first, int *second, int *third)
{
	int min;
	if (*first < *second && *first < *third)
		min = *first;
	else if (*second < *first && *second < *third)
		min = *second;
	else if (*third < *first && *third < *second)
		min = *third;
	return min;
}

int findMax(int *first, int *second, int *third)
{
	int max;
	if (*first > *second && *first > *third)
		max = *first;
	else if (*second > *first && *second > *third)
		max = *second;
	else if (*third > *first && *third > *second)
		max = *third;
	return max;
}

int isMid(int *low, int *high, int *first, int *second, int *third)
{
	int mid; 
	if (*first > *low && *first < *high)
		mid = *first;
	else if (*second > *low && *second < *high)
		mid = *second;
	else if (*third > *low && *third < *high)
		mid = *third;
	else if (*third > *low && *third < *high)
		mid = *third;
	return mid;
}
void displayReport(int *min, int *mid, int *max)
{
	cout << "The minimun value is " << *min
		 << "\nThe maximun value is " << *max
		 << "\nFrom lowest to highest, the numbers are: " 
		 << *min << " " << *mid << " "  << *max << endl;
}
