#include "Monster.h"

void Monster::ToString()
{
    cout << GetName() << " HP: " << GetHp() << " DMG: " << GetDmg() << endl;
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


Monster Monster::parseUnit(const std::string& fileName)
{
    std::ifstream file;
    std::string line;
    std::string name;
    std::string _hp;
    std::string _dmg;
    int hp = 0;
    int dmg = 0;
    int key = 0;
    file.open(fileName);

    if (!file.good()) throw 404;
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, line);
            if (key == 1)
            {
                size_t findcolon = line.find(":");
                for (int i = findcolon+3; line[i] != '"'; i++)
                {
                    name += line[i];
                }

            }
            if (key == 2)
            {
                for (unsigned int i = 0; i < line.size(); i++)
                    if (isdigit(line[i]))
                        _hp += line[i];
            }
            if (key == 3)
            {
                for (unsigned int i = 0; i < line.size(); i++)
                    if (isdigit(line[i]))
                        _dmg += line[i];
            }

            key++;
        }
        hp = stoi(_hp);
        dmg = stoi(_dmg);
        file.close();
    }
    return Monster(name, hp, dmg);
}