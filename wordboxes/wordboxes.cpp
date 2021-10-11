#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool IsWordBox(vector<string> box, vector<string> wb);
bool IsWord(string word, vector<string> wb);

int main(){

    int size = 3;
    ifstream wordBank;
    string filename = "words" + to_string(size) + ".txt";
    wordBank.open(filename, fstream::in);

    vector<string> words;
    
    string line = "";
    do {
        getline(wordBank, line);
        words.push_back(line);        
    } while (line != "asp");
    
    vector<string> testBox3;
    testBox3.push_back("ave");
    testBox3.push_back("sin");
    testBox3.push_back("pad");

    cout << words.size() << endl;
    cout << words[25] << endl;
    cout << IsWordBox(testBox3, words) << endl;
    



    return 0;
}

bool IsWordBox(vector<string> box, vector<string> wb){
    string wordToTest = "";
    for(int i = 0; i < box[0].length(); i++){
        wordToTest = "";
        for(int j = 0; j < box[0].length(); j++){
            wordToTest += box[j].at(i);
        }
        if(! IsWord(wordToTest, wb)){
            return false;
        }
        
    }
    return true;
}

bool IsWord(string word, vector<string> wb){
    for(int i = 0; i < wb.size(); i++){
        if(word == wb[i]){
            return true;
        }
    }
    return false;
}