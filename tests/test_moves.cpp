#include "gtest/gtest.h"
#include "toml.hpp"
#include "cube.hpp"
#include "common.hpp"

using namespace std;

class MoveTest : public ::testing::Test {
    protected:
        Cube solved = Cube();
    // CubeTest() {
    //     Cube cube = Cube();
    // }
    // ~CubeTest() override = default;
};

TEST_F(MoveTest, solved) {
    toml::table config = toml::parse_file("solutions/solved.toml");

    cout << config << endl;

    /*
        try {
            toml::table config = toml::parse_file("config.toml");
            // ... access data from 'config' table
        } catch (const toml::parse_error& err) {
            std::cerr << "Error parsing TOML file: " << err << std::endl;
            return 1; // Or handle the error appropriately
        }
     */
    EXPECT_TRUE(true);
}