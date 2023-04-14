// PlayerMgmtList.h

#include <iostream>
#include <map>
#include <string>

#include "PlayerEntry.h"

using namespace std;

class PlayerMgmtList{
public:
    PlayerMgmtList() : itr_current_entry(m_entries.end()) {}

    void add(const PlayerEntry & e);
    void display_current_entry() const;
    void move_to_next();
    void update_current_entry(const PlayerEntry & new_data);
    void find(const string & name);
    bool empty() const { return m_entries.empty(); }
    void read_file(const string & file_name);
    void write_file(const string & file_name) const;


private:
    map<string, PlayerEntry> m_entries;
    map<string, PlayerEntry>::iterator itr_current_entry;
};

inline void PlayerMgmtList::add(const PlayerEntry & e){

}

inline void PlayerMgmtList::display_current_entry() const{

}

inline void PlayerMgmtList::move_to_next(){

}

inline void PlayerMgmtList::find(const string & name){
    //Sangwon
}