#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void SortAlpha(vector<string> wb);

int main(){
    int size = 4;
    ifstream wordBank;
    string filename = "words" + to_string(size) + ".txt";
    wordBank.open(filename, fstream::in);

    vector<string> words;
    
    string line = "";
    do {
        getline(wordBank, line);
        words.push_back(line);       
    } while (line != "");
    words.pop_back();

    SortAlpha(words);

    return 0;
}

void SortAlpha(vector<string> wb){
    ofstream wordbanksAlpha[26];
    for(int i = 0; i < 26; i++){
        string filename = "alphaWordbanks/wb" + to_string(i) + ".txt";
        wordbanksAlpha[i].open(filename);
    }
    for(int i = 0; i < wb.size(); i++){
        wordbanksAlpha[(tolower(wb[i].at(0)) - 'a')] << wb[i] << endl;
    }
}
