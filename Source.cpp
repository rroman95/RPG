#include "Monster.h"

int main(int argc, char** argv)
{  
   if (argc == 3)
        try
    {
       Monster thor = Monster::parseUnit(argv[1]);
       Monster hulk = Monster::parseUnit(argv[2]);
       Monster::Battle(thor,hulk);
    }

    catch (int e)
    {
        if (e == 404)
        {std::cout << "File Doesnt exist" << std::endl; }
    }
   else
    {
        std::cout << "Wrong arguments" << std::endl;
    }
    return 0;
}