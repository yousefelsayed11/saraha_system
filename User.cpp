#include "User.h"
#include "Messages.h"
#include "Contacts.h"
#include <iostream>
#include "Message.h"
#include<algorithm>
#include <windows.h>
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
using namespace std;
#define el "\n"
User::User(string name, pair<string, string> account, string gender, int id) {
    this->name = name;
    this->account.first = account.first;
    this->account.second = account.second;
    this->gender = gender;
    this->id = id;
}

// change password
void User::changePassword()
{
    string password, confirmPassword;
    cout << "Enter the last password: ";
    getline(cin, password);
   
    if (hashPassword(password) != this->account.second)
    {
        cout << "the last password is inCorrect so try again\n";
        changePassword();
    }

    cout << "Enter New Password: ";
    getline(cin, password);

    if (!isStrongPassword(password)) {
        cout << "Weak password. Must be at least 8 characters." << el;
        changePassword();
    }

    cout << "Re-enter New Password: ";
    getline(cin, confirmPassword);

    if (password != confirmPassword) {
        cout << "Passwords do not match." << el;
        changePassword();

    }
    this->account.second = hashPassword( password);
    cout << "The password has been changed successfully." << el;

}
// placeholder
void User::setAccount(pair<string, string> accountPair) {
    account.first = accountPair.first;
    account.second = accountPair.second;
}

void User::setGender(string g) {
    g= toupper(g[0]);
    if (g == "M")
        gender = "Male";
    else
        gender = "Female";
}
void User::setName(string n) {
    name = n;
}
void User::setId(int i) {
    id = i;
}
int User::getId()const
{
    return id;
}

string User::getGender()const
{
    return gender;
}
string User::getName()const {
    return name;
}

const pair<string, string>& User::getAccount() const
{
    return account;
}


void User::displayUser()  {
    Sleep(100);
    system("cls");
    cout << "<-------------- my_Profile" << el;
    cout << "Username: " << name << el;
    cout << "Gender: " << gender << el;
    cout << "User ID: " << id << el;
   /* for (const auto& c : contacts)
        cout << "Contact ID: " << c.id<< el;*/
    cout << "press ( y ) if you want change password\n";
    string x;
    getline(cin, x);
    if (x == "y") changePassword();



}

bool User::login(const string& email, const string& password) const {

    return account.first == email && account.second == hashPassword(password);
}

bool User::is_id_register(int id, vector<User*>& allUsers)
{
    for (const auto& u : allUsers) {
        if (u->getId() == id) {
            return true;
        }
    }
    return false;
}

Favorites& User::getFavorites()
{
    return favorites;
}




const Favorites& User::getFavorites()const
{
    return favorites;
}

Contacts& User::getContacts()
{
    return contact;
}

BlockManager& User::getBlockManager()
{
    return blockManager;
}

const Contacts& User::getContacts()const
{
    return contact;
}

const BlockManager& User::getBlockManager()const
{
    return blockManager;
}

bool isStrongPassword(const string& password) {
    if (password.length() < 8) return false;

    bool hasLetter = false;
    bool hasDigit = false;

    for (char c : password) {
        if (isalpha(c)) hasLetter = true;
        else if (isdigit(c)) hasDigit = true;
    }

    return hasLetter && hasDigit;
}

string hashPassword(const string& password) {
    hash<string> hasher;
    return to_string(hasher(password));
}

bool isEmailValid(const string& email) {
    int atIndex = email.find('@');
    if (atIndex <= 0 || atIndex == email.length() - 1)
        return false;

    int dotIndex = email.find('.', atIndex);
    if (dotIndex == -1 || dotIndex == email.length() - 1)
        return false;

    string suffix = email.substr(email.length() - 3);
    if (suffix != "com") return false;

    if (email.size() <= 10)
        return false;

    return true;
}
void type(string text)
{
    setColor(10);
    for (int i = 0;i < text.size();i++) {
        cout << text[i];
        Sleep(100);
    }
    setColor(7);

}
