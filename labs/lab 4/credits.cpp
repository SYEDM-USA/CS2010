// FileName : credits.cpp
//Description : Lab 4 – Functions!
//Author : 415 Muhammed Abubaker Syed ; 414 Ryan Lowery

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//prototype
void givemecredit (int creditsd, int &creditsn, string &title);

int main()
{
	// DECLARATION
	int creditsd, creditsn;
	string title;
	//INPUT SECTION
	cout << "Enter no. of credits done? ";
	cin >> creditsd;
	// Function call
	givemecredit(creditsd,creditsn,title);
	// Output Section
	cout << "You are a " << title << " and need " << creditsn << " credits to graduate."<< endl;

	system("pause");
	return 0;
}

// Function
void givemecredit(int creditsd, int &creditsn, string &title)
{
	creditsn = 122 - creditsd;
	if (creditsd > 89)
		title = "senior";
	else if (creditsd > 59)
		title = "Junior";
	else if (creditsd > 29)
		title = "sophmore";
	else
		title = "freshman";
}