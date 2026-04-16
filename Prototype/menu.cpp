#include "menu.h"
#include <iostream>
#include <iomanip>
using namespace std;

void displayVotersTable(vector<Voter> &v) {
    cout << "\n=== VOTERS ===\n";
    cout << left << setw(6)<<"ID"<<setw(12)<<"Name"<<setw(8)<<"Gender"
         <<setw(6)<<"Age"<<setw(10)<<"Contact"<<setw(18)<<"Email"
         <<setw(10)<<"Status"<<setw(12)<<"Const"<<endl;

    for(auto &x: v)
        cout << setw(6)<<x.getId()<<setw(12)<<x.getName()
             <<setw(8)<<x.getGender()<<setw(6)<<x.getAge()
             <<setw(10)<<x.getContact()<<setw(18)<<x.getEmail()
             <<setw(10)<<x.getStatus()<<setw(12)<<x.getConstituency()<<endl;
}

void displayCandidatesTable(vector<Candidate> &c) {
    cout << "\n=== CANDIDATES ===\n";
    cout << left << setw(6)<<"ID"<<setw(12)<<"Name"
         <<setw(10)<<"Party"<<setw(12)<<"Const"<<setw(10)<<"Status"<<endl;

    for(auto &x: c)
        cout << setw(6)<<x.getId()<<setw(12)<<x.getName()
             <<setw(10)<<x.getParty()<<setw(12)<<x.getConstituency()
             <<setw(10)<<x.getStatus()<<endl;
}

void displayAdminsTable(vector<AdminStaff> &a) {
    cout << "\n=== ADMINS ===\n";
    cout << left << setw(6)<<"ID"<<setw(12)<<"Name"<<setw(10)<<"Role"<<endl;

    for(auto &x: a)
        cout << setw(6)<<x.getId()<<setw(12)<<x.getName()
             <<setw(10)<<"Admin"<<endl;
}

void displayOfficersTable(vector<ElectionOfficer> &o) {
    cout << "\n=== OFFICERS ===\n";
    cout << left << setw(6)<<"ID"<<setw(12)<<"Name"
         <<setw(12)<<"Const"<<setw(6)<<"Exp"<<endl;

    for(auto &x: o)
        cout << setw(6)<<x.getId()<<setw(12)<<x.getName()
             <<setw(12)<<x.getConstituency()<<setw(6)<<"--"<<endl;
}

void displayEVMTable(vector<EVM> &e) {
    cout << "\n=== EVMs ===\n";
    cout << "Total Machines: " << e.size() << endl;
}

void displayPollingTable(vector<PollingStation> &p) {
    cout << "\n=== POLLING STATIONS ===\n";
    cout << "Total Stations: " << p.size() << endl;
}

void displayComplaintTable(vector<Complaint> &c) {
    cout << "\n=== COMPLAINTS ===\n";
    cout << "Total Complaints: " << c.size() << endl;
}

void displayNominationTable(vector<NominationRecords> &n) {
    cout << "\n=== NOMINATIONS ===\n";
    cout << "Total Records: " << n.size() << endl;
}

void displayConstituencyTable(vector<Constituency> &c) {
    cout << "\n=== CONSTITUENCIES ===\n";
    cout << "Total: " << c.size() << endl;
}

void displayPartyTable(vector<PoliticalParty> &p) {
    cout << "\n=== PARTIES ===\n";
    cout << "Total Parties: " << p.size() << endl;
}

void displayElectionTable(vector<Election> &e) {
    cout << "\n=== ELECTIONS ===\n";
    cout << "Total Elections: " << e.size() << endl;
}

void voterMenu(vector<Voter> &voters) {
    int ch;
    do {
        cout << "\n--- VOTER MENU ---\n";
        cout << "1. Display All\n2. Update\n3. Cast Vote\n4. Back\n";
        cin >> ch;

        if(ch == 1) {
           displayVotersTable(voters);
        }
        else if(ch == 2) {
            int id; cin >> id;
            for(auto &v : voters)
                if(v.getId() == id) v.updateDetails();
        }
        else if(ch == 3) {
            int id; cin >> id;
            for(auto &v : voters)
                if(v.getId() == id) v.castVote();
        }

    } while(ch != 4);
}


void candidateMenu(vector<Candidate> &candidates) {
    int ch;
    do {
        cout << "\n--- CANDIDATE MENU ---\n";
        cout << "1. Display\n2. Update\n3. Apply Nomination\n4. Status\n5. Back\n";
        cin >> ch;

        if(ch == 1) {
          displayCandidatesTable(candidates);
        }
        else if(ch == 2) {
            int id; cin >> id;
            for(auto &c : candidates)
                if(c.getId() == id) c.updateDetails();
        }
        else if(ch == 3) {
            for(auto &c : candidates) c.applyNomination();
        }
        else if(ch == 4) {
            for(auto &c : candidates) c.checkStatus();
        }

    } while(ch != 5);
}


void adminMenu(vector<AdminStaff> &admins) {
    int ch;
    do {
        cout << "\n--- ADMIN MENU ---\n";
        cout << "1. Display\n2. Verify Voter\n3. Verify Nomination\n4. Process Complaint\n5. Back\n";
        cin >> ch;

        if(ch == 1) {
            displayAdminsTable(admins);
        }
        else if(ch == 2) {
            for(auto &a : admins) a.verifyVoter();
        }
        else if(ch == 3) {
            for(auto &a : admins) a.verifyNomination();
        }
        else if(ch == 4) {
            for(auto &a : admins) a.processComplaint();
        }

    } while(ch != 5);
}


void officerMenu(vector<ElectionOfficer> &officers) {
    int ch;
    do {
        cout << "\n--- OFFICER MENU ---\n";
        cout << "1. Display\n2. Assign Polling Station\n3. Monitor EVM\n4. Handle Complaint\n5. Manage Election\n6. Back\n";
        cin >> ch;

        if(ch == 1) {
            displayOfficersTable(officers);
        }
        else if(ch == 2) {
            for(auto &o : officers) o.assignedPollinStation();
        }
        else if(ch == 3) {
            for(auto &o : officers) o.monitorEVM();
        }
        else if(ch == 4) {
            for(auto &o : officers) o.handleComplaint();
        }
        else if(ch == 5) {
            for(auto &o : officers) o.manageElection();
        }

    } while(ch != 6);
}


void evmMenu(vector<EVM> &evms) {
    int ch;
    do {
        cout << "\n--- EVM MENU ---\n";
        cout << "1. Display\n2. Activate\n3. Record Vote\n4. Shutdown\n5. Report Issue\n6. Back\n";
        cin >> ch;
        if(ch == 1) displayEVMTable(evms);
        for(auto &e : evms) { 
            if(ch == 2) e.activate();
            else if(ch == 3) e.recordVote();
            else if(ch == 4) e.shutdown();
            else if(ch == 5) e.reportIssue();
        }

    } while(ch != 6);
}


void pollingMenu(vector<PollingStation> &ps) {
    int ch;
    do {
        cout << "\n--- POLLING MENU ---\n";
        cout << "1. Display\n2. Start polling\n3. Allocate EVM\n4. Assign Officer\n5. Back\n";
        cin >> ch;
        if(ch == 1) {
          displayPollingTable(ps);
        }
        for(auto &p : ps) {
            if(ch == 2) p.startPolling();
            else if(ch == 3) p.allocateEVM();
            else if(ch == 4) p.assignedELectionOfficer();
        }

    } while(ch != 5);
}



void complaintMenu(vector<Complaint> &comp) {
    int ch;
    do {
        cout << "\n--- COMPLAINT MENU ---\n";
        cout << "1. Display\n2. File\n3. Assign Staff\n4. Escalate\n5. Back\n";
        cin >> ch;
        if(ch == 1) {
          displayComplaintTable(comp);
        }
        for(auto &c : comp) {
            if(ch == 2) c.file();
            else if(ch == 3) c.assignedStaff();
            else if(ch == 4) c.escalate();
        }

    } while(ch != 5);
}



void nominationMenu(vector<NominationRecords> &nr) {
    int ch;
    do {
        cout << "\n--- NOMINATION MENU ---\n";
        cout << "1. Display\n2. Update Docs\n3. Assign Admin\n4. Back\n";
        cin >> ch;
        if(ch == 1) {
          displayNominationTable(nr);
        }
        for(auto &n : nr) {
            if(ch == 2) n.updateDocs();
            else if(ch == 3) n.assignedAdminStaff();
        }

    } while(ch != 4);
}



void constituencyMenu(vector<Constituency> &cs) {
    int ch;
    do {
        cout << "\n--- CONSTITUENCY MENU ---\n";
        cout << "1. Display\n2. Manage PS\n3. Voting Status\n4. Assign Officer\n5. Party Status\n6. Candidate Status\n7. Back\n";
        cin >> ch;
        if(ch == 1) {
          displayConstituencyTable(cs);
        }
        for(auto &c : cs) {
            if(ch == 2) c.managePollingStations();
            else if(ch == 3) c.votingStatus();
            else if(ch == 4) c.assignedELectionOfficer();
            else if(ch == 5) c.ppStatus();
            else if(ch == 6) c.candidateStatus();
        }

    } while(ch != 7);
}


void partyMenu(vector<PoliticalParty> &pp) {
    int ch;
    do {
        cout << "\n--- PARTY MENU ---\n";
        cout << "1. Display\n2. Register\n3. Manage Candidate\n4. Status\n5. View Candidates\n6. Back\n";
        cin >> ch;
        if(ch == 1) {
           displayPartyTable(pp);
        }
        for(auto &p : pp) {
            if(ch == 2) p.regParty();
            else if(ch == 3) p.manageCandidate();
            else if(ch == 4) p.showStatus();
            else if(ch == 5) p.viewActiveCandidates();
        }

    } while(ch != 6);
}



void electionMenu(vector<Election> &el) {
    int ch;
    do {
        cout << "\n--- ELECTION MENU ---\n";
        cout << "1. Display\n2. Start\n3. End\n4. Results\n5. Report\n6. Back\n";
        cin >> ch;
        if(ch == 1) {
           displayElectionTable(el);
        }
        for(auto &e : el) {
            if(ch == 2) e.startElection();
            else if(ch == 3) e.endElection();
            else if(ch == 4) e.generateResults();
            else if(ch == 5) e.publishReport();
        }

    } while(ch != 6);
}
