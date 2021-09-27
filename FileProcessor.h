#include <iostream>
#include <string>
using namespace std;

class FileProcessor{
    public:
        //default contructor and deconstructor
        FileProcessor();
        ~FileProcessor();
        //declaration of method used in FileProcessor
        void processFile(string input, string output, string mode);
};
