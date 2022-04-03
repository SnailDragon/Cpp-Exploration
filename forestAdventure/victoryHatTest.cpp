#include <iostream>
#include <cmath>

using namespace std;

int main(){
    //must be odd
    int victoryHatHeight = 10;
    string layer = "";
    string hatChar = "+";
    string capChar = "O";
    string fillerChar = " ";
    for(int i = 0; i < victoryHatHeight; ++i){
        for(int j = 1; j < (victoryHatHeight*2); ++j){
            
            if( abs(j - (victoryHatHeight)) < i){
                if(i == 1){
                    cout << capChar;
                    break;
                }
                cout << hatChar;
            }
            else {
                cout << fillerChar;
            }

        }
        cout << endl;
    }
    cout << "|";
    for(int i = 0; i < (victoryHatHeight * 2)-3; i++){
        cout << "_";
    }
    cout << "|" << endl;

    return 0;
}