#include "Monster.h"

void Monster::ToString()
{
    std::cout << GetName() << " HP: " << GetHp() << " DMG: " << GetDmg() << " ATTACKSPEED: " << attackspeed << std::endl;
}


void Monster::SetHp(int newhp)
{
    this->hp = newhp;
}


Monster Monster::parseUnit(JSON& obj)
{

    std::map<std::string, std::string> charData = obj.charData;
    std::string name = charData["name"];
    int dmg = stoi(charData["dmg"]);
    int hp = stoi(charData["hp"]);
    return Monster(name, hp, dmg);


};