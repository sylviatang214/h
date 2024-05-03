#include "Doubly_List.h"
#include "elevator.h"
#include <vector>

int main() {
	Doubly_List list_A;

	list_A.insert(0, 1, "up");
	list_A.insert(1, 2, "down");
	list_A.insert(2, 4, "down");
	list_A.insert(3, 5, "up");
	list_A.insert(4, 6, "down");
	list_A.insert(5, 8, "up");
	list_A.insert(6, 9, "down");
	list_A.insert(7, 11, "down");


	list_A.print();


	list_A.sort();

	list_A.print();

	vector<elevator> vect_elevator;

	elevator A (10, "down", 'A');
	elevator B (2, "up", 'B');
	elevator C (5, "up", 'C');
	vect_elevator.push_back(A);
	vect_elevator.push_back(B);
	vect_elevator.push_back(C);

	for (int x = 0; x < 20; x++) {
		for (int i = 0; i < vect_elevator.size(); i++) {
			vect_elevator[i].move(list_A);
			vect_elevator[i].print();
		}
		list_A.print();
		cout << endl << endl;
	}
	//creates multiple elevator
	// every tick, call move function
	//A.stop(Doubly_List list_A);


}