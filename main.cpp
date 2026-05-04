#include <iostream>
#include "Student.h"
#include "Admin.h"
#include "Question.h"
using namespace std;

int main() {
    int choice;

    do {
        cout << "\n1. Student\n2. Admin\n3. Exit\nChoose: ";
        cin >> choice;

        try {
            if (choice == 1) {
                string u, p;
                cout << "Username: ";
                cin >> u;
                cout << "Password: ";
                cin >> p;

                Student s(1, "ashu", "1234");

                if (s.verifyCredentials(u, p)) {
                    s.login();
                    s.takeExam();
                } else {
                    throw "Invalid Student Login!";
                }
            }

            else if (choice == 2) {
                string u, p;
                cout << "Username: ";
                cin >> u;
                cout << "Password: ";
                cin >> p;

                Admin a(2, "admin", "admin123");

                if (a.verifyCredentials(u, p)) {
                    a.login();

                    int adminChoice;
                    cout << "1. Add Question\n2. View Results\nChoose: ";
                    cin >> adminChoice;

                    if (adminChoice == 1)
                        a.addQuestion();
                    else {
                        Question q;
                        q.showResults();
                    }
                } else {
                    throw "Invalid Admin Login!";
                }
            }

        } catch (const char* msg) {
            cout << "Error: " << msg << endl;
        }

    } while (choice != 3);

    return 0;
}