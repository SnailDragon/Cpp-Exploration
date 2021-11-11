#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

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

    bool wordMatrix[26][26][26][26];

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            for(int x = 0; x < size; x++){
                for(int z = 0; z < size; z++){
                    wordMatrix[i][j][x][z] = false;
                }
            }
        }
    }

    for(unsigned int i = 0; i < words.size(); i++){
        wordMatrix[words.at(i).at(0)-'a'][words.at(i).at(1)-'a'][words.at(i).at(2)-'a'][words.at(i).at(3)-'a'] = true;
    }


    //int it = 0;
    for(int i = 0; i < words.size(); ++i){
        for(int j = 0; j < words.size(); ++j){
            for(int z = 0; z < words.size(); ++z){
                for(int x = 0; x < words.size(); ++x){
                    //cout << "Processing box #" << it << endl;
                    //it++;

                    bool isWordBox = true;
                    for(int in = 0; in < size; in++){
                        if(!wordMatrix[words.at(i).at(in)-'a'][words.at(j).at(in)-'a'][words.at(z).at(in)-'a'][words.at(x).at(in)-'a']){
                            isWordBox = false;
                        }
                    }

                    
                    if(isWordBox){
                        vector<string> testBox3;
                        testBox3.push_back(words[i]);
                        testBox3.push_back(words[j]);
                        testBox3.push_back(words[z]);
                        testBox3.push_back(words[x]);
                        // PrintBox(testBox3);
                        SaveBox(testBox3);
                    }
                    else{
                        // PrintBox(testBox3);
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

