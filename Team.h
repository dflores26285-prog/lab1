#include "Player.h"

class Team {
private:
    Player players[10];
    int playercount;

public:
    Team();

    void info();
    void playerdisplay(int i);
    void teamMembers();
    void searchPlayer();
    void teamSummary();
    void registerPlayer();
};
