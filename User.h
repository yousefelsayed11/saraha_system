#pragma once
#include "Contacts.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <windows.h>
#include "Message.h"
#include <stack>
#include "Favorites.h"
#include "BlockManager.h"
using namespace std;
class User {
private:
    pair<string, string> account; 
    string gender;
    string name;
    int id;
    Favorites favorites;
   
public:
    
    User() = default;
    User(std::string name, std::pair<std::string, std::string> credentials, std::string gender, int id);
    // Setter
   
    void changePassword();
    void setAccount(pair<string, string> accountPair);
    void setGender(string g);
    void setName(string n);
    void setId(int i);
 
    int getId()const;
    string getGender()const;
    string getName()const;
    
    const pair<string, string>& getAccount()const;

    //more 
    void displayUser() ;
    bool login(const string& email, const string& password) const;
    bool is_id_register(int id, vector<User*>& allUsers);              
    Favorites& getFavorites(); 
    const Favorites& getFavorites() const;
    
};
bool isStrongPassword(const string& password);
string hashPassword(const string& password);
bool isEmailValid(const string& email);
void type(string text);
void setColor(int color);

