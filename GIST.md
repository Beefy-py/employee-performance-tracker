# Gist — EmployeePerformanceTracker.cpp

## What the Program Does

A C++ console app that collects monthly productivity data for up to 50 employees and prints a performance summary for each one.

---

## Flow at a Glance

1. **Ask how many employees** (1–50) — re-prompts on bad input.
2. **For each employee:**
   - Ask for their **name** (re-prompts if blank).
   - Ask for the **number of days worked** this month (0–31).
   - If 0 days → print "N/A" and move on.
   - Otherwise, collect a **productivity score (0–100)** for every day worked.
   - Compute **total, average, highest, and lowest** scores.
   - Assign a **performance rating** based on the average:
     | Average | Rating |
     |---------|--------|
     | ≥ 80    | Excellent |
     | 60–79   | Good |
     | 40–59   | Satisfactory |
     | < 40    | Needs Improvement |
   - Print the results.
3. Print a goodbye message when all employees are processed.

---

## Key Technical Points

- All inputs are validated in `while (true)` loops — non-numeric input, out-of-range values, and blank names are all caught and re-prompted.
- `getline()` is used for names so spaces are handled correctly.
- `cin.ignore()` clears the input buffer between `cin >>` and `getline()` calls.
- The average is computed with a `double` cast to avoid integer division.
- `continue` skips score collection entirely when an employee worked 0 days.
