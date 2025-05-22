#include "Contacts.h"
#include <algorithm>

void Contacts::addContact(int userID, int contactID) {
    if (!contactExists(userID, contactID)) {
        contacts[userID][contactID] = 0; 
        
    }
}

void Contacts::removeContact(int userID, int contactID) {
   
 
    if (contactExists(userID, contactID)) {
        contacts[userID].erase(contactID);
        cout << "Contact \"" << contactID << "\" removed from User " << userID << ".\n";
    }
    else {
        cout << "Contact \"" << contactID << "\" not found for User " << userID << ".\n";
    }
}

void Contacts::view_contact(int userID) const {
    auto it = contacts.find(userID);
    if (it == contacts.end() || it->second.empty()) {
        cout << "No contacts found for user ID " << userID << endl;
        return;
    }

    cout << "Contacts for user ID " << userID << ":\n";
    vector<pair<int, int>> sortedContacts(it->second.begin(), it->second.end());
    sort(sortedContacts.begin(), sortedContacts.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
        });

    for (const auto& pair : sortedContacts) {
        cout << "Contact ID: " << pair.first << "  Messages: " << pair.second << endl;
    }

}

bool Contacts::contactExists(int userID, int contactID) {
    auto it = contacts.find(userID);
    if (it != contacts.end()) {
        return it->second.count(contactID) > 0;
    }
    return false;
}

void Contacts::setContacts(unordered_map<int, map<int, int>> newContacts) {
    contacts = move(newContacts);
}

unordered_map<int, map<int, int>>& Contacts::getContacts() {
    return contacts;
}
