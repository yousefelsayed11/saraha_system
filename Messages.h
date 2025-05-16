#pragma once
#include "Message.h"
#include "Contacts.h"
#include "BlockManager.h"
#include <vector>
#include <stack>
#include <map>
#include<queue>
#include<iostream>
using namespace std;
class User;
class BlockManager;
class Contacts;

class Messages {
private:
    vector<Message> sentMessages;
    map<string, vector<Message>> receivedMessages;
    stack<Message> undoStack;
  
public:
    bool userExists = false;
    vector<string> registeredUsernames;

   
    void sendMessage(string& senderUsername, int sendrid, string& receiverUsername, string& content, vector<string>& registeredUsernames, vector<User*>& allUsers, Contacts& contacts, BlockManager& blockManager);
    bool undoLastSentMessage(const string& currentUsername);
    bool is_username_regiter(string username, vector<User*>& allUsers);
    void viewSentMessages(string& currentUsername);

public:
    void viewMyReceivedMessages(string& myUsername);

   const vector<Message>& getSentMessages()const;
    void viewReceivedMessageFrom(int senderId, string& receiverUsername);
    void setReceivedMessages( map<string, vector<Message>>);
    void setSentMessages(vector<Message> msg);
    map<string, vector<Message>>& getReceivedMessages();

};

//private:
//   /* void viewReceivedMessagesFrom(string& viewerUsername, string& contactUsername);*/