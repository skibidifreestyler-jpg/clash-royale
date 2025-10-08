#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() 

{
	srand(time(0));
	cout << "Would you like to play single player or multiplayer? (1/2): ";
	int mode;
	cin >> mode;
	if (mode == 1) {

		cout << "Enter 2 player names:\n";
		string name1, name2;
		cin >> name1;
		cin >> name2;
		if (name1 == name2) {
			cout << "Names must be different!\n";
			return 0;
		}
		cout << "Welcome to Clash Royale, " << name1 << " and " << name2 << "!\n";
		cout << "It's" << name1 << "'s turn first.\n";

		bool gameOver = false;
		int tower1 = 30;
		int tower2 = 30;
		int elixir1 = 10;
		int elixir2 = 10;

		struct Card {
			string name;
			int cost;
			int damage;
		};
		Card fireball;
		fireball.name = "Fireball";
		fireball.cost = 4;
		fireball.damage = 6;
		Card archers;
		archers.name = "Archers";
		archers.cost = 3;
		archers.damage = 8;
		Card kinght;
		kinght.name = "Knight";
		kinght.cost = 5;
		kinght.damage = 10;
		Card cannon;
		cannon.name = "Cannon";
		cannon.cost = 5;
		cannon.damage = 7;
		while (tower1 > 0 && tower2 > 0) {
			cout << name1 << "'s turn" << "\n";
			cout << "Avalable cards:\n";
			cout << "1. " << fireball.name << " (Cost: " << fireball.cost << ", Damage: " << fireball.damage << ")\n";
			cout << "2. " << archers.name << " (Cost: " << archers.cost << ", Damage: " << archers.damage << ")\n";
			cout << "3. " << kinght.name << " (Cost: " << kinght.cost << ", Damage: " << kinght.damage << ")\n";
			cout << "4. " << cannon.name << " (Cost: " << cannon.cost << ", Damage: " << cannon.damage << ")\n";
			cout << elixir1 << " elixir available\n";
			int choice;
			cout << "Choose a card to play (1-4): ";
			cin >> choice;
			switch (choice) {
			case 1:
				if (elixir1 >= fireball.cost) {

					tower2 -= fireball.damage;
					cout << "You played " << fireball.name << "! Tower 2 takes " << fireball.damage << " damage.\n";
					cout << "Tower 2 health: " << tower2 << "\n";
					elixir1 -= fireball.cost;
					cout << "Your elixir: " << elixir1 << "\n";
					if (tower2 <= 0) {
						cout << name1 << " wins!\n";
						gameOver = true;
						return 0;
					}

				}
				else cout << "Not enough elixir!\n";


				break;
			case 2:
				if (elixir1 >= archers.cost) {

					tower2 -= archers.damage;
					cout << "You played " << archers.name << "! Tower 2 takes " << archers.damage << " damage.\n";
					cout << "Tower 2 health: " << tower2 << "\n";
					elixir1 -= archers.cost;
					cout << "Your elixir: " << elixir1 << "\n";
					if (tower2 <= 0) {
						cout << name1 << " wins!\n";
						gameOver = true;
						return 0;
					}


				}
				else cout << "Not enough elixir!\n";
				break;
			case 3:
				if (elixir1 >= kinght.cost) {

					tower2 -= kinght.damage;
					cout << "You played " << kinght.name << "! Tower 2 takes " << kinght.damage << " damage.\n";
					cout << "Tower 2 health: " << tower2 << "\n";
					elixir1 -= kinght.cost;
					cout << "Your elixir: " << elixir1 << "\n";
					if (tower2 <= 0) {
						cout << name1 << " wins!\n";
						gameOver = true;
						return 0;
					}


				}
				else cout << "Not enough elixir!\n";
				break;
			case 4:
				if (elixir1 >= cannon.cost) {

					cout << "You played " << cannon.name << "! Tower 2 takes " << cannon.damage << " damage.\n";
					tower2 -= cannon.damage;
					cout << "Tower 2 health: " << tower2 << "\n";
					elixir1 -= cannon.cost;
					cout << "Your elixir: " << elixir1 << "\n";
					if (tower2 <= 0) {
						cout << name1 << " wins!\n";
						gameOver = true;
						return 0;
					}



				}
				else cout << "Not enough elixir!\n";
				break;
			}


			cout << name2 << "'s turn" << "\n";
			cout << "Avalable cards:\n";
			cout << "1. " << fireball.name << " (Cost: " << fireball.cost << ", Damage: " << fireball.damage << ")\n";
			cout << "2. " << archers.name << " (Cost: " << archers.cost << ", Damage: " << archers.damage << ")\n";
			cout << "3. " << kinght.name << " (Cost: " << kinght.cost << ", Damage: " << kinght.damage << ")\n";
			cout << "4. " << cannon.name << " (Cost: " << cannon.cost << ", Damage: " << cannon.damage << ")\n";
			cout << elixir2 << " elixir available\n";

			cout << "Choose a card to play (1-4): ";
			cin >> choice;
			switch (choice) {
			case 1:
				if (elixir2 >= fireball.cost) {

					tower1 -= fireball.damage;
					cout << "You played " << fireball.name << "! Tower 1 takes " << fireball.damage << " damage.\n";
					cout << "Tower 1 health: " << tower1 << "\n";
					elixir2 -= fireball.cost;
					cout << "Your elixir: " << elixir2 << "\n";
					if (tower1 <= 0) {
						cout << name2 << " wins!\n";
						gameOver = true;
						return 0;
					}


				}
				else cout << "Not enough elixir!\n";
				break;
			case 2:
				if (elixir2 >= archers.cost) {

					tower1 -= archers.damage;
					cout << "You played " << archers.name << "! Tower 1 takes " << archers.damage << " damage.\n";
					cout << "Tower 1 health: " << tower1 << "\n";
					elixir2 -= archers.cost;
					cout << "Your elixir: " << elixir2 << "\n";
					if (tower1 <= 0) {
						cout << name2 << " wins!\n";
						gameOver = true;
						return 0;
					}


				}
				else cout << "Not enough elixir!\n";
				break;
			case 3:
				if (elixir2 >= kinght.cost) {

					tower1 -= kinght.damage;
					cout << "You played " << kinght.name << "! Tower 1 takes " << kinght.damage << " damage.\n";
					cout << "Tower 1 health: " << tower1 << "\n";
					elixir2 -= kinght.cost;
					cout << "Your elixir: " << elixir2 << "\n";
					if (tower1 <= 0) {
						cout << name2 << " wins!\n";
						gameOver = true;
						return 0;
					}

				}
				else cout << "Not enough elixir!\n";
				break;
			case 4:
				if (elixir2 >= cannon.cost) {

					cout << "You played " << cannon.name << "! Tower 1 takes " << cannon.damage << " damage.\n";
					tower1 -= cannon.damage;
					cout << "Tower 1 health: " << tower1 << "\n";
					elixir2 -= cannon.cost;
					cout << "Your elixir: " << elixir2 << "\n";
					if (tower1 <= 0) {
						cout << name2 << " wins!\n";
						gameOver = true;
						return 0;
					}


				}
				else cout << "Not enough elixir!\n";


			}
			if (tower1 <= 0) {
				cout << "Player 2 wins!\n";
				return 0;
			}
			else if (tower2 <= 0) {
				cout << "Player 1 wins!\n";
				return 0;
			}
			else {
				cout << "Both towers are still standing!\n";

			}
			if (elixir1 < 10) elixir1++;
			if (elixir2 < 10) elixir2++;
		}
		return 0;



			
			
			
	}
	else if (mode == 2) {

		string name;
		cout << "Enter your name: ";
		cin >> name;
		cout << "Welcome to Clash Royale, Player " << name << "!\n";
		cout << "You will be playing against a bot.\n";
		cout << "It's your turn first.\n";
		bool gameOver = false;
		int ptower = 30;
		int btower = 30;
		int pelixir = 10;
		int belixir = 10;
		struct Card {
			string name;
			int cost;
			int damage;
		};
		Card fireball;
		fireball.name = "Fireball";
		fireball.cost = 4;
		fireball.damage = 6;
		Card archers;
		archers.name = "Archers";
		archers.cost = 3;
		archers.damage = 8;
		Card kinght;
		kinght.name = "Knight";
		kinght.cost = 5;
		kinght.damage = 10;
		Card cannon;
		cannon.name = "Cannon";
		cannon.cost = 5;
		cannon.damage = 7;

		while (ptower > 0 && btower > 0) {
			cout << name << "'s turn" << "\n";
			cout << "Avalable cards:\n";
			cout << "1. " << fireball.name << " (Cost: " << fireball.cost << ", Damage: " << fireball.damage << ")\n";
			cout << "2. " << archers.name << " (Cost: " << archers.cost << ", Damage: " << archers.damage << ")\n";
			cout << "3. " << kinght.name << " (Cost: " << kinght.cost << ", Damage: " << kinght.damage << ")\n";
			cout << "4. " << cannon.name << " (Cost: " << cannon.cost << ", Damage: " << cannon.damage << ")\n";
			cout << pelixir << " elixir available\n";
			int pchoice;
			cout << "Choose a card to play (1-4): ";
			cin >> pchoice;
			cout << pelixir << "elixir available\n";
			switch (pchoice) {
			case 1:
				if (pelixir >= fireball.cost) {
					btower -= fireball.damage;
					cout << "You played " << fireball.name << "! Bot's Tower takes " << fireball.damage << " damage.\n";
					cout << "Bot's Tower health: " << btower << "\n";
					pelixir -= fireball.cost;
					cout << "Your elixir: " << pelixir << "\n";
					if (btower <= 0) {
						cout << "You win!\n";
						gameOver = true;
						return 0;
					}
				}
				else cout << "Not enough elixir!\n";
				break;
			
			
			
			
			
			case 2:



				if (pelixir >= archers.cost) {
					btower -= archers.damage;
					cout << "You played " << archers.name << "! Bot's Tower takes " <<
						archers.damage << " damage.\n";
					cout << "Bot's Tower health: " << btower << "\n";
					pelixir -= archers.cost;
					cout << "Your elixir: " << pelixir << "\n";
					if (btower <= 0) {
						cout << "You win!\n";
						gameOver = true;
						return 0;







					}
					else cout << "Not enough elixir!\n";
					break;
					case 3
						:
							if (pelixir >= kinght.cost) {
								btower -= kinght.damage;
								cout << "You played " << kinght.name << "! Bot's Tower takes " << kinght.damage << " damage.\n";
								cout << "Bot's Tower health: " << btower << "\n";
								pelixir -= kinght.cost;
								cout << "Your elixir: " << pelixir << "\n";
								if (btower <= 0) {
									cout << "You win!\n";
									gameOver = true;
									return 0;
								}
							}
							else cout << "Not enough elixir!\n";
							break;
					case 4:
						if (pelixir >= cannon.cost) {
							btower -= cannon.damage;
							cout << "You played " << cannon.name << "! Bot's Tower takes " << cannon.damage << " damage.\n";
							cout << "Bot's Tower health: " << btower << "\n";
							pelixir -= cannon.cost;
							cout << "Your elixir: " << pelixir << "\n";
							if (btower <= 0) {
								cout << "You win!\n";
								gameOver = true;
								return 0;
							}
						}
						else cout << "Not enough elixir!\n";
						break;
						
				}

						
			}
			if (btower > 0) {
				cout << "\nBot's turn...\n";

				int bchoice = rand() % 4 + 1;
				cout << "Bot chose card #" << bchoice << "!\n";

				switch (bchoice) {
				case 1:
					if (belixir >= fireball.cost) {
						ptower -= fireball.damage;
						belixir -= fireball.cost;
						cout << "Bot played " << fireball.name << "! Your Tower takes " << fireball.damage << " damage.\n";
						
					}
					else cout << "Bot didn't have enough elixir!\n";
					break;
				case 2:
					if (belixir >= archers.cost) {
						ptower -= archers.damage;
						belixir -= archers.cost;
						cout << "Bot played " << archers.name << "! Your Tower takes " << archers.damage << " damage.\n";
						
					}
					else cout << "Bot didn't have enough elixir!\n";
					break;
				case 3:
					if (belixir >= kinght.cost) {
						ptower -= kinght.damage;
						belixir -= kinght.cost;
						cout << "Bot played " << kinght.name << "! Your Tower takes " << kinght.damage << " damage.\n";
						
					}
					else cout << "Bot didn't have enough elixir!\n";
					break;
				case 4:
					if (belixir >= cannon.cost) {
						ptower -= cannon.damage;
						belixir -= cannon.cost;
						cout << "Bot played " << cannon.name << "! Your Tower takes " << cannon.damage << " damage.\n";
						
					}
					else cout << "Bot didn't have enough elixir!\n";
					break;
				}

				cout << "Your Tower health: " << ptower << "\n";
				cout << "Bot's elixir: " << belixir << "\n";
				if (ptower <= 0) {
					cout << "The Bot wins!\n";
					
				}
				if (pelixir < 10) pelixir++;
				if (belixir < 10) belixir++;
			}

		}
		}
	}
