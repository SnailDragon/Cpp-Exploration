#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string ToLowerCase(string str);

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
        wordLists[line.length()] << ToLowerCase(line) << endl;
        cout << line << " ";
    } while (line != "");

    commonwords.close();
    return 0;
}


string ToLowerCase(string str){
    for(int i = 0; i < str.length(); i++){
        str.at(i) = tolower(str.at(i));
    }
    return str;
}
