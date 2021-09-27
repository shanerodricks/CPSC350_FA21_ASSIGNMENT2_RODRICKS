#include <string>
using namespace std;

class Model {
    public:
        //declaring contructor and deconstructor
        Model();
        ~Model();
        //defintion of both functions used in Model class
        string translateSingleCharacterE2T(char input);
        string translateDoubleCharacterE2T(char doubleInput);
        string translateSingleCharacterT2E(string input);
};