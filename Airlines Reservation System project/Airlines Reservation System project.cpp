// Airline Reservation System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Database.h"



using namespace std;
using namespace AirlineReservationSystem;

int Administrator(Database& db);
int displayMenu();
void doBooked(Database& db);
void install(Database& db);
void doCancelFlight(Database& db);
void doFlightDetail(Database& db);
void doDispayTicket(Database& db);



int main()

{

	Database PassengerDB;
	Database FlightDB;

	while (true) {
		int selection = displayMenu();
		switch (selection) {
		case 0:
			return 0;
		case 1:
			FlightDB.displayAllFlight();
			break;
		case 2:
			doBooked(PassengerDB);
			break;
		case 3:
			doCancelFlight(PassengerDB);
			break;
		case 4:
			PassengerDB.displayAllPassenger();
			break;
		case 5:
			doFlightDetail(FlightDB);
			break;
		case 6:
			doDispayTicket(PassengerDB);
			break;

			break;
		case 9:
			Administrator(FlightDB);
			break;
		default:
			cerr << "Unknown command." << endl;
			break;
		}
	}
	return 0;
}

int displayMenu()
{

	int selection;
	cout << "\n\n\n\t\t\t\t\t\t\t\t9. Administrator Login \n";
	cout << "\n\t\t*********************************************************************\n";
	cout << "\t\t..............Welcome to the Selam Airline Services ............\n";
	cout << "\t\t....................Customer Airline Reservation ...............\n\n";

	cout << "\t\t*********************************************************************\n\n";
	cout << "\t\t\tPlease pick an option from the menu below. \n\n";
	cout << "\t\t\t\t1. Flight Schedule \n";
	cout << "\t\t\t\t2. Flight Booking \n";
	cout << "\t\t\t\t3. Cancel reservation \n";
	cout << "\t\t\t\t4. Display passenger info \n";
	cout << "\t\t\t\t5. Display flight details \n";
	cout << "\t\t\t\t6. Display user Ticket Information \n";
	cout << "\t\t\t\t0. Exit \n";
	cout << "\t\t \n\n";

	cout << endl;
	cout << "\t\t\t---> ";

	cin >> selection;

	return selection;


}


void install(Database& db)
{
	Database FlightDB;
	int FlightNumber;
	string departureTime;
	string arrivalTime;
	string startingFrom;
	string to;
	string FlightDate;
	double NewCost;
	string FlightName;


	cout << endl;

	cout << "\nEnter Flight Name: ";
	cin >> FlightName;
	cout << "\nEnter Flight Number: ";
	cin >> FlightNumber;
	cout << "\nEnter Departure Time: ";
	cin >> departureTime;
	cout << "\nEnter Arrival Time:  ";
	cin >> arrivalTime;
	cout << "\nEnter starting From:  ";
	cin >> startingFrom;
	cout << "\nEnter Destination:  ";
	cin >> to;
	cout << "\nEnter Flight Date (mm/dd/yyy):  ";
	cin >> FlightDate;
	cout << "\nEnter Flight Cost: $ ";
	cin >> NewCost;

	db.addFlight(FlightNumber, departureTime, arrivalTime, startingFrom, to, FlightDate, FlightName, NewCost);

	system("CLS");

	cout << "\n\n\n\t\t ----- Data Added on Available Flight List. -------- ";
}


void doBooked(Database& db)


{
	string FirstName;
	string LastName;
	string PhoneNumber;
	int passportNumber;
	int FlightNumber;


	cout << "Enter your First Name?  ";
	cin >> FirstName;
	cout << "Enter Your Last Name?  ";
	cin >> LastName;
	cout << "Enter your Phone NUmber?  ";
	cin >> PhoneNumber;
	cout << "Enter Your Passport Number?  ";
	cin >> passportNumber;
	cout << "Enter Your Flight Number?  ";
	cin >> FlightNumber;

	system("CLS");

	cout << "\n\n\n\t\t Thank you for using our service  ";
	cout << "\n\t\t -----You are Booked!! -------- ";

	db.addPassenger(FirstName, LastName, PhoneNumber, passportNumber, FlightNumber);
}



void doCancelFlight(Database& db)
{
	int PassportNumber;

	cout << "Passport Number? ";
	cin >> PassportNumber;

	try {
		Passenger& pas = db.getPassenger(PassportNumber);
		pas.CancelFlight();
		cout << "Passenger " << PassportNumber << " canceled flight." << endl;
	}
	catch (const std::logic_error& exception) {
		cerr << "Unable to cancel Flight: " << exception.what() << endl;
	}

}
void doFlightDetail(Database& db)
{
	string startingFrom;
	string	to;
	string	FlightDate;


	cout << "\n\n\t\t\tFrom  : ";
	cin >> startingFrom;
	cout << "\n\t\t\tWhere to  : ";
	cin >> to;
	cout << "\n\t\tFlight Date (mm/dd/yyyy)  : ";
	cin >> FlightDate;

	try {
		Flight& Fly = db.getFlight(startingFrom, to, FlightDate);
		Fly.FlightRecord();

	}
	catch (const std::logic_error& exception) {
		cerr << "\n\n\t\tSorry on the given Date : " << exception.what() << endl;
	}

}
void doDispayTicket(Database& db)
{
	int PassportNumber;

	cout << "Passport Number? ";
	cin >> PassportNumber;

	try {
		Passenger& pas = db.getPassenger(PassportNumber);
		pas.display();
		cout << "\n\t\t\tPassenger " << PassportNumber << " Ticket Information." << endl;
	}
	catch (const std::logic_error& exception) {
		cerr << "\n\t\t\t Search Complited  : " << exception.what() << endl;
	}

}


int Administrator(Database& db)
{
	Database FlightDB;

	string username = "";
	int	password;
	bool loginSuccess = false;
	cout << "\t\t\t\t\t************************************* \n";
	cout << "\t\t\t\t\t Administrator Login \n";
	cout << "\t\t\t\t\t************************************* \n";
	do {
		cout << "\t\t\t\t\t hit UserName:- admin  Password:- 1234\n";
		cout << "\t\t\t\t\t\t Username   : ";
		cin >> username;
		cout << "\t\t\t\t\t\t Password   : ";
		cin >> password;

		cout << "\t\t\t\t\t************************************* \n\n";
		if (username == "admin" && password == 1234) {
			Database FlightDB;

			int FlightNumber;
			string departureTime;
			string arrivalTime;
			string startingFrom;
			string to;
			string FlightDate;
			double NewCost;
			string FlightName;


			cout << endl;
			cout << "\n=== Enter Flight status and information === \n\n";
			cout << "\nEnter Flight Name: ";
			cin >> FlightName;
			cout << "\nEnter Flight Number: ";
			cin >> FlightNumber;
			cout << "\nEnter Departure Time: ";
			cin >> departureTime;
			cout << "\nEnter Arrival Time:  ";
			cin >> arrivalTime;
			cout << "\nEnter starting From:  ";
			cin >> startingFrom;
			cout << "\nEnter Destination:  ";
			cin >> to;
			cout << "\nEnter Flight Date:  ";
			cin >> FlightDate;
			cout << "\nEnter Flight Cost:  ";
			cin >> NewCost;

			db.addFlight(FlightNumber, departureTime, arrivalTime, startingFrom, to, FlightDate, FlightName, NewCost);

			system("CLS");

			cout << "\n\n\n\t\t ----- Data Added on Available Flight List. -------- ";
		}
		else {
			cout << "Incorrect username and password";
		}
	} while (loginSuccess = false);
	return 0;
}


