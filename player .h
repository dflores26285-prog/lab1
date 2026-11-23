

#include <string>
using namespace std;

class Player {
private:
    string name;
    string position;
    string characteristic;
    int age;
    double height;
    double weight;

public:
    Player();

    void setDetails(string n, string p, string c,
                    int a, double h, double w);

    string getName();
    string getPosition();
    string getCharacteristic();
    int getAge();
    double getHeight();
    double getWeight();

    void displayPlayer();
};

#endif
