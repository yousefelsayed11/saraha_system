#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <sstream>
#include <unordered_map>
#include <windows.h>
#include "User.h"
#include "Messages.h"
#include "Message.h"
#include "Favorites.h"
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

// Constants
const int COLOR_SUCCESS = 10;
const int COLOR_ERROR = 12;
const int COLOR_DEFAULT = 7;
const int MAX_LOGIN_ATTEMPTS = 5;

// Global variables
Favorites favorites;
Messages messages;
unordered_map<int, User> users;
int currentId = 0;
int nextUserId = 1;

// Helper functions
//void setColor(int color) {
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
//}

void clearScreen() {
    system("cls");
}

void sleep(int ms) {
    Sleep(ms);
}

void typewriterEffect(const string& text, int color = COLOR_DEFAULT) {
    setColor(color);
    for (char c : text) {
        cout << c << flush;
        sleep(50);
    }
    setColor(COLOR_DEFAULT);
    cout << endl;
}

bool isEmailUnique(const string& email) {
    for (const auto& pair : users) {
        if (pair.second.getAccount().first == email) {
            return false;
        }
    }
    return true;
}

// Core functions
User registerUser() {
    clearScreen();
    User newUser;
    string username, email, password, confirmPassword, gender;

    cout << "<--------------- Registration Page\n";

    // Get username
    cout << "Enter your username: ";
    getline(cin, username);
    newUser.setName(username);

    // Get email
    while (true) {
        cout << "Enter email: ";
        getline(cin, email);

        if (!isEmailValid(email)) {
            typewriterEffect("Invalid email format.", COLOR_ERROR);
            continue;
        }

        if (!isEmailUnique(email)) {
            typewriterEffect("This email is already registered.", COLOR_ERROR);
            continue;
        }
        break;
    }

    // Get password
    while (true) {
        cout << "Enter password: ";
        getline(cin, password);

        if (!isStrongPassword(password)) {
            typewriterEffect("Weak password. Must be at least 8 characters.", COLOR_ERROR);
            continue;
        }

        cout << "Re-enter password: ";
        getline(cin, confirmPassword);

        if (password != confirmPassword) {
            typewriterEffect("Passwords do not match.", COLOR_ERROR);
            continue;
        }
        break;
    }

    // Get gender
    while (true) {
        cout << "Enter gender (M/F): ";
        getline(cin, gender);

        if (gender.size() == 1 && (toupper(gender[0]) == 'M' || toupper(gender[0]) == 'F')) {
            newUser.setGender(string(1, gender[0]));
            break;
        }
        typewriterEffect("Invalid input. Only M or F allowed.", COLOR_ERROR);
    }

    // Finalize user
    newUser.setAccount({ email, hashPassword(password) });
    newUser.setId(nextUserId);
    users[nextUserId] = newUser;
    currentId = nextUserId;
    nextUserId++;

    typewriterEffect("Account created successfully!", COLOR_SUCCESS);
    sleep(500);

    return newUser;
}

bool loginUser() {
    clearScreen();
    cout << "  ------------------> Login Page\n";

    int attempts = 0;
    while (attempts < MAX_LOGIN_ATTEMPTS) {
        string email, password;

        // Get email
        cout << "Enter email: ";
        getline(cin, email);

        if (!isEmailValid(email)) {
            typewriterEffect("Invalid email format.", COLOR_ERROR);
            attempts++;
            continue;
        }

        // Get password
        cout << "Password: ";
        getline(cin, password);

        // Check credentials
        for (auto& pair : users) {
            if (pair.second.login(email, password)) {
                typewriterEffect("Login successful!", COLOR_SUCCESS);
                sleep(300);
                currentId = pair.first;
                return true;
            }
        }

        attempts++;
        if (attempts < MAX_LOGIN_ATTEMPTS) {
            typewriterEffect("Incorrect email or password. Attempts remaining: " +
                to_string(MAX_LOGIN_ATTEMPTS - attempts), COLOR_ERROR);
        }
    }

    typewriterEffect("Maximum login attempts reached.", COLOR_ERROR);
    return false;
}

// Menu functions
void showMainMenu() {
    clearScreen();
    cout << "\n===== Modified-Saraha =====\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
    cout << "===========================\n";
}

void showUserMenu() {
    clearScreen();
    cout << "\n===== User Menu =====\n";
    cout << "1. Profile\n";
    cout << "2. Send Message\n";
    cout << "3. Undo Last Sent Message\n";
    cout << "4. View Sent Messages\n";
    cout << "5. View All Received Messages\n";
    cout << "6. View Received Messages From Specific Contact\n";
    cout << "7. Remove Oldest Favorite Message\n";
    cout << "8. View Favorite Messages\n";
    cout << "9. Remove Contacts\n";
    cout << "10. Search Contacts\n";
    cout << "11. View Contacts List\n";
    cout << "12. Block User\n";
    cout << "13. Unblock User\n";
    cout << "14. View Blocked Users List\n";
    cout << "15. Log Out\n";
    cout << "===========================\n";
}

// Data persistence
void saveAllData() {
    // Save users
    ofstream userFile("users.csv");
    if (userFile) {
        userFile << "ID,Name,Gender,Email,Password\n";
        for (const auto& pair : users) {
            const User& user = pair.second;
            auto acc = user.getAccount();
            userFile << user.getId() << ","
                << user.getName() << ","
                << user.getGender() << ","
                << acc.first << ","
                << acc.second << "\n";
        }
    }

    // Save contacts
    ofstream contactFile("contacts.csv");
    if (contactFile) {
        contactFile << "UserID,ContactID\n";
        for (const auto& pair : users) {
            for (const auto& contact : pair.second.getContacts()) {
                contactFile << pair.first << "," << contact.id << "\n";
            }
        }
    }

    // Save blocked users
    ofstream blockFile("blocked_users.csv");
    if (blockFile) {
        blockFile << "UserID,BlockedID\n";
        for (const auto& pair : users) {
            for (const auto& bid : pair.second.getblockUser()) {
                blockFile << pair.first << "," << bid << "\n";
            }
        }
    }

    // Save messages
    ofstream messageFile("messages.csv");
    if (messageFile) {
        messageFile << "SenderID,SenderUsername,ReceiverUsername,Content,Timestamp\n";
        for (const Message& msg : messages.getSentMessages()) {
            messageFile << msg.getSenderId() << ","
                << msg.getSenderUsername() << ","
                << msg.getReceiverUsername() << ","
                << msg.getContent() << ","
                << msg.getTimestamp() << "\n";
        }
    }
}

void loadAllData() {
    // Load users
    ifstream userFile("users.csv");
    if (userFile) {
        string line;
        getline(userFile, line); // Skip header

        while (getline(userFile, line)) {
            stringstream ss(line);
            string idStr, name, gender, email, password;

            if (getline(ss, idStr, ',') &&
                getline(ss, name, ',') &&
                getline(ss, gender, ',') &&
                getline(ss, email, ',') &&
                getline(ss, password)) {

                try {
                    int id = stoi(idStr);
                    User user;
                    user.setId(id);
                    user.setName(name);
                    user.setGender(string(1, gender[0]));
                    user.setAccount({ email, password });
                    users[id] = user;

                    if (id >= nextUserId) {
                        nextUserId = id + 1;
                    }
                }
                catch (...) {
                    continue;
                }
            }
        }
    }

    // Load contacts
    ifstream contactFile("contacts.csv");
    if (contactFile) {
        string line;
        getline(contactFile, line); // Skip header

        while (getline(contactFile, line)) {
            stringstream ss(line);
            string uidStr, cidStr;

            if (getline(ss, uidStr, ',') && getline(ss, cidStr, ',')) {
                try {
                    int uid = stoi(uidStr);
                    int cid = stoi(cidStr);

                    if (users.count(uid) && users.count(cid)) {
                        users[uid].addContact(cid);
                    }
                }
                catch (...) {
                    continue;
                }
            }
        }
    }

    // Load blocked users
    ifstream blockFile("blocked_users.csv");
    if (blockFile) {
        string line;
        getline(blockFile, line); // Skip header

        while (getline(blockFile, line)) {
            stringstream ss(line);
            string uidStr, bidStr;

            if (getline(ss, uidStr, ',') && getline(ss, bidStr, ',')) {
                try {
                    int uid = stoi(uidStr);
                    int bid = stoi(bidStr);

                    if (users.count(uid)) {
                        users[uid].setblockUser(bid);
                    }
                }
                catch (...) {
                    continue;
                }
            }
        }
    }

    // Load messages
    ifstream messageFile("messages.csv");
    if (messageFile) {
        string line;
        getline(messageFile, line); // Skip header

        vector<Message> loadedMessages;
        while (getline(messageFile, line)) {
            stringstream ss(line);
            string senderIdStr, senderUsername, receiverUsername, content, timestampStr;

            if (getline(ss, senderIdStr, ',') &&
                getline(ss, senderUsername, ',') &&
                getline(ss, receiverUsername, ',') &&
                getline(ss, content, ',') &&
                getline(ss, timestampStr)) {

                try {
                    int senderId = stoi(senderIdStr);
                    Message msg(senderUsername, senderId, receiverUsername, content);
                    loadedMessages.push_back(msg);
                }
                catch (...) {
                    continue;
                }
            }
        }
        messages.setSentMessages(loadedMessages);
    }
}

// Main function
int main() {
    // Load existing data
    loadAllData();

    // Main loop
    while (true) {
        showMainMenu();
        string choice;
        cout << "Enter choice: ";
        getline(cin, choice);

        if (choice == "1") {
            registerUser();
        }
        else if (choice == "2") {
            if (loginUser()) {
                // User menu loop
                while (currentId != 0) {
                    showUserMenu();
                    cout << "Enter choice: ";
                    getline(cin, choice);

                    if (choice == "1") {
                        // Profile
                        users[currentId].displayUser();
                        cout << "\nPress Enter to continue...";
                       // cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    else if (choice == "15") {
                        currentId = 0; // Log out
                    }
                    else {
                        // Handle other menu options...
                        typewriterEffect("Feature not yet implemented", COLOR_ERROR);
                        sleep(1000);
                    }
                }
            }
        }
        else if (choice == "3") {
            saveAllData();
            typewriterEffect("Goodbye!", COLOR_SUCCESS);
            break;
        }
        else {
            typewriterEffect("Invalid choice.", COLOR_ERROR);
        }
    }

    return 0;
}