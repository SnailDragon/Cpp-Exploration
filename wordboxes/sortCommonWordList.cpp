#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream commonwords;
    ofstream wordLists[9];
    for(int i = 1; i <= 9; i++){
        string filename = "words" + to_string(i) + ".txt";
        wordLists[i].open(filename);
    }
    commonwords.open("commonwords.txt", fstream::in);
    string line = "";

    do {
        getline(commonwords, line);
        if(line.length() >= 9){
            continue;
        }
        wordLists[line.length()] << line << endl;
        cout << line << " ";
    } while (line != "");

    commonwords.close();
    return 0;
}