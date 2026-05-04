#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Question.h"

class Student : public User {
public:
    Student(int id, string u, string p)
        : User(id, u, p, "Student") {}

    void login() override {
        cout << "Student Login Successful\n";
    }

    void takeExam() {
        Question q;
        q.loadQuestions();
        q.startExam(username);
    }
};

#endif