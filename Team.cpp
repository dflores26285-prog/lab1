
#include <iostream>
#include <limits>
#include <string>
#include "Team.h"
using namespace std;

Team::Team() {
    playercount = 0;
}

void Team::info() {
    if (playercount >= 10) {
        cout << "\nTeam registration is full.\n";
        return;
    }

    string name, position, characteristic;
    int age, option;
    double height, weight;

    cout << "\nEnter Player Name: ";
    getline(cin, name);

    cout << "Player Height (cm): ";
    cin >> height;

    while (height <= 0 || height >= 220) {
        cout << "Invalid height. Enter again: ";
        cin >> height;
    }

    cout << "Player Weight (kg): ";
    cin >> weight;

    while (weight <= 0 || weight >= 100) {
        cout << "Invalid weight. Enter again: ";
        cin >> weight;
    }

    cout << "Player Age: ";
    cin >> age;

    while (age <= 0 || age >= 60) {
        cout << "Invalid age. Enter again: ";
        cin >> age;
    }

    cout << "\nSelect Player Position:\n";
    cout << "1. Defence\n";
    cout << "2. Midfielder\n";
    cout << "3. Striker\n";
    cout << "Enter choice: ";
    cin >> option;

    while (option < 1 || option > 3) {
        cout << "Invalid option. Enter 1, 2, or 3: ";
        cin >> option;
    }

    switch (option) {
        case 1:
            position = "Defence";
            break;

        case 2:
            position = "Midfielder";
            break;

        case 3:
            position = "Striker";
            break;
    }

    cin.ignore();

    cout << "Special Characteristic: ";
    getline(cin, characteristic);

    players[playercount].setDetails(
        name, position, characteristic,
        age, height, weight
    );

    playerdisplay(playercount);
    playercount++;
}

void Team::playerdisplay(int i) {
    players[i].displayPlayer();
}

void Team::teamMembers() {
    if (playercount == 0) {
        cout << "\nNo players registered yet.\n";
        return;
    }

    cout << "\n=========== TEAM MEMBERS ===========\n";

    for (int i = 0; i < playercount; i++) {
        cout << "\nPlayer " << i + 1 << endl;
        cout << "Name: " << players[i].getName() << endl;
        cout << "Position: " << players[i].getPosition() << endl;
        cout << "Age: " << players[i].getAge() << endl;
    }
}

void Team::searchPlayer() {
    if (playercount == 0) {
        cout << "\nNo players available to search.\n";
        return;
    }

    string searchName;
    bool found = false;

    cout << "\nEnter player name to search: ";
    getline(cin, searchName);

    for (int i = 0; i < playercount; i++) {
        if (players[i].getName() == searchName) {
            cout << "\nPlayer found!";
            playerdisplay(i);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nPlayer not found.\n";
    }
}

void Team::teamSummary() {
    int defence = 0;
    int midfielder = 0;
    int striker = 0;

    for (int i = 0; i < playercount; i++) {
        if (players[i].getPosition() == "Defence") {
            defence++;
        }
        else if (players[i].getPosition() == "Midfielder") {
            midfielder++;
        }
        else if (players[i].getPosition() == "Striker") {
            striker++;
        }
    }

    cout << "\n=========== TEAM SUMMARY ===========\n";
    cout << "Total Players: " << playercount << endl;
    cout << "Defence Players: " << defence << endl;
    cout << "Midfielders: " << midfielder << endl;
    cout << "Strikers: " << striker << endl;
}

void Team::registerPlayer() {
    info();
}
