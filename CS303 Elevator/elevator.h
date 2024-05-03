#pragma once

#include "Doubly_List.h"
#include <string>
#include <iostream>
using namespace std;

class elevator {
private:
	int floor = 0;
	int target = 0;
	string direction = "\0";
	char id = '\0';
public:
	elevator();
	elevator(int f, string d);
	elevator(int f, string d, char i);

	void target_floor(Doubly_List list);
	void move(Doubly_List list);
	void print();
};