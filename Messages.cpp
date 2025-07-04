#include "Messages.h"
#include <iostream>
#include <algorithm>
#include "User.h"
#include"Favorites.h"
using namespace std;


void Messages::sendMessage(string& senderUsername,int senderid, string& receiverUsername, string& content, vector<string>& registeredUsernames, vector<User*>& allUsers, Contacts& contacts, BlockManager& blockManager) {
  
    for (User* u : allUsers) {
        if (u->getName() == receiverUsername) {
            int receiverId = u->getId();

           
            if (!contacts.contactExists(receiverId, senderid)) {
                contacts.addContact(receiverId, senderid);
            }

           
            contacts.getContacts()[receiverId][senderid]++;

            cout << "Added message for : " << senderUsername << endl;
            break;
        }
    }


    Message msg(senderUsername, senderid,receiverUsername, content);
    sentMessages.push_back(msg);
    receivedMessages[receiverUsername].push_back(msg);
    undoStack.push(msg);
    cout << "Message sent successfully!\n";
    
}
bool Messages::undoLastSentMessage(const string& currentUsername) {
    stack<Message> tempStack;
    bool found = false;

    while (!undoStack.empty()) {
        Message last = undoStack.top();
        undoStack.pop();

        if (last.getSenderUsername() == currentUsername ) {
           
            for (auto it = sentMessages.rbegin(); it != sentMessages.rend(); ++it) {
                if (it->getSenderUsername() == last.getSenderUsername() &&
                    it->getReceiverUsername() == last.getReceiverUsername() &&
                    it->getContent() == last.getContent() &&
                    it->getTimestamp() == last.getTimestamp()) {
                    sentMessages.erase(next(it).base());
                    break;
                }
            }

        
            auto& msgs = receivedMessages[last.getReceiverUsername()];
            for (auto it = msgs.rbegin(); it != msgs.rend(); ++it) {
                if (it->getSenderUsername() == last.getSenderUsername() &&
                    it->getContent() == last.getContent() &&
                    it->getTimestamp() == last.getTimestamp()) {
                    msgs.erase(next(it).base());
                    break;
                }
            }

            found = true;
            cout << "Last message by " << currentUsername << " undone.\n";
            break;
        }
        else {
            tempStack.push(last); 
        }
    }

    
    while (!tempStack.empty()) {
        undoStack.push(tempStack.top());
        tempStack.pop();
    }

    if (!found) {
        cout << "No sent message to undo for " << currentUsername << ".\n";
        return false;
    }

    return true;
}


bool Messages::is_username_regiter(string username, vector<User*>& allUsers)
{
    for (auto& pair1 : allUsers) {
        string name = pair1->getName();
        registeredUsernames.push_back(name);
        if (name == username) {
            return true;
              
        }
    }
    return false;

}



void Messages::viewSentMessages(string& currentUsername) {
    bool hasMessages = false;
    for (auto& msg : sentMessages) {
        if (msg.getSenderUsername() == currentUsername) {
            hasMessages = true;
            break;
        }
    }

    if (!hasMessages) {
        cout << "You haven't sent any messages yet.\n";
    }
    else {
        for (auto& msg : sentMessages) {
            if (msg.getSenderUsername() == currentUsername) {
                time_t timestamp = time(nullptr);
                char buffer[26];
                ctime_s(buffer, sizeof(buffer), &timestamp);
                string date(buffer);
                date.pop_back();
                cout << "[" << date << "] To "
                    << msg.getReceiverUsername() << ": "
                    << msg.getContent() << "\n";
            }
        }
    }
}



void Messages::viewReceivedMessageFrom(int senderId, string& receiverUsername) {
    auto it = receivedMessages.find(receiverUsername);
    if (it != receivedMessages.end()) {
        vector<Message>& msgs = it->second;
        bool found = false;
        for (Message& msg : msgs) {
            if (msg.getSenderId() == senderId) {
                cout << "From: " << senderId << "\n";
                cout << "Message: " << msg.getContent() << "\n";
                cout << "Date: " << msg.getDate() << "\n\n";
                found = true;
            }
        }
        if (!found)
            cout << "No messages from " << senderId << ".\n";
    }
    else {
        cout << "No messages received by " << receiverUsername << ".\n";
    }
}

void Messages::setReceivedMessages(map<string, vector<Message>>msg)
{
    this->receivedMessages = msg;
}

void Messages::setSentMessages(vector<Message> msg)
{
    this->sentMessages = msg;
}


void Messages::viewMyReceivedMessages(string& myUsername) {
    auto it = receivedMessages.find(myUsername);
    if (it != receivedMessages.end()) {
        cout << "Your received messages:\n";
        for (auto& msg : it->second) {
            time_t timestamp = time(nullptr);
            char buffer[26];
            ctime_s(buffer, sizeof(buffer), &timestamp);
            string date(buffer);
            date.pop_back();
            cout << "[" << date << "] " << ": " << msg.getContent() << "\n";

        }
    }
    else {
        cout << "You have not received any messages.\n";
    }
}


const vector<Message>& Messages::getSentMessages()const {
    return sentMessages;
}

map<string, vector<Message>>& Messages::getReceivedMessages() {
    return receivedMessages;
}
