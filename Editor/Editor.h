/**
 * Class for editor
 * 
 * Author: Meir Nizri
 * First assignment in advanced programming course
 * Date: 2021-03
 */
 
#include "Document.h"
using namespace std;

class Editor {
    private:
        Document doc;

    public:
        Editor() {};
        void insertFile(const string file);
        void loop();
        void executeCommand(const string input);
};