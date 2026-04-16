#include <iostream>
using namespace std;

// =====================================================
// 🔹 LOW LEVEL MODULE (REAL CODE)
// =====================================================

class Voter {
    string name;
    int age;

public:
    Voter(string n, int a) : name(n), age(a) {}

    string getName() { return name; }
    int getAge() { return age; }

    void castVote() {
        cout << "[Voter] Vote casted by " << name << endl;
    }
};

// =====================================================
// 🔥 DRIVER (SIMULATES UPPER MODULES LIKE MENU + MAIN)
// =====================================================

int main() {

    cout << "=========== BOTTOM-UP TESTING (DRIVER) ===========\n";

    int failed = 0;

    // =================================================
    // 🔹 TC1: Simulating voterMenu calling Voter
    // =================================================
    Voter v("Parth", 20);

    if(v.getName() != "Parth") {
        cout << "TC1 Failed\n";
        failed++;
    }

    if(v.getAge() != 20) {
        cout << "TC2 Failed\n";
        failed++;
    }

    // =================================================
    // 🔹 TC2: Simulating vote operation (menu action)
    // =================================================
    cout << "\n[Driver] Calling castVote() (as menu would do)\n";
    v.castVote();

    // =================================================
    // 🔹 FINAL RESULT
    // =================================================
    if(failed == 0)
        cout << "\n✅ All Bottom-Up Tests Passed\n";
    else
        cout << "\n❌ Tests Failed: " << failed << endl;

    return 0;
}