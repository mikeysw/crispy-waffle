//PlayerMgmt.cpp

#include "PlayerMgmt.h"
#include <string> 
using namespace std;

void PlayerMgmt::run()
{
    entry_list.read_file(file_name);
    bool done = false;
    while (!done) {
        display_entry_and_main();
        cout << "choice: ";
        char command;
        cin >> command;
        cin.get(); // new line char
        execute(command, done);
        cout << endl;
    }
}

void PlayerMgmt::display_entry_and_main() const {
    string long_separator(50, '-');
    string short_separator(8, '-');

    system(clear_command);

    entry_list.display_current_entry();

    cout << long_separator << endl
         << "  (N)ew     (a)dd       (S)earch    \n"
         << "  (P)rint   (d)isplay   (s)top     \n"
         << short_separator << endl;
}
//CHECKKKKKK

void PlayerMgmt::display_entry_and_search() const {
    string long_separator(50, '-');
    string short_separator(8, '-');

    system(clear_command);

    entry_list.display_current_entry();

    cout << long_separator << endl
         << "  (S)earch   (n)ext    (p)revious   \n"
         << "  (e)dit     (P)rint   (E)xit     (s)top     \n"
         << short_separator << endl;
}

void PlayerMgmt::execute(char command, bool & done)
{
    switch (command) {
        
        case 'N': {
            // Start a new season
            break;
        }
        case 'n': {
            // Move to next
            entry_list.move_to_next();
            break;
        }
        case 'p': {
            // Move to previous
            entry_list.move_to_previous();
            break;
        }
        
        case 'a': {
            // Add a player
            PlayerEntry e;
            string lastName0;
            string firstName0;
            int yearOfBirth0;
            string category0;
            string regStatus0;
            cout << "Last name: ";
            getline(cin, lastName0);
            e.setLastName(lastName0);
            cout << "First name: ";
            getline(cin, firstName0);
            e.setLastName(firstName0);
            cout << "Year of birth: ";       
            cin >> yearOfBirth0;
            e.setYearOfBirth(yearOfBirth0);
            cout << "Category: ";
            int category_int;                      //we should probably make this into a function
            category_int = 2023 - int(yearOfBirth0); //season year - birthyear = categoryint
            category0 = "U"+ to_string(category_int);
            e.setCategory(category0);
            cout << "Registration status (paid or unpaid): ";
            getline(cin, regStatus0);
            e.setLastName(regStatus0);
            entry_list.add(e);
            break;
        }
        
        case 'e': {
            //edit player info
            if (entry_list.empty())
                return;
            PlayerEntry new_data;
            string lastName0;
            string firstName0;
            int yearOfBirth0;
            string category0;
            string regStatus0;
            cout << "Leave blank if no change is needed." << endl;
            cout << "Update last name: ";
            getline(cin, lastName0);
            new_data.setLastName(lastName0);
            cout << "Update first name: ";
            getline(cin, firstName0);
            new_data.setLastName(firstName0);
            cout << "Update year of birth: ";       
            cin >> yearOfBirth0;
            new_data.setYearOfBirth(yearOfBirth0);
            cout << "Category: ";
            int category_int;                        //we should probably make this into a function
            category_int = 2023 - int(yearOfBirth0); //season year - birthyear = categoryint
            category0 = "U"+ to_string(category_int);
            new_data.setCategory(category0);
            cout << "Update registration status (paid or unpaid): ";
            getline(cin, regStatus0);
            new_data.setLastName(regStatus0);

            entry_list.update_current_player(new_data);
            break;
        }

        case 'S': {
            //Search for players
            break;
        }
        case 'P': {
            //Print a list of players
            /*
            for(const auto& [e.getLastName(), e.getFirstName(), e.getYearOfBirth(), e.Category(), e.RegStatus()] : entry_list){
                cout << e.lastName << '\n';
                cout << e.firstName << '\n';
                cout << e.yearOfBirth << '\n';
                cout << e.category << '\n';
                cout << e.regStatus << '\n';
            }
            */
            break;
        }
        case 'd': {
            //Display Statistics
            /*
            PlayerEntry::display_stats();

            //blah blah
            */

            break;
        }
        case 's': {
            // Stop the program
            entry_list.write_file(file_name);
            done = true;
            break;
        }
        
    }
}