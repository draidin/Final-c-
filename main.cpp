#include<iostream>
using namespace std;
//global variables
string choice;
string inv[5];
int hp = 100;
int aura = 100;
void BattleSim();
void shop();
bool room3 = false;
int main() {
	srand(time(NULL));
	int room = 1;

	cout << "Welcome to the text based game!" << endl;
	while (hp > 0) {
		cout << endl;
		cout << "Inventory: ";
		for (int i = 0; i < 5; i++)
			cout << inv[i] << " | ";
		cout << endl << endl;
		switch (room) {
		case 1:
			system("color 07");
			cout << "You get out of a portal and you look around see a door you can go" << endl;
			cout << "(n)orth to go into the room " << endl;
			cin >> choice;
			if (choice == "north")
				room = 2;
			break;
		case 2:
			if (inv[0] != "axe") {
				if (inv[0] != "bow") {
					cout << "You enter the room and in the corner of youre eye you see a dead zombie with a" << endl;
					cout << "axe and bow but you can only pick one what will you pick?" << endl;
					cin >> choice;
					if (choice == "axe")
						inv[0] = "axe", cout << "You picked up the axe and the bow turned into ash" << endl;
					else if (choice == "bow")
						inv[0] = "bow", cout << "You picked up the bow and the axe flew away" << endl;
					break;
				}
			}
			cout << "You are in a dark creepy cold room the cold aura gives you the chills you want to leave" << endl;
			cout << "You can go (e)ast or (s)outh" << endl;
			cin >> choice;
			if (choice == "east")
				room = 3;
			else if (choice == "south")
				room = 1;
			break;
		case 3:
			system("color 47");
			if (room3 == false) {
				BattleSim();
				room3 = true;
			}
			cout << "You took some damage but you will live btw you got 500 AURA points for killing that zombie" << endl;
			cout << "Now you can go (e)ast or (w)est" << endl;
			cin >> choice;
			if (choice == "east")
				room = 4;
			else if (choice == "west")
				break;
		case 4:
			system("color 07");
			if (inv[2] != "sheild") {
				cout << "You are exploring the room looking for anything to help you escape" << endl;
				cout << "you see a skeleton with a sheild that you can use will you pick it up" << endl;
				cin >> choice;
				if (choice == "sheild")
					inv[2] = "sheild", cout << "You picked up the sheild." << endl;
				break;
			}
			cout << "You can go (s)outh or (w)est" << endl;
			cin >> choice;
			if (choice == "south")
				room = 5;
			else if (choice == "west")
				room = 3;
				break;
		case 5:
			cout << "You are in room 5 you can go (e)ast or (s)outh" << endl;
			cin >> choice;
			if (choice == "east")
				room = 7;
			else if (choice == "south")
				room = 6;
			break;
		case 6:
			if (inv[1] != "armor") {
				cout << "you are exploring the room when you look" << endl;
				cout << "in a cabinet and a skeleton falls out" << endl;
				cout << "It is wearing armor you can use it " << endl;
				cin >> choice;
				if (choice == "use")
					inv[1] = "armor";
				break;
			}
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
			shop();
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
	} if (hp <= 0)
		cout << "game over loser" << endl; //end game loop
}

// function definitions
void BattleSim() {
	int MonsterHealth = 20;
	int hit;
	int choice;
	int escape;
	cout << endl << "---------BATTLE----------" << endl;
	while (hp > 0 && MonsterHealth > 0) {
		// monster attack sequence
		if (inv[1] == "armor") {
			hit = rand() % 11 + 5; // monster does 5-15 dmg 
			cout << "The monster hits you and you take " << hit << " dmg" << endl;
			hp -= hit;

		}

		else if (inv[2] == "sheild") {
			hit = rand() % 11 + 5; // monster does 5-15 dmg 
			cout << "The monster hits you and you take " << hit << " dmg" << endl;
			hp -= hit;

		}

		else if (inv[1] == "armor") {
			if (inv[2] == "sheild") {
				hit = rand() % 6 + 5; // monster does 5-10 dmg 
				cout << "The monster hits you and you take " << hit << " dmg" << endl;
				hp -= hit;
			}
		}

		else {
			hit = rand() % 16 + 5; // monster does 5-20 dmg
			cout << "Monster bites you and you take " << hit << " dmg" << endl;
			hp -= hit;

		}


		cout << "Press 1 to attack, 2 to try to escape." << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			//player attack sequence
			if (inv[0] == "axe") {
				hit = rand() % 26 + 10; //hit for 10-35 dmg
				cout << "You slash the monster for " << hit << " dmg" << endl;
				MonsterHealth -= hit;

			}

			else if (inv[0] == "bow") {
				hit = rand() % 11 + 5; // 5-15 dmg
				cout << "You shoot the monster for " << hit << " dmg" << endl;
				MonsterHealth -= hit;

			}
			break;
		case 2: // try to escape
			escape = rand() % 100 + 1;
			if (escape > 61) {
				cout << "You successfully escape!" << endl;
				MonsterHealth = 0;

			}
			else if (escape < 61) {
				cout << "You were unable to escape" << endl;
			}
			break;

		}// end switch


		cout << "HP: " << hp << endl;
		cout << "Monster HP: " << MonsterHealth << endl;




	}
	cout << "You Win" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	system("color 07");
}

void shop() {
	char input = 'a';
	cout << endl << endl << "---------------------------------------------------------" << endl;
	cout << "welcome to the AURA shop!" << endl;
	cout << "type 'q' to quit" << endl;
	while (input != 'q') {
		cout << "Pick an item: h) HP potion d) dog ?) ??? " << endl;
		cin >> input;
		switch (input) {
		case 'h':
			cout << "Heres your HP potion" << endl;
			inv[3] = "potion";
			break;
		case 'd':
			cout << "Heres your dog" << endl;
			inv[4] = "jeremy";
			break;
		case '?':
			cout << "Heres your ???" << endl;
			hp -= 100;
			break;
		}
		cout << "---------------------------------------------------------" << endl;
	}
}
