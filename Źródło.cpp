// pe13-4.cpp -- tests Port and VintagePort classes
// This is exercise 4 of chapter 12 in C++ Primer Plus by Stephen Prata
// this is not part of the question but used to make sure that 
// the Port and VintagePort classes work
// compile with port.cpp and vintageport.cpp

#include<iostream>
#include "port.h"
#include "vintagePort.h"
const int LEN = 50;
const int arrSize = 3;

int main(void)
{
	using namespace std;

	char brand[LEN];
	char style[LEN];
	int bottles;
	char nickname[LEN];
	int year;
	int choice;
	Port * arr[arrSize];

	for (int i = 0; i < arrSize; i++)
	{
		cout << "Object " << i + 1 << endl;
		cout << "Enter the brand for the object: ";
		cin.getline(brand, LEN);
		cout << "Enter the number of bottles: ";
		cin >> bottles;
		cin.get(); 	// discard newline character
		cout << "Enter 1 if you would like this to be a Port object" << endl;
		cout << "Enter 2 if you would like this to be a Vintage Port object";
		cout << endl;
		cin >> choice;
		cin.get(); 	// discard newline character

		switch (choice)
		{
		case 1:
			cout << "Enter the style: ";
			cin.getline(style, LEN);
			arr[i] = new Port(brand, style, bottles);
			break;
		case 2:
			cout << "Enter the style: ";
			cin.getline(style, LEN);
			cout << "Enter the nickname: ";
			cin.getline(nickname, LEN);
			cout << "Enter the year: ";
			cin >> year;
			cin.get(); 	// discard newline character
			arr[i] = new VintagePort(brand, style, bottles, nickname, year);
			break;
		default:
			cout << "Input not recognized. Making a default Port object";
			cout << endl;
			arr[i] = new Port();
			break;
		}
	}

	cout << "Here's our array:" << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << "Element "<< endl;
		(*arr[i]).Show();
	}

	cout << "\n\n\nIle butelek " << arr[0]->Brand() << " chcesz pobrac: ";
	int temp;
	cin >> temp;
	*arr[0] -= temp;

	cout << "\nIle butelek " << arr[1]->Brand() << " chcesz zdeponować: ";
	cin >> temp;
	*arr[1] += temp;

	
	cout << "\nIle butelek " << arr[2]->Brand() << " chcesz pobrac: ";
	cin >> temp;
	*arr[2] -= temp;

	for (int i = 0; i < arrSize; i++)
	{
		cout << "Element 1: " << i + 1 << ": " <<*arr[i] << "gotowe." << endl;

	}
	cout << "Bye!" << endl;

	cin.get();
	cin.get();
	return 0;
}
