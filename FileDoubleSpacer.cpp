/* File Double-Spacer
Create a derived class of the abstract filter class of Programming Challenge 9 (File Filter) 
that double-spaces a file, that is, it inserts a blank line between any two lines of the file.
*/

#include <fstream>
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
class FileDoubleSpacer: public FileFilter{
    public:
    void doFilter(std::ifstream &in, std::ofstream &out){
            char ch;
            while(in.get(ch))
            {
            out.put(transform(ch));
            if(ch=='\n')
            {
                out.put('\n');
                out.put('\n');
            }
        }
        };
    char transform(char ch) override{
        return ch;
    }
};
int main(){
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    FileDoubleSpacer f;
    f.doFilter(input,output);
    return 0;
}