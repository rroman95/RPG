#include "Monster.h"

void Monster::Attack(Monster& monster1, Monster& monster2) /// Monster1 attacks Monster2
{
    cout << monster1.name << " -> " << monster2.name << endl;
    monster2.hp = monster2.hp - monster1.dmg;
    if (monster2.hp < 0)
        monster2.hp = 0;
}

void Monster::ToString()
{
    cout << GetName() << " HP: " << GetHp() << " DMG: " << GetDmg() << endl;
}

Monster::Monster()
{
    this->name = "";
    this->hp = 0;
    this->dmg = 0;
}

Monster::Monster(string name, int hp, int dmg)
{
    this->name = name;
    this->hp = hp;
    this->dmg = dmg;
}