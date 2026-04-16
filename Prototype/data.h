#ifndef DATA_H
#define DATA_H

#include "ElectionSystem.h"
#include <vector>

using namespace std;

// All getters
vector<Voter> getVoters();
vector<Candidate> getCandidates();
vector<AdminStaff> getAdmins();
vector<ElectionOfficer> getOfficers();
vector<EVM> getEVMs();
vector<PollingStation> getPollingStations();
vector<Complaint> getComplaints();
vector<NominationRecords> getNominations();
vector<Constituency> getConstituencies();
vector<PoliticalParty> getParties();
vector<Election> getElections();

#endif
