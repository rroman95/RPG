#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Monster
{
private:
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
