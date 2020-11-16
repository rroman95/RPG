#ifndef MONSTER_H
#define MONSTER_H
#include<iostream>
#include<string>
#include<fstream>
#include "JSON.h"

class Monster
{
protected:
    std::string name;
    int hp;
    int dmg;
    double attackspeed;
    virtual void Attack(Monster& other);
    
public:
    double cooldown;
    Monster(std::string name, int hp, int dmg) : name(name), hp(hp), dmg(dmg),attackspeed(0),cooldown(0) {};
    Monster(std::string name, int hp, int dmg, double attackspeed) : name(name), hp(hp), dmg(dmg),attackspeed(attackspeed), cooldown(attackspeed) {};
    std::string GetName() const { return name; }
    int GetHp() const { return hp; }  					 ///< Lekéri a szörny életét
    void SetHp(int);							 ///< Beállítja a szörny életét
    int GetDmg() const { return dmg; }					 ///< Lekéri a szörny sebzését
    double GetAttackSpeed() const{ return attackspeed; }
    virtual void ToString();
    virtual bool IsAlive();
    static void Battle(Monster&, Monster&);
    static void WhoAttacks(Monster&, Monster&);
    static Monster parseUnit(JSON&);
};

#endif
