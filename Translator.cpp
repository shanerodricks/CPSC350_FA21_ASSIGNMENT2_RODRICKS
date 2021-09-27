#include "Translator.h"
#include "Model.h"

Translator::Translator(){
    //default constructor
}
Translator::~Translator(){
    //default deconstructor
}
string Translator::translateEnglishWord(string input){
    string translatedWord;
    Model m;
    //for loop loops through input to replace words with Tutenese language
    for(int i = 0; i < input.length(); ++i){
        //if statement is for the vowels and leaves them untouched in the word
        if(toupper(input[i]) == 'A' || toupper(input[i]) == 'E' 
        || toupper(input[i]) == 'I'|| toupper(input[i]) == 'O' || toupper(input[i]) == 'U')
            translatedWord = translatedWord + input[i];
        //else statement turns the input into the translated word using the index i
        else    
            translatedWord = translatedWord + m.translateSingleCharacterE2T(input[i]);
    }
    return translatedWord;
}
string Translator::translateTutneseWord(string input){
    string translatedWord;
    string word;
    Model m;
    for(int i = 0; i < input.length(); ++i){
        //'X' is the only character whose translation starts with a vowel
        //special if case to check for that
        if(toupper(input[i]) == 'E' && toupper(input[i+1]) == 'X'){
            word = input.substr(i,2);
            i = i + 1;
            //subtr(): gets characters value in second paramter
            translatedWord = translatedWord + m.translateSingleCharacterT2E(word);
        }
        //else if checks for vowels
        else if(toupper(input[i]) == 'A' || toupper(input[i]) == 'E' 
        || toupper(input[i]) == 'I'|| toupper(input[i]) == 'O' || toupper(input[i]) == 'U'){
            translatedWord = translatedWord + input[i];
        }
        //else if checks for 3 character Tutnese words
        else if(toupper(input[i]) == 'B' || toupper(input[i]) == 'D' || toupper(input[i]) == 'F'
        || toupper(input[i]) == 'G' || toupper(input[i]) == 'J' || toupper(input[i]) == 'L' || 
        toupper(input[i]) == 'M' || toupper(input[i]) == 'N' || toupper(input[i]) == 'P' || 
        toupper(input[i]) == 'R' || toupper(input[i]) == 'S' || toupper(input[i]) == 'T' || 
        toupper(input[i]) == 'V' || toupper(input[i]) == 'Y' || toupper(input[i]) == 'Z'){
            word = input.substr(i,3);
            i = i + 2;
            //subtr(): gets characters value in second paramter
            translatedWord = translatedWord + m.translateSingleCharacterT2E(word);
        }
        //else if checks for 4 character Tutnese words
        else if(toupper(input[i]) == 'C' || toupper(input[i]) == 'H' || toupper(input[i]) == 'K'
        || toupper(input[i]) == 'Q' || toupper(input[i]) == 'W'){
            word = input.substr(i,4);
            i = i + 3;
            //subtr(): gets characters value in second paramter
            translatedWord = translatedWord + m.translateSingleCharacterT2E(word);
        }
    }
    return translatedWord;
        
}
string Translator::translateTutneseSentence(string input){
    //inWord tells if the current place that this function is checking is in the word or not
    bool inWord = false;
    string word = "";
    string convertedSentence = "";
    //this for loop is used to parse through the sentence and check every Tutense word
    for(int i = 0; i < input.length(); ++i){
        //ispunct(): checks whether a character is a punctuation or not
        //isspace(): checks whether a character is whitespace(including tabs, newline) or not
        //if statement checks if a word is not being worked on, if true add character to the empty string
        if(!inWord && (ispunct(input[i]) || isspace(input[i]))){
            convertedSentence += input[i];
        }
        //checks if a word is being worked on and checking for punctuation and whitespace
        //if true the parsing of the word is complete
        else if(inWord && (ispunct(input[i]) || isspace(input[i]))){
            inWord = false;
            convertedSentence += translateTutneseWord(word);
            convertedSentence += input[i];
        }
        //checks if we are not working on a word and a normal character is detected
        //if true it means a word is starting
        else if(!inWord){
            inWord = true;
            word = input[i];
        }
        //we are working on a word and if true add character to the word
        else{
            word += input[i];
        }
    }
    //last statement checks if a word is being worked on it when the for loop is finished
    //if true, word is added to the translated sentence
    if(inWord){
        convertedSentence += translateTutneseWord(word);
    }
    return convertedSentence;
}
string Translator::translateEnglishSentence(string input){
    //inWord tells if the current place that this function is checking is in the word or not
    bool inWord = false;
    string word = "";
    string convertedSentence = "";
    //this for loop is used to parse through the sentence and check every character
    for(int i = 0; i < input.length(); ++i){
        //ispunct(): checks whether a character is a punctuation or not
        //isspace(): checks whether a character is whitespace(including tabs, newline) or not
        //if statement checks if a word is not being worked on, if true add character to the empty string
        if(!inWord && (ispunct(input[i]) || isspace(input[i]))){
            convertedSentence += input[i];
        }
        //checks if a word is being worked on and checking for punctuation and whitespace
        //if true the parsing of the word is complete
        else if(inWord && (ispunct(input[i]) || isspace(input[i]))){
            inWord = false;
            convertedSentence += translateEnglishWord(word);
            convertedSentence += input[i];
        }
        //checks if we are not working on a word and a normal character is detected
        //if true it means a word is starting
        else if(!inWord){
            inWord = true;
            word = input[i];
        }
        //we are working on a word and if true add character to the word
        else{
            word += input[i];
        }
    }
    //last statement checks if a word is being worked on it when the for loop is finished
    //if true, word is added to the translated sentence
    if(inWord){
        convertedSentence += translateEnglishWord(word);
    }
    return convertedSentence;
}