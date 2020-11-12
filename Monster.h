#pragma once
#include<iostream>
#include<string>
using namespace std;

class Monster
{
private:
    std::string name;
    int hp;
    int dmg;
public:
    Monster();
    Monster(string, int, int);
    std::string GetName() const { return name; }
    int GetHp() const { return hp; }
    int GetDmg() const { return dmg; }
    void ToString();
    static void Attack(Monster&, Monster&);
};