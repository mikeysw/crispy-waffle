// PlayerList.h

#ifndef _PlayerList_h_
#define _PlayerList_h_

#include <iostream>
#include <map>
#include <string>

#include "Player.h"

using namespace std;

class PlayerList{
public:
    PlayerList() : season(-1), itr_current_player(m_players.end()) {}

    void add(const Player & p);
    void search(const Player & p, const string & keyword, PlayerList & searched);
    void update_current_player(const Player & new_data);

    void display_current_player() const;
    void move_to_next();
    void move_to_prev();

    void set_season(int season0) {season = season0;}

    bool empty() const { return m_players.empty(); }
    void clear() { m_players.clear(); }

    void edit_current_player(const Player & new_data);
    void read_file(const string & file_name);
    void write_file(const string & file_name) const;
    void main_write_file(const string & file_name) const;


private:
    int season;
    map<string, Player> m_players;
    map<string, Player>::iterator itr_current_player;
};

inline void PlayerList::add(const Player & p){

    auto result = m_players.insert({p.lastName, p});
    itr_current_player = result.first;
}

inline void PlayerList::search(const Player & p, const string & keyword, PlayerList & searched){
    while(itr_current_player != m_players.end()){
        if(itr_current_player->second.compare(p)){
            searched.add(itr_current_player->second);
        }
    }
    
}

inline void PlayerList::display_current_player() const {
    if (m_players.empty())
        return;
    cout << itr_current_player->second;
}

inline void PlayerList::move_to_next(){
    if (m_players.empty())
        return;

    ++itr_current_player;
    if (itr_current_player == m_players.end())
        itr_current_player = m_players.begin();
}

inline void PlayerList::move_to_prev(){
    if (m_players.empty())
        return;

    if (itr_current_player == m_players.begin())
        itr_current_player = m_players.end();
    --itr_current_player;
}

#endif