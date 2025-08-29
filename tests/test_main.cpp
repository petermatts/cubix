#include "gtest/gtest.h"
#include "toml++/toml.h"
#include "cube.hpp"

using namespace std;

TEST(Solved, solved) {
    toml::table config = toml::parse_file("./solutions/solved.toml");

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
}

// TEST(MoveTest, U) {

// }
