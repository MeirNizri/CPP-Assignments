/**Program that searches words within text according to how the words sound. 
 * Ignores the searcher's spelling errors. There are defined letters that can be exchanged, 
 * as can be seen in the checkLetter function.
 * 
 * Author: Meir Nizri
 * Second assignment in cpp course
 * Date: 2020-03-30
 */
#include "PhoneticFinder.hpp"
#include <iostream>
#include <sstream> 
#include <string>
#include <algorithm> 
#include <exception>

using namespace std;
namespace phonetic {
	
	 /** Returns same number for similar letters */
	int checkLetter(char c) {
		switch(c) {
			case 'v': case 'V': case 'w': case 'W':
				return 1; break;
			case 'b': case 'B': case 'f': case 'F': case 'p': case 'P':
				return 2; break;
			case 'g': case 'G': case 'j': case 'J':
				return 3; break;
			case 'c': case 'C': case 'k': case 'K': case 'q': case 'Q':
				return 4; break;
			case 's': case 'S': case 'z': case 'Z':
				return 5; break;
			case 'd': case 'D': case 't': case 'T':
				return 6; break;
			case 'o': case 'O': case 'u': case 'U':
				return 7; break;
			case 'i': case 'I': case 'y': case 'Y':
				return 8; break;
			case 'a': case 'A':
				return 9; break;
			case 'e': case 'E':
				return 10; break;
			case 'h': case 'H':
				return 11; break;
			case 'l': case 'L':
				return 12; break;
			case 'm': case 'M':
				return 13; break;
			case 'n': case 'N':
				return 14; break;
			case 'r': case 'R':
				return 15; break;
			default:
				return 16; // 'x' or 'X'
		}
	}
	
	/**Receives text and word to search within it. Returns the word that appears 
	 * within the text that similar to the word searching for.
	 */
	string find(string text, string word) {
		// Initialise the istringstream and remove spaces from the word
		istringstream iss(text);
		word.erase(remove(word.begin(), word.end(), ' '), word.end());
		// Variables representing a word within the text and matching between the words
		string subWord = "";
		bool identical = false;

		// Iterate the istringstream using do-while loop 
		do { 
			// Get the word from the istringstream 
			iss >> subWord;
			// Check if the words are not empty and in the same length
			if(!word.empty() && word.length()==subWord.length()) {
				identical = true;
				// Iterate all letters in both words and check if equal
				for (string::size_type i = 0; i < word.size(); i++) {
					if(checkLetter(word[i])!=checkLetter(subWord[i]))
						identical = false;
				}
				// If no different letter is found return the word. Otherwise go to the next word in the text.
				if(identical) return subWord;
			}
		} while (iss);
		// No identical word is found in the text
		throw std::invalid_argument("Can't find identical word");
	}
}