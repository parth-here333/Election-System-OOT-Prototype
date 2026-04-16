# 🗳️ Election Commission OOT System – Testing Documentation

## 📌 Overview

This project implements an Election Management System using Object-Oriented Programming in C++.
To ensure correctness, reliability, and robustness, multiple software testing techniques were applied.

---

# 🧪 Testing Techniques Implemented

## 🔷 1. White-Box Testing (Using Google Test)

### 📖 Description

White-box testing focuses on internal logic, code structure, and execution paths.

### ⚙️ Implementation

* Implemented using **Google Test (GTest)**
* Test cases written in `test.cpp`
* Covered:

  * Statement Coverage
  * Branch Coverage
  * Path Coverage
  * Loop Testing
  * Internal Structure Testing

### ▶️ Run Tests

```bash
g++ -std=c++17 test.cpp menu.cpp config.cpp data.cpp googletest/googletest/src/gtest-all.cc googletest/googletest/src/gtest_main.cc -I . -I googletest/googletest -I googletest/googletest/include -pthread -o test.exe
./test.exe
```

### ✅ Result

All unit tests passed successfully.

---

## 🔷 2. Top-Down Testing

### 📖 Description

Testing starts from the main module and proceeds downward.

### ⚙️ Implementation

* Created `menu_stub.cpp`
* Replaced all menu functions with stub outputs

### Example Stub

```cpp
void voterMenu(...) {
    cout << "[STUB] voterMenu called\n";
}
```

### ▶️ Run

```bash
g++ -std=c++17 main.cpp menu_stub.cpp config.cpp data.cpp -o topdown.exe
./topdown.exe
```

### ✅ Result

* Verified system flow
* Confirmed correct module invocation

---

## 🔷 3. Bottom-Up Testing

### 📖 Description

Testing starts from low-level modules and integrates upward.

### ⚙️ Implementation

* Created `driver.cpp`
* Directly tested classes like:

  * Voter
  * Candidate
  * EVM
  * Election

### ▶️ Run

```bash
g++ -std=c++17 driver.cpp menu.cpp config.cpp data.cpp -o bottomup.exe
./bottomup.exe
```

### ✅ Result

* Verified individual module logic
* All components function correctly

---

## 🔷 4. Mixed (Sandwich) Testing

### 📖 Description

Combination of Top-Down and Bottom-Up testing.

### ⚙️ Implementation

* Executed both:

  * `topdown.exe`
  * `bottomup.exe`

### ✅ Result

* Verified both system integration and module functionality

---

## 🔷 5. Regression Testing

### 📖 Description

Ensures new changes do not break existing functionality.

### ⚙️ Changes Tested

* Admin Authentication
* Debug Mode

### ▶️ Test Cases

| Feature         | Result |
| --------------- | ------ |
| Login System    | Pass   |
| Menu Navigation | Pass   |
| Voting System   | Pass   |
| Exit System     | Pass   |

### ✅ Result

No regressions detected.

---

## 🔷 6. Minimal Output Testing

### 📖 Description

Testing with minimum and edge-case inputs.

### ▶️ Test Cases

| Input               | Expected Output | Result |
| ------------------- | --------------- | ------ |
| Invalid login       | Access Denied   | Pass   |
| Immediate exit (12) | Program exits   | Pass   |
| Invalid menu input  | No crash        | Pass   |

### ✅ Result

System handles edge cases safely.

---

## 🔷 7. State-Based Testing

### 📖 Description

Testing system behavior based on state transitions.

### 🧠 States

* S0: Start
* S1: Login
* S2: Menu
* S3: Module
* S4: Exit

### 🔁 Transitions

```
S0 → S1 → S2 → S3 → S2 → S4
```

---

### ✔ Checklists Used

#### 1. Structure Checklist

* All states defined ✔
* Valid transitions ✔
* No dead states ✔

#### 2. State Name Checklist

* Clear and meaningful names ✔

#### 3. Guarded Transition Checklist

* Valid login → Menu ✔
* Invalid login → Retry ✔
* Menu → Module ✔

#### 4. Robustness Checklist

* Handles invalid inputs ✔
* Handles edge cases ✔

---

### ▶️ Test Cases

| Input Sequence      | State Path  | Result |
| ------------------- | ----------- | ------ |
| Login → Menu → Exit | S0→S1→S2→S4 | Pass   |
| Invalid login x3    | S1→S1→S4    | Pass   |
| Menu navigation     | S2→S3→S2    | Pass   |

---

### ✅ Result

System correctly transitions between all states.

---

# 📊 Final Summary

| Testing Type        | Status      |
| ------------------- | ----------- |
| White-Box Testing   | ✔ Completed |
| Top-Down Testing    | ✔ Completed |
| Bottom-Up Testing   | ✔ Completed |
| Mixed Testing       | ✔ Completed |
| Regression Testing  | ✔ Completed |
| Minimal Testing     | ✔ Completed |
| State-Based Testing | ✔ Completed |

---

# 🚀 Conclusion

All major software testing techniques were successfully implemented.
The system is:

* ✔ Functionally correct
* ✔ Structurally sound
* ✔ Robust against edge cases
* ✔ Well-tested for real-world scenarios

---

# 👨‍💻 Author

Muppala Venkata Prajyesh
