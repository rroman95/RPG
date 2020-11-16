#include "Monster.h"
#include "Adventurer.h"

int main(int argc, char** argv)
{  
   //if (argc == 3)
        try
    {
        /*JSON json1(argv[1]);
        JSON json2(argv[2]);*/
        JSON json1("units/adventurer.json");
        JSON json2("units/monster.json");
        Monster monster = Monster::parseUnit(json2);
        Adventurer adventurer = Monster::parseUnit(json1);
        json1.printcharData();
        json2.printcharData();
        monster.ToString();
        adventurer.ToString();

        Monster::Battle(adventurer, monster);
    }

    catch (int e)
    {
        if (e == 404)
        {std::cout << "File Doesnt exist" << std::endl; }
    }
   /*else
    {
        std::cout << "Wrong arguments" << std::endl;
    }*/
    return 0;
}
