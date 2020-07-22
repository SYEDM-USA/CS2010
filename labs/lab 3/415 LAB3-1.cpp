// Name   	   :  415 Muhammed Abubaker Syed
// File Name   :  415 lab3.cpp
// Date        :  3/4/19
// Description :  Lab 3 – Calculating Travel Cost The Holiday Travel Agency is putting
//                together some travel packages for vacations, and
//                they would like a program that will help them
//                calculate the cost of a customers trip.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{

	// constants
	const double BUS_RATE = 0.25;	// 0.25 per mile
	const double TRAIN_RATE = 0.40;	// 0.40 per mile
	const double PLANE_RATE = 0.75;	// 0.75 per mile
	const double DISC500_RATE = 0.2;	// 20% discount 500 more
	const double DISC250_RATE = 0.1;	// 10% discount 250-499

										// variables
	string vehicle;  	// Type of transportation as a word
	int menuchoice;     // Menu selection
	int numMiles;		// Number of miles (input)
	double subtotal;		// Hold the value for subtotal (output)
	double disc = 0;    //discount for flying
	double total;		// Hold the value for total (output)


						//Input Secttion
	cout << "---------------------" << endl;
	cout << "1 - Bus " << endl;
	cout << "2 - Train " << endl;
	cout << "3 - Plane " << endl;
	cout << "---------------------" << endl;
	cout << "How will you travel: ";
	cin >> menuchoice;
	cout << "Enter the number of miles: ";
	cin >> numMiles;

	// Add your if statements here
	if (menuchoice == 1)
	{
		vehicle = "Bus";
		subtotal = numMiles * BUS_RATE;
	}
	if (menuchoice == 2)
	{
		vehicle = "Train";
		subtotal = numMiles * TRAIN_RATE;
	}
	if (menuchoice == 3)
	{
		vehicle = "Plane";
		subtotal = numMiles * PLANE_RATE;
		if (numMiles < 250)
			disc = 0;
		else if (numMiles < 500)
		{
			disc = subtotal * DISC250_RATE;
		}
		else
		{
			disc = subtotal * DISC500_RATE;
		}
	}

	if (menuchoice > 3)
	{
		cout << "wrong Input" << endl;
		total = 0;
		subtotal = 0;

	}

	total = subtotal - disc;


		//Output Section
	cout << fixed << showpoint << setprecision(2);
	cout << "---------------------" << endl;
	cout << "CS2010 Travels" << endl;
	cout << "---------------------" << endl;
	cout << "Your " << vehicle << " trip of " << numMiles << " miles." << endl;
	cout << "Subtotal:    $" << setw(7) << subtotal << endl;
	cout << "Discount:    $" << setw(7) << disc << endl;
	cout << "Total:       $" << setw(7) << total << endl;

	system("pause");
	return 0;
}
