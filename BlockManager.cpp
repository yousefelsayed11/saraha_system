#include "BlockManager.h"
#include "User.h"

bool BlockManager::isBlocked(int ownerID, int targetID) {
    return blockUser[ownerID].count(targetID) > 0;
}

void BlockManager::blockUserBy(int ownerID, int targetID) {
    if (!isBlocked(ownerID, targetID)) {
        blockUser[ownerID].insert(targetID);
        cout << "User " << ownerID << " has blocked user " << targetID << ".\n";
    }
    else {
        cout << "User " << targetID << " is already blocked by user " << ownerID << ".\n";
    }
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

void BlockManager::setBlockUser(int ownerID, const set<int>& blockedSet) {
    blockUser[ownerID] = blockedSet;
}

const unordered_map<int, set<int>>& BlockManager::getBlockUser() const {
    return blockUser;
}
