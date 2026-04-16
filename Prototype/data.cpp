#include "data.h"

int User::totalUsers = 0;
int Voter::totalVoters = 0;
int Candidate::totalCandidate = 0;
int AdminStaff::totalStaff = 0;
int ElectionOfficer::totaleo = 0;
int EVM::totalevm = 0;
int PollingStation::totalps = 0;
int Complaint::totalc = 0;
int NominationRecords::totalnr = 0;
int Constituency::totalcs = 0;
int PoliticalParty::totalpp = 0;
int Election::totalElection = 0;


// ================= VOTERS =================
vector<Voter> getVoters() {
    return {
        Voter(101,"Rahul","Male",21,1111,"r@gmail.com","Active","Surat"),
        Voter(102,"Aman","Male",22,2222,"a@gmail.com","Active","Ahmedabad"),
        Voter(103,"Priya","Female",23,3333,"p@gmail.com","Inactive","Surat"),
        Voter(104,"Neha","Female",24,4444,"n@gmail.com","Active","Vadodara"),
        Voter(105,"Karan","Male",25,5555,"k@gmail.com","Active","Rajkot")
    };
}

// ================= CANDIDATES =================
vector<Candidate> getCandidates() {
    return {
        Candidate(201,"Amit","Male",45,1111,"a@gmail.com","Approved","Surat","Business","Clean","ABC"),
        Candidate(202,"Ravi","Male",50,2222,"r@gmail.com","Pending","Ahmedabad","Lawyer","Clean","XYZ"),
        Candidate(203,"Sita","Female",40,3333,"s@gmail.com","Approved","Surat","Teacher","Clean","ABC"),
        Candidate(204,"Meena","Female",42,4444,"m@gmail.com","Rejected","Rajkot","Doctor","Clean","XYZ"),
        Candidate(205,"Raj","Male",48,5555,"raj@gmail.com","Approved","Vadodara","Engineer","Clean","PQR")
    };
}

// ================= ADMINS =================
vector<AdminStaff> getAdmins() {
    return {
        AdminStaff(301,"Neha","Female",35,1111,"n@gmail.com",1,"Admin","2020","Senior"),
        AdminStaff(302,"Riya","Female",30,2222,"r@gmail.com",2,"Admin","2021","Junior"),
        AdminStaff(303,"Arjun","Male",40,3333,"a@gmail.com",3,"Admin","2019","Senior"),
        AdminStaff(304,"Kiran","Male",38,4444,"k@gmail.com",4,"Admin","2022","Mid"),
        AdminStaff(305,"Pooja","Female",32,5555,"p@gmail.com",5,"Admin","2023","Junior")
    };
}

// ================= OFFICERS =================
vector<ElectionOfficer> getOfficers() {
    return {
        ElectionOfficer(401,"Raj","Male",40,1111,"r@gmail.com",1,"Officer","2021","Supervisor","Surat",10),
        ElectionOfficer(402,"Amit","Male",42,2222,"a@gmail.com",2,"Officer","2020","Manager","Ahmedabad",12),
        ElectionOfficer(403,"Neha","Female",38,3333,"n@gmail.com",3,"Officer","2022","Supervisor","Rajkot",8),
        ElectionOfficer(404,"Ravi","Male",45,4444,"r@gmail.com",4,"Officer","2018","Manager","Surat",15),
        ElectionOfficer(405,"Priya","Female",37,5555,"p@gmail.com",5,"Officer","2023","Supervisor","Vadodara",7)
    };
}

// ================= EVM =================
vector<EVM> getEVMs() {
    return {
        EVM(101,"EVMSO1","EVMOS2.1"), 
        EVM(102,"EVMSO3","EVMOS2.2"), 
        EVM(103,"EVMSO4","EVMOS2.3"), 
        EVM(104,"EVMSO2","EVMOS2.3"), 
        EVM(105,"EVMSO3","EVMOS2.2")
    };
}

// ================= POLLING STATIONS =================
vector<PollingStation> getPollingStations() {
    return {
        PollingStation("PS1","Surat",1,5,500),
        PollingStation("PS2","Ahmedabad",2,6,600),
        PollingStation("PS3","Rajkot",3,4,400),
        PollingStation("PS4","Vadodara",4,7,700),
        PollingStation("PS5","Bhavnagar",5,5,550)
    };
}

// ================= COMPLAINTS =================
vector<Complaint> getComplaints() {
    return {
        Complaint(1,"Tech","EVM issue","Voter1","01-01","Pending"),
        Complaint(2,"Delay","Late start","Voter2","02-01","Resolved"),
        Complaint(3,"Fraud","Fake vote","Voter3","03-01","Pending"),
        Complaint(4,"System","Crash","Voter4","04-01","Resolved"),
        Complaint(5,"Other","General","Voter5","05-01","Pending")
    };
}

// ================= NOMINATIONS =================
vector<NominationRecords> getNominations() {
    return {
        NominationRecords(1,"Amit","Docs","01-01","Pending"),
        NominationRecords(2,"Ravi","Docs","02-01","Approved"),
        NominationRecords(3,"Sita","Docs","03-01","Pending"),
        NominationRecords(4,"Meena","Docs","04-01","Rejected"),
        NominationRecords(5,"Raj","Docs","05-01","Approved")
    };
}

// ================= CONSTITUENCY =================
vector<Constituency> getConstituencies() {
    return {
        Constituency("Surat",1,10,100000,"Urban",5,3),
        Constituency("Ahmedabad",2,12,200000,"Urban",6,4),
        Constituency("Rajkot",3,8,80000,"Semi",4,2),
        Constituency("Vadodara",4,9,90000,"Urban",5,3),
        Constituency("Bhavnagar",5,7,70000,"Rural",3,2)
    };
}

// ================= POLITICAL PARTIES =================
vector<PoliticalParty> getParties() {
    return {
        PoliticalParty("ABC","Delhi",1,"Leader1","2000","ABC",1000,"Active"),
        PoliticalParty("XYZ","Mumbai",2,"Leader2","1995","XYZ",800,"Active"),
        PoliticalParty("PQR","Delhi",3,"Leader3","2010","PQR",600,"Inactive"),
        PoliticalParty("LMN","Kolkata",4,"Leader4","2005","LMN",700,"Active"),
        PoliticalParty("DEF","Chennai",5,"Leader5","2015","DEF",500,"Active")
    };
}

// ================= ELECTION =================
vector<Election> getElections() {
    return {
        Election(1,"General","01-05","10-05","ECI",50000),
        Election(2,"State","02-06","12-06","ECI",60000),
        Election(3,"Local","03-07","13-07","ECI",30000),
        Election(4,"General","04-08","14-08","ECI",70000),
        Election(5,"State","05-09","15-09","ECI",80000)
    };
}
