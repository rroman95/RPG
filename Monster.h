#ifndef MONSTER_H
#define MONSTER_H
#include<iostream>
#include<string>
#include<fstream>
#include "JSON.h"


class Monster
{
private:
    std::string name;
    int hp;
    int dmg;
    double attackspeed;
    
public:
    double cooldown;
    Monster(string name, int hp, int dmg) : name(name), hp(hp), dmg(dmg),attackspeed(0),cooldown(0) {};
    Monster(string name, int hp, int dmg,double attackspeed) : name(name), hp(hp), dmg(dmg),attackspeed(attackspeed), cooldown(attackspeed) {};
    std::string GetName() const { return name; }
    int GetHp() const { return hp; }  					 ///< Lekéri a szörny életét
    void SetHp(int);							 ///< Beállítja a szörny életét
    int GetDmg() const { return dmg; }					 ///< Lekéri a szörny sebzését
    double GetAttackSpeed() { return attackspeed; }
    void ToString();
    static void Battle(Monster&, Monster&);
    static void WhoAttacks(Monster&, Monster&);
    static void Attack(Monster&, Monster&);
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
