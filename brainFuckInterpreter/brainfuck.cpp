#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

using namespace std;

int main(int argc, char* argv[]){

    uint8_t mem[30000];
    for(int i = 0; i < 30000; i++){
        mem[i] = 0;
    }

    uint8_t *pointer = mem;

    string path = "";
    if(argc == 2){
        path = argv[1];
    }
    else {
        cout << "Bad path" << endl;
        return 0;
    }

    ifstream fileIn;
    fileIn.open(path);
    char ch;
    string goodChars = "><+-.,[]";
    string commands = "";
    while(fileIn >> noskipws >> ch){
        if (goodChars.find(ch) != string::npos){
            commands += ch;
        }
    }
    
    for(int i = 0; i < commands.length(); i++){
        char c = commands[i];
        if(c == '>') pointer++;
        else if(c == '<') pointer--;
        else if(c == '+') ++*pointer;
        else if(c == '-') --*pointer;
        else if(c == '.') cout << *pointer;
        else if(c == ',') cin >> *pointer;
        else if(c == '['){
            if(*pointer == 0){
                while(commands[i] != ']' && i < commands.length()){
                    i++;
                }
                i++;
            }
        }
        else if(c == ']'){
            if(*pointer != 0){
                while(commands[i] != '[' && i >= 0){
                    i--;
                }
                i++;
            }
        }
    }




    return 0;
}