#include "Model.h"
#include <iostream>
using namespace std;

Model::Model(){
    //default constructor
}
Model::~Model(){
    //default deconstructor
}
string Model::translateSingleCharacterE2T(char input)
{
    //isLower indicates if the word is in lower case or upper case(bool)
    bool isLower = false;
    //if statment states that if input is lower case(between a and z), input is changed toupper, and is able to be translated
    if(input >= 'a' && input <= 'z'){
        input = toupper(input);
        isLower = true;
    }
    //since no arrays can be used, multiple if statements define the rules of the Tutenese language
    string result;
    if(input == 'B')
        result = "Bub";
    else if(input == 'C')
        result = "Cash";
    else if(input == 'D')
        result = "Dud";
    else if(input == 'F')
        result = "Fuf";
    else if(input == 'G')
        result = "Gug";
    else if(input == 'H')
        result = "Hash";
    else if(input == 'J')
        result = "Jay";
    else if(input == 'K')
        result = "Kuck";
    else if(input == 'L')
        result = "Lul";
    else if(input == 'M')
        result = "Mum";
    else if(input == 'N')
        result = "Nun";
    else if(input == 'P')
        result = "Pub";
    else if(input == 'Q')
        result = "Quack";
    else if(input == 'R')
        result = "Rug";
    else if(input == 'S')
        result = "Sus";
    else if(input == 'T')
        result = "Tut";
    else if(input == 'V')
        result = "Vuv";
    else if(input == 'W')
        result = "Wack";
    else if(input == 'X')
        result = "Ex";
    else if(input == 'Y')
        result = "Yub";
    else if(input == 'Z')
        result = "Zub";
    if(isLower){
        result[0] = tolower(result[0]);
    }
    return result;
}
string Model::translateDoubleCharacterE2T(char doubleInput)
{
    //translateDoubleCharacter uses the previous function to print the reuslt twice 
    return translateSingleCharacterE2T(doubleInput) + translateSingleCharacterE2T(doubleInput);
}
string Model::translateSingleCharacterT2E(string input){
    bool isLower = false;
    //if statment states that if input is lower case(between a and z), input is changed toupper, and is able to be translated
    if(input[0] >= 'a' && input[0] <= 'z'){
        isLower = true;
    }
    for(int i = 0; i < input.length(); ++i){
            input[i] = toupper(input[i]);
        }
    

    //since no arrays can be used, multiple if statements define the rules of the Tutenese language
    string result;
    if(input == "BUB")
        result = "B";
    else if(input == "CASH")
        result = "C";
    else if(input == "DUD")
        result = "D";
    else if(input == "FUF")
        result = "F";
    else if(input == "GUG")
        result = "G";
    else if(input == "HASH")
        result = "H";
    else if(input == "JAY")
        result = "J";
    else if(input == "KUCK")
        result = "K";
    else if(input == "LUL")
        result = "L";
    else if(input == "MUM")
        result = "M";
    else if(input == "NUN")
        result = "N";
    else if(input == "PUB")
        result = "P";
    else if(input == "QUACK")
        result = "Q";
    else if(input == "RUG")
        result = "R";
    else if(input == "SUS")
        result = "S";
    else if(input == "TUT")
        result = "T";
    else if(input == "VUV")
        result = "V";
    else if(input == "WACK")
        result = "W";
    else if(input == "EX")
        result = "X";
    else if(input == "YUB")
        result = "Y";
    else if(input == "ZUB")
        result = "Z";
    else{
        result = "*";
    }
    if(isLower){
        result[0] = tolower(result[0]);
    }
    return result;
}