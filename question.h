#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
using namespace std;

class Question {
    struct Q {
        int id;
        string text;
        vector<string> options;
        string correct;
    };

    vector<Q> questions;

public:
    void loadQuestions() {
        ifstream file("data/questions.txt");

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            Q q;
            string temp;

            getline(ss, temp, '|');
            q.id = stoi(temp);

            getline(ss, q.text, '|');

            getline(ss, temp, '|');
            stringstream opt(temp);
            string option;
            while (getline(opt, option, ',')) {
                q.options.push_back(option);
            }

            getline(ss, q.correct);

            questions.push_back(q);
        }
        file.close();
    }

    void startExam(string username) {
        int score = 0;
        string ans;

        auto start = chrono::steady_clock::now();

        for (auto &q : questions) {

            auto now = chrono::steady_clock::now();
            int time_taken = chrono::duration_cast<chrono::seconds>(now - start).count();

            if (time_taken > 30) {
                cout << "\nTime's up!\n";
                break;
            }

            cout << "\n" << q.text << endl;

            for (int i = 0; i < q.options.size(); i++) {
                cout << i + 1 << ". " << q.options[i] << endl;
            }

            cout << "Answer: ";
            cin >> ans;

            if (ans == q.correct)
                score++;
        }

        cout << "\nFinal Score: " << score << endl;

        ofstream result("data/results.txt", ios::app);
        result << username << " Score: " << score << endl;
        result.close();
    }

    void showResults() {
        ifstream file("data/results.txt");
        string line;

        cout << "\n--- Result History ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    }
};

#endif