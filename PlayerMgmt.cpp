// PlayerMgmt.cpp

#include "PlayerMgmt.h"

using namespace std;

void PlayerMgmt::run() {
    player_list.read_file(pl_file_name);
    MorS = true; 
    bool done = false;
    while (!done) {
        if(MorS == true) display_main();
        else display_searched();

        cout << "choice: ";
        char command;
        cin >> command;
        cin.get(); 
        execute(command, done);
        cout << endl;
    }
}

void PlayerMgmt::display_main() const {
    string long_separator(50, '-');
    string short_separator(8, '-');

    system(clear_command);

    cout << long_separator << endl
         << "  (N)ew     (a)dd       (s)earch    \n"
         << "  (P)rint   (d)isplay   (S)top     \n"
         << short_separator << endl;
}

void PlayerMgmt::display_searched() const {
    string long_separator(50, '-');
    string short_separator(8, '-');

    system(clear_command);

    searched_list.display_current_player();

    cout << long_separator << endl
         << "  (s)earch   (n)ext     (p)revious   \n"
         << "  (e)dit     (P)rint    (E)xit     (S)top     \n"
         << short_separator << endl;
}

void PlayerMgmt::execute(char command, bool & done)
{
    switch (command) {
        case 'N': {
            int new_year;
            cout << "New season: ";
            cin >> new_year;

            char yorn;
            cout << "Do you confirm deleting all the existing players and start a new season of " + to_string(new_year) +"? (y or n) ";
            cin >> yorn;

            if(yorn == 'y'){
                player_list.set_season(new_year);
                player_list.clear();
            }
            else break;

            break;
        }
        case 'a': {
            // Add a player
            int category_int;
            string lastName0;
            string firstName0;
            string yearOfBirth0;
            string category0;
            string regStatus0;
            cout << "Last name: ";
            getline(cin, lastName0);
            //e.setLastName(lastName0);
            cout << "First name: ";
            getline(cin, firstName0);
            //e.setLastName(firstName0);
            cout << "Year of birth: ";       
            getline(cin, yearOfBirth0);
            //e.setYearOfBirth(yearOfBirth0);
            category_int = 2023 - stoi(yearOfBirth0); //season year - birthyear = category
            if (category_int < 6){
                category0="U6";
            }
            else if(6 <= category_int && category_int < 8){
                category0="U8";
            }
            else if(8 <= category_int && category_int < 10){
                category0="U10";
            }
            else if(10 <= category_int && category_int < 12){
                category0="U12";
            }
            else if(12 <= category_int && category_int < 14){
                category0="U14";
            }
            else if(14 <= category_int && category_int < 17){
                category0="U17";
            }
            else{
                "There is no category";
                break;
            }
            //category0 = "U"+ to_string(category_int);
            //e.setCategory(category0);
            cout << "RegStatus: " << category0;
            getline(cin, regStatus0);
            //e.setLastName(regStatus0);
            Player e(lastName0, firstName0, yearOfBirth0, category0, regStatus0);
            player_list.add(e);
            cout << e.getFirstName() << " " << e.getLastName();
            cin.get();
            break;
        }
        
        case 'e': {
            //edit player info
            /*
            if (player_list.empty())
                return;
            Player new_data;
            string lastName0;
            string firstName0;
            string yearOfBirth0;
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
            category_int = 2023 - int(yearOfBirth0); //season year - birthyear = category
            category0 = "U"+ to_string(category_int);
            new_data.setCategory(category0);
            cout << "Update registration status (paid or unpaid): ";
            getline(cin, regStatus0);
            new_data.setLastName(regStatus0);
*/
        }
        case 'P': {
            
            if(MorS == true){
                string filename;
                cout << "Enter the name of the file to write to: ";
                getline(cin, filename);
                player_list.write_file(filename);
            }
            else{
                string filename;
                cout << "Enter the name of the file to write to: ";
                getline(cin, filename);
                player_list.main_write_file(filename);
            }
            /*
            for(const auto& [e.getLastName(), e.getFirstName(), e.getYearOfBirth(), e.Category(), e.RegStatus()] : player_list){
                cout << e.lastName << '\n';
                cout << e.firstName << '\n';
                cout << e.yearOfBirth << '\n';
                cout << e.category << '\n';
                cout << e.regStatus << '\n';
            }
            player_list.display_current_player();
            */
            break;
        }
        case 'd': {}
        case 'S': {}

        case 'n': {
            searched_list.move_to_next();
            break;
        }
        case 'p': {
            searched_list.move_to_prev();
            break;
        }
        case 'E': {
            searched_list.clear();
            MorS = true;
        }
    }
}