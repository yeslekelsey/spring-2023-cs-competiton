#include <iostream>
#include <string.h>
#include <set>
#include <algorithm>
#include <regex>

using namespace std;

void diff_letters(string str) {
    set<char> distinctLetters;
	for (int i = 0; i < str.length(); i++) {
		if(str[i] == ' ' || (str[i] <= 64 && str[i] >= 0)) {
		    
		} else {
		   distinctLetters.insert(str[i]); 
		}
	}
	cout << "1. number of distinct letters: " << distinctLetters.size() << endl;
}

void total_vowels(string str) {
    int vowel = 0;
    regex vowels("[aeiouAEIOU]"); //regex for all vowels
    for(char x : str) {
        string character(1, x); // convert character into string for regex match
        if(regex_match(character, vowels)) {
            vowel++;
        }
    }
    cout << "2. number of vowels: " << vowel << endl;
}

void total_uppercase(string str){
    int upper = 0;
    regex uppercase("[A-Z]");
    for(char x : str) {
        string character(1, x);
        if(regex_match(character, uppercase)) {
            upper++;
        }
    }
    cout << "3. number of uppercase: " << upper << endl;
}

void most_frequent(string str) {
    char frequentest; //is that even a word?
    int count[26] = {0};
    for(int i = 0; i < str.length(); i++) {
        if(isalpha(str[i])) {
            str[i] = tolower(str[i]);
            count[str[i] - 'a']++;
        }
    }
    int highest_count = 0;
    for(int i = 0; i < 26; i++) {
        if(count[i] > highest_count) {
            highest_count = count[i];
        }
    }
    for(int i = 0; i < 26; i++) {
        if(count[i] == highest_count) {
            frequentest = 'a' + i;
            break;
        }
    }
    cout << "4. most frequent letter: " << frequentest << endl;
}

void longest_word(string str) {
    string temp;
    string longest;
    for(int i = 0; i <= str.length(); i++) {
        if(i == str.length() || str[i] == ' ' || (str[i] <= 64 && str[i] >= 0)) {
            if(temp.length() > longest.length()) {
                longest = temp;
            }
            temp = '\0';
        } else {
            temp = temp + str[i];
        }
    }
    cout << "5. longest word: " << longest << endl;
}

int main()
{
    cout << "this is a program that uses strings to count the number of distinct letters,\nvowels, uppercase letters, the most frequent letter, and the longest word." << endl;
    cout << "type 'BREAK' to end the program." << endl << endl;
    string sentence;
    while(sentence != "BREAK") {
        cout << "enter your sentence here:" << endl;
        cout << "-~-~-~-~-~-~-~-~-~-~-~-~-~" << endl;
        getline(cin, sentence);
        
        // functions:
        diff_letters(sentence);
        total_vowels(sentence);
        total_uppercase(sentence);
        most_frequent(sentence);
        longest_word(sentence);
        cout << endl;
    }
    cout << "thank you for using my program, have a nice day!";
}
