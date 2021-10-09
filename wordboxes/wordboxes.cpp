#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool IsWordBox(string top, string middle, string bottom, vector<string> wb);
bool NotWord(string word, vector<string> wb);

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
    } while (line != "");
    int it = 0;
    for(int i = 0; i < sizeof(words); i++){
        for(int j = 0; j < sizeof(words); j++){
            for(int x = 0; x < sizeof(words); x++){
                if(IsWordBox(words[i], words[j], words[x], words)){
                    cout << words[i] << endl;
                    cout << words[j] << endl;
                    cout << words[x] << endl;
                }
                else{
                    cout << it++ << endl;
                }
            }
        }
    }



    return 0;
}


bool IsWordBox(string top, string middle, string bottom, vector<string> wb){

    for(int i = 0; i < 3; i++){
        string str = "";
        str += top.at(i) + middle.at(i) + bottom.at(i);
        if(NotWord(str, wb)){
            return false;
        }
    }

    return true;
}

bool NotWord(string word, vector<string> wb){

    for(int i = 0; i < sizeof(wb); i++){
        if(word == wb[i]){
            return false;
        }
    }

    return true;
}
