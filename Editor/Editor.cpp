/**
 * Class for editor
 * 
 * Author: Meir Nizri
 * First assignment in advanced programming course
 * Date: 2021-03
 */
 
#include "Editor.h"
#include <regex>
#include <iostream>
#include <fstream>
using namespace std;

void Editor::insertFile(const string fileName) {
    doc.insertFile(fileName);
}

void Editor::loop() {
    string command;
    getline(cin, command);
    while(command != "q") {
        executeCommand(command);
        getline(cin, command);
    }
}

void Editor::executeCommand(const string input) {
    regex r1 (R"(\d+)");
    regex r2 (R"([+-]\d+)");
    regex r3 (R"(a|i|c|d|j|\$)");
    regex r4 (R"(/([^/]+)/)");
    regex r5 (R"(s/([^/]+)/([^/]*)/)");
    regex r6 (R"((w|e) (.+))");
    smatch sm;
    
    if (regex_match (input, r1)) 
        doc.updateCurrentLine(stoi(input));
    
    else if (regex_match (input, r2))
        doc.addCurrentLine(stoi(input));
        
    else if (regex_match (input, r3)) {
        if (input == "$") doc.jumpLastLine();
	    else if (input == "a") doc.addLine();
	    else if (input == "i") doc.addLineBefore();
	    else if (input == "c") doc.replaceLine();
	    else if (input == "d") doc.deleteLine(); 
	    else if (input == "j") doc.concat(); 
    }
    
    else if (regex_match (input, sm, r4))
        doc.searchAndUpdateLine(sm[1]);
        
    else if (regex_match (input, sm, r5))
        doc.replace(sm[1], sm[2]);
        
    else if (regex_match (input, sm, r6)) {
        if(sm[1] == "w")
            doc.writeToFile(sm[2]);
        else
            doc.insertFile(sm[2]);
    }
        
    else
        cout << "?_" << endl;
}

// void Editor::executeFile(const string fileName) {
//     ifstream file(fileName);
//     string newCommand;
//     while (getline(file, newCommand))
//         executeCommand(newCommand);
// }