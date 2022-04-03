#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool IsWordBox(vector<string> box, vector<string> wb);
bool IsWord(string word, vector<string> wb);
void PrintBox(vector<string> box);
void SaveBox(vector<string> box);

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
    
    int jStart = 26;
    int zStart = 504;
    bool unStarted = true;

    int it = 0;
    for(int i = 0; i < words.size(); ++i){
        for(int j = 0; j < words.size(); ++j){
            if(unStarted) j = jStart;
            for(int z = 0; z < words.size(); ++z){
                if(unStarted) z = zStart;
                unStarted = false;
                for(int x = 0; x < words.size(); ++x){
                    cout << "Processing box #" << it << endl;
                    it++;
                    vector<string> testBox3;
                    testBox3.push_back(words[i]);
                    testBox3.push_back(words[j]);
                    testBox3.push_back(words[z]);
                    testBox3.push_back(words[x]);
                    if(IsWordBox(testBox3, words)){
                        PrintBox(testBox3);
                        SaveBox(testBox3);
                    }
                    else{
                        PrintBox(testBox3);
                        cout << i << "." << j << "." << z << "." << x << endl; 
                    }
                }
            }
        }
        cout << "Done i = " << i << endl;
    }
    



    return 0;
}

void SaveBox(vector<string> box){
    ofstream boxes;
    boxes.open("fourboxes.txt");
    for(int i = 0; i < box.size(); ++i){
        boxes << box[i] << endl;
    }
    boxes << endl << endl;
}

void PrintBox(vector<string> box){
    for(int i = 0; i < box.size(); ++i){
        cout << box[i] << endl;
    }
    cout << endl;
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