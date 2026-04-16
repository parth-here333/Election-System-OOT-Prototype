#include <iostream>
#include <string>
using namespace std;

class LoginSystem {
public:
    enum State {
        IDLE,
        ENTER,
        AUTHENTICATED,
        RETRY,
        LOCKED
    };

private:
    State currentState;
    int attempts;

public:
    LoginSystem() {
        currentState = IDLE;
        attempts = 0;
    }

    void enterCredentials(string user, string pass) {
        if(currentState == LOCKED) return;

        if(user == "parth" && pass == "1234") {
            currentState = AUTHENTICATED;
        } else {
            attempts++;
            if(attempts >= 3)
                currentState = LOCKED;
            else
                currentState = RETRY;
        }
    }

    State getState() {
        return currentState;
    }
};

// =====================================================
// 🔥 TEST CASES (STATE-BASED)
// =====================================================

int main() {

    cout << "=========== STATE BASED TESTING ===========\n";

    // TC1: Initial State
    LoginSystem sys1;
    if(sys1.getState() == LoginSystem::IDLE)
        cout << "TC1 Passed\n";

    // TC2: Successful Login
    LoginSystem sys2;
    sys2.enterCredentials("parth","1234");
    if(sys2.getState() == LoginSystem::AUTHENTICATED)
        cout << "TC2 Passed\n";

    // TC3: One Wrong Attempt
    LoginSystem sys3;
    sys3.enterCredentials("wrong","wrong");
    if(sys3.getState() == LoginSystem::RETRY)
        cout << "TC3 Passed\n";

    // TC4: Correct After Retry
    LoginSystem sys4;
    sys4.enterCredentials("wrong","wrong");
    sys4.enterCredentials("parth","1234");
    if(sys4.getState() == LoginSystem::AUTHENTICATED)
        cout << "TC4 Passed\n";

    // TC5: Three Wrong Attempts
    LoginSystem sys5;
    sys5.enterCredentials("a","b");
    sys5.enterCredentials("a","b");
    sys5.enterCredentials("a","b");
    if(sys5.getState() == LoginSystem::LOCKED)
        cout << "TC5 Passed\n";

    // TC6: Locked State
    LoginSystem sys6;
    sys6.enterCredentials("a","b");
    sys6.enterCredentials("a","b");
    sys6.enterCredentials("a","b");
    sys6.enterCredentials("parth","1234");
    if(sys6.getState() == LoginSystem::LOCKED)
        cout << "TC6 Passed\n";

    return 0;
}