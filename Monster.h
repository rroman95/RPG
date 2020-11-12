#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "JSON.h"
using namespace std;

class Monster
{
private:
    std::string name;
    int hp;
    int dmg;
    double attackspeed;

public:
    double cooldown;
    Monster(string name, int hp, int dmg) : name(name), hp(hp), dmg(dmg), attackspeed(0), cooldown(0) {};
    Monster(string name, int hp, int dmg, double attackspeed) : name(name), hp(hp), dmg(dmg), attackspeed(attackspeed), cooldown(attackspeed) {};
    std::string GetName() const { return name; }
    int GetHp() const { return hp; }
    void SetHp(int);
    int GetDmg() const { return dmg; }
    double GetAttackSpeed() { return attackspeed; }
    void ToString();
    static Monster parseUnit(JSON&);
};
