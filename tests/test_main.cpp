#include <gtest/gtest.h>
#include "Cube.hpp"  // Adjust if it's in a subfolder

class CubeTest : public ::testing::Test {
protected:
    Cube solved;

    void SetUp() override {
        // No setup required for now
    }
};

TEST_F(CubeTest, CubeIsSolvedAtStart) {
    EXPECT_TRUE(solved.isSolved());
}

TEST_F(CubeTest, SingleMoveUnsolvesCube) {
    Cube moved = solved.U();
    EXPECT_FALSE(moved.isSolved());
}

TEST_F(CubeTest, FourSameMovesRestoreCube) {
    Cube moved = solved.U().U().U().U();
    EXPECT_TRUE(moved.isSolved());
}

TEST_F(CubeTest, InverseMoveRestoresCube) {
    Cube moved = solved.U().U_prime();
    EXPECT_TRUE(moved.isSolved());
}

TEST_F(CubeTest, SequenceAndInverseRestoreCube) {
    Cube scrambled = solved.U().R().L();
    Cube restored = scrambled.L_prime().R_prime().U_prime();
    EXPECT_TRUE(restored.isSolved());
}

TEST_F(CubeTest, DifferentMovesYieldDifferentStates) {
    Cube u = solved.U();
    Cube r = solved.R();
    EXPECT_FALSE(u.isSolved());
    EXPECT_FALSE(r.isSolved());
    EXPECT_NE(u, r);
}

TEST_F(CubeTest, NoMutationOnOriginalCube) {
    Cube u = solved.U();
    EXPECT_TRUE(solved.isSolved()); // original should still be solved
    EXPECT_FALSE(u.isSolved());
}
