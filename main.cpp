#include<iostream>
using namespace std;

int main() {
	int room = 1;
	string choice;

	cout << "Welcome to the text based game!" << endl;
	do {
		 switch (room) {
		 case 1:
			 cout << "You are in room 1. You can go (n)orth." << endl;
			 cin >> choice;
			 if (choice == "north")
				 room = 2;
				 break;
		 case 2:
			 cout << "You are in room 2 you can go (e)ast" << end;
			 cin >> choice;
			 if (choice == "east")
				 room = 3;
				 break;
		 case 3:
			 cout << "you are in room 3 you can go (e)ast" << endl;
			 cin >> choice;
             if (choice == "east")
				 room = 4;
			     break;
		 case 4:
			 cout << "You are in room 4 you can go (s)outh" << endl;
			 cin >> choice;
             if (choice == "south")
				 room = 5;
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

                 

    
