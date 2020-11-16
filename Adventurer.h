#ifndef ADVENTURER_H
#define ADVENTURER_H
#include<iostream>
#include<string>
#include<fstream>
#include "Monster.h"

class Adventurer : public Monster
{
protected:
    int xp, level;
    int max_hp;
    virtual void Attack(Monster& other);
public:
    Adventurer(const Monster& sz) :Monster(sz.GetName(), sz.GetHp(), sz.GetDmg(), sz.GetAttackSpeed()), xp(0), level(1), max_hp(hp) {};
    int GetLevel() const { return level; }
    int GetXp() const { return xp; };
    void ToString();
    int GetMax_Hp() { return max_hp; };
    int GetLevel() { return level; }


    void LevelingLogic();
};

#endif