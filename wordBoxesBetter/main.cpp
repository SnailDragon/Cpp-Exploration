#include <iostream>

#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <iomanip>


#include "BoxGen.h"

using namespace std;

int hasher(string const& str);

int main(int argc, char* argv[]){

    auto start = std::chrono::high_resolution_clock::now();
    BoxGen box("words.txt");
    auto stop = std::chrono::high_resolution_clock::now();
    auto tsetup = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    int num = 3;
    if(argc == 2){
        stringstream ss;
        ss << argv[1];
        ss >> num;
    }

    

    //cout << box.section_to_string(3) << endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    vector<vector<string>> boxes = box.genWordBoxes(num);
    auto stop2 = std::chrono::high_resolution_clock::now();
    auto trun = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);
    
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

    cout << fixed << setprecision(2) << "Setup Time: " << tsetup.count()/1000.0 << " us" << endl;
    if(trun.count() < 1000 * 10000){
        cout << fixed << setprecision(2) <<  "Execution Time: " << trun.count()/1000.0 << " us" << endl;
    }
    else {
        cout << fixed << setprecision(2) << "Execution Time: " << trun.count()/1000000/60/60 << " hrs" << endl;
    }
    return 0;
}

int hasher(string const& str){
    return 1;
}