// Group Members:
/*
- Hoft. K, 15413
- Pawirosetiko. T, 15589
- Soekhlal. A, 15397
- Waterberg. A, 15518
- Welzijn. C, 15632
*/

// Employee Monthly Performance Tracker
// This program takes in employee names and their daily productivity scores,
// then calculates stats like average, highest, lowest, and gives a rating.

#include <iostream>
#include <string>
#include <limits>  // needed for clearing bad input from cin
using namespace std;

int main() {
    int numEmployees;

    cout << "=== Employee Monthly Performance Tracker ===" << endl;
    cout << endl;

    // get number of employees, make sure its a valid positive number
    while (true) {
        cout << "How many employees will be evaluated? ";
        cin >> numEmployees;

        if (cin.fail()) {
            // user typed something thats not a number
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That's not a valid number. Try again." << endl;
        }
        else if (numEmployees <= 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You need at least 1 employee. Try again." << endl;
        }
        else if (numEmployees > 50) {
            // putting a cap so nobody enters something crazy
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Max 50 employees at a time. Try again." << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    for (int i = 0; i < numEmployees; i++) {
        string name;
        int daysWorked;

        cout << "\n--- Employee " << (i + 1) << " ---" << endl;

        // get name - using getline so names with spaces work
        cout << "Enter employee's name: ";
        getline(cin, name);

        // check if name is empty
        while (name.empty()) {
            cout << "Name can't be blank. Enter employee's name: ";
            getline(cin, name);
        }

        // get days worked with validation
        while (true) {
            cout << "Enter the number of days worked this month: ";
            cin >> daysWorked;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a number." << endl;
            }
            else if (daysWorked < 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Days can't be negative." << endl;
            }
            else if (daysWorked > 31) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "A month only has up to 31 days. Try again." << endl;
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }

        // handle the case where someone worked 0 days
        if (daysWorked == 0) {
            cout << "\n>>> Results for " << name << " <<<" << endl;
            cout << "  Days worked:            0" << endl;
            cout << "  No scores to calculate." << endl;
            cout << "  Performance rating:     N/A" << endl;
            continue;  // skip to next employee
        }

        int totalScore = 0;
        int highestScore = 0;
        int lowestScore = 100;

        for (int day = 0; day < daysWorked; day++) {
            int score;

            // keep asking until we get a valid score between 0 and 100
            while (true) {
                cout << "  Productivity score for day " << (day + 1) << " (0-100): ";
                cin >> score;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "  That's not a number. Try again." << endl;
                }
                else if (score < 0 || score > 100) {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "  Invalid score! Please enter a value between 0 and 100." << endl;
                }
                else {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
            }

            totalScore += score;

            if (score > highestScore) {
                highestScore = score;
            }
            if (score < lowestScore) {
                lowestScore = score;
            }
        }

        // calculate average - need to cast to double so we dont get integer division
        double averageScore = static_cast<double>(totalScore) / daysWorked;

        // figure out the rating based on the average
        string rating;
        if (averageScore >= 80) {
            rating = "Excellent";
        }
        else if (averageScore >= 60) {
            rating = "Good";
        }
        else if (averageScore >= 40) {
            rating = "Satisfactory";
        }
        else {
            rating = "Needs Improvement";
        }

        // print out the results for this employee
        cout << "\n>>> Results for " << name << " <<<" << endl;
        cout << "  Days worked:            " << daysWorked << endl;
        cout << "  Total productivity:     " << totalScore << endl;
        cout << "  Average productivity:   " << averageScore << endl;
        cout << "  Highest daily score:    " << highestScore << endl;
        cout << "  Lowest daily score:     " << lowestScore << endl;
        cout << "  Performance rating:     " << rating << endl;
    }

    cout << "\n=== All employees processed. Goodbye! ===" << endl;

    return 0;
}
