#include "BlockManager.h"
#include "User.h"
bool BlockManager::isblock(int ID)
{

    for (auto found : blockUser)
        if (found == ID)
            return true;
    return false;
}

void BlockManager::doB_User(int ID)
{
    if (!isblock(ID)) {
        blockUser.push_back(ID);
        string text = "done blocked the user : ";
        type(text);
        cout << ID << endl;
        /*  cout << blockUser.size();*/
    }
    else
    {
        cout << "this user is already blocked before\n";
    }
}

void BlockManager::unBlock(int ID)
{
    for (auto it = blockUser.begin();it != blockUser.end();++it) {
        if (*it == ID) {
            blockUser.erase(it);
            type("UnBlock :");
            cout << ID << endl;
            return;
        }
    }
    cout << "this User notBlocked " << ID << endl;
}

void BlockManager::view_user_is_blocked()
{
    if (blockUser.empty()) {
        cout << "You have not blocked any users.\n";
        return;
    }

    cout << "Blocked Users:\n";
    for (int Id : blockUser) {
        cout << "- User ID: " << Id << endl;
    }
}

void BlockManager::setblockUser(int newblockUser)
{
    blockUser.push_back(newblockUser);
}

const vector<int>& BlockManager::getblockUser() const
{
    return blockUser;
}
