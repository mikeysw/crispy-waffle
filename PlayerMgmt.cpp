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
         << "  next    previous  edit     \n"
         << short_separator << endl;
}

void PlayerMgmt::execute(char command, bool & done)
{
    switch (command) {
        case 'n': {
            // Start a new season
            break;
        }
        case 'next': {
            // Move to next
            entry_list.move_to_next();
            break;
        }
        case 'previous': {
            // Move to previous
            entry_list.move_to_previous();
            break;
        }
        case 'a': {
            // Add a player
            PlayerEntry e;
            cout << "Last name: ";
            getline(cin, e.lastName);
            cout << "First name: ";
            getline(cin, e.firstName);
            cout << "Year of birth: ";
            cin >> e.yearOfBirth;
            cout << "Category: ";
            getline(cin, e.category);
            cout << "Reg status: ";
            getline(cin, e.regStatus);
            entry_list.add(e);
            break;
        }
        case 'se': {
            //Search for players
            break;
        }
        case 'p': {
            //Print a list of players
            for(const auto& [e.lastName,e.firstName,e.yearOfBirth,e.category,e.regStatus]:m){
                cout << e.lastName << '\n';
                cout << e.firstName << '\n';
                cout << e.yearOfBirth << '\n';
                cout << e.category << '\n';
                cout << e.regStatus << '\n';
            }
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