#define _CRT_SECURE_NO_WARNINGS
#include "Message.h"
#include <ctime>

Message::Message(string sender, int sendrid, string receiver,  string msg)
    : senderUsername(sender), senderId(sendrid),receiverUsername(receiver), content(msg) {
    timestamp = time(nullptr);
    date = ctime(&timestamp);
    date.pop_back();
    text = msg;
}

string Message::getSenderUsername() const {
    return senderUsername;
}

string Message::getReceiverUsername() const {
    return receiverUsername;
}

string Message::getContent() const {
    return content;
}

string Message::getDate() const
{
    return date;
}

string Message::getText() const
{
    return text;
}

time_t Message::getTimestamp() const {
    return timestamp;
}

int Message::getSenderId() const
{
    return senderId;
}

void Message::setSenderUsername(string senderUsername)
{
    this->senderUsername = senderUsername;

}

void Message::setReceiverUsername(string receiverUsername)
{
    this->receiverUsername = receiverUsername;
}

void Message::setContent(string content)
{
    this->content = content;
}

void Message::setDate(string date)
{
    this->date = date;
}

void Message::setText(string text)
{
    this->text = text;
}

void Message::setTimestamp(time_t timestamp)
{
    this->timestamp = timestamp;

}

void Message::setSenderId(int senderId)
{
    this->senderId = senderId;
}

