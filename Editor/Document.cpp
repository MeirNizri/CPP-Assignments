/**
 * Class for document
 * 
 * Author: Meir Nizri
 * First assignment in advanced programming course
 * Date: 2021-03
 */
 
#include "Document.h"
#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;

Document::Document() {
    currentLine = 1;
}

void Document::insertFile(const string fileName) {
    docLines.clear();
    ifstream file(fileName);
    string newLine;
    int i = 0;
    while (getline(file, newLine)) {
        docLines.insert(docLines.begin() + i, newLine);
        i++;
    }
    currentLine = 1;
}

void Document::updateCurrentLine(const int num) {
    if(num > 0 && num <=docLines.size()) {
        currentLine = num;
        cout << docLines[currentLine-1] << endl;
    }
    else
        cout << "?" << endl;
}

void Document::addCurrentLine(const int num) {
    if((currentLine+num) <= docLines.size() && (currentLine+num) > 0) {
        currentLine += num;
        cout << docLines[currentLine-1] << endl;
    }
    else 
        cout << "?" << endl;
}

void Document::jumpLastLine() {
    currentLine = docLines.size();
    cout << docLines.back() << endl;
}

void Document::addLine() {
    string newLine;
    getline(cin, newLine);
    while(newLine != ".") {
        if(currentLine <= docLines.size())
            docLines.insert(docLines.begin() + currentLine, newLine);
        else
            docLines.insert(docLines.begin() + currentLine -1, newLine);
        currentLine++;
        getline(cin, newLine);
    }
}

void Document::addLineBefore() {
    string newLine;
    int numLinesToAdd = 0;
    getline(cin, newLine);
    while(newLine != ".") {
        if(numLinesToAdd == 0)
            docLines.insert(docLines.begin() + currentLine -1, newLine);
        else {
            docLines.insert(docLines.begin() + currentLine, newLine);
            currentLine++;
        }

        getline(cin, newLine);
        numLinesToAdd++;
    }
}

void Document::replaceLine() {
    string newLine;
    int numLinesToAdd = 0;
    getline(cin, newLine);
    
    while(newLine != ".") {
        if(numLinesToAdd == 0)
            docLines[currentLine-1] = newLine;
        else {
            docLines.insert(docLines.begin() + currentLine, newLine);
            currentLine++;
        }
        
        getline(cin, newLine);
        numLinesToAdd++;
    }
}

void Document::deleteLine() {
    if(!docLines.empty()) {
        docLines.erase(docLines.begin() + currentLine - 1);
        if(currentLine > 1) 
            currentLine--;
    }
    else
        cout << "?" << endl;
}

void Document::searchAndUpdateLine(const string text) {
    for(int i=currentLine-1; i<docLines.size(); i++) {
        if(docLines[i].find(text) != string::npos) {
            currentLine = i + 1;
            cout << docLines[i] << endl;
            return;
        }
    }
    for(int i=0; i<currentLine-1; i++) {
        if(docLines[i].find(text) != string::npos) {
            currentLine = i + 1;
            cout << docLines[i] << endl;
            return;
        }
    }
    cout << "?" << endl;
}

void Document::replace(const string old, const string _new) {
    size_t found = docLines[currentLine-1].find(old); 
    if(found != string::npos) 
        docLines[currentLine-1].replace(found, old.length(), _new);
    else
        cout << "?" << endl;
}

void Document::concat() {
    if(currentLine != docLines.size()) {
        docLines[currentLine-1] += docLines[currentLine];
        docLines.erase(docLines.begin() + currentLine);
    }
    else
        cout << "?" << endl;
}

void Document::writeToFile(const string fileName) {
    ofstream file(fileName);
    ostream_iterator<string> outItr(file,"\n");
    for(string line : docLines) {
        (*outItr) = line;
        outItr++;
    }
    file.close();
}