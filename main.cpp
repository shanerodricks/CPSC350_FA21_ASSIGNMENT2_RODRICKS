#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    FileProcessor fp;
    //argv[1]: input text
    //argv[2]: output text
    //argv[3]: T2E or E2T
    fp.processFile(argv[1], argv[2], argv[3]);
   
}