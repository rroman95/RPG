#include "Monster.h"
using namespace std;

void Battle(Monster& monster1, Monster& monster2)
{
    int n = 0;
    monster1.ToString();
    monster2.ToString();
    while (monster1.GetHp() > 0 && monster2.GetHp() > 0)
    {
        if ((n % 2 == 0) && monster1.GetHp() > 0)
            Monster::Attack(monster1, monster2);
        else if (monster2.GetHp() > 0)
            Monster::Attack(monster2, monster1);

        monster1.ToString();
        monster2.ToString();
        n++;
    }
    if (monster1.GetHp() == 0) { cout << monster1.GetName() << " DIED! " << monster2.GetName() << " wins." << endl; }
    else { cout << monster2.GetName() << " DIED! " << monster1.GetName() << " wins." << endl; }
}


int main()
{
    Monster thor("Thor", 150, 10);
    Monster loki("Loki", 45, 30);
    Battle(thor, loki);
    return 0;
}
