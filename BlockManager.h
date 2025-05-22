#pragma once
#include "Contacts.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <windows.h>
#include "Message.h"
#include "User.h"

class User;
class BlockManager {
private:
    unordered_map<int, unordered_set<int>> blockUser;  // ownerID -> {blockedIDs}
public:
    bool isBlocked(int ownerID, int targetID);
    void blockUserBy(int ownerID, int targetID);
    void unblockUserBy(int ownerID, int targetID);
    void viewBlockedUsers(int ownerID);
    void viewUsersWhoBlocked(int targetID, const vector<User*>& allUsers);
    void setBlockUser(int ownerID, const unordered_set<int>& blockedSet);
    const unordered_map<int, unordered_set<int>>& getBlockUser() const;
};
