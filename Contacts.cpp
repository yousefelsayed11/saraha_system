#include "Contacts.h"
#include <algorithm>

void Contacts::addContact(int userID, int contactID) {
    if (!contactExists(userID, contactID)) {
        contacts[userID][contactID] = 0; 
        cout << "Contact with ID " << contactID << " added for User " << userID << endl;
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
    for (const auto& pair : it->second) {
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
