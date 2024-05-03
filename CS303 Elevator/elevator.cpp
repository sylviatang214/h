#include "elevator.h"

elevator::elevator() {
	int floor = 0;
	int target = 0;
	string direction = "\0";
	char id = '\0';
}

elevator::elevator(int f, string d) {
	floor = f;
	target = f;
	direction = d;
}

elevator::elevator(int f, string d, char i) {
	floor = f;
	target = f;
	direction = d;
	id = i;
}

void elevator::target_floor(Doubly_List list) { //set elevator's target floor
	target = list.stop(floor, direction, id);

	if (floor < target) { //setting direction
		direction = "up";
	}
	else {
		direction = "down";
	}
}

void elevator::move(Doubly_List list){
	if (target == floor) {	//checks if target floor needs update
		target_floor(list);
	}
	else {
		if (direction == "up") {
			floor++;
		}
		else {
			floor--;
		}
	}
}

void elevator::print() {
	cout << "id: " << id << endl;
	cout << "target floor: " << target << endl;
	cout << "current floor: " << floor << endl;
}