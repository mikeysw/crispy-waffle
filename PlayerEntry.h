//PlayerEntry.h

#ifndef _PlayerEntry_h_
#define _PlayerEntry_h_

#include <fstream>
#include <string>

using namespace std;

class PlayerEntry{
public:
    PlayerEntry() : lastName("no name"), firstName("no name"), yearOfBirth(-1),
                    category("invalid"), regStatus("invalid") {}
    PlayerEntry(const string & lastName0, const string & firstName0, int yearOfBirth0, 
                const string & category0, const string & regStatus0) :
        lastName(lastName0), firstName(firstName0), yearOfBirth(yearOfBirth0), 
        category(category0), regStatus(regStatus0) {}

    void update(const PlayerEntry & new_data);

private:
    string lastName;
    string firstName;
    int yearOfBirth;
    string category;
    string regStatus;
};

inline void PlayerEntry::update(const PlayerEntry & new_data){

}

#endif