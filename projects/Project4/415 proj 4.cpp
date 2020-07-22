// Program #4 – landscape Program
// Programmer:  415 Muhammed Abubaker Syeed
// Class:  CS 2010, Spring 2019
// Due Date: 10 April 2019
// Purpose of program: The Landscaping Agency
// needs a program for their clients. They 
// offer several services.


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
//Global
const double newcustdisc = 0.2;
const int costperbush = 10;
const int flowerbedpsqf = 2;
const int costperbag = 11;
const int pergbagarea = 5000;

//Prototype
string convertAcct2String(string acttype);
double getBushCost(string acttype, int num_bushes, double bush_cost, int costperbush, double newcustdisc);
double getFlowerBedCost(double length, double width, double flowerbedcost, int flowerbedpsqf);
double getFertilCost(int sqfootage, int bags, int pergbagarea, double costfert, int costperbag);


int main()
{
	string acttype;
	int num_bushes, bags, sqfootage;
	double length, width, bush_cost, flowerbedcost, costfert,total ;

	bush_cost = 0;
	flowerbedcost = 0;
	costfert = 0;
	bags = 0;

	cout << "Enter Account Type \n P for Preferred \n R for Regular \n N for New:";
	cin >> acttype;
	acttype = convertAcct2String(acttype);

	cout << "Enter the number of bushes to be installed: ";
	cin >> num_bushes;
	cout << "Enter the length of flower bed to be constructed: ";
	cin >> length;
	cout << "Enter the width of flower bed to be constructed: ";
	cin >> width;
	cout << "Enter square footage of the lawn for fertilizing: ";
	cin >> sqfootage;

	bush_cost = getBushCost(acttype, num_bushes, bush_cost, costperbush, newcustdisc);
	flowerbedcost = getFlowerBedCost(length, width, flowerbedcost, flowerbedpsqf);
	costfert = getFertilCost(sqfootage, bags, pergbagarea, costfert, costperbag);

	total = bush_cost + flowerbedcost + costfert;

	cout << fixed << showpoint << setprecision(2);
	cout << "====== Falcon Landing ======" << endl;
	cout << " Account Type: " << acttype << endl;
	cout << "Bush Cost         $ " << setw(7) << bush_cost << endl;
	cout << "Flower Bed Cost   $ " << setw(7) << flowerbedcost <<endl;
	cout << "Fertilizer Cost   $ " << setw(7) << costfert << endl;
	cout << "Final cost        $ " << setw(7) << total << endl;
	cout << "============================" << endl;


	system("pause");
	return 0;
}



string convertAcct2String(string acttype)
{
	if (acttype == "p" || acttype == "P")
		acttype = "Preferred";
	else if (acttype == "r" || acttype == "R")
		acttype = "Regular";
	else if (acttype == "n" || acttype == "N")
		acttype = "New";
	else
	{
		cout << "Wrong data" << endl;
		system("pause");

	}
	return acttype;
}

double getBushCost(string acttype, int num_bushes, double bush_cost, int costperbush, double newcustdisc)
{
	if (acttype == "Preferred")
	{
		if (num_bushes > 5)
			bush_cost = (num_bushes - 5) * costperbush;
		else
			bush_cost = 0;
	}
	else if (acttype == "New")
		bush_cost = (num_bushes * costperbush)-(num_bushes * costperbush*newcustdisc);

	else
		bush_cost = num_bushes * costperbush;

	return bush_cost;
}
double getFlowerBedCost(double length, double width, double flowerbedcost, int flowerbedpsqf)
{
	flowerbedcost = length* width * flowerbedpsqf;
	return flowerbedcost;
}

double getFertilCost(int sqfootage, int bags, int pergbagarea, double costfert, int costperbag)
{
	if (sqfootage% pergbagarea != 0)
	{
		bags = (sqfootage / pergbagarea) + 1;
		costfert = bags * costperbag;
	}
	else
	{
		bags = sqfootage / pergbagarea;
		costfert = bags * costperbag;
	}
	return costfert;
}
