//****************************************
// CS2010 LAB 1
// 313 Muhammed Abubaker Syed 
// This program calculates the user's pay.
//****************************************
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//Declaration
	string name, major, phone;
	int age;

	//Input Section
	cout << "Enter your name: ";
	getline(cin, name);
	cout << "Your Major: ";
	getline(cin, major);
	cout << "Your phone: ";
	getline(cin, phone);
	cout << "Your Age: ";
	cin >> age;

	//Output Section
	cout << endl;
	cout << "Hello " << name << endl;
	cout << "Welcome to CS 2010 Programming Course!" << endl;
	cout << major << endl;
	cout << phone << endl;
	cout << age << endl;
	cout << "Congratulations! On Your first C++ program!!" << endl;
	cout << "Isn't it fun !!!" << endl << endl;

	system("pause");
	return 0;
}