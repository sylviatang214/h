#pragma once

#include <string>
#include <iostream>
using namespace std;

class node {
public:
	node* next = nullptr;
	node* prev = nullptr;

	string direction = "\0";
	char id = '\0'; //id of elevator that can answer calls
	int floor = 0;
};

class Doubly_List {
private:
	node* headPtr;
	node* tailPtr;
public:

	Doubly_List();

	void insert(int i, int floor, string direction);
	void print();
	bool empty();
	void push_front(node* tempNode);
	void push_back(node* tempNode);
	void sort();
	void pop(int floor, string direction);

	int stop(int f, string d, char i);
};