#include <iostream>
#include "Ship.h"

int main()
{
    Ship *ptr[3] = { new Ship("Titanic","1994"),
        new CruiseShip("Titanic","1994",309), 
        new CargoShip("Titanic","1994",1300)};
    ptr[0]->print();
    ptr[1]->print();
    ptr[2]->print();

}