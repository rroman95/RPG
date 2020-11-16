#include "../JSON.h"
#include "gtest/gtest.h"


using namespace std;


TEST(Jsontest, Fajlvaltozo) {
	std::ifstream f("Adventurer.json");
        JSON json(f);
	EXPECT_EQ(json.charData["name"], "Adventurer");
	EXPECT_EQ(json.charData["dmg"], "15");
	EXPECT_EQ(json.charData["hp"], "300");
        EXPECT_EQ(json.charData["cooldown"], "2");
}
