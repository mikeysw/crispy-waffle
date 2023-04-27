#include "PlayerList.h"

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

void PlayerList::read_file(const std::string & file_name){
    ifstream ifs(file_name);
    if (!ifs) // no file -- one will be created when write_file is called
        return;

    int num_players;
    int season0;
    ifs >> num_players;
    ifs.get(); // \n
    ifs >> season0;
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

    auto itr_print_current_player = m_players.begin();
    for (int i = 0; i < m_players.size(); ++i) {
        cout << itr_print_current_player->second;
        ++itr_print_current_player;
    }
}