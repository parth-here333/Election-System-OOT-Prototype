#include "ElectionSystem.h"
#include "data.h"
#include "menu.h"
#include "config.h"
#include<iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <termios.h>
#include <unistd.h>

using namespace std;

string getPassword() {
    string password;

    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~ECHO;   // disable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    getline(cin, password);

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore
    cout << endl;

    return password;
}

// ===== AUTHENTICATION FUNCTION =====
bool authenticateAdmin(string &loggedAdmin) {
    string username, password;

    cout << "\n================ ADMIN LOGIN ================\n";
    cout << "Enter Admin Name: ";
    cin >> username;

    cout << "Enter Password: ";
    cin.ignore();              
    password = getPassword();  

    // Multiple admins
    vector<pair<string, string>> validAdmins = {
        {"parth", "1234"},
        {"prajyesh", "5678"}
    };

    for (auto &admin : validAdmins) {
        if (username == admin.first && password == admin.second) {
            loggedAdmin = username;
            cout << "\nAccess Granted! Welcome " << username << " 👋\n";
            return true;
        }
    }

    cout << "\nAccess Denied! Invalid Credentials.\n";
    return false;
}

// ===== MAIN FUNCTION =====
int main() {
    cout<<"___________________________________________________________________________________________\n"<<endl;
    cout<<"------------------- WELCOME TO ELECTION COMMISSION OOT PROTOTYPE --------------------------"<<endl;
    cout<<"___________________________________________________________________________________________"<<endl;
    cout<<endl;

    // ===== ADMIN AUTHENTICATION =====
    string currentAdmin;
    int attempts = 3;
    bool accessGranted = false;

    while(attempts--) {
        if(authenticateAdmin(currentAdmin)) {
            accessGranted = true;
            break;
        } else {
            cout << "Attempts left: " << attempts << endl;
        }
    }

    if(!accessGranted) {
        cout << "\nToo many failed attempts. Exiting system.\n";
        return 0;
    }

    cout << "\nCurrently Logged In Admin: " << currentAdmin << endl;

    // ===== DEBUG CONTROL =====
    int debugChoice;
    cout << "\nEnable Debug Mode? (1 = Yes, 0 = No): ";
    cin >> debugChoice;
    cin.ignore();
    DEBUG = (debugChoice == 1);

    if(DEBUG)
        cout << "[DEBUG MODE ENABLED]\n";
    else
        cout << "[NORMAL MODE]\n";

    // ===== LOAD DATA =====
    auto voters = std::move(getVoters());
    auto candidates = std::move(getCandidates());
    auto admins = std::move(getAdmins());
    auto officers = std::move(getOfficers());
    auto evms = std::move(getEVMs());
    auto ps = std::move(getPollingStations());
    auto comp = std::move(getComplaints());
    auto nr = std::move(getNominations());
    auto cs = std::move(getConstituencies());
    auto pp = std::move(getParties());
    auto el = std::move(getElections());

    int ch;

    do {
        cout << "\n==============================================================\n";
        cout << "         ELECTION COMMISSION OOT SYSTEM - MAIN MENU\n";
        cout << "==============================================================\n\n";

        cout << left
             << setw(5)  << "1."  << setw(28) << "Voter Portal"
             << setw(5)  << "2."  << setw(28) << "Candidate Portal" << endl;

        cout << left
             << setw(5)  << "3."  << setw(28) << "Admin Portal"
             << setw(5)  << "4."  << setw(28) << "Officer Portal" << endl;

        cout << left
             << setw(5)  << "5."  << setw(28) << "EVM Management"
             << setw(5)  << "6."  << setw(28) << "Polling Station Portal" << endl;

        cout << left
             << setw(5)  << "7."  << setw(28) << "Complaint Portal"
             << setw(5)  << "8."  << setw(28) << "Nomination Portal" << endl;

        cout << left
             << setw(5)  << "9."  << setw(28) << "Constituency Portal"
             << setw(5)  << "10." << setw(28) << "Political Party Portal" << endl;

        cout << left
             << setw(5)  << "11." << setw(28) << "Election Portal"
             << setw(5)  << "12." << setw(28) << "Exit" << endl;

        cout << "\n==============================================================\n";
        string input;

        cout << "\nEnter your choice: ";
        getline(cin, input);

        bool isValid = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isValid = false;
                break;
            }
        }

        if (!isValid || input.empty()) {
           cout << "\n❌ Invalid Input! Only numbers allowed.\n";
           continue;
        }

        ch = stoi(input);

        if (ch < 1 || ch > 12) {
            cout << "\n❌ Invalid Choice! Allowed range is 1 to 12.\n";
            continue;   // or return 0;
        }
        switch(ch) {
            case 1: voterMenu(voters); break;
            case 2: candidateMenu(candidates); break;
            case 3: adminMenu(admins); break;
            case 4: officerMenu(officers); break;
            case 5: evmMenu(evms); break;
            case 6: pollingMenu(ps); break;
            case 7: complaintMenu(comp); break;
            case 8: nominationMenu(nr); break;
            case 9: constituencyMenu(cs); break;
            case 10: partyMenu(pp); break;
            case 11: electionMenu(el); break;
            case 12: cout << "\nExiting system... Thank you!\n";
                     break;
       }

    } while(ch != 12);

    return 0;
}
