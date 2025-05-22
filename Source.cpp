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
#include "Contacts.h"
#include "BlockManager.h"
using namespace std;
// Constants
const int COLOR_SUCCESS = 10;
const int COLOR_ERROR = 12;
const int COLOR_DEFAULT = 7;
const int MAX_LOGIN_ATTEMPTS = 5;
// Global variables
//Favorites favorites;
Messages messages;
Contacts contacts;
unordered_map<int, User> users;
BlockManager blockManager;
int currentId = 0;
int nextUserId = 1;
// Helper functions
//void setColor(int color) {ظ
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
bool isUserNameUnique(const string& username) {
    for (const auto& u : users) {
        if ( u.second.getName() == username) {
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
    if (!isUserNameUnique(username))
    {
        typewriterEffect("This username is already registered.", COLOR_ERROR);
        registerUser();
    }
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
// Helper function to unescape CSV fields
string unescapeCSV(const string& input) {
    if (input.empty() || input[0] != '"') {
        return input;
    }

    string output;
    output.reserve(input.length());

    bool inQuotes = true;
    for (size_t i = 1; i < input.length(); ++i) {
        if (input[i] == '"') {
            if (i + 1 < input.length() && input[i + 1] == '"') {
                // Double quote - add single quote
                output += '"';
                ++i;
            }
            else {
                // Closing quote
                inQuotes = false;
            }
        }
        else if (inQuotes) {
            output += input[i];
        }
    }

    return output;
}
string escapeCSV(const string& input) {
    if (input.find(',') == string::npos &&
        input.find('"') == string::npos &&
        input.find('\n') == string::npos) {
        return input;
    }

    string output;
    output.reserve(input.length() + 2);
    output += '"';

    for (char c : input) {
        if (c == '"') {
            output += '"'; // Double quote
        }
        output += c;
    }

    output += '"';
    return output;
}
// Data persistence
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
                    user.setName(unescapeCSV(name));
                    user.setGender(string(1, gender[0]));
                    user.setAccount({ unescapeCSV(email), password });
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
        userFile.close();
    }

    // Load contacts
    ifstream contactFile("contacts.csv");
    if (contactFile) {
        string line;
        getline(contactFile, line); // Skip header

        while (getline(contactFile, line)) {
            stringstream ss(line);
            string uidStr, cidStr, countStr;

            if (getline(ss, uidStr, ',') && getline(ss, cidStr, ',') && getline(ss, countStr)) {
                try {
                    int uid = stoi(uidStr);
                    int cid = stoi(cidStr);
                    int count = stoi(countStr);

                    if (users.count(uid) && users.count(cid)) {
                        
                        if (!contacts.contactExists(uid, cid)) {
                            contacts.addContact(uid, cid);
                        }
                        contacts.getContacts()[uid][cid] = count;
                    }
                }
                catch (...) {
                    continue;
                }
            }
        }
        contactFile.close();
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
                        blockManager.blockUserBy(uid, bid);
                    }
                }
                catch (...) {
                    continue;
                }
            }
        }
        blockFile.close();
    }

    // Load messages
    ifstream messageFile("messages.csv");
    if (messageFile) {
        string line;
        getline(messageFile, line); // Skip header

        vector<Message> loadedMessages;
        map<string, vector<Message>> receivedMessages;

        while (getline(messageFile, line)) {
            stringstream ss(line);
            string userIdStr, senderIdStr, senderUsername, receiverUsername, content, timestampStr;

            if (getline(ss, senderIdStr, ',') &&
                getline(ss, senderUsername, ',') &&
                getline(ss, receiverUsername, ',') &&
                getline(ss, content, ',') &&
                getline(ss, timestampStr)) {

                try {
                    int senderId = stoi(senderIdStr);
                    Message msg(senderUsername, senderId, receiverUsername, content);

                    loadedMessages.push_back(msg);
                    receivedMessages[receiverUsername].push_back(msg); // <-- Add to receiver's inbox
                }
                catch (...) {
                    continue;
                }
            }
        }

        messages.setSentMessages(loadedMessages);
        messages.setReceivedMessages(receivedMessages); // <-- Set the map
        messageFile.close();
    }

   
    // Load favorites
    ifstream favoritesFile("favorites.csv");
    if (favoritesFile) {
        string line;
        getline(favoritesFile, line); // Skip header

        // Temporary map to store favorites by user ID
        unordered_map<int, deque<Message>> userFavorites;

        while (getline(favoritesFile, line)) {
            stringstream ss(line);
            string userIdStr, senderIdStr, senderUsername, receiverUsername, content, timestampStr;

            if (getline(ss, userIdStr, ',') &&
                getline(ss, senderIdStr, ',') &&
                getline(ss, senderUsername, ',') &&
                getline(ss, receiverUsername, ',') &&
                getline(ss, content, ',') &&
                getline(ss, timestampStr)) {

                try {
                    int userId = stoi(userIdStr);
                    int senderId = stoi(senderIdStr);
                    Message msg(senderUsername, senderId, receiverUsername, content);
                    userFavorites[userId].push_back(msg);
                }
                catch (...) {
                    continue;
                }
            }
        }

        // Assign favorites to each user
        for (auto& pair : userFavorites) {
            if (users.count(pair.first)) {
                users[pair.first].getFavorites().setFavoriteMessages(pair.second);
            }
        }
        favoritesFile.close();
    }
}

void saveAllData() {
    // Save users
    ofstream userFile("users.csv");
    if (userFile) {
        userFile << "ID,Name,Gender,Email,Password\n";
        for (const auto& pair : users) {
            const User& user = pair.second;
            auto acc = user.getAccount();
            userFile << user.getId() << ","
                << escapeCSV(user.getName()) << ","
                << user.getGender() << ","
                << escapeCSV(acc.first) << ","
                << acc.second << "\n";
        }
        userFile.close();
    }

    // Save contacts
    ofstream contactFile("contacts.csv");
    if (contactFile) {
        contactFile << "UserID,ContactID,MessageCount\n";
        for (const auto& pair : contacts.getContacts()) {
            int userID = pair.first;
            const map<int, int>& contactMap = pair.second;
            for (const auto& contactPair : contactMap) {
                int contactID = contactPair.first;
                int msgCount = contactPair.second;

                contactFile << userID << "," << contactID << "," << msgCount << "\n";
            }
        }
        contactFile.close();
    }


    // Save blocked users
    ofstream blockFile("blocked_users.csv");
    if (blockFile) {
        blockFile << "UserID,BlockedID\n";
        for (const auto& pair : blockManager.getBlockUser()) {
            for (const auto& bid : pair.second) {
                blockFile << pair.first << "," << bid << "\n";
            }
        }
        blockFile.close();
    }

    // Save messages
    ofstream messageFile("messages.csv");
    if (messageFile) {
        messageFile << "SenderID,SenderUsername,ReceiverUsername,Content,Timestamp\n";
        for (const Message& msg : messages.getSentMessages()) {
            messageFile << msg.getSenderId() << ","
                << escapeCSV(msg.getSenderUsername()) << ","
                << escapeCSV(msg.getReceiverUsername()) << ","
                << escapeCSV(msg.getContent()) << ","
                << msg.getTimestamp() << "\n";
        }
        messageFile.close();
    }

    
   // Save favorites
    ofstream favoritesFile("favorites.csv");
    if (favoritesFile) {
        favoritesFile << "UserID,SenderID,SenderUsername,ReceiverUsername,Content,Timestamp\n";
        for (const auto& userPair : users) {
            const User& user = userPair.second;
            const Favorites& userFavorites = user.getFavorites();
            const deque<Message>& favorites = userFavorites.getFavoriteMessages();

            for (const Message& msg : favorites) {
                favoritesFile << user.getId() << ","
                    << msg.getSenderId() << ","
                    << escapeCSV(msg.getSenderUsername()) << ","
                    << escapeCSV(msg.getReceiverUsername()) << ","
                    << escapeCSV(msg.getContent()) << ","
                    << msg.getTimestamp() << "\n";
            }
        }
        favoritesFile.close();
    }
}

// Helper function to escape CSV special characters
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


void nextPage(int tempId)
{
    Sleep(100);
    system("cls");
       
    User& currentUser = users[tempId];
    int ID;
    string choice;
    showUserMenu();
    cin >> choice;
    cin.ignore();
    vector<User*> allUsers;
    for (auto it = users.begin(); it != users.end(); ++it) {
        allUsers.push_back(&(it->second));
    }


    if (choice == "1") {
        currentUser.displayUser();
        cout << "\nPress Enter to return to menu...";
        cin.get();
        nextPage(tempId);
    }
    else if (choice == "2") {

        string receiverUsername, content;
        int id=0;
        cout << "Enter receiver's username: ";
        getline(cin, receiverUsername);

            for (auto& pair : users)
            {
                string name = pair.second.getName();
                if (name == receiverUsername)
                    id = pair.second.getId();
            }
            if (blockManager.isBlocked(currentId,id )|| blockManager.isBlocked(id, currentId)){
                cout << "this accout has been blocked\n";
                cout << "Press Enter to return to menu...\n";
                cin.get();
                nextPage(tempId);
            }
        if (messages.is_username_regiter(receiverUsername, allUsers)) {
            cout << "Enter your message: ";
            getline(cin, content);

            string senderUsername = currentUser.getName();
            int senderid = currentUser.getId();

           
            messages.sendMessage(senderUsername, senderid, receiverUsername, content, messages.registeredUsernames, allUsers, contacts,blockManager);
        }
        else
        {
            cout << "This username isn't registered.\n";
        }
        cout << "Press Enter to return to menu...\n";
        cin.get();
        nextPage(tempId);

    }


    else if (choice == "3") {
        messages.undoLastSentMessage(currentUser.getName());

        cout << "Press Enter to return to menu...";
        cin.get();
        nextPage(tempId);
    }

    else if (choice == "4") {
        string senderUsername = currentUser.getName();
       const vector<Message>& allSent = messages.getSentMessages();
        vector< Message> userSentMsgs;

        cout << "\nYour sent messages:\n";
        int index = 1;
        for (auto& msg : allSent) {
            if (msg.getSenderUsername() == senderUsername) {
                cout << index << ". To " << msg.getReceiverUsername()
                    << " | " << msg.getContent() << "\n";
                userSentMsgs.push_back(msg);
                ++index;
            }
        }

        if (userSentMsgs.empty()) {
            cout << "You haven't sent any messages yet.\n";
        }
        else {
            int choice;
            cout << "\nEnter the number of the message to add to favorites (or 0 to skip): ";
            cin >> choice;
            cin.ignore();

            if (choice > 0 && choice <= userSentMsgs.size()) {
                currentUser.getFavorites().addToFavorites(userSentMsgs[choice - 1]);
            }
            else {
                cout << "No message added to favorites.\n";
            }
        }

        cout << "Press Enter to return to menu...";
        cin.get();
        nextPage(tempId);
    }

    else if (choice == "5") {
        string currentUsername = currentUser.getName();
        
        auto it = messages.getReceivedMessages().find(currentUsername);

        if (it != messages.getReceivedMessages().end() && !it->second.empty()) {
            vector<Message>& msgs = it->second;
            vector< Message*> userReceivedMsgs;

            cout << "\nYour received messages:\n";
            int index = 1;
            for (auto& msg : msgs) {
                cout << index << " | " << msg.getContent() << "\n";
                userReceivedMsgs.push_back(&msg);
                ++index;
            }

            int choice;
            cout << "\nEnter the number of the message to add to favorites (or 0 to skip): ";
            cin >> choice;
            cin.ignore();

            if (choice > 0 && choice <= userReceivedMsgs.size()) {
                currentUser.getFavorites().addToFavorites(*userReceivedMsgs[choice - 1]);
            }
            else {
                cout << "No message added to favorites.\n";
            }
        }
        else {
            cout << "You have not received any messages.\n";
        }

        cout << "Press Enter to return to menu...";
        cin.get();
        nextPage(tempId);
    }

    else if (choice == "6") {
        int senderid;
        cout << "Enter sender id  to view received messages from: ";
        cin >> senderid;

        string currentUsername = currentUser.getName();
        messages.viewReceivedMessageFrom(senderid, currentUsername);

        cout << "Press Enter to return to menu...";

        cin.ignore();
        cin.get();
        nextPage(tempId);
    }

    else if (choice == "7") {
        currentUser.getFavorites().removeOldestFavorite();
        cout << "Press Enter to return to menu...";
        cin.get();
        nextPage(tempId);
    }


    else if (choice == "8") {
        currentUser.getFavorites().viewAllFavorites();
        cout << "Press Enter to return to menu...";
        cin.get();
        nextPage(tempId);
    }
    else if (choice == "9") {
        auto it = contacts.getContacts().find(currentId);
        if (it == contacts.getContacts().end() || it->second.empty()) {
            cout << "No contacts found for this user. Nothing to remove." << endl;
           
        }
        else
        {
            contacts.view_contact(currentId);
            cout << "Enter the ID of the contact you want to remove:\n";
            cin >> ID;
            contacts.removeContact(currentId, ID);
            cin.ignore();
        }       
        cout << "Press Enter to return to menu...";

        cin.get();
        nextPage(tempId);

    }
    else if (choice == "10") {
        auto it = contacts.getContacts().find(currentId);
        if (it == contacts.getContacts().end() || it->second.empty()) {
            cout << "No contacts found for this user. Nothing to search ." << endl;

        }
        else {
            cout << "Enter the contact ID you want to search for: ";
            cin >> ID;

            if (contacts.contactExists(currentId, ID)) {
                cout << "Contact with ID " << ID << " exists in your contact list.\n";
            }
            else {
                cout << "Contact with ID " << ID << " was not found in your contact list.\n";
            }
            cin.ignore();
        }

        cout << "Press Enter to return to the menu...";
        cin.get();
        nextPage(tempId);

    }
    else if (choice == "11") {
        contacts.view_contact(currentId);
        cout << "Press Enter to return to menu...";
        cin.get();
        nextPage(tempId);

    }
    else if (choice == "12") {

        cout << "Enter the ID of the user you want to block:\n";

        cin >> ID;
        if (!currentUser.is_id_register(ID, allUsers))
        {
            cout << "This id isn't registered.\n";
        }
        else

        {
            blockManager.blockUserBy(currentId, ID);            

        }

        cout << "Press Enter to return to menu...";
        cin.ignore();
        cin.get();
        nextPage(tempId);

    }
    else if (choice == "13") {
        blockManager.viewBlockedUsers(currentId);
        const auto& blockedSet = blockManager.getBlockUser().at(currentId);
        if (!blockedSet.empty())
        {

            cout << "enter the id want to unblocked him\n ";
            cin >> ID;
            blockManager.unblockUserBy(currentId, ID);
            cin.ignore();
        }
        
        cout << "Press Enter to return to menu...";

        cin.get();
        nextPage(tempId);

    }
    else if (choice == "14") {
        cout << "1. View users I have blocked\n";
        cout << "2. View users who have blocked me\n";

        do
        {
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();
            if (choice == "1") {
                blockManager.viewBlockedUsers(currentId);
            }
            else if (choice == "2") {
                blockManager.viewUsersWhoBlocked(currentId, allUsers);
            }
            else {
                cout << "Invalid choice. Please enter 1 or 2.\n";
            }
        } while (choice!="1"&& choice!="2");
       
        cout << "Press Enter to return to menu...";
        cin.get();
        nextPage(tempId);


    }

    else if (choice == "15") {
        cout << "Logging out...\n";
        return;

    }

    else {

        cout << "Invalid choice. Try again.\n";
        nextPage(tempId);
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
            nextPage(currentId);
        }
        else if (choice == "2") {
            if (loginUser()) {                
               nextPage(currentId);
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