//  ************************************************
//  CS2010  Lab 5
//  Name :  414 Ryan Lowery
//  Name :  415 Muhammed Abubaker Syed
//  Purpose: The program will zoo read data
//  and divide the animals up into two categories.
//  The code will yield the average weight of each category
// along with the heaviest and lightest overall animals.
//  *************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;


int main()
{
	

	//declare and initialize your variables
	int largestrfid, smallestrfid, rfid, weight ;
	string largestname, smallestname, name;
	int largestweight = -500;
	int smallestweight = 50000000;
	int jumbocnt = 0;
	int  midcnt = 0;
	double jumbosum = 0.00;
	double  midsum = 0.00;
	double jumboavg, midavg;

	ifstream indata;
	//----------------------------------------------------
	indata.open("zooB.txt");
	if (!indata)
	{
		cerr << "Error:" << endl;
		system("pause");
		return 0;
	}
	//----------------------------------------------------
	//add your code here
	while (!indata.eof())
	{
		indata >> rfid;
		indata.ignore();
		getline(indata, name);
		indata >> weight;

		if (weight > largestweight)
		{
			largestrfid = rfid;
			largestname = name;
			largestweight = weight;
		}

		if (weight < smallestweight)
		{
			smallestrfid = rfid;
			smallestname = name;
			smallestweight = weight;
		}

		if (weight < 200)
		{
			midcnt++;
			midsum += weight;
		}

		else
		{
			
			jumbocnt++;
			jumbosum += weight;
		}
	}
		if (jumbocnt == 0 || jumbosum == 0.00)
		{
			jumboavg = 0.00;
		}
		else
		{
			jumboavg = jumbosum / jumbocnt;
		}
		if (midcnt == 0 || midsum ==0.00)
		{
			midavg = 0.00;
		}
		else
		{
			midavg = midsum / midcnt;
		}

	
	

	cout << fixed << showpoint << setprecision(2);
	cout << "------------------------------" << endl;
	cout << "Largest RFID  : " <<largestrfid << endl;
	cout << "Largest name  : " << largestname << endl;
	cout << "Largest Weight: " << largestweight <<endl;
	cout << "------------------------------" << endl;
	cout << "Smallest RFID  : " <<smallestrfid<< endl;
	cout << "Smallest name  : " << smallestname<<endl;
	cout << "Smallest Weight: " << smallestweight <<endl;
	cout << "------------------------------" << endl;
	cout << "Jumbo-Jungle Average: " << jumboavg << endl;
	cout << "Mid-Meadows Average: " <<  midavg << endl;


	indata.close();

	system("pause");
	return 0;

}


