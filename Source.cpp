#include "Monster.h"

void Attack(Adventurer& adventurer, Monster& monster) // ADVENTURER attacks Monster
{
    monster.SetHp(monster.GetHp() - adventurer.GetDmg());
    if (monster.GetHp() < 0) { monster.SetHp(0); }
    adventurer.LevelingLogic();
}

void Attack(Monster& monster, Adventurer& adventurer) // Monster attacks ADVENTURER
{
    adventurer.SetAct_Hp(adventurer.GetAct_Hp() - monster.GetDmg());
    if (adventurer.GetAct_Hp() < 0) { adventurer.SetAct_Hp(0); }
}

void Battle(Adventurer& adventurer, Monster& monster)
{
    int n = 0;
    while (adventurer.GetHp() > 0 && monster.GetHp() > 0)
    {
        if ((n % 2 == 0) && adventurer.GetHp() > 0)
            Attack(adventurer, monster);
        else if (monster.GetHp() > 0)
            Attack(monster, adventurer);
        n++;
    }
    if (adventurer.GetHp() == 0) { std::cout << monster.GetName() << " wins Remaining HP: " << monster.GetHp() << endl; }
    else { std::cout << adventurer.GetName() << " wins Remaining HP: " << adventurer.GetHp() << " Level: " << adventurer.GetLevel() << endl; }
}


int main(int argc, char** argv)
{
   if (argc == 3)
        try
    {
        JSON json1(argv[1]);
        JSON json2(argv[2]);
        Monster monster1 = Monster::parseUnit(json1);
        Monster monster2 = Monster::parseUnit(json2);
        Battle(monster1, monster2);
    }

    catch (int e)
    {
        {std::cout << "File Doesnt exist" << std::endl; }
    }
    if (argc < 3)
    {
        std::cout << "Wrong arguments" << std::endl;
    }
    return 0;
}
