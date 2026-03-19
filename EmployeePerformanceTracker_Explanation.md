# Employee Performance Tracker — Line-by-Line Explanation

---

## Header Comment (Lines 1–8)

```cpp
// Group Members:
/*
- Hoft. K, 15413
- Pawirosetiko. T, 15589
- Soekhlal. A, 15397
- Waterberg. A, 15518
- Welzijn. C, 15632
*/
```

- **Line 1:** A single-line comment introducing the group members section.
- **Lines 2–8:** A multi-line block comment (`/* ... */`) listing all group member names and their IDs.

---

## Program Description Comment (Lines 6–8)

```cpp
// Employee Monthly Performance Tracker
// This program takes in employee names and their daily productivity scores,
// then calculates stats like average, highest, lowest, and gives a rating.
```

- Brief description of what the program does, written as single-line comments.

---

## Includes & Namespace (Lines 10–13)

```cpp
#include <iostream>
#include <string>
#include <limits>  // needed for clearing bad input from cin
using namespace std;
```

- **Line 10:** `#include <iostream>` — Includes the **iostream** library, which provides `cout` (output to console) and `cin` (input from console).
- **Line 11:** `#include <string>` — Includes the **string** library, enabling the use of the `string` data type for text.
- **Line 12:** `#include <limits>` — Includes the **limits** library, which gives us `numeric_limits<streamsize>::max()` used to clear the input buffer when bad input is entered.
- **Line 13:** `using namespace std;` — Allows use of standard library names (`cout`, `cin`, `string`, `endl`) without the `std::` prefix.

---

## Main Function Start & Variable (Lines 15–16)

```cpp
int main() {
    int numEmployees;
```

- **Line 15:** Declares the **main function**, the entry point of every C++ program. It returns an `int` to the operating system when done.
- **Line 16:** Declares an integer variable `numEmployees` to store how many employees will be evaluated.

---

## Welcome Message (Lines 18–19)

```cpp
    cout << "=== Employee Monthly Performance Tracker ===" << endl;
    cout << endl;
```

- Prints the program title with decorative `===` borders. `endl` flushes the buffer and adds a newline. The second line adds an extra blank line for spacing.

---

## Number of Employees Input with Validation (Lines 21–40)

```cpp
    while (true) {
        cout << "How many employees will be evaluated? ";
        cin >> numEmployees;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That's not a valid number. Try again." << endl;
        }
        else if (numEmployees <= 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You need at least 1 employee. Try again." << endl;
        }
        else if (numEmployees > 50) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Max 50 employees at a time. Try again." << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
```

- A `while (true)` loop that keeps asking until valid input is given.
- `cin.fail()` checks if the user entered something that isn't a number (like letters). If so, `cin.clear()` resets the error state and `cin.ignore(...)` clears the junk from the buffer.
- Rejects values ≤ 0 (need at least 1 employee) and values > 50 (reasonable cap).
- On valid input, clears the leftover newline with `cin.ignore(...)` and `break`s out of the loop.

---

## Outer For Loop — Iterating Over Employees (Line 42)

```cpp
    for (int i = 0; i < numEmployees; i++) {
```

- Starts a **for loop** that repeats once for each employee. `i` starts at `0` and increments by `1` each iteration, running while `i < numEmployees`.

---

## Employee Name Input with Validation (Lines 43–55)

```cpp
        string name;
        int daysWorked;

        cout << "\n--- Employee " << (i + 1) << " ---" << endl;

        cout << "Enter employee's name: ";
        getline(cin, name);

        while (name.empty()) {
            cout << "Name can't be blank. Enter employee's name: ";
            getline(cin, name);
        }
```

- **Line 43:** Declares a `string` variable `name` to hold the employee's name.
- **Line 44:** Declares an `int` variable `daysWorked` for the number of days the employee worked.
- **Line 46:** Prints a header like `--- Employee 1 ---`. `(i + 1)` converts from 0-based index to 1-based display.
- **Lines 48–49:** Prompts for the employee's name using `getline()` so names with spaces work properly.
- **Lines 51–54:** Validation loop — if the user just hits Enter without typing a name, it re-prompts. Keeps going until something is actually entered.

---

## Days Worked Input with Validation (Lines 57–73)

```cpp
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
```

- Same validation pattern as `numEmployees`. Handles non-numeric input, rejects negative values and anything over 31 days (since a month can't have more).
- Clears the buffer on each path so the next input reads cleanly.

---

## Handle Zero Days Worked (Lines 75–81)

```cpp
        if (daysWorked == 0) {
            cout << "\n>>> Results for " << name << " <<<" << endl;
            cout << "  Days worked:            0" << endl;
            cout << "  No scores to calculate." << endl;
            cout << "  Performance rating:     N/A" << endl;
            continue;
        }
```

- If an employee worked 0 days, there are no scores to enter. Prints a short summary with "N/A" rating and uses `continue` to skip to the next employee without asking for scores.

---

## Score Tracking Variables (Lines 83–85)

```cpp
        int totalScore = 0;
        int highestScore = 0;
        int lowestScore = 100;
```

- **`totalScore`** accumulates the sum of all daily scores. Initialized to `0`.
- **`highestScore`** tracks the maximum score. Initialized to `0` (any valid score will be ≥ 0).
- **`lowestScore`** tracks the minimum score. Initialized to `100` (any valid score will be ≤ 100).

---

## Inner For Loop — Iterating Over Days (Line 87)

```cpp
        for (int day = 0; day < daysWorked; day++) {
```

- A **nested for loop** that repeats once for each day the employee worked. This is the inner loop inside the outer employee loop.

---

## Score Input with Full Validation (Lines 88–104)

```cpp
            int score;

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
```

- Declares `score` for the current day's productivity.
- The `while (true)` loop validates input:
  - `cin.fail()` catches non-numeric input (letters, symbols) and clears the error.
  - Rejects scores outside the 0–100 range.
  - On valid input, clears the buffer and breaks out.

---

## Accumulate and Track Scores (Lines 106–113)

```cpp
            totalScore += score;

            if (score > highestScore) {
                highestScore = score;
            }
            if (score < lowestScore) {
                lowestScore = score;
            }
```

- **`totalScore += score;`** — Adds the current day's score to the running total.
- If the current `score` is greater than `highestScore`, update the max.
- If the current `score` is less than `lowestScore`, update the min.

---

## Calculate Average Score (Line 117)

```cpp
        double averageScore = static_cast<double>(totalScore) / daysWorked;
```

- `static_cast<double>(totalScore)` converts `totalScore` from `int` to `double` before dividing, ensuring **decimal (floating-point) division** rather than integer division. We already know `daysWorked > 0` at this point because we handled the zero case earlier with `continue`.

---

## Determine Performance Rating (Lines 119–130)

```cpp
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
```

- An **if / else-if / else chain** that assigns a rating based on the average score:
  - `>= 80` → `"Excellent"`
  - `>= 60` (but < 80) → `"Good"`
  - `>= 40` (but < 60) → `"Satisfactory"`
  - `< 40` → `"Needs Improvement"`

---

## Display Results (Lines 132–139)

```cpp
        cout << "\n>>> Results for " << name << " <<<" << endl;
        cout << "  Days worked:            " << daysWorked << endl;
        cout << "  Total productivity:     " << totalScore << endl;
        cout << "  Average productivity:   " << averageScore << endl;
        cout << "  Highest daily score:    " << highestScore << endl;
        cout << "  Lowest daily score:     " << lowestScore << endl;
        cout << "  Performance rating:     " << rating << endl;
```

- Prints a formatted summary for the current employee, including:
  - Days worked
  - Total productivity score (sum of all daily scores)
  - Average productivity score
  - Highest and lowest individual daily scores
  - The calculated performance rating

---

## Closing the Outer Loop (Line 140)

```cpp
    }
```

- Closes the outer `for` loop (iterating over employees). The program loops back to process the next employee.

---

## Goodbye Message & Return (Lines 142–145)

```cpp
    cout << "\n=== All employees processed. Goodbye! ===" << endl;

    return 0;
}
```

- **Line 142:** Prints a closing message once all employees have been processed.
- **Line 144:** `return 0;` — Returns `0` to the operating system, indicating the program finished successfully.
- **Line 145:** Closing brace `}` ends the `main` function.

---

## Summary of Key Concepts Used

| Concept                      | Where Used                                                    |
| ---------------------------- | ------------------------------------------------------------- |
| **For loop**                 | Outer loop (employees), inner loop (days)                     |
| **While loop**               | Input validation for employee count, days worked, and scores  |
| **If / else-if / else**      | Performance rating logic, input validation branches           |
| **Nested loops**             | Day-scoring loop inside the employee loop                     |
| **Input validation**         | All inputs validated — non-numeric, out-of-range, empty names |
| **cin.fail() / cin.clear()** | Detecting and recovering from non-numeric input               |
| **numeric_limits**           | Clearing the entire input buffer after bad input              |
| **Type casting**             | `static_cast<double>()` for accurate average calculation      |
| **getline()**                | Reading full names (with spaces)                              |
| **cin.ignore()**             | Clearing the input buffer between `cin >>` and `getline()`    |
| **continue statement**       | Skipping score entry when an employee worked 0 days           |
