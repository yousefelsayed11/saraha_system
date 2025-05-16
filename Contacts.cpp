#include "Contacts.h"
#include "unordered_map"
#include "map"
#include <algorithm>
#include <iostream>
using namespace std;

void Contacts::addContact(int userID, int contactID)
{
    if (!contactExists(userID, contactID))
    {
        contacts[userID].insert(contactID);
        cout << "Contact with ID " << contactID << " added for User " << userID << endl;
    }
      
}

void Contacts::removeContact(int userID, int contactID)
{
    if (contactExists(userID, contactID)) {
        contacts[userID].erase(contactID);
        cout << "Contact \"" << contactID << "\" removed from User " << userID << ".\n";
    }
    else {
        cout << "Contact \"" << contactID << "\" not found for User " << userID << ".\n";
    }
}



void Contacts::view_contact(int userId) const {
    auto itContacts = contacts.find(userId);
    if (itContacts == contacts.end() || itContacts->second.empty()) {
        cout << "No contacts found for user ID " << userId << endl;
        return;
    }

    cout << "Contacts for user ID " << userId << ":\n";
    const set<int>& userContacts = itContacts->second;

    auto itMsgCount = senderMessageCount.find(userId);

    for (int contactId : userContacts) {
        int msgCount = 0;
        if (itMsgCount != senderMessageCount.end()) {
            auto itCount = itMsgCount->second.find(contactId);
            if (itCount != itMsgCount->second.end()) {
                msgCount = itCount->second;
            }
        }
        cout << "Contact ID: " << contactId << "  Messages: " << msgCount << endl;
    }
}

bool Contacts::contactExists(int userID, int contactID)
{
    return contacts[userID].count(contactID) > 0;
}

void Contacts::setContacts(unordered_map<int, set<int>> newContacts)
{
    contacts = move(newContacts);
}

const unordered_map<int, set<int>>& Contacts::getContacts() const
{
    return contacts;
}

void Contacts::setSenderMessageCount(int userId, const map<int, int>& newSenderMessageCount)
{
    map<int, int>& getSenderMessageCount(int userId);
}


map<int, int>& Contacts::getSenderMessageCount(int userId)
{
    return senderMessageCount[userId];
}

