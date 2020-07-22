// Program #6 – Hurricane Program
// Programmer:  415 Muhammed Abubaker Syed
// Class:  CS 2010, Spring 2019
// Due Date: May. 9, 2019
// Purpose of program: Create a program that 
// will read data from a file called hurricanes.txt.  
// The data will consist of a city’s name, wind velocity 
//and amount of rain for the hurricanes that occurred in the United States.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
//global constants
const int MAXCITIES = 50;
using namespace std;
// Prototype
void fillArray(string city[], int wind[], double rain[], int &numcities);
void sortArray(string city[], int wind[], double rain[], int numcities);
void printarrays(string city[], int wind[], double rain[], int numcities);
void Violentwinds(string city[], int wind[], int numcities);
void MajorFloods(string city[], double rain[], int numcities);
int Windiestcitypos(string city[], int wind[], int numcities);
double Averagewind(string city[], int wind[], int numcities);
double Averagerain(string city[], double rain[], int numcities);


int main()

{
// Declared variables and arrays
	string city[MAXCITIES];
	int wind[MAXCITIES];
	double rain[MAXCITIES];
	int numcities = 0, hiwindpos;
	double avgwind, avgrain;

	
// call to the functions
	fillArray(city, wind, rain, numcities);
	sortArray( city, wind, rain,  numcities);
	printarrays(city, wind, rain, numcities);
	Violentwinds(city, wind,numcities);
	MajorFloods(city, rain, numcities);
	hiwindpos = Windiestcitypos(city, wind, numcities);
	avgwind = Averagewind(city, wind, numcities);
	avgrain = Averagerain(city, rain,  numcities);

// Oout put averages and highest
	cout << city[hiwindpos] << " is the windiest city at " << wind[hiwindpos] << " mph." << endl;
	cout << endl;
	cout << "The average wind is " << avgwind << endl;
	cout << "The average rain is " << avgrain << endl;


	system("Pause");
	return 0;
}


// Function to calculate average rain
double Averagerain(string city[], double rain[], int numcities)
{
	cout << left << fixed << setprecision(3);
	double sum = 0, cnt = 0;
	for (int count = 0; count < numcities; count++)
	{
		sum += rain[count];
		cnt++;
	}
	return sum / cnt;
}

// Function to calculate average wind speed
double Averagewind(string city[], int wind[], int numcities)
{
	cout << left << fixed << setprecision(1);
	double sum = 0, cnt = 0;
	for (int count = 0; count < numcities; count++)
	{
		sum += wind[count];
		cnt++;
	}
	return sum / cnt;
}

// function to return the city position with the highest wind speed
int Windiestcitypos(string city[], int wind[], int numcities)
{
	int hipos = 0, hiwind = -500;
	for (int count = 0; count < numcities; count++)
	{
		if (wind[count] > hiwind)
		{
			hiwind = wind[count];
			hipos = count;
		}
	}
	return hipos;
}

//function to print the cities with major floods
void MajorFloods(string city[], double rain[], int numcities)
{
	cout << "Cities with major floods" << endl;
	for (int count = 0; count < numcities; count++)
	{
		if (rain[count] > 3.4)
		{
			cout << setw(15) << city[count] << setw(10);
			cout << rain[count] << endl;
		}
	}
	cout << endl;
	cout << endl;
}

//function to print the cities with violent winds
void Violentwinds(string city[], int wind[], int numcities)
{
	cout << "Cities with violent winds" << endl;
	for (int count = 0; count < numcities; count++)
	{
		if (wind[count] > 119)
		{
			cout << setw(15) << city[count] << setw(10);
			cout << wind[count] << endl;
		}
	}
	cout << endl;
	cout << endl;
}

// function to print arrays
void printarrays(string city[], int wind[], double rain[], int numcities)
{
	cout << "The Data file consists of: " << endl;
	cout << setw(15) << "City" << setw(10) << "Wind" << setw(10) << " Rain" << endl;
	cout << setw(15) << "------" << setw(10) << "----" << setw(10) << "-----" << endl;

	for (int count = 0; count < numcities; count++)
	{
		cout << setw(15) << city[count] << setw(10);
		cout << wind[count] << setw(10);
		cout << rain[count];
		cout << endl;
		

	}
	cout << endl;
	cout << endl;
}
//function to sort arrays
void sortArray(string city[], int wind[], double rain[], int numcities)
{
	int  itemp;
	double dbtemp;
	string stemp;
	bool sort = false;


	while (!sort)
	{
		sort = true;
		for (int k = 0; k < (numcities - 1); k++)
		{
			if (city[k] > city[k + 1])
			{
				stemp = city[k];
				city[k] = city[k + 1];
				city[k + 1] = stemp;

				itemp = wind[k];
				wind[k] = wind[k + 1];
				wind[k + 1] = itemp;

				dbtemp = rain[k];
				rain[k] = rain[k + 1];
				rain[k + 1] = dbtemp;

				sort = false;
			}
		}
	}
}

//function to read and fill arrays
void fillArray(string city[], int wind[], double rain[], int &NumCities)
{
	cout << left << fixed << setprecision(1);
	ifstream indata;
	NumCities = 0;

	//Now we will open the file

	indata.open("hurricanes.txt");
	if (!indata)
	{
		cerr << "Error" << endl;
	}

	//We will now run a loop to get al of the data from the file and assign it to the proper array
	while (!indata.eof() && NumCities < MAXCITIES)
	{
		getline(indata, city[NumCities]);
		indata >> wind[NumCities];
		indata >> rain[NumCities];
		indata.ignore();
		NumCities++;
	}
	indata.close();
}