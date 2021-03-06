#include "JSON.h"
#include "Monster.h"
#include "Adventurer.h"
#include "gtest/gtest.h"


using namespace std;


TEST(JSON_test, normal_json_file) {
	std::ifstream f("Adventurer.json");
        JSON json(f);
	EXPECT_EQ(json.charData["name"], "Adventurer");
	EXPECT_EQ(json.charData["hp"], "300");
	EXPECT_EQ(json.charData["dmg"], "15");
        EXPECT_EQ(json.charData["cooldown"], "2");
}

TEST(JSON_test, whitespace_offset) {
	std::ifstream f("Monster.json");
        JSON json(f);
	EXPECT_EQ(json.charData["name"], "Monster");
	EXPECT_EQ(json.charData["hp"], "100");
	EXPECT_EQ(json.charData["dmg"], "30");
        EXPECT_EQ(json.charData["cooldown"], "2.5");
}

TEST(JSON_test, different_type_of_inputs_for_JSON) {
	std::ifstream stream_input("Adventurer.json");
	std::string string_input = "Adventurer.json";
	const char * filename_input = "Adventurer.json";
	JSON json1(stream_input);
	JSON json2(string_input);
	JSON json3(filename_input);
	EXPECT_EQ(json1.charData["name"], "Adventurer");
	EXPECT_EQ(json2.charData["name"], "Adventurer");
	EXPECT_EQ(json3.charData["name"], "Adventurer");
	EXPECT_EQ(json1.charData["hp"], json2.charData["hp"]);
	EXPECT_EQ(json2.charData["hp"], json3.charData["hp"]);
	EXPECT_EQ(json1.charData["dmg"], json3.charData["dmg"]);
}

TEST(Unit_test,Fight_til_death) {
	std::ifstream in1("Adventurer.json");
	std::ifstream in2("Monster.json");
        JSON json1(in1);
	JSON json2(in2);
	Monster monster = Monster::parseUnit(json2);
        Adventurer adventurer = Monster::parseUnit(json1);
        Monster::Battle(adventurer, monster);
	EXPECT_TRUE(adventurer.IsAlive());
	EXPECT_FALSE(monster.IsAlive());
}

