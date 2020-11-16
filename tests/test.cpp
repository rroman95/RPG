#include "../JSON.cpp"
#include "gtest/gtest.h"


using namespace std;


TEST(Jsontest, Fajlvaltozo) {
	std::ifstream f("Adventurer.json");
  JSON json1(f);
	Adventurer adventurer = Monster::parseUnit(json1);
	EXPECT_EQ(adventurer.charData["name"], "Adventurer");
	EXPECT_EQ(adventurer.charData["dmg"], "300");
	EXPECT_EQ(adventurer.charData["hp"], "15");
  EXPECT_EQ(adventurer.charData["cooldown"], "2");
}
