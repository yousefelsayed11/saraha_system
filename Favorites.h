#pragma once
#include <deque>
#include "Message.h"


class Favorites {
private:
    deque<Message> favoriteMessages;

public:
    void addToFavorites(Message& msg);
    void removeOldestFavorite();
    void viewAllFavorites();
    const deque<Message>& getFavoriteMessages()const; 
    void setFavoriteMessages(deque<Message> mg);
};
