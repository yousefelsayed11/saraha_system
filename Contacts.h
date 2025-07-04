#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Contacts {
private:
    unordered_map<int, unordered_map<int, int>> contacts;  // userID -> {contactID -> messageCount}

public:
    void addContact(int userID, int contactID);
    void removeContact(int userID, int contactID);
    void view_contact(int userID) const;
    bool contactExists(int userID, int contactID);

    void setContacts(const unordered_map<int, unordered_map<int, int>>& newContacts);
     unordered_map<int, unordered_map<int, int>>& getContacts() ;
};
