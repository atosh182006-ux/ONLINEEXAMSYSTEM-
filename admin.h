#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <fstream>

class Admin : public User {
public:
    Admin(int id, string u, string p)
        : User(id, u, p, "Admin") {}

    void login() override {
        cout << "Admin Login Successful\n";
    }

    void addQuestion() {
        ofstream file("data/questions.txt", ios::app);

        int id;
        string question, op1, op2, op3, op4, correct;

        cout << "Enter Question ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Question: ";
        getline(cin, question);

        cout << "Enter 4 options:\n";
        getline(cin, op1);
        getline(cin, op2);
        getline(cin, op3);
        getline(cin, op4);

        cout << "Correct Answer: ";
        getline(cin, correct);

        file << id << "|" << question << "|"
             << op1 << "," << op2 << "," << op3 << "," << op4
             << "|" << correct << endl;

        file.close();
        cout << "Question Added Successfully!\n";
    }
};

#endif