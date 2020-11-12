#include "Monster.h"

void Monster::ToString()
{
    std::cout << GetName() << " HP: " << GetHp() << " DMG: " << GetDmg() << " ATTACKSPEED: " << attackspeed << std::endl;
}

void Monster::SetHp(int newhp)
{
    this->hp = newhp;
}

void Monster::Attack(Monster& monster1, Monster& monster2) // monster1 Attacks monster2
{
    std::cout << monster1.GetName() << " -> " << monster2.GetName() << std::endl;
    monster2.SetHp(monster2.GetHp() - monster1.GetDmg());
    if (monster2.GetHp() < 0) { monster2.SetHp(0); }
}

void Monster::WhoAttacks(Monster& monster1, Monster& monster2)
{
    if (monster1.cooldown < monster2.cooldown) // monster1 attacks monster2 
    {
        Attack(monster1, monster2);                         //ATTACK
        monster2.cooldown -= monster1.cooldown;
        monster1.cooldown = monster1.GetAttackSpeed();

    }
    else if (monster1.cooldown > monster2.cooldown) // monster2 attacks monster1
    {
        Attack(monster2, monster1);                         //ATTACK
        monster1.cooldown -= monster2.cooldown;
        monster2.cooldown = monster2.GetAttackSpeed();

    }
    if (monster1.cooldown == monster2.cooldown) //if cooldown1 == coldown2, monster1 attacks
    {
        //Attack(monster1, monster2);
        std::cout << "PARRY" << std::endl;
        monster1.cooldown = monster1.GetAttackSpeed();
        monster2.cooldown = monster2.GetAttackSpeed();
    }

}

void Monster::Battle(Monster& monster1, Monster& monster2)
{
    while (monster1.GetHp() > 0 && monster2.GetHp() > 0)
    {
        WhoAttacks(monster1, monster2);
    }
    if (monster1.GetHp() == 0) { std::cout << monster2.GetName() << " wins Remaining HP: " << monster2.GetHp() << endl; }
    else { std::cout << monster1.GetName() << " wins Remaining HP: " << monster1.GetHp() << endl; }
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
