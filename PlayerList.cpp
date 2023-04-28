#include "PlayerList.h"
#include <algorithm>
#include <fstream>
//#include <ifstream>
using std::ifstream;
using std::ofstream;
#include <iostream>
using std::cout;
using std::endl;
#include <map>
using std::pair;
#include <string>
using std::string;

void PlayerList::update_current_player(const Player & new_data){
    itr_current_player->second.update(new_data);
    string new_lname = new_data.lastName;
    if ( (!new_lname.empty()) && (new_lname != itr_current_player->first) ) {
        auto result = m_players.insert({new_lname, itr_current_player->second});
        m_players.erase(itr_current_player);
        itr_current_player = result.first;
    }
}
string PlayerList::calculate_category(std::string & yearOfBirth){
            int birth_year = stoi(yearOfBirth);
            int category_int = season - birth_year; //season year - birthyear = category
            if (4<= category_int && category_int < 6){
                return "U6";
            }
            else if(6 <= category_int && category_int < 8){
                return "U8";
            }
            else if(8 <= category_int && category_int < 10){
                return "U10";
            }
            else if(10 <= category_int && category_int < 12){
                return "U12";
            }
            else if(12 <= category_int && category_int < 14){
                return "U14";
            }
            else if(14 <= category_int && category_int < 17){
                return "U17";
            }
            else{
                return "invalid";
            }
}
void PlayerList::read_file(const std::string & file_name){
    ifstream ifs(file_name);
    if (!ifs) // no file -- one will be created when write_file is called
        return;

    int num_players;
    int season0;
    ifs >> num_players;
    cout << "num_p: " << num_players;
    ifs.get(); // \n
    ifs >> season0;
    cout << "sea: " << season0;
    ifs.get(); // \n
    for (int i = 0; i < num_players; i++) {
        Player new_player;
        ifs >> new_player;
        // m_entries[new_entry.name] = new_entry;
        m_players.insert(m_players.end(),
                          {new_player.lastName, new_player});
    }
    itr_current_player = m_players.begin();
}
void PlayerList::write_file(const std::string & file_name) const{
    ofstream save(file_name);
    for (auto it = m_players.begin(); it != m_players.end(); ++it) {
        save << it->second;
    }
}

void PlayerList::main_write_file(const std::string & file_name) const{
    ofstream save(file_name);
    save << "U6 Players: " <<endl;
    for (auto it = m_players.begin(); it != m_players.end(); ++it) {
        if (it->second.category == "U6") {
            save << it->second;
        }
    }

    save << "U8 Players: " <<endl;
    for (auto it = m_players.begin(); it != m_players.end(); ++it) {
        if (it->second.category == "U8") {
            save << it->second;
        }
    }
    save << "U10 Players: " <<endl;
    for (auto it = m_players.begin(); it != m_players.end(); ++it) {
        if (it->second.category == "U10") {
            save << it->second;
        }
    }
    save << "U12 Players: " <<endl;
    for (auto it = m_players.begin(); it != m_players.end(); ++it) {
        if (it->second.category == "U12") {
            save << it->second;
        }
    }
    save << "U14 Players: " <<endl;
    for (auto it = m_players.begin(); it != m_players.end(); ++it) {
        if (it->second.category == "U14") {
            save << it->second;
        }
    }
    save << "U17 Players: " <<endl;
    for (auto it = m_players.begin(); it != m_players.end(); ++it) {
        if (it->second.category == "U17") {
            save << it->second;
        }
    }
    
}