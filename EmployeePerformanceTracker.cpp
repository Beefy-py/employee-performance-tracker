// Group Members:
/*
- Hoft. K - 15413
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int numEmployees;

    cout << "=== Employee Monthly Performance Tracker ===\n\n" << endl;
    cout << "How many employees will be evaluated? ";
    cin >> numEmployees;
    cin.ignore();

    for (int i = 0; i < numEmployees; i++) {
        string name;
        int daysWorked;

        cout << "\n--- Employee " << (i + 1) << " ---" << endl;
        cout << "Enter employee's name: ";
        getline(cin, name);

        cout << "Enter the number of days worked this month: ";
        cin >> daysWorked;

        int totalScore = 0;
        int highestScore = 0;
        int lowestScore = 100;


        for (int day = 0; day < daysWorked; day++) {
            int score;


            while (true) {
                cout << "  Productivity score for day " << (day + 1) << " (0-100): ";
                cin >> score;

                if (score >= 0 && score <= 100) {
                    break;
                }
                cout << "  Invalid score! Please enter a value between 0 and 100." << endl;
            }

            totalScore += score;

            if (score > highestScore) {
                highestScore = score;
            }
            if (score < lowestScore) {
                lowestScore = score;
            }
        }

        double averageScore = 0.0;
        if (daysWorked > 0) {
            averageScore = static_cast<double>(totalScore) / daysWorked;
        }

        string rating;
        if (averageScore >= 80) {
            rating = "Excellent";
        } else if (averageScore >= 60) {
            rating = "Good";
        } else {
            rating = "Needs Improvement";
        }

        cout << "\n>>> Results for " << name << " <<<" << endl;
        cout << "  Days worked:            " << daysWorked << endl;
        cout << "  Total productivity:     " << totalScore << endl;
        cout << "  Average productivity:   " << averageScore << endl;
        cout << "  Highest daily score:    " << highestScore << endl;
        cout << "  Lowest daily score:     " << lowestScore << endl;
        cout << "  Performance rating:     " << rating << endl;

        cin.ignore();
    }

    cout << "\n=== All employees processed. Goodbye! ===\n" << endl;

    return 0;
}
