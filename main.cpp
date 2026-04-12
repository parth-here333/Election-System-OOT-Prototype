#include "ElectionSystem.h"
#include "data.h"
#include "menu.h"
#include "config.h"
#include<iostream>
#include <iomanip>
#include <utility>   

using namespace std;
int main() {
    cout<<"___________________________________________________________________________________________\n"<<endl;
    cout<<"------------------- WELCOME TO ELECTION COMMISSION OOT PROTOTYPE --------------------------"<<endl;
    cout<<"___________________________________________________________________________________________"<<endl;
    cout<<endl;
    
    // ===== DEBUG CONTROL =====
    int debugChoice;
    cout << "Enable Debug Mode? (1 = Yes, 0 = No): ";
    cin >> debugChoice;

    DEBUG = (debugChoice == 1);

    if(DEBUG)
        cout << "[DEBUG MODE ENABLED]\n";
    else
        cout << "[NORMAL MODE]\n";

    // ===== LOAD DATA (FIXED USING MOVE) =====
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
          cout << "Enter your choice: ";
        cin >> ch;

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
        }

    } while(ch != 12);
    return 0;
}


