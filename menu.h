#ifndef MENU_H
#define MENU_H

#include "ElectionSystem.h"
#include <vector>

using namespace std;

// Declare all menus
void voterMenu(vector<Voter>&);
void candidateMenu(vector<Candidate>&);
void adminMenu(vector<AdminStaff>&);
void officerMenu(vector<ElectionOfficer>&);
void evmMenu(vector<EVM>&);
void pollingMenu(vector<PollingStation>&);
void complaintMenu(vector<Complaint>&);
void nominationMenu(vector<NominationRecords>&);
void constituencyMenu(vector<Constituency>&);
void partyMenu(vector<PoliticalParty>&);
void electionMenu(vector<Election>&);

#endif
