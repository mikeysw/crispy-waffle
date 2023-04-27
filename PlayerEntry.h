//PlayerEntry.h

#ifndef _PlayerEntry_h_
#define _PlayerEntry_h_

#include <fstream>
#include <string>

using namespace std;

class PlayerEntry{
public:
    PlayerEntry() : lastName("no name"), firstName("no name"), yearOfBirth("no year"),
                    category("invalid"), regStatus("invalid") {}
    PlayerEntry(const string & lastName0, const string & firstName0, const string & yearOfBirth0, 
                const string & category0, const string & regStatus0) :
        lastName(lastName0), firstName(firstName0), yearOfBirth(yearOfBirth0), 
        category(category0), regStatus(regStatus0) {
            ++ players;
        }
    
    // Getters
    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    string getYearOfBirth() const { return yearOfBirth; }
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
    string yearOfBirth;
    string category;
    string regStatus;

    int players;
    int paid;
    int unpaid;
    int U6;
    int U8;
    int U10;
    int U12;
    int U14;
    int U16;
    int U17;

};

inline void PlayerEntry::update(const PlayerEntry & new_data){
    if (!new_data.firstName.empty())
        firstName = new_data.firstName;
    if (!new_data.lastName.empty())
        lastName = new_data.lastName;
    if (!new_data.yearOfBirth.empty())
        yearOfBirth = new_data.yearOfBirth;
   //call category calculator
    if(!new_data.regStatus.empty())
        regStatus = new_data.regStatus;
}


inline void PlayerEntry::display_stats(){
    for (int i = 0; i < players; ++i) {  
        if (regStatus == "paid") ++paid;
        else ++unpaid;

        if (category == "U6") ++U6;
        else if (category == "U8") ++U8;
        else if (category == "U10") ++U10;
        else if (category == "U12") ++U12;
        else if (category == "U14") ++U14;
        else if (category == "U16") ++U16;
        else ++U17;
    }

    cout << "Total players:" << players;
    cout << "Total paid: " << paid;
    cout << "Total unpaid: " << unpaid;
    cout << "Total U6: " << U6;
    cout << "Total U8: " << U8;
    cout << "Total U10: " << U10;
    cout << "Total U12: " << U12;
    cout << "Total U14: " << U14;
    cout << "Total U16: " << U16;
    cout << "Total U17: " << U17;
}


#endif