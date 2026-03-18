# Employee Performance Tracker — Line-by-Line Explanation

---

## Header Comment (Lines 1–4)

```cpp
// Group Members:
/*
- Hoft. K - 15413
*/
```

- **Line 1:** A single-line comment introducing the group members section.
- **Lines 2–4:** A multi-line block comment (`/* ... */`) listing the group member name and ID.

---

## Includes & Namespace (Lines 6–8)

```cpp
#include <iostream>
#include <string>
using namespace std;
```

- **Line 6:** `#include <iostream>` — Includes the **iostream** library, which provides `cout` (output to console) and `cin` (input from console).
- **Line 7:** `#include <string>` — Includes the **string** library, enabling the use of the `string` data type for text.
- **Line 8:** `using namespace std;` — Allows use of standard library names (`cout`, `cin`, `string`, `endl`) without the `std::` prefix.

---

## Main Function Start (Line 10)

```cpp
int main() {
```

- Declares the **main function**, the entry point of every C++ program. It returns an `int` (integer) to the operating system when done.

---

## Variable Declaration (Line 11)

```cpp
    int numEmployees;
```

- Declares an integer variable `numEmployees` to store how many employees will be evaluated.

---

## Welcome Message & Input (Lines 13–16)

```cpp
    cout << "=== Employee Monthly Performance Tracker ===\n\n" << endl;
    cout << "How many employees will be evaluated? ";
    cin >> numEmployees;
    cin.ignore();
```

- **Line 13:** Prints the program title with decorative `===` borders and two newlines for spacing. `endl` flushes the output buffer and adds another newline.
- **Line 14:** Prompts the user to enter the number of employees.
- **Line 15:** `cin >> numEmployees;` — Reads the user's integer input and stores it in `numEmployees`.
- **Line 16:** `cin.ignore();` — Discards the leftover newline character (`\n`) in the input buffer (left behind by `cin >>`), so the next `getline()` call works correctly.

---

## Outer For Loop — Iterating Over Employees (Line 18)

```cpp
    for (int i = 0; i < numEmployees; i++) {
```

- Starts a **for loop** that repeats once for each employee. `i` starts at `0` and increments by `1` each iteration, running while `i < numEmployees`.

---

## Employee Name & Days Worked (Lines 19–27)

```cpp
        string name;
        int daysWorked;

        cout << "\n--- Employee " << (i + 1) << " ---" << endl;
        cout << "Enter employee's name: ";
        getline(cin, name);

        cout << "Enter the number of days worked this month: ";
        cin >> daysWorked;
```

- **Line 19:** Declares a `string` variable `name` to hold the employee's name.
- **Line 20:** Declares an `int` variable `daysWorked` for the number of days the employee worked.
- **Line 22:** Prints a header like `--- Employee 1 ---`. `(i + 1)` converts from 0-based index to 1-based display.
- **Line 23:** Prompts for the employee's name.
- **Line 24:** `getline(cin, name);` — Reads an entire line of input (including spaces) into `name`. This is why `cin.ignore()` was called earlier.
- **Line 26:** Prompts for the number of days worked.
- **Line 27:** `cin >> daysWorked;` — Reads the integer input into `daysWorked`.

---

## Score Tracking Variables (Lines 29–31)

```cpp
        int totalScore = 0;
        int highestScore = 0;
        int lowestScore = 100;
```

- **Line 29:** `totalScore` accumulates the sum of all daily scores. Initialized to `0`.
- **Line 30:** `highestScore` tracks the maximum score. Initialized to `0` (any valid score will be ≥ 0).
- **Line 31:** `lowestScore` tracks the minimum score. Initialized to `100` (any valid score will be ≤ 100).

---

## Inner For Loop — Iterating Over Days (Line 34)

```cpp
        for (int day = 0; day < daysWorked; day++) {
```

- A **nested for loop** that repeats once for each day the employee worked. This is the inner loop inside the outer employee loop.

---

## Score Input with Validation (Lines 35–45)

```cpp
            int score;

            while (true) {
                cout << "  Productivity score for day " << (day + 1) << " (0-100): ";
                cin >> score;

                if (score >= 0 && score <= 100) {
                    break;
                }
                cout << "  Invalid score! Please enter a value between 0 and 100." << endl;
            }
```

- **Line 35:** Declares an `int` variable `score` for the current day's productivity score.
- **Line 37:** `while (true)` — Starts an **infinite loop** that will keep asking for input until a valid score is entered.
- **Line 38:** Prompts the user for the productivity score for the current day (1-based).
- **Line 39:** Reads the score from input.
- **Lines 41–43:** **Validation check** — If `score` is between 0 and 100 (inclusive), `break;` exits the while loop. Otherwise, an error message is printed and the loop repeats, asking again.

---

## Accumulate and Track Scores (Lines 47–53)

```cpp
            totalScore += score;

            if (score > highestScore) {
                highestScore = score;
            }
            if (score < lowestScore) {
                lowestScore = score;
            }
```

- **Line 47:** `totalScore += score;` — Adds the current day's score to the running total.
- **Lines 49–51:** If the current `score` is greater than `highestScore`, update `highestScore` to the new maximum.
- **Lines 52–54:** If the current `score` is less than `lowestScore`, update `lowestScore` to the new minimum.

---

## Closing the Inner Loop (Line 55)

```cpp
        }
```

- Closes the inner `for` loop (iterating over days).

---

## Calculate Average Score (Lines 57–61)

```cpp
        double averageScore = 0.0;
        if (daysWorked > 0) {
            averageScore = static_cast<double>(totalScore) / daysWorked;
        }
```

- **Line 57:** Declares `averageScore` as a `double` (decimal number), initialized to `0.0`.
- **Line 58:** Checks that `daysWorked > 0` to avoid **division by zero**.
- **Line 59:** `static_cast<double>(totalScore)` converts `totalScore` from `int` to `double` before dividing, ensuring **decimal (floating-point) division** rather than integer division.

---

## Determine Performance Rating (Lines 63–70)

```cpp
        string rating;
        if (averageScore >= 80) {
            rating = "Excellent";
        } else if (averageScore >= 60) {
            rating = "Good";
        } else {
            rating = "Needs Improvement";
        }
```

- **Line 63:** Declares a `string` variable `rating`.
- **Lines 64–70:** An **if / else-if / else chain** that assigns a rating based on the average score:
  - `>= 80` → `"Excellent"`
  - `>= 60` (but < 80) → `"Good"`
  - `< 60` → `"Needs Improvement"`

---

## Display Results (Lines 72–79)

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

## Buffer Cleanup (Line 81)

```cpp
        cin.ignore();
```

- Discards the trailing newline left by the last `cin >>` so that the next iteration's `getline()` (for the next employee's name) works correctly.

---

## Closing the Outer Loop (Line 82)

```cpp
    }
```

- Closes the outer `for` loop (iterating over employees). The program loops back to process the next employee.

---

## Goodbye Message & Return (Lines 84–86)

```cpp
    cout << "\n=== All employees processed. Goodbye! ===" << endl;

    return 0;
}
```

- **Line 84:** Prints a closing message once all employees have been processed.
- **Line 86:** `return 0;` — Returns `0` to the operating system, indicating the program finished successfully.
- **Line 87:** Closing brace `}` ends the `main` function.

---

## Summary of Key Concepts Used

| Concept                 | Where Used                                                 |
| ----------------------- | ---------------------------------------------------------- |
| **For loop**            | Outer loop (employees), inner loop (days)                  |
| **While loop**          | Input validation for scores                                |
| **If / else-if / else** | Performance rating logic                                   |
| **Nested loops**        | Day-scoring loop inside the employee loop                  |
| **Input validation**    | Score must be 0–100; re-prompts on invalid input           |
| **Type casting**        | `static_cast<double>()` for accurate average calculation   |
| **getline()**           | Reading full names (with spaces)                           |
| **cin.ignore()**        | Clearing the input buffer between `cin >>` and `getline()` |
