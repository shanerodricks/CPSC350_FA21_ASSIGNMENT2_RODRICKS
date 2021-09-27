#include "FileProcessor.h"
#include "Translator.h"
#include <fstream> //file input/output
using namespace std;

FileProcessor::FileProcessor(){
    //deafult constructor
}
FileProcessor::~FileProcessor(){
    //default deconstructor
}
void FileProcessor::processFile(string input, string output, string mode){
    //creation of file object(input)
    ifstream inputFile(input);
    //if statement checks if the file can open
    //if file cannot be opened, an error message is printed to the screen(input)
    if(!inputFile.is_open()){
        cout << "Could not open the file." << input << endl;
        exit(1);
    }
    //creation of file object(output)
    ofstream outputFile(output);
    //if statement checks if the file can open
    //if file cannot be opened, an error message is printed to the screen(output)
    if(!outputFile.is_open()){
        cout << "Could not open the file." << output << endl;
        exit(1);
    }
    //creating an instance of Translator class, new string variable
    Translator translate;
    string line;
    //getline(): built in function that gets the next line and returns true if succeeded
    //while loop checks each line in the file, and the result is translateEnglishSentence() for each line in the file
    while (getline(inputFile, line)) {
        string result; 
        if(mode == "E2T"){
            result = translate.translateEnglishSentence(line);
        }
        else{
            result = translate.translateTutneseSentence(line);
        }
        //result is written to the outputFile
        outputFile << result << endl;
    }
    //closing the input/output file
    inputFile.close();
    outputFile.close();
}