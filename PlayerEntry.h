//PlayerEntry.h

#ifndef _PlayerEntry_h_
#define _PlayerEntry_h_

#include <fstream>
#include <string>

using namespace std;

class PlayerEntry{
public:
    friend std::ostream & operator<<(std::ostream & out, const PlayerEntry & player);

    PlayerEntry() : lastName("no name"), firstName("no name"), yearOfBirth(-1),
                    category("invalid"), regStatus("invalid") {}
    PlayerEntry(const string & lastName0, const string & firstName0, int yearOfBirth0, 
                const string & category0, const string & regStatus0) :
        lastName(lastName0), firstName(firstName0), yearOfBirth(yearOfBirth0), 
        category(category0), regStatus(regStatus0) {
            ++ players;
        }
    
    // Getters
    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    int getYearOfBirth() const { return yearOfBirth; }
    string getCategory() const { return category; }
    string getRegStatus() const { return regStatus; }
    
    // Setters
    void setLastName(const string& lastName) { this->lastName = lastName; }
    void setFirstName(const string& firstName) { this->firstName = firstName; }
    void setYearOfBirth(int yearOfBirth) { this->yearOfBirth = yearOfBirth; }
    void setCategory(const string& category) { this->category = category; }
    void setRegStatus(const string& regStatus) { this->regStatus = regStatus; }
    
    void update(const PlayerEntry & new_data);
    void display_stats();

private:
    string lastName;
    string firstName;
    int yearOfBirth;
    string category;
    string regStatus;

    int players;
    int U6;
    int pU6;
    int upU6;
    int U8;
    int U10;
    int U12;
    int U14;
    int U16;
    int U17;

};


inline void PlayerEntry::display_stats() {
    for (int i = 0; i < players; ++i) {          //go thru all players
    if (category == "U6") {
        ++U6;
        if (regStatus == "paid") {
            ++pU6;
        } else ++upU6;
    }

        if (category == "U6") ++U6;
        else if (category == "U8") ++U8;
        else if (category == "U10") ++U10;
        else if (category == "U12") ++U12;
        else if (category == "U14") ++U14;
        else if (category == "U16") ++U16;
        else ++U17;
    
    }

    cout << "Total U6: " << U6;
    cout << "Total paid U6: " << pU6;
    cout << "Total unpaid U6:" << upU6;
    cout << "Total U8: " << U8;
    cout << "Total U10: " << U10;
    cout << "Total U12: " << U12;
    cout << "Total U14: " << U14;
    cout << "Total U16: " << U16;
    cout << "Total U17: " << U17;

}


std::ostream & operator<<(std::ostream & out, const PlayerEntry & player) {
    out << player.lastName << endl;
    out << player.firstName << endl;
    out << player.yearOfBirth << endl;
    out << player.category << endl;
    out << player.regStatus << endl;

    return out;
}

std::istream & operator>>(std::istream & in, PlayerEntry & player) {
    string lastName;
    getline(in, lastName);
    player.setLastName(lastName);
    string firstName;
    getline(in, firstName);
    player.setFirstName(firstName);
    int yearOfBirth;
    in >> yearOfBirth;
    player.setYearOfBirth(yearOfBirth);
    in.get(); //endl char
    string category;
    getline(in, category);
    player.setCategory(category);
    string regStatus;
    getline(in, regStatus);
    player.setRegStatus(regStatus);
    
    return in;
}

inline void PlayerEntry::update(const PlayerEntry & new_data){
    if (!new_data.firstName.empty())
        firstName = new_data.firstName;
    if (!new_data.lastName.empty())
        lastName = new_data.lastName;
    /*
    if (!new_data.yearOfBirth.empty())
        yearOfBirth = new_data.yearOfBirth;
        */
   //call category calculator
    if(!new_data.regStatus.empty())
        regStatus = new_data.regStatus;

}

#endif