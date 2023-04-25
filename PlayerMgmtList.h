// PlayerMgmtList.h

#include <iostream>
#include <map>
#include <string>

#include "PlayerEntry.h"

using namespace std;

class PlayerMgmtList{
public:
    PlayerMgmtList() : itr_current_player(m_entries.end()) {}

    void add(const PlayerEntry & e);
    void display_current_entry() const;
    void move_to_next();
    void move_to_previous();
    void update_current_player(const PlayerEntry & new_data);
    void find(const string & name);
    bool empty() const { return m_entries.empty(); }
    void read_file(const string & file_name);
    void write_file(const string & file_name) const;


private:
    map<string, PlayerEntry> m_entries;
    map<string, PlayerEntry>::iterator itr_current_player;
};

inline void PlayerMgmtList::add(const PlayerEntry & e){
    auto result = m_entries.insert({e.getLastName(), e});
    itr_current_player = result.first;
}

inline void PlayerMgmtList::display_current_entry() const{

}

inline void PlayerMgmtList::move_to_next(){
    if (m_entries.empty())
            return;
        ++itr_current_player;
        if (itr_current_player == m_entries.end())
            itr_current_player = m_entries.begin();
}
inline void PlayerMgmtList::move_to_previous(){
    if (m_entries.empty())
            return;
        --itr_current_player;
        if (itr_current_player == m_entries.begin())
            itr_current_player = m_entries.end();
}

inline void PlayerMgmtList::find(const string & name){
    //Sangwon
}
