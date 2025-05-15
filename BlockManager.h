#pragma once
#include "Contacts.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <map>
#include <windows.h>
#include "Message.h"
class BlockManager
{
    unordered_map<int, set<int>> blockUser; // ownerID -> set of blocked IDs

public:
    bool isBlocked(int ownerID, int targetID);
    void blockUserBy(int ownerID, int targetID);
    void unblockUserBy(int ownerID, int targetID);
    void viewBlockedUsers(int ownerID);
    void setBlockUser(int ownerID, const set<int>& blockedSet);
    const unordered_map<int, set<int>>& getBlockUser() const;

};

