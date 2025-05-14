#pragma once
#include "Contacts.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <windows.h>
#include "Message.h"
class BlockManager
{
private:
	vector<int >blockUser;
public:
    bool isblock(int id);
    void doB_User(int id);
    void unBlock(int id);
    void view_user_is_blocked();
    void setblockUser(int newblockUser);
    const vector<int>& getblockUser() const;

};

