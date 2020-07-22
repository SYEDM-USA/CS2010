// Program #3 – Vacation Program
// Programmer:  your class code and name
// Class:  CS 2010, Spring 2019
// Due Date: March. 13, 2019
// Purpose of program: The Holiday Travel Agency is putting
//  together some travel packages for vacations, and
//  they would like a program that will help them
//  calculate the cost of a customers trip.


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{

	// constants
	const double hotelrateflorida = 70;	// 70 per day
	const double hotelratetexas = 60;	// 60 per day
	const double hotelratecancum = 100;	// 100 per day
	const double hotelratebahamas = 95;	// 95 per day

	const double airfareflorida = 175.55; // Air fare to florida
	const double airfaretexas = 225.98; // Air fare to texas
	const double airfarecancum = 474.89; // Air fare to cancum
	const double airfarebahamas = 355.98; // Air fare to bahamas

	const double long_stay_disc_FL_and_CNM_hotelday = (-1); //Discount for Florida and Cancun:  one day free hotel 
	const double long_stay_disc_TX_and_BHMS_airfare = 0.5; //Discount for Texas and Bahamas: 50% off the airfare 
	
	const double one_4week = 0; //Reservation 1 - 4 weeks in advance no discount
	const double five_6week = 0.05; //Reservation 5 - 6 weeks in advance 5% discount
	const double seven_9week = 0.08;//Reservation 7-9 weeks in advance 8% discount
	const double ten_plusweek = 0.08;//Reservation 10 or more weeks in advance	10% discount



	// variables
	
	string destination ;  	// Type of destination as a word
	int no_ofdaysstay, weeksinadv ;     // number of weeks in advance boooked and no of days staying is integer
	double cost_hotel, cost_airfare, final_bill ;// All the variables are assigned double type for calculations to be done
	double longstay_disc = 0;    //discount for long stay
	double earlysignup_disc = 0; //discount for early sign up
	

	//Input Secttion
	cout << "Enter weeks before the trip: ";
	cin >> weeksinadv;
	cout << "How many days are you staying: ";
	cin >> no_ofdaysstay;
	cout << "Please enter your destination:" <<endl<<"F for Florida" <<endl<<"T for Texas" <<endl<<"C for Cancum" << endl <<"B for Bahamas" << endl <<"========>";
	cin >> destination;

	// Processing Section

	// destination is florida
	if (destination == "f" || destination == "F")
	{
		destination = "Florida";
		cost_airfare = airfareflorida;
		// if stay is longer than 5 days
		if (no_ofdaysstay > 6)
		{
			cost_hotel = hotelrateflorida * (no_ofdaysstay + long_stay_disc_FL_and_CNM_hotelday);
			longstay_disc = hotelrateflorida;
		}
		else
		{
			cost_hotel = hotelrateflorida * no_ofdaysstay;
		}
	}
	
	// destination is Cancum
	if (destination == "c" || destination == "C")
	{
		destination = "Cancum";
		cost_airfare = airfarecancum;
		// if stay is longer than 5 days
		if (no_ofdaysstay > 6)
		{
			cost_hotel = hotelratecancum * (no_ofdaysstay + long_stay_disc_FL_and_CNM_hotelday);
			longstay_disc = hotelratecancum;
		}
		else
		{
			cost_hotel = hotelratecancum * no_ofdaysstay;
		}
	
	}

	// destination is Texas
	if (destination == "t" || destination == "T")
	{
		destination = "Texas";
		cost_hotel = no_ofdaysstay * hotelratetexas;
		// if stay is longer than 5 days
		if (no_ofdaysstay > 6)
		{
			longstay_disc = airfaretexas * long_stay_disc_TX_and_BHMS_airfare;
			cost_airfare = airfaretexas - longstay_disc;
		}
		else
		{
			cost_airfare = airfaretexas;
		}
			
	}

	// destination is Bahamas
	if (destination == "b" || destination == "B")
	{
		destination = "Bahamas";
		cost_hotel = no_ofdaysstay * hotelratebahamas;
		// if stay is longer than 5 days
		if (no_ofdaysstay > 6)
		{
			longstay_disc = airfarebahamas * long_stay_disc_TX_and_BHMS_airfare;
			cost_airfare = airfarebahamas - longstay_disc;
		}
		else
		{
			cost_airfare = airfarebahamas;
		}
	}
	
	final_bill = cost_hotel + cost_airfare;

	// to calculate early signup disc
	if (weeksinadv < 5)
		earlysignup_disc = (final_bill * one_4week);
	else if (weeksinadv < 7)
		earlysignup_disc = (final_bill * five_6week);
	else if (weeksinadv < 10)
		earlysignup_disc = (final_bill * seven_9week);
	else
	{
		earlysignup_disc = (final_bill * ten_plusweek);
	}
		
	final_bill = cost_hotel + cost_airfare - earlysignup_disc;

	//Output Section
	cout << fixed << showpoint << setprecision(2);
	cout << "==============================================" << endl;
	cout << "==============================================" << endl;
	cout << "            Holiday Travel Agency" << endl;
	cout << "                Customer Bill" << endl;
	cout << "Destination:               " << destination << endl;
	cout << "Number of weeks to go:     " << weeksinadv << endl;
	cout << "Number of Days to Stay:    " << no_ofdaysstay << endl;
	cout << endl;
	cout << "Cost of Hotel:              $" << setw(7) << cost_hotel << endl;
	cout << "Cost of Airfare:            $" << setw(7) << cost_airfare << endl;
	cout << "Longer Stay Discount:       $" << setw(7) << longstay_disc << endl;
	cout << "Early Signup Discount:      $" << setw(7) << earlysignup_disc << endl;
	cout << endl;
	cout << "Final Bill:                 $" << setw(7) << final_bill << endl;
	cout << "==============================================" << endl;
	cout << "==============================================" << endl;

	system("pause");
	return 0;
}