#include "Monster.h"
using namespace std;

void Attack(Monster& monster1, Monster& monster2) // monster1 Attacks monster2
{
    monster2.SetHp(monster2.GetHp() - monster1.GetDmg());
    if (monster2.GetHp() < 0) { monster2.SetHp(0); }
}

void Battle(Monster& monster1, Monster& monster2)
{
    int n = 0;
    while (monster1.GetHp() > 0 && monster2.GetHp() > 0)
    {
        if ((n % 2 == 0) && monster1.GetHp() > 0)
            Attack(monster1,monster2);
        else if (monster2.GetHp() > 0)
            Attack(monster2, monster1);


        n++;

    }
    if (monster1.GetHp() == 0) {std::cout << monster2.GetName() << " wins Remaining HP: "<< monster2.GetHp() << endl; }
    else {std::cout << monster1.GetName() << " wins Remaining HP: " << monster1.GetHp() << endl; }
}


int main(int argc, char** argv)
{
   if (argc == 3)
        try
    {
        Monster thor = Monster::parseUnit(argv[1]);
        Monster hulk = Monster::parseUnit(argv[2]);
        Battle(hulk, thor);
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