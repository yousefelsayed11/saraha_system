#include "Contacts.h"
#include<algorithm>
#include <iostream>
#include "vector"
void Contacts::addContact(int contactID)
{
    
    if (!contactExists( contactID))
    {
        contacts.push_back(contactID);
        
        cout << "Contact with ID " << contactID << " added  "<< endl;
    }
    else {
        cout << "Contact with ID " << contactID << " already exists." << endl;
    }
}

void Contacts::removeContact( int contactID)
{
    if (contactExists( contactID)) {
        contacts.erase(remove(contacts.begin(), contacts.end(), contactID), contacts.end());
        cout << "Contact \"" << contactID << "\" removed.\n";
    }
    else {
        cout << "Contact \"" << contactID << "\" not found.\n";
    }
}

void Contacts::view_contact()
{
    if (contacts.empty()) {
        cout << "No contacts found.\n";
        return;
    }
    vector<pair<int, int>> sortedMessages;
    for (auto& pair : senderMessageCount) {
        sortedMessages.push_back(pair);
    }
    sort(sortedMessages.begin(), sortedMessages.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
        });

    for (auto& pair : sortedMessages) {
        cout << "Contact ID: " << pair.first << "  Messages: " << pair.second << endl;
    }


}

bool Contacts::contactExists( int contactID)
{
    for (const auto& c : contacts) {
        if (c == contactID)
            return true;
    }
    return false;
}

void Contacts::setContacts(vector<int> newContacts)
{
    contacts = newContacts;
}

vector<int> Contacts::getContacts_id()const
{
    return contacts;
}

void Contacts::setSenderMessageCount(map<int, int> newSenderMessageCount)
{
    senderMessageCount = newSenderMessageCount;
}

map<int, int>& Contacts::getSenderMessageCount()
{
    return senderMessageCount;
}

