#include "Doubly_List.h"

Doubly_List::Doubly_List() {
	headPtr = nullptr;
	tailPtr = nullptr;
}


bool Doubly_List::empty() {
	return (headPtr == nullptr);

}
void Doubly_List::pop(int floor, string direction) {
	node* tempNode = headPtr;

	while(tempNode->next != nullptr) {
		if (tempNode->floor == floor && tempNode->direction == direction) { // if node to pop is found
			if (headPtr == tailPtr) { // if only one node exists
				headPtr = nullptr;
				tailPtr = nullptr;
				delete tempNode;
			}
			else if (tempNode == headPtr) { // headPtr case
				cout << "+++++++++++++++++++++++++++++++++++++++++++++\n";
				headPtr = tempNode->next;
				cout << "{}{}{}{}{}{}}{}{}{}{}{}{}{}{}{}{}{} " << headPtr->floor << "\n";
				tempNode->next->prev = nullptr;
				delete tempNode;
				return;
			}
			else { //pop for other cases
				tempNode->prev->next = tempNode->next;
				tempNode->next->prev = tempNode->prev;
				delete tempNode;
				return;
			}
		}
		tempNode = tempNode->next; //traverse
	}
	if (tempNode == tailPtr) { // tailPtr case ------ new code, figuring out why headPtr is not permanently 11
		if (headPtr == tailPtr) {
			headPtr = nullptr;
			tailPtr = nullptr;
		}
		else {
			tailPtr = tempNode->prev;
		}
		tempNode->prev->next = nullptr;
		delete tempNode;
		return;
	}
}
void Doubly_List::push_front(node* tempNode) {

	if (headPtr == nullptr) { //if list is empty, set headprt and tailptr as frontNode 
		headPtr = tempNode;
		tailPtr = tempNode;
	}
	else { // add to front
		tempNode->next = headPtr;
		headPtr->prev = tempNode;
		headPtr = tempNode;
	}
}

void Doubly_List::push_back(node* tempNode) {

	if (headPtr == nullptr) { //if list is empty, set headptr and tailptr as backNode 
		headPtr = tempNode;
		tailPtr = tempNode;
	}
	else { // push to back
		tailPtr->next = tempNode;
		tempNode->prev = tailPtr;
		tailPtr = tempNode;
	}
}

void Doubly_List::insert(int input, int floor, string direction) {
	node* insertNode = new node;

	insertNode->floor = floor;
	insertNode->direction = direction;

	if (empty() || input == 0) {
		push_front(insertNode);
	}
	else if (input == 1) {
		node* tempPtr = headPtr;
		if (headPtr == tailPtr) {
			tailPtr = insertNode;
		}
		else {
			tempPtr->next->next = insertNode;
		}
		tempPtr->next = insertNode;
		insertNode->prev = tempPtr;



	}
	else {
		node* tempPtr = headPtr;   //let tempNode be headptr
		//node* insertNode = new node;

		node* prevPtr;
		node* nextPtr;

		//move tempNode to position input
		for (int i = 0; i < input; i++) {
			tempPtr = tempPtr->next;
			if (tempPtr == nullptr)
				break;
		}

		if (tempPtr == nullptr) {
			push_back(insertNode);
		}
		else {
			//assign floor and direction to insertNode
			insertNode->floor = floor;
			insertNode->direction = direction;

			nextPtr = tempPtr;        //assign tempNode position to nextNode
			prevPtr = tempPtr->prev;  //point prevNode to tempNode

			//put insertNode between next and prev nodes
			insertNode->next = nextPtr;
			insertNode->prev = prevPtr;
			//insertNode = tempPtr;
			//insertNode->prev = tempPtr->prev;
			//insertNode->next = tempPtr->next;

			//change prev and next node to point to insert node
			prevPtr->next = insertNode;
			nextPtr->prev = insertNode;
		}

	}


}

void Doubly_List::print() {
	if (empty()) {
		cout << "Empty list" << endl;
	}
	else {
		node* tempPtr = headPtr;
		cout << "List: " << endl;
		while (tempPtr != nullptr) {
			cout << tempPtr->floor << " ";
			tempPtr = tempPtr->next;
		}
		tempPtr = tailPtr;
		cout << endl;
		while (tempPtr != nullptr) {
			cout << tempPtr->floor << " ";
			tempPtr = tempPtr->prev;
		}
	}

	cout << "\n\n";

}

void Doubly_List::sort() {
	//sort by floors and DIRECTION
	node* current = headPtr;
	node* nextPtr = current->next;
	bool sorted = false;

	//going up
	//while not sorted ==============================================
	// sorted = true;
	while (sorted == false) {
		sorted = true;
		current = headPtr;
		nextPtr = current->next;
		while (nextPtr != nullptr) {
			cout << "end of list check" << endl;
			while (nextPtr != nullptr && current->floor <= nextPtr->floor) { // traversing if already sorted
				current = nextPtr;
				nextPtr = current->next;
				cout << "traversing" << endl;
			}

			while (nextPtr != nullptr && current->floor > nextPtr->floor) {
				//if enters loop: sorted = false ================================================
				sorted = false;
				cout << "run while" << endl;
				if (current->prev != nullptr) { //if prev exists
					current->prev->next = nextPtr;
					nextPtr->prev = current->prev;
					cout << "aaaaaaaaaaaaaa" << endl;
				}
				if (current->next != nullptr) { //if nextptr exists
					if (nextPtr->next != nullptr) { //if nextptr next exists
						nextPtr->next->prev = current;
					}
					else { // if current is at end of list, make it tailptr
						tailPtr = current;
					}

					current->next = nextPtr->next;
					cout << "bbbbbbbbbbbb" << endl;
				}
				//sort
				nextPtr->next = current;
				//cout << "[[[ " << current->prev->floor << "\n";
				current->prev = nextPtr;
				//cout << "[[[ " << current->prev->floor << "\n";

				print();
				cout << "current: " << current->floor << endl;
				cout << "next: " << nextPtr->floor << endl;

				nextPtr = current->next;
				cout << "\nnew next: " << nextPtr->floor << endl;
				system("pause");

			}
			system("pause");
		}
	}
}



int Doubly_List::stop(int f, string d, char i) {
	if (empty()) {
		return f;
	}
	else if (headPtr == tailPtr) {
		cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
		int temp = headPtr->floor; //stores target floor
		pop(headPtr->floor, headPtr->direction); //remove target from linked list
		return temp;
	}

	cout << "[[[[[[[[[[[[[ " << headPtr->floor << "\n";
	cout << "[[[[[[[[[[[[[ " << tailPtr->floor << "\n";

	node* tempPtr = headPtr; //move until overshoots floor
	while (tempPtr != nullptr && ((tempPtr->floor < f && d == "up") || (tempPtr->floor >f && d == "down"))) {
		tempPtr = tempPtr->next;
	}

	if (tempPtr == nullptr) {
		tempPtr = tailPtr;
	}
	else if (d == "down" && tempPtr->prev != nullptr) {
		tempPtr = tempPtr->prev;
	}
	

	bool go_up;
	if (d == "up") {
		//cout << "1###########################" << endl;
		go_up = true;
	}
	else {
		//cout << "2###########################" << endl;
		go_up = false;
	}

	if (tempPtr == nullptr) { cout << "\nAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n"; }
	while (true) {
		cout << "3###########################" << endl;
		while (go_up == true) {
			cout << "4###########################" << endl;
			if (((tempPtr->direction == "up" && go_up == true) || (tempPtr == tailPtr && tempPtr->prev->prev == nullptr)) || (tempPtr->id == i )) { //if pickup or dropoff
				cout << "5a###########################" << endl;
				//if (tempPtr->direction == "up" && tempPtr->floor >= f) {
				if (tempPtr->floor >= f) { //up case
					cout << "5b###########################" << endl;
					int temp = tempPtr->floor; //stores target floor
					pop(tempPtr->floor, tempPtr->direction); //remove target from linked list
					return temp; //returns target floor
				}
			}
			if (tempPtr == tailPtr) { go_up = false; break; }
			tempPtr = tempPtr->next; //traverse
		}
		while (go_up == false) {
			cout << "6###########################" << endl;
			if (((tempPtr->direction == "down" && go_up == false) || (tempPtr == headPtr && tempPtr->next->next == nullptr)) || (tempPtr->id == i )) { //if pickup or dropoff
				cout << "7a###########################" << endl;
				//if (tempPtr->direction == "down" && tempPtr->floor <= f) {
				if (tempPtr->floor <= f) {  //down case
					cout << "7b###########################" << endl;
					int temp = tempPtr->floor; //stores target floor
					pop(tempPtr->floor, tempPtr->direction); //remove target from linked list
					return temp; //returns target floor
				}
			}
			cout << "8###########################" << endl;
			if (tempPtr == headPtr) { go_up = true; break; }
			tempPtr = tempPtr->prev; //traverse
		}
		system("pause");
	}
}