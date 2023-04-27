// Player.h

#ifndef _Player_h_
#define _Player_h_

#include <fstream>
#include <string>

using namespace std;

class Player{
public:
    Player() : lastName("N/A"), firstName("N/A"), yearOfBirth("N/A"),
                    category("N/A"), regStatus("N/A") {}
    Player(const string & lastName0, const string & firstName0, const string & yearOfBirth0, 
                const string & category0, const string & regStatus0) :
        lastName(lastName0), firstName(firstName0), yearOfBirth(yearOfBirth0), 
        category(category0), regStatus(regStatus0) {}

    void edit(const Player & new_data);
    bool compare(const Player & search_data);
    void update(const Player & new_data);

     // Getters
    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    string getYearOfBirth() const { return yearOfBirth; }
    string getCategory() const { return category; }
    string getRegStatus() const { return regStatus; }
    
    // Setters
    void setLastName(const string& lastName0) { this->lastName = lastName0; }
    void setFirstName(const string& firstName0) { this->firstName = firstName0; }
    void setYearOfBirth(const string& yearOfBirth0) { this->yearOfBirth = yearOfBirth0; }
    void setCategory(const string& category0) { this->category = category0; }
    void setRegStatus(const string& regStatus0) { this->regStatus = regStatus0; }


    string lastName;
    string firstName;
    //int yearOfBirth;
    string yearOfBirth;
    string category;
    string regStatus;
};

inline void Player::edit(const Player & new_data){
    
}

inline bool Player::compare(const Player & search_data){
    if(lastName == search_data.getLastName() || search_data.getLastName() == "N/A"){
        if(firstName == search_data.getFirstName() || search_data.getFirstName() == "N/A"){
            if(yearOfBirth == search_data.getYearOfBirth() || search_data.getYearOfBirth() == "N/A"){
                if(category == search_data.getCategory() || search_data.getCategory() == "N/A"){
                    if(regStatus == search_data.getRegStatus() || search_data.getRegStatus() == "N/A"){
                        return true;
                    }
                    else return false;
                }
                else return false;
            }
            else return false;
        }   
        else return false;
    }
    else return false;
}

inline void Player::update(const Player & new_data){
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

inline istream & operator>>(istream & in, Player & p){
    string temp;
    in >> p.firstName;
    in >> p.lastName;
    in.get();
    //getline(in, temp);
    //p.yearOfBirth = stoi(temp);
    getline(in, p.yearOfBirth);
    getline(in, p.category);
    getline(in, p.regStatus);

    return in;
}

inline ostream & operator<<(ostream & out, const Player & e){
   out << e.firstName << " " << e.lastName << endl
        //<< to_string(e.yearOfBirth) << endl
        << e.yearOfBirth << endl
        << e.category << endl
        << e.regStatus << endl;

    return out;
}

#endif