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

using namespace std;

int main() {
    int numEmployees;

    cout << "=== Employee Monthly Performance Tracker ===" << endl << endl;

    // Ask for number of employees
    while (true) {
        cout << "How many employees will be evaluated? ";
        cin >> numEmployees;

        if (cin.fail()) {
            cin.clear(); // clear error state
            cin.ignore(10000, '\n'); // clear out the bad input
            cout << "That's not a valid number. Try again." << endl;
        }
        else if (numEmployees <= 0 || numEmployees > 50) {
            cout << "Invalid number. Enter a value between 1 and 50." << endl;
        }
        else {
            cin.ignore(10000, '\n'); // clears the newline character for getline later
            break;
        }
    }

    for (int i = 0; i < numEmployees; i++) {
        string name;
        int daysWorked;

        cout << "\n--- Employee " << (i + 1) << " ---" << endl;

        // ask for the name
        cout << "Enter employee's name: ";
        getline(cin, name);

        // make sure they actually typed a name
        while (name == "" || name == " ") {
            cout << "Name can't be empty. Enter employee's name: ";
            getline(cin, name);
        }

        // ask for days worked
        while (true) {
            cout << "Enter the number of days worked this month: ";
            cin >> daysWorked;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Please enter a real number for days." << endl;
            }
            else if (daysWorked < 0 || daysWorked > 31) {
                cout << "Invalid days. Enter a number from 0 to 31." << endl;
            }
            else {
                // valid input
                break;
            }
        }

        if (daysWorked == 0) {
            cout << "\n>>> Results for " << name << " <<<" << endl;
            cout << "No days worked. Rating: N/A" << endl;
            // clean the buffer just in case before the next loop
            cin.ignore(10000, '\n');
            continue; 
        }

        int totalScore = 0;
        int highestScore = -1; // start low
        int lowestScore = 101; // start high

        for (int day = 0; day < daysWorked; day++) {
            int score;

            // keep asking until we get a good score
            while (true) {
                cout << "  Productivity score for day " << (day + 1) << " (0-100): ";
                cin >> score;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "  Oops! That's not a number. Try again." << endl;
                }
                else if (score < 0 || score > 100) {
                    cout << "  Invalid! Enter score 0-100." << endl;
                }
                else {
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

        double averageScore = (double)totalScore / daysWorked;

        // Find the rating
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

        cout << "\n>>> Results for " << name << " <<<" << endl;
        cout << "  Days worked: " << daysWorked << endl;
        cout << "  Total: " << totalScore << endl;
        cout << "  Average: " << averageScore << endl;
        cout << "  High: " << highestScore << " | Low: " << lowestScore << endl;
        cout << "  Rating: " << rating << endl;

        // Clear the new line character so the next employee name doesn't break
        cin.ignore(10000, '\n');
    }

    cout << "\nAll done. Goodbye!" << endl;
    return 0;
}