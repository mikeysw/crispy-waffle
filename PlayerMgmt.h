// PlayerMgmt.h

#ifndef _PlayerMgmt_h_
#define _PlayerMgmt_h_

#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "PlayerMgmtList.h"
#include "PlayerEntry.h"

//const char clear_command[] = "cls"; // for Windows
const char clear_command[] = "clear"; // for Linux and possibly Mac's

const char file_name[] = "playerlist.txt";

class PlayerMgmt{
public:
    void run();

private:
    void display_entry_and_main() const; // main view - before searching (return to this view with command exit)
    void display_entry_and_search() const; // second view - after searching
    void execute(char command, bool & done);

    PlayerMgmtList entry_list;
};

#endif