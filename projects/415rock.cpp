// Program #5 – Rock Program
// Programmer: 415 MuhammedAbubaker Syed
// Class:  CS 2010, Spring 2019
// Due Date: May. 1, 2019
// Purpose of program: a program that allows 
//a user to play a game of rock/paper/scissors 
//with the computer

#include<iostream>
#include <ctime>  
#include <cstdlib> 
using namespace std;

// Prototype
int getUserChoice(int usernum);
int getComputerChoice(int pcnum);
int determineWinner(int usernum, int pcnum);
void displayResults(int usernum, int pcnum, int wincode);
string convertchoice(int x);
string convertwin(int wincode);
// Start of main Function
int main()
{
	int pcnum = 0, usernum = 0, wincode;


	usernum = getUserChoice(usernum);
	while (usernum != 4)
	{
		pcnum = getComputerChoice(pcnum);
		wincode = determineWinner(usernum, pcnum);
		displayResults(usernum, pcnum, wincode);
		cout << "Game Menu" << endl;
		cout << "---------" << endl;
		cout << "1> Rock" << endl;
		cout << "2> Paper" << endl;
		cout << "3> Scissors" << endl;
		cout << "4> Quit" << endl;
		cout << "Enter your choice: " << endl;
		cin >> usernum;

	}
}

// Start of user Choice function
int getUserChoice(int usernum)
{
	cout << "Game Menu" << endl;
	cout << "---------" << endl;
	cout << "1> Rock" << endl;
	cout << "2> Paper" << endl;
	cout << "3> Scissors" << endl;
	cout << "4> Quit" << endl;
	cout << "Enter your choice: " << endl;
	cin >> usernum;
	return usernum;
}
//Start of computer choice function
int getComputerChoice(int pcnum)
{
	srand(time(NULL));
	pcnum = rand() % 3 + 1;
	return pcnum;
}
// Start of winner identification function
int determineWinner(int usernum, int pcnum)
{
	if (usernum == 1 && pcnum == 3)
	{
		return 1;
	}
	else if (usernum == 1 && pcnum == 2)
	{
		return 2;
	}
	else if (usernum == 1 && pcnum == 1)
	{
		return 0;
	}

	else if (usernum == 2 && pcnum == 1)
	{
		return 1;
	}
	else if (usernum == 2 && pcnum == 3)
	{
		return 2;
	}
	else if (usernum == 2 && pcnum == 2)
	{
		return 0;
	}

	else if (usernum == 3 && pcnum == 2)
	{
		return 1;
	}
	else if (usernum == 3 && pcnum == 1)
	{
		return 2;
	}
	else
	{
		return 0;
	}


}
// Start of print function
void displayResults(int usernum, int pcnum, int wincode)
{
	string userchoice, pcchoice, winner;
	userchoice = convertchoice(usernum);
	pcchoice = convertchoice(pcnum);
	winner = convertwin(wincode);

	cout << "===============================" << endl;
	cout << "You Selected: " << userchoice << endl;
	cout << "The computer selected: " << pcchoice << endl;
	cout << "Game Winner: " << winner << endl;
	cout << "===============================" << endl;

}
// Start of conversion of choice function
string convertchoice(int x)
{
	if (x == 1)
		return "Rock";
	else if (x == 2)
		return "Paper";
	else
		return "Scissors";
}
// Start of conversion of winner function
string convertwin(int wincode)
{
	if (wincode == 1)
		return "User";
	else if (wincode == 2)
		return "Computer";
	else
		return "Tie";

}