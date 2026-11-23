
#include <iostream>
#include "Player.h"
using namespace std;

Player::Player() {
    name = "";
    position = "";
    characteristic = "";
    age = 0;
    height = 0;
    weight = 0;
}

void Player::setDetails(string n, string p, string c,
                        int a, double h, double w) {
    name = n;
    position = p;
    characteristic = c;
    age = a;
    height = h;
    weight = w;
}

string Player::getName() {
    return name;
}

string Player::getPosition() {
    return position;
}

string Player getCharacteristic() {
    return characteristic;
}

int Player getAge() {
    return age;
}

double Player getHeight() {
    return height;
}

double Player getWeight() {
    return weight;
}

void Player displayPlayer() {
    cout << "\n================================================\n";
    cout << "              Player Profile                   \n";
    cout << "================================================\n";
    cout << "Name: " << name << endl;
    cout << "Height: " << height << " cm\n";
    cout << "Weight: " << weight << " kg\n";
    cout << "Age: " << age << endl;
    cout << "Position: " << position << endl;
    cout << "Characteristic: " << characteristic << endl;
}
