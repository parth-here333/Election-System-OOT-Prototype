#ifndef ELECTION_SYSTEM_H
#define ELECTION_SYSTEM_H
#include "config.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//                         USER 
//                          |
//                          |
//          -------------------------------
//          |               |              |
//          |               |              |
//        VOTER        CANDIDATE    ELECTION STAFF
//                                         |
//                                         |
//                                --------------------
//                                |                  |
//                                |                  |
//                           ADMIN STAFF      ELECTION OFFICER
//


// ================= BASE CLASS =================
class User {

protected:
    int adharId;
    string name;
    string gender;
    int age;
    long long int contact;
    string email;
    static int totalUsers;
public:
    User(int adharId, string name,string gender,
    int age,
    int contact,
    string email) : adharId(adharId), name(name),gender(gender),
    age(age),contact(contact),email(email) {
    	totalUsers++;
    }
    int getId() const { return adharId; }
    string getName() const { return name; }
    string getGender() const { return gender; }
    int getAge() const { return age; }
    int getContact() const { return contact; }
    string getEmail() const { return email; }
    
    virtual void display(){
       cout << "Details appeared: "<<endl;
       cout << " Name: " <<name<<endl;
       cout << " AdharId: " <<adharId<<endl;
       cout << " Age: " <<age<<endl;
       cout << " Gender: " <<gender<<endl;
       cout << " Contact: " <<contact<<endl;
       cout << " Email: " <<email<<endl;
    }
    
    static void showTotalUsers(){                       //static function           
   	cout<<"Total Users: "<<totalUsers<<endl;
    }
    
    ~User(){                                             //destructor
    	totalUsers--;
    	if(DEBUG)
    	  cout<<"User object destroyed: "<<name<<endl;
    }
};




// ================= 1. VOTER =================
class Voter : public User {

private:
    string status;
    string constituency;
    static int totalVoters;
public:
    Voter(int adharId, string name,string gender,
    int age, int contact,
    string email ,string status , string constituency )
    : User(adharId,name,gender,age,contact,email),
      status(status),constituency(constituency) {
      	totalVoters++;
      }
   
    void castVote() {
        cout << "[Voter] Vote casted by " << name << endl;
    }

    void display() override{
        cout<< "Voter " ;
        User::display();
        cout<< " VoterStatus: "<<status<<endl;
        cout<< " Constituency: "<<constituency<<endl;
    }
    string getStatus() const { return status; }
    string getConstituency() const { return constituency; }
    void updateDetails() {
        int choice;
        do {
        	cout << "\nUpdate Menu:\n";
        	cout << "1. Name\n2. Age\n3. Gender\n4. Constituency\n0. Exit\n";
        	cout << "Enter choice: ";
        	cin >> choice;

        	switch(choice) {
            case 1:
                	cout << "Enter new name: ";
                	cin >> name;
                	break;

            case 2:
                	cout << "Enter age: ";
                	cin >> age;
                	break;

            case 3:
                	cout << "Enter gender: ";
                	cin >> gender;
                	break;

            case 4:
                	cout << "Enter constituency: ";
                	cin >> constituency;
                	break;
        		}
    	} while(choice != 0);

     }
     static void showTotalVoters(){                       //static function           
   	   cout<<"Total Voters: "<<totalVoters<<endl;
     }
    
     ~Voter(){                                             //destructor
    	 totalVoters--;
    	 if(DEBUG)
    	   cout<<"Voter object destroyed: "<<name<<endl;
     }
};



// ================= 2. CANDIDATE =================
class Candidate : public User {
private:
    string occupation;
    string status;
    string affidavitDetails;
    string constituency;
    string politicalParty;
    static int totalCandidate;
public:
    Candidate(int adharId, string name,string gender,
    int age, int contact,
    string email ,string status , string constituency,
    string occupation,string affidavitDetails ,string politicalParty
    )
    : User(adharId,name,gender,age,contact,email),
      occupation(occupation),status(status),
      affidavitDetails(affidavitDetails),
      constituency(constituency),
      politicalParty(politicalParty) {
      	totalCandidate++;
      }

    void applyNomination() {
        cout << "[Candidate] Applied for nomination\n";
    }
    string getParty() const { return politicalParty; }
    string getConstituency() const { return constituency; }
    string getStatus() const { return status; }
    void display() override{
        cout<< "Candidate " ;
        User::display();
        cout<< " Candidate Status: "<<status<<endl;
        cout<< " Constituency: "<<constituency<<endl;
        cout<< " Candidate Occupation: "<<occupation<<endl;
        cout<< " Candidate Political Party: "<<politicalParty<<endl;
        cout<< " Candidate affidavit details: "<<affidavitDetails<<endl;
    }
    
    void updateDetails() {
         int choice;
         do {
        	cout << "\nUpdate Menu:\n";
        	cout << "1. Name\n2. Age\n3. Gender\n4. Constituency\n5. Political Party\n6. Occupation\n0. Exit\n";
        	cout << "Enter choice: ";
        	cin >> choice;

        	switch(choice) {
            case 1:
                	cout << "Enter new name: ";
                	cin >> name;
                	break;

            case 2:
                	cout << "Enter age: ";
                	cin >> age;
                	break;

            case 3:
                	cout << "Enter gender: ";
                	cin >> gender;
                	break;

            case 4:
                	cout << "Enter constituency: ";
                	cin >> constituency;
                	break;
        		
        	   case 5:
                	cout << "Enter political party: ";
                	cin >> politicalParty;
                	break;
        		
        	   case 6:
                	cout << "Enter occupation: ";
                	cin >> occupation;
                	break;
        	   }
    	} while(choice != 0);

    	cout << "[Candidate] Details updated\n";
    }
    
    void checkStatus(){
        cout<<"Candidate status: "<<status<<endl;
    }
    static void showTotalCandidate(){                       //static function           
   	  cout<<"Total Candidates: "<<totalCandidate<<endl;
    }
    
    ~Candidate(){                                             //destructor
    	totalCandidate--;
    	if(DEBUG)
    	  cout<<"Candidate object destroyed: "<<endl;
    }
};




// ================= ELECTION STAFF =================
class ElectionStaff : public User {
protected:
    int staffId;
    string role;
public:
    ElectionStaff(int adharId, string name,string gender,
    int age, int contact,
    string email ,int staffId , string role
    )
    : User(adharId,name,gender,age,contact,email),
      staffId(staffId),role(role) {}
    
    void display() override {
        cout<< "Election Staff " ;
        User::display();
        cout<< " Staff ID: "<<staffId<<endl;
        cout<< " Staff Role: "<<role<<endl;
    }
};



// ================= ADMIN STAFF =================
class AdminStaff : public ElectionStaff {

protected:
    string doj;
    string rank;     
    static int totalStaff;
public:
    AdminStaff(int adharId, string name,string gender,
    int age, int contact,
    string email ,int staffId , string role , string doj, string rank
    )
    : ElectionStaff(adharId,name,gender,age,contact,email,staffId,role),
      doj(doj),rank(rank) {
      	totalStaff++;
      }
    
    void display() override {
        ElectionStaff::display();
        cout<< " Admin Staff Date Of Joining: "<<doj<<endl;
        cout<< " Admin Staff Rank: "<<rank<<endl;
    }
    void verifyVoter(){
        cout<<"Manually verifying voter's Document...."<<endl;
        cout<<"[Voter] verified.!"<<endl;
    }
    void verifyNomination(){
        cout<<"Manually verifying the Nomination record..."<<endl;
        cout<<"[Candidate] nomination verified!!"<<endl;
    }
    void processComplaint(){
        cout<<"Processing Complaint manually...."<<endl;
    } 
    static void showTotalStaff(){                       //static function           
   	  cout<<"Total Admin Staff: "<<totalStaff<<endl;
    }
    
    ~AdminStaff(){                                             //destructor
    	totalStaff--;
    	if(DEBUG)
    	  cout<<"Admin Staff object destroyed: "<<endl;
    }
};





// ================= ELECTION OFFICER =================
class ElectionOfficer : public ElectionStaff {

protected:
    string doa;
    string post;
    string constituency;     
    int experience;
    static int totaleo;
public:
    ElectionOfficer(int adharId, string name,string gender,
    int age, int contact,
    string email ,int staffId , string role , string doa, string post,
    string constituency, int experience)
    : ElectionStaff(adharId,name,gender,age,contact,email,staffId,role),
      doa(doa),post(post),constituency(constituency),experience(experience) {
      	totaleo++;
      }
    string getConstituency() const {
            return constituency;
    }
    void display() override {
        ElectionStaff::display();
        cout<< " Election Officer Date Of Appointment: "<<doa<<endl;
        cout<< " Election Officer Post: "<<post<<endl;
        cout<< " Constituency Assigned to Election Officer : "<<constituency<<endl;
        cout<< " Election Officer Experience (in years): "<<experience<<endl;
        
    }
    void assignedPollinStation(){
        cout<<"List of assigned polling stations..."<<endl;
        cout<<"//after wards actual logic"<<endl;
    }
    void monitorEVM(){
        cout<<"Checking [EVM] status..."<<endl;
    }
    void handleComplaint(){
        cout<<"Handling Complaint manually...."<<endl;
        cout<<"If not handled escalating it to admin staff..."<<endl;
    }
    void manageElection(){
        cout<<"Managing Election [XYZ] ... "<<endl;
    }
    static void showTotalElectionOfficer(){                       //static function           
   	  cout<<"Total ElectionOfficer: "<<totaleo<<endl;
    }
    
    ~ElectionOfficer(){                                             //destructor
    	totaleo--;
    	if(DEBUG)
    	  cout<<"ElectionOfficer object destroyed: "<<name<<endl;
    }
};





// ================= EVM =================
class EVM {

private:
    int evmId;
    string model;
    string software;
    static int totalevm;
public:
    EVM(int evmId,
    string model,
    string software){
    	totalevm++;
    }

    void display(){
        cout<<"Electronic Voting Machine Id: "<<evmId<<endl;
        cout<<"Electronic Voting Machine Model: "<<model<<endl;
        cout<<"Electronic Voting Machine Software version: "<<software<<endl;
    }
    void activate() {
        cout << "[EVM] Activated\n";
    }
    void recordVote() {
        cout << "[EVM] started to record vote...\n";
    }
    void shutdown() {
        cout << "[EVM] shutting down....\n";
    }
    void reportIssue() {
        cout << "[EVM] BEEP!! BEEP!! BEEP!!\n";
        cout << "error occured --> report issue\n";
    }
static void showTotalEVM(){                       //static function           
   	cout<<"Total EVM: "<<totalevm<<endl;
    }
    
    ~EVM(){                                             //destructor
    	totalevm--;
    	if(DEBUG)
    	  cout<<"EVM object destroyed: "<<evmId<<endl;
    }
};




// ================= POLLING STATION =================
class PollingStation {

private:
    string name;
    string location;
    int psId;
    int noOfEVMs;
    int capacity;
    static int totalps;
public:
    PollingStation(string name,string location,int psId,int noOfEVMs,int capacity)
        : name(name),location(location),psId(psId),
          noOfEVMs(noOfEVMs),capacity(capacity) {
       totalps++;
    }
    void display(){
        cout<<"Polling Station Name: "<<name<<endl;
        cout<<"Polling Station Id: "<<psId<<endl;
        cout<<"Polling Station has : "<<noOfEVMs<<" EVMs . "<<endl;
        cout<<"Polling Station has capacity of : "<<capacity<<" people."<<endl;
        cout<<"Polling Station Location: "<<location<<endl;
    }
    void startPolling() {
        cout << "[PollingStation] Polling started\n";
    }
    void allocateEVM(){
        cout<<"[EVM] {no. XYZ} allocated to [Voter].."<<endl;
    }
    void assignedELectionOfficer(){
        cout<<"[Election Officer] -- is assigned."<<endl;
    }
    static void showTotalPollingStation(){                       //static function           
   	  cout<<"Total Polling Station: "<<totalps<<endl;
    }
    
    ~PollingStation(){                                             //destructor
    	totalps--;
    	if(DEBUG)
    	  cout<<"Polling Station object destroyed: "<<name<<endl;
    }
};




// ================= COMPLAINT =================
class Complaint {

private:
    int complaintId;
    string complaintType;
    string description;
    string proposer;
    string dateFiled;
    string status;
    static int totalc;
public:
    Complaint(int complaintId,string complaintType,string description,
    string proposer,string dateFiled,string status)
        : complaintId(complaintId),complaintType(complaintType),
          description(description),proposer(proposer),
          dateFiled(dateFiled),status(status) {
       totalc++;
    }
    void display(){
        cout<<"Complaint from: "<<proposer<<endl;
        cout<<"Complaint Id: "<<complaintId<<endl;
        cout<<"Complaint Type: "<<complaintType<<endl;
        cout<<"Complaint 's Date filed:  "<<dateFiled<<endl;
        cout<<"Complaint description :  "<<description<<endl;
        cout<<"COmplaint status: "<<status<<endl;
    } 
    void file() {
        cout << "[Complaint] Filed in Database.\n";
    }
    void assignedStaff(){
        cout << "Assigned staff will resolve the complaint .."<<endl;
    }
    void escalate(){
        cout<< "If not resolved by ELection Officer ---> escalate."<<endl;
    }
    static void showTotalComplaints(){                       //static function           
   	  cout<<"Total Complaints: "<<totalc<<endl;
    }
    
    ~Complaint(){                                             //destructor
    	totalc--;
    	if(DEBUG)
    	  cout<<"Complaint object destroyed: "<<complaintId<<endl;
    }
};




// ================= NOMINATION RECORDS =================
class NominationRecords {

private:
    int nominationId;
    string nominee;
    string docsSubmitted;
    string don;
    string status;
    static int totalnr;
public:
    NominationRecords(int nominationId,string nominee,string docsSubmitted,
    string don,string status)
        : nominationId(nominationId),nominee(nominee),
          docsSubmitted(docsSubmitted),don(don),status(status) {
       totalnr++;
    }

    void dislay(){
        cout<<"Nomaination Record Id: "<<nominationId<<endl;
        cout<<"Nominee Name (candidate): "<<nominee<<endl;
        cout<<"Date Of Nomination:  "<<don<<endl;
        cout<<"Documents Submitted :  "<<docsSubmitted<<endl;
        cout<<"Nomination status: "<<status<<endl;
    }
    void updateDocs(){
        int choice;
        do {
        	cout << "\nUpdate Menu:\n";
        	cout << "1. Name\n2. Nomination Id\n3. Docs Submitted\n0. Exit\n";
        	cout << "Enter choice: ";
        	cin >> choice;

        	switch(choice) {
            case 1: cin >> nominee; break;
            case 2: cin >> nominationId; break;
            case 3: cin >> docsSubmitted; break;
        	   }
    	} while(choice != 0);
        cout << "[Nomination Record] updated successfully.\n";
    }

    void assignedAdminStaff(){
        cout << "Assigned Admin staff will verify the nomination record .."<<endl;
    }
static void showTotalNominationRecords(){                       //static function           
   	cout<<"Total NominationRecords: "<<totalnr<<endl;
    }
    
    ~NominationRecords(){                                             //destructor
    	totalnr--;
    	if(DEBUG)
    	  cout<<"Nomination object destroyed: "<<nominationId<<endl;
    }
};




// ================= CONSTITUENCY =================
class Constituency {

private:
    string name;
    int cId;
    int noOfPs;
    int population;
    string level;
    int noOfCandidates;
    int noPP;
    static int totalcs;
public:
    Constituency(string name,int cId,int noOfPs,int population,
    string level,int noOfCandidates,int noPP)
        : name(name),cId(cId),noOfPs(noOfPs),
          population(population),level(level),
          noOfCandidates(noOfCandidates),noPP(noPP) {
       totalcs++;
    }
    void display(){
        cout<<"Constituency Name: "<<name<<endl;
        cout<<"Constituency Id: "<<cId<<endl;
        cout<<"[Constituency] has : "<<noOfPs<<" polling stations . "<<endl;
        cout<<"Constituency has population of : "<<population<<" people."<<endl;
        cout<<"Constituency level: "<<level<<endl;
        cout<<"Constituency has : "<<noOfCandidates<<" candidates registered."<<endl;
        cout<<"Constituency has : "<<noPP<<" political parties registered."<<endl;
    }
    void managePollingStations() {
        cout << "[PollingStation] "<< noOfPs<<" are managed by "<<name<<" .";
    }
    void votingStatus(){
        cout<<"[Voters] had voted. out of "<<population<<" ."<<endl;
    }
    void assignedELectionOfficer(){
        cout<<"[Election Officer/s] -- is assigned."<<endl;
    }
    void ppStatus(){
        cout<<"[Political party1] is ahead of [Political party2]. "<<endl;
    }
    void candidateStatus(){
        cout<<"[Candidate] will be regarded as MP."<<endl;
    }
    static void showTotalConstituencies(){                       //static function           
   	cout<<"Total Constituencies: "<<totalcs<<endl;
    }
    
    ~Constituency(){                                             //destructor
    	totalcs--;
    	if(DEBUG)
    	  cout<<"Constituency object destroyed: "<<name<<endl;
    }
};



// ================= POLITICAL PARTY =================
class PoliticalParty {

private:
    string name;
    string location;
    int pId;
    string leader;
    string regDate;
    string abb;
    int members;
    string status;
    static int totalpp;
public:
    PoliticalParty(string name,string location,int pId,
    string leader,string regDate,string abb,int members,string status)
        : name(name),location(location),pId(pId),
          leader(leader),regDate(regDate),
          abb(abb),members(members),status(status) {
       totalpp++;
    }
    void display(){
        cout<<"Political Party Name: "<<name<<endl;
        cout<<"Political Party Id: "<<pId<<endl;
        cout<<"Political Party Abbreviation: "<<abb<<endl;
        cout<<"Political Party has : "<<members<<" members . "<<endl;
        cout<<"Political Party Leader/Founder: "<<leader<<endl;
        cout<<"Political Party Registeration Date: "<<regDate<<endl;
        cout<<"Political Party Location: "<<location<<endl;
    }
    void regParty() {
        cout << "[Political party] registered in [Constituency]\n";
    }
    void manageCandidate(){
        cout<<"1. Remove [Candidate1]"<<endl;
        cout<<"2. Add [Candidate2]"<<endl;
    }
    void showStatus(){
        cout<<"Political Party status: "<<status<<endl;
    }
    void viewActiveCandidates(){
        cout<<"Political Party has : "<<members<<" candidates."<<endl;
    }
    static void showTotalParties(){                       //static function           
   	cout<<"Total Political Parties: "<<totalpp<<endl;
    }
    
    ~PoliticalParty(){                                             //destructor
    	totalpp--;
    	if(DEBUG)
    	  cout<<"Party object destroyed: "<<name<<endl;
    }
};



// ================= ELECTION =================
class Election {

private:
    int eId;
    string electionType;
    string startDate;
    string endDate;
    string conductingAuthority;
    int eligibleVoterCount;
    static int totalElection;
    
public:
    Election(int eId,string electionType,string startDate,
    string endDate,string conductingAuthority,int eligibleVoterCount)
        : eId(eId),electionType(electionType),
          startDate(startDate),endDate(endDate),
          conductingAuthority(conductingAuthority),
          eligibleVoterCount(eligibleVoterCount) {
       totalElection++;
    }
    void display(){
        cout<<"Election Id: "<<eId<<endl;
        cout<<"Election Type: "<<electionType<<endl;
        cout<<"Election started on : "<<startDate<<" and ended on "<<endDate<<" ."<<endl;
        cout<<"Election had eligible voters count of : "<<eligibleVoterCount<<" people."<<endl;
        cout<<"Election conducting Authority: "<<conductingAuthority<<endl;
    }
    void startElection() {
        cout << "[Election] has started\n";
    }
    void endElection() {
        cout << "[Election] has ended\n";
    }
    void generateResults(){
        cout<<"[Political party] won in [constituencies]. {list}"<<endl;
        cout<<"[Candidates] won in [constituencies]. {list}"<<endl;
    }
    void publishReport(){
        cout<<"{list} and report is uploaded to website."<<endl;
    }
    static void showTotalElection(){                       //static function           
   	cout<<"Total Election: "<<totalElection<<endl;
    }
    
    ~Election(){                                             //destructor
    	totalElection--;
    	if(DEBUG)
    	  cout<<"Election object destroyed: "<<eId<<endl;
    }
};



#endif
