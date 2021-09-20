/**
 * Author: Meir Nizri
 * First assignment in advanced programming course
 * Date: 2021-03
 */
 
#include "Editor.h"
#include "iostream"
using namespace std;

int main(int argc, char* argv[]) {
    Editor editor;
    switch (argc) {
        case 1:
            break;
        case 2:
            editor.insertFile(argv[1]);
            break;
        default:
            cout << "?" << endl;
    }
    editor.loop();
    return 0;
}