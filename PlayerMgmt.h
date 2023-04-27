// PlayerMgmt.h

#ifndef _PlayerMgmt_h_
#define _PlayerMgmt_h_

#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "PlayerList.h"
#include "Player.h"

//const char clear_command[] = "cls"; // for Windows
const char clear_command[] = "clear"; // for Linux and possibly Mac's

const char pl_file_name[] = "playerlist.txt";

class PlayerMgmt {
public:
    void run();

private:
    void display_main() const;
    void display_searched() const;
    void execute(char command, bool & done);

    bool MorS; // true:main false:search

    PlayerList player_list;
    PlayerList searched_list;
};

#endif
