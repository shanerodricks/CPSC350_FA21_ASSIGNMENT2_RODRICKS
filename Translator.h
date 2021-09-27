#include <string>
using namespace std;

class Translator{
    public:
    //declaring default contructor and deconstructor
    Translator();
    ~Translator();
    //defintion of both functions used in Model class
    string translateEnglishWord(string input);
    string translateEnglishSentence(string input);
    string translateTutneseWord(string input);
    string translateTutneseSentence(string input);
};