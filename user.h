#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    int userID;
    string username;
    string password;
    string role;

public:
    User(int id, string u, string p, string r) {
        userID = id;
        username = u;
        password = p;
        role = r;
    }

    virtual void login() = 0;

    bool verifyCredentials(string u, string p) {
        return (u == username && p == password);
    }

    string getUsername() { return username; }
    string getRole() { return role; }
};

#endif