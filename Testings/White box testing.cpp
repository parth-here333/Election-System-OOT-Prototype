#include <gtest/gtest.h>
#include "ElectionSystem.h"

// ================= HELPER FUNCTION =================
// (Refactored version of authenticate logic for testability)

bool checkCredentials(std::string username, std::string password) {
    std::vector<std::pair<std::string, std::string>> validAdmins = {
        {"parth", "1234"},
        {"prajyesh", "5678"}
    };

    for (auto &admin : validAdmins) {
        if (username == admin.first && password == admin.second) {
            return true;
        }
    }
    return false;
}

// ===================================================
// 🔥 1. STATEMENT COVERAGE
// ===================================================

TEST(StatementCoverage, ValidAdmin) {
    EXPECT_TRUE(checkCredentials("parth", "1234"));
}

TEST(StatementCoverage, InvalidAdmin) {
    EXPECT_FALSE(checkCredentials("wrong", "wrong"));
}

// ===================================================
// 🔥 2. BRANCH / DECISION COVERAGE
// ===================================================

TEST(BranchCoverage, CorrectUsernameWrongPassword) {
    EXPECT_FALSE(checkCredentials("parth", "wrong"));
}

TEST(BranchCoverage, WrongUsername) {
    EXPECT_FALSE(checkCredentials("unknown", "1234"));
}

TEST(BranchCoverage, CorrectBoth) {
    EXPECT_TRUE(checkCredentials("prajyesh", "5678"));
}

// ===================================================
// 🔥 3. PATH COVERAGE (Login Attempts Simulation)
// ===================================================

bool loginSimulation(std::vector<std::pair<std::string,std::string>> attempts) {
    int tries = 3;
    for (auto &a : attempts) {
        if (tries-- == 0) break;
        if (checkCredentials(a.first, a.second)) {
            return true;
        }
    }
    return false;
}

TEST(PathCoverage, SuccessFirstAttempt) {
    std::vector<std::pair<std::string,std::string>> attempts = {
        {"parth","1234"}
    };
    EXPECT_TRUE(loginSimulation(attempts));
}

TEST(PathCoverage, SuccessSecondAttempt) {
    std::vector<std::pair<std::string,std::string>> attempts = {
        {"wrong","wrong"},
        {"parth","1234"}
    };
    EXPECT_TRUE(loginSimulation(attempts));
}

TEST(PathCoverage, FailAllAttempts) {
    std::vector<std::pair<std::string,std::string>> attempts = {
        {"a","b"}, {"c","d"}, {"e","f"}
    };
    EXPECT_FALSE(loginSimulation(attempts));
}

// ===================================================
// 🔥 4. LOOP TESTING
// ===================================================

int loopTestFunction(int ch) {
    int count = 0;
    do {
        count++;
    } while(ch-- > 1);
    return count;
}

TEST(LoopTesting, ZeroIterationLikeExit) {
    EXPECT_EQ(loopTestFunction(1), 1);
}

TEST(LoopTesting, SingleIteration) {
    EXPECT_EQ(loopTestFunction(2), 2);
}

TEST(LoopTesting, MultipleIterations) {
    EXPECT_EQ(loopTestFunction(5), 5);
}

// ===================================================
// 🔥 5. INTERNAL STRUCTURE TESTING (CLASSES)
// ===================================================

TEST(VoterTest, GetterFunctions) {
    Voter v(1,"A","M",20,123456,"a@mail","active","XYZ");

    EXPECT_EQ(v.getName(), "A");
    EXPECT_EQ(v.getAge(), 20);
    EXPECT_EQ(v.getStatus(), "active");
    EXPECT_EQ(v.getConstituency(), "XYZ");
}

TEST(VoterTest, MethodExecution) {
    Voter v(2,"B","F",25,999,"b@mail","active","ABC");
    v.castVote(); // just checking no crash
}

TEST(CandidateTest, GetterTest) {
    Candidate c(1,"C","M",30,111,"c@mail","approved","XYZ",
                "Engineer","details","PartyA");

    EXPECT_EQ(c.getParty(), "PartyA");
    EXPECT_EQ(c.getStatus(), "approved");
}

TEST(EVMTest, Operations) {
    EVM e(1,"ModelX","v1");
    e.activate();
    e.recordVote();
    e.shutdown();
}

TEST(ComplaintTest, Methods) {
    Complaint c(1,"Type","Desc","User","01-01-2026","Open");
    c.file();
    c.assignedStaff();
    c.escalate();
}

// ===================================================
// 🔥 6. EDGE CASE TESTING (IMPORTANT FOR FULL COVERAGE)
// ===================================================

TEST(EdgeCase, EmptyCredentials) {
    EXPECT_FALSE(checkCredentials("", ""));
}

TEST(EdgeCase, SpecialCharacters) {
    EXPECT_FALSE(checkCredentials("@@@", "###"));
}

TEST(EdgeCase, CaseSensitivity) {
    EXPECT_FALSE(checkCredentials("Parth", "1234")); // should fail
}

// ===================================================
// MAIN
// ===================================================

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}