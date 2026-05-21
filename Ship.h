/*Ship, CruiseShip, and CargoShip Classes
Design a Ship class that has the following members:
• A member variable for the name of the ship (a string)
• A member variable for the year that the ship was built (a string)
• A constructor and appropriate accessors and mutators
• A virtual print function that displays the ship’s name and the year it was built.
Design a CruiseShip class that is derived from the Ship class. The CruiseShip class should have the following members:
• A member variable for the maximum number of passengers (an int)
• A constructor and appropriate accessors and mutators
• A print function that overrides the print function in the base class. The CruiseShip class’s print function should display only the ship’s name and the maximum number of passengers.
Design a CargoShip class that is derived from the Ship class. The CargoShip class should have the following members:
• A member variable for the cargo capacity in tonnage (an int)
• A constructor and appropriate accessors and mutators
• A print function that overrides the print function in the base class. The CargoShip class’s print function should display only the ship’s name and the ship’s cargo capacity.
Demonstrate the classes in a program that has an array of Ship pointers. The array elements should be initialized with the addresses of dynamically allocated Ship, CruiseShip, and CargoShip objects. (See Program 15-14, lines 17 through 22, for an example of how to do this.) The program should then step through the array, calling each object’s print function.*/


#include <string>
#include <iostream>
class Ship{
    private:
        std::string name;
        std::string yearBuilt;
    public:
        Ship():name(""),yearBuilt(""){}
        Ship(std::string n,std::string y):name(n),yearBuilt(y){}
        
        void setName(std::string n){name=n;}
        void setYearBuilt(std::string y){yearBuilt=y;}
        
        std::string getName() const{return name;}
        std::string getYearBuilt() const{return yearBuilt;}

        virtual void print() const{
            std::cout << "Name: "<<this->getName()<<std::endl;
            std::cout << "Year Built: "<<this->getYearBuilt()<<std::endl;
        }
};

class CruiseShip: public Ship{
    private:
        int maxNoOfPassengers;
    public:
        CruiseShip():Ship(),maxNoOfPassengers(0){}
        CruiseShip(std::string n,std::string y, int max):
                                                        Ship(n,y),maxNoOfPassengers(max){}

        void setMaxNoOfPassengers(int m){maxNoOfPassengers=m;}
        int getMaxNoOfPassengers() const{return maxNoOfPassengers;}

        void print() const override{
            std::cout << "Name: "<<this->getName()<<std::endl;
            std::cout << "Maximum Number of Passengers:"<<this->getMaxNoOfPassengers()<<std::endl;
        
        }

};

class CargoShip: public Ship{
    private:
        int cargoCapacity;
    public:
        CargoShip():Ship(),cargoCapacity(0){}
        CargoShip(std::string n,std::string y,int c):Ship(n,y),cargoCapacity(c){}

        void setCargoCapacity(int c){cargoCapacity=c;}
        int getCargoCapacity() const{return cargoCapacity;}

        void print() const override{
            std::cout << "Name: "<<this->getName()<<std::endl;
            std::cout << "Ship's Cargo Capacity:"<<this->getCargoCapacity()<<std::endl; 
        }

};