#pragma once
#ifndef _WORKER
#define _WORKER
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
class worker
{
protected:
	string name;
	int id;
	string password;
	int level;
public:
	worker();
	worker(string name, int id, int level, string password);
	void getid_worker()const;//retrn id
	int get_level();
	string get_name();
	string get_password();
	void print();
	~worker();
};
#endif // !WORKER