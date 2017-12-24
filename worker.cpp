#include "worker.h"

worker::worker()
{
	name = "unkmown";
	id = 0000;
	//level = 0;
	password = "";
}

worker::worker(string name, int id, int level, string password)
{
	this->name = name;
	this->id = id;
	this->level = level;
	this->password = password;
}

worker::~worker()
{
}

void worker::getid_worker()const
{
	cout<<(this->id);
}

int worker::get_level()
{
	return this->level;
}

string worker::get_name()
{
	return this->name;
}

string worker::get_password()
{
	return this->password;
}

void worker::print()
{
	cout << "the worker is-\n";
	cout << this->name;
	cout << this->id;
	cout << "his level-" << this->level;
}
