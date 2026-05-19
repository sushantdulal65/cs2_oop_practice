// Design a class named PersonData with the following member variables:
// • lastName
// • firstName
// • address
// • city
// • state
// • zip
// • phone
// Write the appropriate accessor and mutator functions for these member variables.
// Next, design a class named CustomerData, which is derived from the PersonData class. The CustomerData class should have the following member variables:
// ﻿• customerNumber
// • mailingList
// The customerNumber variable will be used to hold a unique integer for each customer. The mailingList variable should be a bool. It will be set to true if the customer wishes to be on a mailing list, or false if the customer does not wish to be on a mailing list. Write appropriate accessor and mutator functions for these member variables. Demonstrate an object of the CustomerData class in a simple program.


#include <iostream>
#include "PersonData.h"
using namespace std;

int main(){

    CustomerData Sushant;

    Sushant.setFirstName("Sushant");
    Sushant.setLastName("Dulal");
    Sushant.setAddress("123 Main Street");
    Sushant.setCity("Irving");
    Sushant.setState("TX");
    Sushant.setZip(75062);
    Sushant.setPhone(2145551234);
    Sushant.setCustomerNumber(1001);
    Sushant.setMailingList(true);

    cout << "Customer Information" << endl;
    cout << "--------------------" << endl;
    cout << "Name: " << Sushant.getFirstName() << " "
         << Sushant.getLastName() << endl;
    cout << "Address: " << Sushant.getAddress() << endl;
    cout << "City: " << Sushant.getCity() << endl;
    cout << "State: " << Sushant.getState() << endl;
    cout << "ZIP: " << Sushant.getZip() << endl;
    cout << "Phone: " << Sushant.getPhone() << endl;
    cout << "Customer Number: " << Sushant.getCustomerNumber() << endl;
    cout << "Mailing List: "
         << (Sushant.getMailingList() ? "Yes" : "No") << endl;
    
    return 0;
}
