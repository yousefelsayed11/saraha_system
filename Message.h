#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Message {
private:
    string senderUsername;
    int senderId;
    string date;
    string text;

    string receiverUsername;
    string content;
    time_t timestamp;

public:

    Message(string sender,int sendrid, string receiver, string msg);
    string getSenderUsername() const;
    string getReceiverUsername() const;
    string getContent() const;
    string getDate()const;
    string getText()const;
    time_t getTimestamp() const;
    int getSenderId()const;

    void setSenderUsername(string senderUsername) ;
    void setReceiverUsername(string receiverUsername) ;
   void setContent(string content) ;
    void setDate(string date);
    void setText(string text);
    void setTimestamp(time_t timestamp) ;
    void setSenderId(int senderId);

};
