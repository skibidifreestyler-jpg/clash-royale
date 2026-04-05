#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For sorting/finding best card
#include <cstdlib>
#include <ctime>

using namespace std;

struct Card {
    string name;
    int cost;
    int damage;
};

// Logic for Bot to choose a card based on difficulty
int getBotChoice(int elixir, const vector<Card>& deck, int difficulty) {
    if (difficulty == 1) { // EASY: Picks the cheapest card it can afford
        int cheapestIdx = -1;
        int minCost = 100;
        for (int i = 0; i < deck.size(); i++) {
            if (deck[i].cost <= elixir && deck[i].cost < minCost) {
                minCost = deck[i].cost;
                cheapestIdx = i;
            }
        }
        return (cheapestIdx != -1) ? cheapestIdx + 1 : (rand() % deck.size() + 1);
    } 
    else if (difficulty == 3) { // HARD: Picks the highest damage card it can afford
        int bestIdx = -1;
        int maxDamage = -1;
        for (int i = 0; i < deck.size(); i++) {
            if (deck[i].cost <= elixir && deck[i].cost > maxDamage) {
                maxDamage = deck[i].damage;
                bestIdx = i;
            }
        }
        return (bestIdx != -1) ? bestIdx + 1 : (rand() % deck.size() + 1);
    }
    // MEDIUM (or default): Random pick
    return (rand() % deck.size()) + 1;
}

bool playTurn(string playerName, int &currentElixir, int &enemyTower, const vector<Card>& deck, bool isBot, int difficulty) {
    cout << "\n--- " << playerName << "'s Turn ---" << endl;
    cout << "Elixir: " << currentElixir << " | Enemy Tower: " << enemyTower << endl;

    int choice;
    if (isBot) {
        choice = getBotChoice(currentElixir, deck, difficulty);
        cout << "Bot (Level " << difficulty << ") chooses: " << deck[choice - 1].name << endl;
    } else {
        for (int i = 0; i < deck.size(); i++) {
            cout << i + 1 << ". " << deck[i].name << " (Cost: " << deck[i].cost << ")\n";
        }
        cout << "Choose a card: ";
        cin >> choice;
    }

    if (choice < 1 || choice > deck.size()) return false;

    const Card& selected = deck[choice - 1];
    if (currentElixir >= selected.cost) {
        currentElixir -= selected.cost;
        enemyTower -= selected.damage;
        cout << playerName << " dealt " << selected.damage << " damage with " << selected.name << "!" << endl;
    } else {
        cout << playerName << " failed to play " << selected.name << " (Low Elixir)!" << endl;
    }

    return enemyTower <= 0;
}

int main() {
    srand(time(0));
    vector<Card> deck = {{"Fireball", 4, 6}, {"Archers", 3, 8}, {"Knight", 5, 10}, {"Cannon", 5, 7}};

    cout << "1. Multiplayer\n2. Single Player\nChoice: ";
    int mode, difficulty = 2; // Default to Medium
    cin >> mode;

    string p1Name, p2Name = "Bot";
    bool p2IsBot = (mode == 2);

    if (mode == 1) {
        cout << "P1 Name: "; cin >> p1Name;
        cout << "P2 Name: "; cin >> p2Name;
    } else {
        cout << "Your Name: "; cin >> p1Name;
        cout << "Select Difficulty (1: Easy, 2: Med, 3: Hard): ";
        cin >> difficulty;
    }

    int t1 = 30, t2 = 30, e1 = 10, e2 = 10;

    while (t1 > 0 && t2 > 0) {
        if (playTurn(p1Name, e1, t2, deck, false, 0)) break;
        if (playTurn(p2Name, e2, t1, deck, p2IsBot, difficulty)) break;
        if (e1 < 10) e1++; if (e2 < 10) e2++;
    }

    cout << "\nGAME OVER" << endl;
    return 0;
}
