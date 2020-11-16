#include "Adventurer.h"


void Adventurer::Attack(Monster& other) //Adventurer attacks Other Monster
{
    //std::cout << this->name << " -> " << other.GetName() << std::endl;
    other.SetHp(other.GetHp() - dmg);
    LevelingLogic();
}


void Adventurer::LevelingLogic()
{
    xp += dmg;

    if (xp >= 100)
        while (xp >= 100)
        {
            level++;
            xp -= 100;
            max_hp = max_hp + (int)round(max_hp * 0.1);
            hp = max_hp;
            dmg = dmg + (int)round(dmg * 0.1);
            //std::cout << name << " has leveled up to " << level << std::endl;
        }
}

void Adventurer::ToString()
{
    std::cout << GetName() << " HP: " << GetHp() << " DMG: " << GetDmg() << " Level: " << GetLevel() << " XP: " << GetXp() << " Attackspeed: " << GetAttackSpeed() << std::endl;
}
