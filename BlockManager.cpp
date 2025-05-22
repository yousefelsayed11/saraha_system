#include "BlockManager.h"
#include "User.h"

bool BlockManager::isBlocked(int ownerID, int targetID) {
    return blockUser[ownerID].count(targetID) > 0;
}

void BlockManager::blockUserBy(int ownerID, int targetID) {
    if (isBlocked(ownerID, targetID)) {
       
        cout << "User " << targetID << " is already blocked by user " << ownerID << ".\n";
    }
    blockUser[ownerID].insert(targetID);
}

void BlockManager::unblockUserBy(int ownerID, int targetID) {
    if (blockUser[ownerID].erase(targetID)) {
        cout << "User " << ownerID << " has unblocked user " << targetID << ".\n";
    }
    else {
        cout << "User " << targetID << " was not blocked by user " << ownerID << ".\n";
    }
}

void BlockManager::viewBlockedUsers(int ownerID) {
    if (blockUser[ownerID].empty()) {
        cout << "User " << ownerID << " has not blocked any users.\n";
        return;
    }

    cout << "User " << ownerID << " has blocked:\n";
    for (int id : blockUser[ownerID]) {
        cout << "- User ID: " << id << endl;
    }
}

void BlockManager::viewUsersWhoBlocked(int targetID, const vector<User*>& allUsers) {
    vector<int> usersWhoBlocked;

    for (const auto& entry : blockUser) {
        int ownerID = entry.first;
        const unordered_set<int>& blocked = entry.second;

        if (blocked.find(targetID) != blocked.end()) {
            usersWhoBlocked.push_back(ownerID);
        }
    }

    if (usersWhoBlocked.empty()) {
        cout << "No users have blocked you.\n";
    }
    else {
        cout << "Users who blocked you:\n";
        for (int blockerID : usersWhoBlocked) {
            string blockerName;
            for (const User* user : allUsers) {
                if (user->getId() == blockerID) {
                    blockerName = user->getName();
                    break;
                }
            }
            cout << "- " << blockerName << " (ID: " << blockerID << ")\n";
        }
    }
}

void BlockManager::setBlockUser(int ownerID, const unordered_set<int>& blockedSet) {
    blockUser[ownerID] = blockedSet;
}

const unordered_map<int, unordered_set<int>>& BlockManager::getBlockUser() const {
    return blockUser;
}
