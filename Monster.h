#ifndef MONSTER_H
#define MONSTER_H
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Monster
{
protected:
    std::string name;
    int hp;
    int dmg;
public:
    Monster(string name, int hp, int dmg) : name(name), hp(hp), dmg(dmg) {};
    std::string GetName() const { return name; }
    int GetHp() const { return hp; }
    void SetHp(int);
    int GetDmg() const { return dmg; }
    void ToString();
    static Monster parseUnit(const std::string&);
};

class Adventurer : public Monster
{
protected:
    int xp, level;
    int act_hp;

public:
    Adventurer(const Monster& sz) :Monster(sz.GetName(), sz.GetHp(), sz.GetDmg()), xp(0), level(1), act_hp(hp) {};
    int GetLevel() const { return level; }
    void SetLevel(int);
    int GetXp() const { return xp; };
    void SetXp(int);
    void ToString();
    int GetAct_Hp() { return act_hp; };
    void SetAct_Hp(int);


    void LevelingLogic();
};


#endif