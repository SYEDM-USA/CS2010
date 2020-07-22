// Class codes 415
// Name ; Muhammed Abubaker Syed
// FileName : swap.cpp
//Description : Lab 4 – Functions!
//Author : Put your class code and names here

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//prototype
void swap ( double &age, double &wt);

int main()
{
	//Variables
	double age, wt;
	// Input Section
	cout << "Enter Your Age: ";
	cin >> age;
	cout << "Enter your Weight: ";
	cin >> wt;
	//function call
	swap(age,wt);
	//Output Section
	cout << "your age is: " << age << endl;
	cout << "your weight is: " << wt << endl;

	system("pause");
	return 0;
}
//function header

void swap(double &age, double &wt)
{
	double temp;

	if(age>wt)
	{
		temp = age;
		age = wt;
		wt = temp;
	}

}