#ifndef BOX_H
#define BOX_H

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>


using namespace std;

class BoxGen {

    public:
        BoxGen(string wordbankpath){
            for(int i = 0; i < 10; i++){
                table[i] = vector<vector<string>>(100);
            }

            ifstream file;
            file.open(wordbankpath);
            string word = "";
            while(!file.eof()){
                file >> word;
                if(word.length() <= 1 || badInput(word) || word.length() >= 10) continue;
                masterlist[word.length()].push_back(word);
                table[word.length()].at(hasher(word)).push_back(word);
            }
        }
        ~BoxGen(){

        }

        bool badInput(string str){
            for(char s : str){
                if(!isalpha(s)){
                    return true;
                }
            }
            return false;
        }

        int hasher(string str) const {
            int num = 0;
            for(unsigned int i = 0; i < str.length(); i++){
                num += str[i] - 'a';
            }
            return num % 100;
        }

        string section_to_string(int len) const {
            stringstream ss;
            for(unsigned int i = 0; i < table[len].size(); i++){
                ss << i << ": ";
                for(unsigned int j = 0; j < table[len].at(i).size(); j++){
                    ss << table[len].at(i).at(j) << ", ";
                }
                ss << endl;
            }
            return ss.str();
        }

        vector<vector<string>> genWordBoxes(int len){
            if(len < 2) len = 3;
            vector<unsigned int> indexes;
            for(int i = 0; i < len; i++){
                indexes.push_back(0);
            }
            cout << masterlist[len].size() << endl;
            vector<vector<string>> genedwb;
            while(indexes.at(0) < masterlist[len].size()){
                vector<string> wb;
                //populate wb
                for(unsigned int i = 0; i < indexes.size(); i++){
                    wb.push_back(masterlist[len].at(indexes.at(i)));
                }
                //test wb
                if(isWordBox(wb)) genedwb.push_back(wb);
                //incrememt indexex
                indexes.at(indexes.size()-1)++;
                for(unsigned int i = indexes.size()-1; i > 0; i--){
                    if(indexes.at(i) > masterlist[len].size()-1){
                        indexes.at(i-1)++;
                        if(i == 1){
                            cout << indexes.at(0) << " ";
                        }
                        indexes.at(i) = 0;
                    }
                    
                }
            }
            cout << endl;
            return genedwb;
        }

        bool isWordBox(vector<string> box) const {
            for(unsigned int i = 0; i < box.size(); i++){
                string word = "";
                for(unsigned int j = 0; j < box.size(); j++){
                    word += box.at(j)[i];
                }
                if(!isWord(word)) return false;
            }
            return true;
        }

        bool isWord(string str) const{
            for(string s : table[str.length()].at(hasher(str))){
                if(s == str) return true;
            }
            return false;
        }

        string to_string() const {
            stringstream ss;
            for(int i = 2; i < 10; i++){
                ss << section_to_string(i) << endl;
            }
            return ss.str();
        }

        string box_to_string(vector<string> b) const {
            stringstream ss;
            for(unsigned int i = 0; i < b.size(); i++){
                for(unsigned int j = 0; j < b.size(); j++){
                    ss << b.at(i).at(j);
                }
                ss << endl;
            }
            return ss.str();
        }

        vector<vector<string>> table[10];
        vector<string> masterlist[10];
        
};

// for(unsigned int i = 0; i < words.size(); i++){
//                 vector<char> chars;
//                 for(unsigned int j = 0; j < words.at(i).length(); j++){
//                     chars.push_back(words.at(i)[j]);
//                 }
//                 wordbox.push_back(chars);
//             }

#endif