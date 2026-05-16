#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    int id;
    std::string username;
    std::string password;

    User(int id, const std::string& username, const std::string& password);
};

#endif
