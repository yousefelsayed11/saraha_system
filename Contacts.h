#pragma once
#include "Contacts.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <windows.h>

#include "Message.h"
#include "unordered_map"
#include "set"
using namespace std;
class Contacts
{
private:
     unordered_map<int, map<int, int>> senderMessageCount;
	 unordered_map<int,set<int>> contacts;
public:
    void addContact(int userID, int contactID);
    void removeContact(int userID, int contactID);
    void view_contact(int userID) const;
    bool contactExists(int userID, int contactID);
    void setContacts(unordered_map<int, set<int>> newContacts);

    const unordered_map<int, set<int>>& getContacts() const;
    void setSenderMessageCount(int userId, const map<int, int>& newSenderMessageCount);
    map<int, int>& getSenderMessageCount(int userId);

	 
};
