#include "JSON.h"
#include "gtest/gtest.h"


using namespace std;


TEST(JSON_test, normal_json_file) {
	std::ifstream f("Adventurer.json");
        JSON json(f);
	EXPECT_EQ(json.charData["name"], "Adventurer");
	EXPECT_EQ(json.charData["dmg"], "15");
	EXPECT_EQ(json.charData["hp"], "300");
        EXPECT_EQ(json.charData["cooldown"], "2");
}

TEST(JSON_test, whitespace_offset) {
	std::ifstream f("Monster.json");
        JSON json(f);
	EXPECT_EQ(json.charData["name"], "Monster");
	EXPECT_EQ(json.charData["dmg"], "100");
	EXPECT_EQ(json.charData["hp"], "30");
        EXPECT_EQ(json.charData["cooldown"], "2.5");
}

