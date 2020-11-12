#include "Monster.h"

void Monster::ToString()
{
     cout << GetName() << " HP: " << GetHp() << " DMG: " << GetDmg() << endl;
}


void Monster::SetHp(int newhp)
{
    this->hp = newhp;
}
Monster Monster::parseUnit(const std::string& fileName)
{
    std::ifstream file;
    std::string line;
    std::string name;
    std::string _hp;
    std::string _dmg;
    int hp = 0;
    int dmg = 0;
    int key = 0;
    file.open(fileName);

    if (!file.good()) throw 404;
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, line);
            if (key == 1)
            {
                size_t findcolon = line.find(":");
                for (int i = findcolon+3; line[i] != '"'; i++)
                {
                     name += line[i];
                }

            }
            if (key == 2)
            {
                for (unsigned int i = 0; i < line.size(); i++)
                    if (isdigit(line[i]))
                        _hp += line[i];
            }
            if (key == 3)
            {
                for (unsigned int i = 0; i < line.size(); i++)
                    if (isdigit(line[i]))
                        _dmg += line[i];
            }

            key++;
        }
        hp = stoi(_hp);
        dmg = stoi(_dmg);
        file.close();
    }
    return Monster(name, hp, dmg);
}
