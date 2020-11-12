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

void Adventurer::LevelingLogic()
{
    xp += dmg;

    if (xp >= 100)
        while (xp >= 100)
        {
            level++;
            xp -= 100;
            hp = hp + (hp * 0.1);
            act_hp = hp;
            dmg = dmg + (dmg * 0.1);
            //std::cout << name << " has leveled up to " << level << std::endl;
        }
}

void Adventurer::SetAct_Hp(int acthp)
{
    act_hp = acthp;
}

void Adventurer::ToString()
{
    cout << GetName() << " HP: " << GetAct_Hp() << " DMG: " << GetDmg() << " Level: " << GetLevel() << " XP: " << GetXp() << endl;
}
