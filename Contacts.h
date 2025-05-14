#pragma once
#include "Contacts.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <windows.h>
#include "Message.h"
using namespace std;
class Contacts
{
private:
	 map<int, int> senderMessageCount;
	 vector<int> contacts;
public:
	void addContact(int contactID);
	void removeContact(int contactID);
	void view_contact();
	bool contactExists(int contactID);
	void setContacts(vector<int> newContacts);
	vector<int> getContacts_id()const;
	void setSenderMessageCount(map<int, int> newSenderMessageCount);
	map<int, int>& getSenderMessageCount();

	
	 
};
