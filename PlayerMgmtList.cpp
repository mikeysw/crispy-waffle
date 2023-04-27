//PlayerMgmtList.cpp

#include "PlayerMgmtList.h"

#include <fstream>
using std::ifstream;
using std::ofstream;
#include <iostream>
using std::cout;
using std::endl;
#include <map>
using std::pair;
#include <string>
using std::string;

void PlayerMgmtList::update_current_player(const PlayerEntry & new_data){
    itr_current_player->second.update(new_data);
    string new_lname = new_data.lastName;
    if ( (!new_lname.empty()) && (new_lname != itr_current_player->first) ) {
        auto result = m_entries.insert({new_lname, itr_current_player->second});
        m_entries.erase(itr_current_player);
        itr_current_player = result.first;
    }
}

void PlayerMgmtList::read_file(const string & file_name){

}

void PlayerMgmtList::write_file(const string & file_name) const{
    ofstream save(file_name);


}