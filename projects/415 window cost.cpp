/*415 Muhammed Abubaker Syed
  CS 2010
  1:30 
  PROJECT 1
  415window_cost.cpp
  DUE- WED 20 FEB
  Write a C++ program in Microsoft Visual Studio (VS) 
  to help a local builder calculate the total cost of a new window.*/
#include <iostream>
#include <math.h>
#include <iomanip>        // Needed to use stream manipulators
using namespace std;	//the main function of the program

int main()
{
	//Declaration section
	//Setting all the values needed for program to execute
	const double COST_GLASS_PSqF = 5.50;
	const double COST_FRAME_PSqF = 8.60;
	const double SALESTAX_Percentage = 0.055;	
	const double LABOR_RATE_PSqF = 11.25;
	//Assigning variable type for required variables
	double height, width, glass_area, cost_of_glass, framing, cost_of_framing, sales_tax, totalcost, laborcost;

	//Input Section
	//Ask the user to input required values
	cout << "Input height of the window = ";
	cin >> height;
	cout << "Input width of the windows = ";
	cin >> width;

	//Calculation Section
	//calculate all values required to complete calculation
	//Calculate Glass Area
	glass_area = height * width;
	//Calculate Cost of Glass
	cost_of_glass = glass_area * COST_GLASS_PSqF;
	//Calculate perimeter of window
	framing = 2 * (height + width);
	//Caluclate Cost Of framing
	cost_of_framing = framing * COST_FRAME_PSqF;
	//Adding Both costs
	totalcost = cost_of_glass + cost_of_framing;
	//Calculate Sales Tax
	sales_tax = SALESTAX_Percentage * totalcost;
	//Calculate Labor cost
	laborcost = LABOR_RATE_PSqF * glass_area;
	//Calculate final costs
	totalcost = totalcost + sales_tax + laborcost;

	//Output section
	//Displaying all the values to the user
	cout << endl ;
	cout << fixed << showpoint << setprecision(2);
	cout << "The cost information for the window is" << endl;
	cout << "Glass area:               " << setw(7) << glass_area << endl;
	cout << "Cost of Glass:           $" << setw(7) << cost_of_glass << endl;
	cout << "Linear feet of framing:   " << setw(7) << framing << endl;
	cout << "Cost of framing:         $" << setw(7) << cost_of_framing << endl;
	cout << "Sales tax:               $" << setw(7) << sales_tax << endl;
	cout << "Labor cost:              $" << setw(7) << laborcost << endl;
	cout << "Total windows cost:      $" << setw(7) << totalcost << endl;

	//Pauses program
	system("pause");

	return 0;
}