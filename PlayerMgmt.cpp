//PlayerMgmt.cpp

#include "PlayerMgmt.h"

using namespace std;

void PlayerMgmt::run()
{
    entry_list.read_file(file_name);
    bool done = false;
    while (!done) {
        display_entry_and_menu();
        cout << "choice: ";
        char command;
        cin >> command;
        cin.get(); // new line char
        execute(command, done);
        cout << endl;
    }
}

void PlayerMgmt::display_entry_and_menu() const {
    string long_separator(50, '-');
    string short_separator(8, '-');

    system(clear_command);

    entry_list.display_current_entry();

    cout << long_separator << endl
         << "  new     add       search    \n"
         << "  print   display   stop     \n"
         << short_separator << endl;
}

void PlayerMgmt::execute(char command, bool & done)
{
    switch (command) {
        case 'n': {
            // Start a new season
            break;
        }
        case 'a': {
            // Add a player
            break;
        }
        case 'se': {
            //Search for players
            break;
        }
        case 'p': {
            //Print a list of players
            break;
        }
        case 'd': {
            //Display Statistics
            break;
        }
        case 'st': {
            // Stop the program
            break;
        }
    }
}