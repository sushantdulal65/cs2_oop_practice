#ifndef PERSONDATA_H
#define PERSONDATA_H


#include <string>
using namespace std;

class PersonData{
    private:
        string lastName;
        string firstName;
        string address;
        string city;
        string state;
        long int zip;
        long int phone;
    public:
        // Mutators
        void setLastName(string lname)
        { lastName = lname; }

        void setFirstName(string fname)
        { firstName = fname; }

        void setAddress(string addr)
        { address = addr; }

        void setCity(string c)
        { city = c; }

        void setState(string s)
        { state = s; }

        void setZip(long int z)
        { zip = z; }

        void setPhone(long int p)
        { phone = p; }

        // Accessors
        string getLastName() const
        { return lastName; }

        string getFirstName() const
        { return firstName; }

        string getAddress() const
        { return address; }

        string getCity() const
        { return city; }

        string getState() const
        { return state; }

        long int getZip() const
        { return zip; }

        long int getPhone() const
        { return phone; }

};
class CustomerData: public PersonData{

    private:
        long int customerNumber;
        bool mailingList;
    public:
        void setCustomerNumber(long int c)
        {
            customerNumber = c;
        }
        void setMailingList(bool m)
        {
            mailingList = m;
        }
        long int getCustomerNumber() const{
            return customerNumber;
        }
        bool getMailingList() const{
            return mailingList;
        }

};

#endif