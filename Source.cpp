#ifndef _manew
#define _manew

#include <typeinfo>
#include <string>
#include "worker.h"
void add_worker();

void main()
{
	//*arr=NULL;
	int num;
	int choice;
	do {
		cout << endl << endl << "***********************************" << endl;
		cout << "Choose the opption: " << endl;
		cout << "1-add worker " << endl;
		cout << "2-add_emoplye " << endl;
		cout << "3-shoping  " << endl;
		cout << "4-ruturn iteam " << endl;
		cout << "5-print_chain" << endl;
		cout << "6-sum salris store  " << endl;
		cout << "7-sum salris shop   " << endl;
		cout << "8-print shop " << endl;
		cout << "9-print employe  " << endl;
		cout << "10-exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1: 
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		default: cout << endl << "wrong choice chose agein" << endl;
		}
	} while (choice != 10);
	cout << "have a nice day\n";
}
#endif // !_manew

void add_worker()
{
	string name;
	int id, id_store, level;
	char sog_employe;
	cout << "plese enter the name of the new worker\n";
	cin >> name;
	cout << "plese enter is id \n";
	cin >> id;
	cout << "plese enter 1 FOR MANGE 2\n";
	cin >> sog_employe;
	cout << "plese enter the precent of the job \n";
	//*arr[x]->add_worker(name, id, level);
}
