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
	int level;
public:
	worker();
	worker(string name, int id, int precent);
	void getid_worker()const;//retrn id
	void get_level();
	void print();
	~worker();
};
#endif // !WORKER