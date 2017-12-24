#ifndef _manew
#define _manew

#include <typeinfo>
#include <string>
#include <iostream>
#include <fstream>
#include "worker.h"
#include "fruit.h"
#include "status.h"
void addWorker();
void checkFruits();
void initializeWorkers(worker **workersList); //Set the workers
bool checkLogin();
void printSum();

// Global vars
worker currentLoggedWorker;
worker **workers = new worker*[10];
int numOfWorkers;
fruit **fruits = new fruit*[5];
int numOfFruits = 0;

void main()
{
	// Variables
	initializeWorkers(workers);
	int choice;

	// Print introduction
	cout << "Welcome to Perutov! the best fruit sorter in the world." << endl;
	
	// Check login and start main program if login succeed
	if (checkLogin())
	{
		do {
			system("Color 1A");
			cout << "***********************************" << endl;
			cout << "Welcome to Perutov! the best fruit sorter in the world." << endl;
			cout << "1-check fruits " << endl;
			if (currentLoggedWorker.get_level() == 2)
			{
				cout << "2-add emoplye " << endl;
			}
			cout << "3-print sum  " << endl;
			cout << "5-exit" << endl;
			cin >> choice;
			switch (choice) {
			case 1:
				checkFruits();
				break;
			case 2:
				if (currentLoggedWorker.get_level() == 2)
				{
					addWorker();
				}
				break;
			case 3:
				printSum();
				break;
			case 5:
				break;
			default: 
				cout << endl << "wrong choice. please chose again:" << endl;
				system("cls");
			}
		} while (choice != 5);
	}

	// End program
	system("cls");
	cout << "***********************************" << endl;
	cout << "have a nice day from Perutov(C) team! :)\n";
}
#endif // !_manew

void initializeWorkers(worker **workersList)
{
	workersList[0] = new worker("Bar", 204590384, 2, "1234");
	workersList[1] = new worker("Ginadi", 123456789, 0, "1234");
	workersList[2] = new worker("Ilan", 439203984, 1, "abc");
	
	// Update num of workers
	numOfWorkers = 3;
}

bool checkLogin()
{
	bool loginSuccess = false;
	string user;
	string password;
	string choice;

	while (!loginSuccess) // Change to TRUE!!!
	{
		cout << "Please enter your user name:" << endl;
		cin >> user;
		cout << "Please enter your Password:" << endl;
		cin >> password;

		// Get over all the workers
		for (int currentWorkerIndex = 0; currentWorkerIndex < numOfWorkers; currentWorkerIndex++)
		{
			if (workers[currentWorkerIndex]->get_name() == user && workers[currentWorkerIndex]->get_password() == password)
			{
				// Update the current user logged to the system
				currentLoggedWorker = *workers[currentWorkerIndex];

				loginSuccess = true;
				cout << "Login succeed!" << endl;
				//Sleep(400);
				system("cls");
				break;
			}
		}

		if (loginSuccess == false)
		{
			cout << "No user found/ Password incorrect." << endl;
			cout << "Do you wish to try again?" << endl;
			cin >> choice;
			if (choice == "no" || choice == "NO" || choice == "No")
			{
				break;
			}
		}
	}

	return loginSuccess;
}

void checkFruits()
{
	// Vars
	string filePath;
	string goodColour;
	string badColour;
	ifstream FS;

	while (true)
	{
		// Get fruit stats path
		cout << "Please enter the fruit status file name:" << endl;
		cin >> filePath;

		// Check if user wish to exit
		if (filePath == "exit" || filePath == "Exit" || filePath == "EXIT" || filePath == "5")
		{
			system("cls");
			break;
		}

		// Read the file
		FS.open(filePath + ".txt");

		// Check if succeed open
		if (!FS.is_open())
		{
			cout << "Can't open the file. please try again" << endl;
			cin >> filePath;
			system("cls");
			break;
		}

		// Save the relevant lines
		getline(FS, goodColour); // Save the good colour parameter
		getline(FS, badColour); // Save the bad colour parameter

		// Init instance of the fruit object
		fruits[numOfFruits] = new fruit(filePath, 1, "", atoi(goodColour.c_str()), atoi(badColour.c_str()));
		fruits[numOfFruits]->get_status();
		
		// Print current fruit parameters
		cout << "The good color percents is: " + goodColour + "." << endl;
		cout << "The bad color percents is: " + badColour << endl << endl;

		FS.close();

		// Update num of fruits sorted since system is up
		numOfFruits++;
	}

	// Needed?
	//system ("pause");
}

void addWorker()
{
	string name, password;
	int id, level;

	cout << "plese enter the name of the new worker:\n";
	cin >> name;
	cout << "plese enter an id:\n";
	cin >> id;
	cout << "please enter a password\n";
	cin >> password;
	cout << "plese enter the worker level (0-regula worker, 1-manager, 2-system admin)\n";
	cin >> level;

	workers[numOfWorkers] = new worker(name, id, level, password);

	// Update num of workers
	numOfWorkers++;
}

void printSum()
{
	// Vars
	int sumOfA = 0;
	int sumOfB = 0;
	int sumOfC = 0;
	int sumOfD = 0;

	// Calc the number of fruits suited for each quality rank which sorted today
	for (int currentFruitIndex = 0; currentFruitIndex < numOfFruits; currentFruitIndex++)
	{
		if (fruits[currentFruitIndex]->get_fruit_status_sum() == "A")
		{
			sumOfA++;
		}
		if (fruits[currentFruitIndex]->get_fruit_status_sum() == "B")
		{
			sumOfB++;
		}
		if (fruits[currentFruitIndex]->get_fruit_status_sum() == "C")
		{
			sumOfC++;
		}
		if (fruits[currentFruitIndex]->get_fruit_status_sum() == "D")
		{
			sumOfD++;
		}
	}

	// Clear screen and print intro for user
	system("cls");
	cout << "The sumnery for today is:" << endl;

	if (numOfFruits > 0)
	{
		// print summery info
		cout << "Totally " << numOfFruits;
		cout << " fruits was sorted." << endl;

		cout << "the division of the fruits sorted is:" << endl;
		if (sumOfA > 0)
		{
			cout << sumOfA << " Total A class fruits." << endl;
		}
		if (sumOfB > 0)
		{
			cout << sumOfB << " Total B class fruits." << endl;
		}
		if (sumOfC > 0)
		{
			cout << sumOfC << " Total C class fruits." << endl;
		}
		if (sumOfD > 0)
		{
			cout << sumOfD << " Total D class fruits." << endl;
		}
	}
	else
	{
		cout << "No fruits were sorted today." << endl;
	}

	// Delay the return to the main menu
	cout << endl << endl << "Press any key to return to the main menu" << endl;
	string temp;
	cin >> temp;
	system("cls");
}