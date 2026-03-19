# Employee Performance Tracker

A C++ console application that tracks and evaluates employee productivity on a monthly basis.

## Group Members

- Hoft. K, 15413
- Pawirosetiko. T, 15589
- Soekhlal. A, 15397
- Waterberg. A, 15518
- Welzijn. C, 15632

## What It Does

- Takes in the number of employees to evaluate
- For each employee, collects their name, days worked, and daily productivity scores (0–100)
- Calculates total, average, highest, and lowest scores
- Assigns a performance rating based on the average:
  - **Excellent** — 80+
  - **Good** — 60–79
  - **Satisfactory** — 40–59
  - **Needs Improvement** — below 40

## Features

- Full input validation on all fields (rejects non-numeric input, out-of-range values, and blank names)
- Handles edge cases like 0 days worked
- Clear, formatted output for each employee

## How to Compile and Run

```bash
g++ -o EmployeePerformanceTracker.exe EmployeePerformanceTracker.cpp
./EmployeePerformanceTracker.exe
```
