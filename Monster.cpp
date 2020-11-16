#include "Monster.h"

void Monster::ToString()
{
    std::cout << GetName() << " HP: " << GetHp() << " DMG: " << GetDmg() << " Attackspeed: " << attackspeed << std::endl;
}

void Monster::SetHp(int newhp)
{
    this->hp = newhp;
}

bool Monster::IsAlive()
{
    if (this->hp > 0)
        return 1;
    else
        return 0;
}

void Monster::Attack(Monster& other) //Current Monster attacks Other Adventurer
{
    std::cout << this->name << " -> " << other.GetName() << std::endl;
    other.SetHp(other.GetHp() - dmg);
}

void Monster::WhoAttacks(Monster& monster1, Monster& monster2)
{
    if (monster1.cooldown < monster2.cooldown) // monster1 attacks monster2 
    {
        monster1.Attack(monster2);                         //ATTACK
        monster2.cooldown -= monster1.cooldown;
        monster1.cooldown = monster1.GetAttackSpeed();

    }
    else if (monster1.cooldown > monster2.cooldown) // monster2 attacks monster1
    {
        monster2.Attack(monster1);                         //ATTACK
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

void Monster::Battle(Monster& adventurer, Monster& monster)
{
    while (adventurer.IsAlive() && monster.IsAlive())
    {
        WhoAttacks(adventurer, monster);
        adventurer.ToString();
        monster.ToString();
    }
    if (!adventurer.IsAlive()) { std::cout << monster.GetName() << " wins Remaining HP: " << monster.GetHp() << std::endl; }
    else { std::cout << adventurer.GetName() << " wins Remaining HP: " << adventurer.GetHp() << std::endl; }
}

Monster Monster::parseUnit(JSON& obj)
{

    std::map<std::string, std::string> charData = obj.charData;
    std::string name = charData["name"];
    int dmg = stoi(charData["dmg"]);
    int hp = stoi(charData["hp"]);
    int cooldown = stoi(charData["cooldown"]);
    return Monster(name, hp, dmg, cooldown);


};
