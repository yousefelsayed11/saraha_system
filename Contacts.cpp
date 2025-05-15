#include "Contacts.h"
#include "unordered_map"
#include "map"
#include <algorithm>
#include <iostream>
using namespace std;

void Contacts::addContact(int userID, int contactID)
{
    if (!contactExists(userID, contactID)) {
        contacts[userID].insert(contactID);
        cout << "Contact with ID " << contactID << " added for User " << userID << endl;
    }
    else {
        cout << "Contact with ID " << contactID << " already exists for User " << userID << endl;
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
    auto it = senderMessageCount.find(userId);
    if (it == senderMessageCount.end() || it->second.empty()) {
        cout << "No contacts found for user ID " << userId << endl;
        return;
    }

    const map<int, int>& userMsgMap = it->second;
    vector<pair<int, int>> sortedMessages(userMsgMap.begin(), userMsgMap.end());

    sort(sortedMessages.begin(), sortedMessages.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
        });

    for (const auto& pair : sortedMessages) {
        cout << "Contact ID: " << pair.first << "  Messages: " << pair.second << endl;
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

