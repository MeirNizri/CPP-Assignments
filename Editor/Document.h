/**
 * Class for document
 * 
 * Author: Meir Nizri
 * First assignment in advanced programming course
 * Date: 2021-03
 */

#pragma once
#include <string>
#include <vector> 

using namespace std;

class Document{
    private:
        vector<string> docLines;
        int currentLine;
    
    public:
        Document();
        void insertFile(const string fileName);
        void updateCurrentLine(const int num);
        void addCurrentLine(const int num);
        void jumpLastLine();
        void addLine();
        void addLineBefore();
        void replaceLine();
        void deleteLine();
        void searchAndUpdateLine(const string text);
        void replace(const string old, const string _new);
        void concat();
        void writeToFile(const string file);
};