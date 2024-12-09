#include<iostream>
using namespace std;
//global variables
string choice;
string inv[5];
int main() {
	int room = 1;

	cout << "Welcome to the text based game!" << endl;
	do {
		switch (room) {
		case 1:
			system("color 82");
			cout << "You are in  (n)orth" << endl;
			cin >> choice;
			if (choice == "north")
				room = 2;
			break;
		case 2:
			if (inv[0] != "axe") {
				if (inv[0] != "bow") {
					cout << "You find a axe and a bow you can only pick one" << endl;

				}
			}
			cout << "You are in room 2 you can go (e)ast or (s)outh" << endl;
			cin >> choice;
			if (choice == "east")
				room = 3;
			else if (choice == "south")
				room = 1;
			else if (choice == "axe")
				inv[0] = "axe";
			else if (choice == "bow")
				inv[0] = "bow";
				break;
		case 3:
			cout << "you are in room 3 you can go (e)ast or (w)est" << endl;
			cin >> choice;
			if (choice == "east")
				room = 4;
			else if (choice == "west")
				break;
		case 4:
			cout << "You are in room 4 you can go (s)outh or (w)est" << endl;
			cin >> choice;
			if (choice == "south")
				room = 5;
			else if (choice == "west")
				break;
		case 5:
			cout << "You are in room 5 you can go (e)ast or (s)outh" << endl;
			cin >> choice;
			if (choice == "east")
				room = 7;
			else if (choice == "s")
				room = 6;
			break;
		case 6:
			cout << "You are in 6 you can go (n)orth" << endl;
			cin >> choice;
			if (choice == "north")
				room = 5;
			break;
		case 7:
			cout << "You are in 7 you can go (w)est or (e)ast" << endl;
			cin >> choice;
			if (choice == "east")
				room = 8;
			else if (choice == "west")
				break;
		case 8:
			cout << "You are in 8 you can go (s)outh or (w)est" << endl;
			cin >> choice;
			if (choice == "south")
				room = 9;
			else if (choice == "west")
				room = 7;
			break;
		case 9:
			cout << "You are in 9 you can go (n)orth or (e)ast" << endl;
			cin >> choice;
			if (choice == "east")
				room = 10;
			else if (choice == "north")
				room = 8;
			break;
		case 10:
			cout << "You are in room 10 you can go (w)est" << endl;
			cin >> choice;
			if (choice == "west")
				room = 9;
			break;

		}
	} while (choice != "quit"); //end game loop
}
