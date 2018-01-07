#ifndef _manew
#define _manew
using namespace std;
#include <typeinfo>
#include <string>
#include <iostream>
#include <fstream>
#include "worker.h"
//#include "fruit.h"
//#include "status.h"
void addWorker();
void checkFruits();
void initializeWorkers(worker **workersList); //Set the workers
bool checkLogin();
void printSum();
void what_fruit();
string quality(int, int, int);
void clean_day();//restert the systerm
void print_all_workers();
void  print_introdction();

				 // Global vars
worker currentLoggedWorker;
worker **workers = new worker*[10];
int numOfWorkers;
//fruit **fruits = new fruit*[5];
int numOfFruits = 0;
//global sums
int sumOfA = 0;
int sumOfB = 0;
int sumOfC = 0;
//int sumOfD = 0;
int black1 = 0;
int gray1 = 0;
int white1 = 0;
int flag = 0;
void main()
{
	// Variables
	initializeWorkers(workers);//include useres
	int choice;
	// Print introduction
	cout << "Welcome to Perutov! the best fruit sorter in the world." << endl;
	// Check login and start main program if login succeed
	if (checkLogin())
	{
		do {
			system("Color 1A");//colur blue
			cout << "***********************************" << endl;
			if (flag == 0)
			{
				what_fruit();
				flag++;
			}
			cout << "Welcome to Perutov! the best fruit sorter in the world." << endl;
			cout << "1-check fruits " << endl;
			if (currentLoggedWorker.get_level() == 2)
			{
				cout << "2-add employee " << endl;
			}
			cout << "3-print sum  " << endl;
			cout << "4-exit" << endl;
			cout << "5-clean all day and start new one" << endl;;
			//cout << "6- print all workers" 
			if (currentLoggedWorker.get_level() == 2)
			{
			cout << "6- print all workers" << endl;
			}
			cout << "7-genrel information" << endl;
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
			case 4:
				break;
			case 5:clean_day();
				break;
			case 6: 
				if (currentLoggedWorker.get_level() == 2)
				{
					print_all_workers();
				}
			case 7:print_introdction();
				break;
			default:
				cout << endl << "wrong choice. please chose again:" << endl;
				system("cls");
			}
		} while (choice != 4);
	}
	// End program
	system("cls");
	cout << "***********************************" << endl;
	cout << "have a nice day from Perutov(C) team! :)\n";
}
#endif // !_manew

void initializeWorkers(worker **workersList)//ontalizion users
{
	workersList[0] = new worker("Bar", 204590384, 2, "1234");
	workersList[1] = new worker("Ginadi", 123456789, 0, "1234");
	workersList[2] = new worker("Ilan", 439203984, 1, "abc");
	workersList[3] = new worker("a", 123456789, 2, "a");


	// Update num of workers
	numOfWorkers = 4;
}
bool checkLogin()//enter the system
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
	string black_color;
	string gray_color;
	string white_color;
	ifstream FS;
	int  fruit33[3];
	while (true)
	{
		// Get fruit stats path
		cout << "Please enter:" << endl;
		cout << "to exit press 911 else enter 1 to scan next fruit" << endl;
		cin >> filePath;
		if (filePath == "911")
		{
			system("cls");
			return;
		}
		else
			filePath = "report";
		// Check if user wish to exit
		if (filePath == "exit" || filePath == "Exit" || filePath == "EXIT" || filePath == "5")
		{
			system("cls");
			return;
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
		while (!FS.eof()) {
			// Save the relevant lines
			getline(FS, black_color); // Save the good colour parameter
			getline(FS, gray_color); // Save the bad colour parameter
			getline(FS, white_color);

			// Init instance of the fruit object
			fruit33[0] = (filePath, 1, atoi(black_color.c_str()));
			fruit33[1] = (filePath, 1, atoi(gray_color.c_str()));
			fruit33[2] = (filePath, 1, atoi(white_color.c_str()));
			//fruits[numOfFruits]->get_status();
			// Print current fruit parameters
			cout << "Fruit number " << numOfFruits + 1 << ":" << endl;
			cout << "Black: " + black_color << ", ";
			cout << "Gray: " + gray_color << ", ";
			cout << "White: " + white_color << endl;
			cout << quality(fruit33[0], fruit33[1], fruit33[2]) << endl;
			//cout << "enter 1 for the next fruit" << endl << endl;


			// Update num of fruits sorted since system is up
			numOfFruits++;
		}
		FS.close();
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
	cout << "plese enter the worker level (0-regular worker, 1-manager, 2-system admin)\n";
	cin >> level;

	workers[numOfWorkers] = new worker(name, id, level, password);

	// Update num of workers
	numOfWorkers++;
}
void printSum()
{
	// Clear screen and print intro for user
	system("cls");
	cout << "The summery for today is:" << endl;

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
	}
	else
		cout << "No fruits were sorted today." << endl;
	// Delay the return to the main menu
	cout << endl << endl << "Press any key to return to the main menu" << endl;
	string temp;
	cin >> temp;
	system("cls");
}
void what_fruit()
{
	cout << "plese select your fruit you want check today\n";
	cout << "1-avokado ";
	cout << "2 malon ";
	cout << "3 apple ";
	cout << "\n";
	int a;
	cin >> a;
	if (a == 1)
	{
		black1 = 1853;
		gray1 = 1236;
		white1 = 2789;
	}
	if (a == 2)
	{
		black1 = 0;
		gray1 = 0;
		white1 = 0;
	}
	if (a == 3)
	{
		black1 = 0;
		gray1 = 0;
		white1 = 0;
	}
}
string quality(int b, int g, int w)
{
	if (b - black1 >= 1800 && b - black1 <= 2100) {
		sumOfA++;
		return ("Good fruit!\n");
	}
	if (b - black1 <= 1000 || b - black1 >= 2101) {
		sumOfB++;
		return ("Medium fruit!\n");
	}
	else {
		sumOfC++;
		return ("Bad fruit!\n");
	}
}
void clean_day()
{
	flag = 0;
	sumOfA = 0;
	sumOfB = 0;
	sumOfC = 0;
	numOfFruits = 0;
	cout << "the day has been deleted" << endl;
	cout << "a new start has arrived" << endl;
}
void print_all_workers()
{
	for (int i = 0; i < 1; i++)
	{
		cout << "worker : " << i+1<<endl;
		((*workers)[i]).print();
		//workers[i]->print;
	}
	cout << endl << endl << "Press any key to return to the main menu" << endl;
	string temp;
	cin >> temp;
	system("cls");
}

void print_introdction()
{
	system("cls");
	cout << "This project made in 2017 by 'Perotuv' company;" << endl << "In a course at sce second grade";
	cout << "thie project is in give you the sum of scaned fruit in the day \n";
	cout << "only an workers and mangers can acsses the progrem for help plese call 911\n";
	int i = 0;
	while (i<1000000000)
	{
		i++;
	}
	system("cls");
}
