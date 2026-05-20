/*File Filter
A file filter reads an input file, transforms it in some way, and writes the results to 
an output file. Write an abstract file filter class that defines a pure virtual function for 
transforming a character. Create one derived class of your file filter class that performs 
encryption, another that transforms a file to all uppercase, and another that creates an 
unchanged copy of the original file. The class should have the following member function:
void doFilter(ifstream &in, ofstream &out) 
This function should be called to perform the actual filtering. The member function for 
transforming a single character should have the prototype:
char transform(char ch)
The encryption class should have a constructor that takes an integer as an argument and uses it 
as the encryption key.*/

#include <fstream>
#include <cctype>
using namespace std;

class FileFilter{
    public:
        void doFilter(std::ifstream &in, std::ofstream &out){
            char ch;
            while(in.get(ch))
            {
            out.put(transform(ch));
            }
        };
        virtual char transform( char ch)=0;
};


class EncryptDerived : public FileFilter{
    private:
        int key;
    public:
        EncryptDerived():key(0){}
        EncryptDerived(int k):key(k){}
    char transform(char ch) override{
        return ch+key;
    }
};

class UpperDerived:public FileFilter{
    char transform(char ch) override{
        return toupper(ch);
    }
};

class UnchangedDerived:public FileFilter{
    char transform(char ch) override{
        return ch;
    }


};

int main()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    UpperDerived u;
    u.doFilter(infile,outfile);
    return 0;
}