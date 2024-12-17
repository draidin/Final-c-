#include<iostream>
#include<Windows.h>
using namespace std;
//global variables
string choice;
string inv[5];
int hp = 100;
int aura = 100;
void BattleSim();
void larrysim();
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
			cout << "You get out of a portal you see zombies in cages you try to go back but the time machine broke" << endl;
			cout << "now you have to find a new machine so you look around and you see a door you can go (n)orth " << endl;
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
					if (choice == "axe") {
						inv[0] = "axe";
						cout << "You picked up the axe and the bow turned into ash" << endl;
						//PlaySound(TEXT("Pokemon_Item_Found_Sound_Effect.wav"), NULL, SND_FILENAME | SND_ASYNC);
					}
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
			cout << "You took some damage but you will live oh you got 500 AURA points for killing that zombie" << endl;
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
			cout << "You explore a dark crawl space you go in its really tight" << endl;
			cout << "Wll u turn back (w)est or keep going (s)outh" << endl;
			cin >> choice;
			if (choice == "south")
				room = 5;
			else if (choice == "west")
				room = 3;
			break;
		case 5:
			cout << "While you explore the room you trip on a bag and fall you open the bag and find 1000" << endl;
			cout << "Aura points now you can go (e)ast or (s)outh" << endl;
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
			cout << "You can go (n)orth" << endl;
			cin >> choice;
			if (choice == "north")
				room = 5;
			break;
		case 7:
			cout << "You walk into the next room then you step into a puddle of goo that stinks more then noah" << endl;
			cout << "After you get out of the goo you hera a loud roar you can go (w)est or (e)ast" << endl;
			cin >> choice;
			if (choice == "east")
				room = 8;
			else if (choice == "west")
				break;
		case 8:
			cout << "while you get closer to the doors the roars get louder you can go (s)outh or (w)est" << endl;
			cin >> choice;
			if (choice == "south")
				room = 9;
			else if (choice == "west")
				room = 7;
			break;
		case 9:
			shop();
			cout << "You are right infront of The door you can hear the beast sniffing you because of the goo" << endl;
			cout << "That you stept in you can go (n)orth or (e)ast" << endl;
			cin >> choice;
			if (choice == "east")
				room = 10;
			else if (choice == "north")
				room = 8;
			break;
		case 10:
			cout << "	     _____()() " << endl;
			cout << "       /       @@\      " << endl;
			cout << " `~~~~~\\_; m__m._>o        " << endl;
			if (inv[4] == "jeremy") {
				cout << "You see the new machine and the mice named Larry gaurding it and you tell jeremy to go eat him" << endl;
				cout << "Jeremy starts running at him and Larys mouth opens and eats jeremy  " << endl;
				cout << "You are speechless as the dog that u had for 30 seconds is now dead " << endl;
				cout << "Now you are mad and BALKIN RAGE KICKS IN +50 HP" << endl;
				hp += 50;
			}
			else
				cout << "You see the machine and the mice named Larry gaurding it" << endl;
			larrysim();
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

void larrysim() {
	int LarryHealth = 200;
	int hit;
	int choice;
	int escape;
	cout << endl << "---------BATTLE----------" << endl;
	system("color 04");
	while (hp > 0 && LarryHealth > 0) {
		// monster attack sequence

		if (inv[1] == "armor") {
			if (inv[2] == "sheild") {
				hit = rand() % 16 + 5; // monster does 5-20 dmg 
				cout << "Larry hits you and you take " << hit << " dmg" << endl;
				hp -= hit;
			}
		}

		if (inv[1] == "armor") {
			hit = rand() % 26 + 5; // monster does 5-30 dmg 
			cout << "Larry hits you and you take " << hit << " dmg" << endl;
			hp -= hit;

		}

		else if (inv[2] == "sheild") {
			hit = rand() % 26 + 5; // monster does 5-30 dmg 
			cout << "Larry hits you and you take " << hit << " dmg" << endl;
			hp -= hit;

		}



		else {
			hit = rand() % 16 + 5; // monster does 5-20 dmg
			cout << "Larry switch cheese you and you take " << hit << " dmg" << endl;
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
				LarryHealth -= hit;

			}

			else if (inv[0] == "bow") {
				hit = rand() % 11 + 5; // 5-15 dmg
				cout << "You shoot the monster for " << hit << " dmg" << endl;
				LarryHealth -= hit;

			}
			break;
		case 2: // try to escape
			escape = rand() % 100 + 1;
			if (escape > 61) {
				cout << "You successfully escape!" << endl;
				LarryHealth = 0;

			}
			else if (escape < 61) {
				cout << "You were unable to escape" << endl;
			}
			break;

		}// end switch


		cout << "HP: " << hp << endl;
		cout << "Larry HP: " << LarryHealth << endl;




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
			cout << "Heres your HP potion -200" << endl;
			inv[3] = "potion";
			break;
		case 'd':
			cout << "Heres your dog -400" << endl;
			inv[4] = "jeremy";
			break;
		case '?':
			cout << "Heres your ??? you can have it for free" << endl;
			hp -= 100;
			break;
		}
		cout << "---------------------------------------------------------" << endl;
	}
}
