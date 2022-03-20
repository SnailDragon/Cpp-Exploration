#include <iostream>

#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
#include <fstream>

#include "BoxGen.h"

using namespace std;

int hasher(string const& str);

int main(int argc, char* argv[]){

    BoxGen box("words.txt");

    stringstream ss;
    int num;
    ss << argv[1];
    ss >> num;

    

    //cout << box.section_to_string(3) << endl;

    vector<vector<string>> boxes = box.genWordBoxes(num);
    
    if(argc == 3){
        ofstream file;
        file.open(argv[2]);
        if(!file){
            cout << "Bad path" << endl;
        }
        else {
            for(auto b : boxes){
                file << box.box_to_string(b) << endl;
            }
        }
    }

    for(auto b : boxes){
        cout << box.box_to_string(b) << endl;
    }

    return 0;
}

int hasher(string const& str){
    return 1;
}