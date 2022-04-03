#include <iostream>
#include <string>
#include <iomanip>   

using namespace std;

char GetValidOption();
void DisplayMenu();
void HandleEncrypt();
void HandleDecryptKnown();
void HandleDecryptUnknown();
string Decrypt(string ciphertext, int shift);
string AllToLower(string str);
bool AllDigits(string str);

const string alphabet = "abcdefghijklmnopqrstuvwxyz";

int main(){
    cout << "Welcome to the Caesar Cipher decoder/encoder" << endl;
    while(true){
        char input = GetValidOption();

        if(input == '0'){
            HandleEncrypt();
        }
        else if(input == '1'){
            HandleDecryptKnown();
        }
        else if(input == '2'){
            HandleDecryptUnknown();
        }
        else if(input == '3'){
            cout << "Goodbye" << endl;
            break;
        }
        else {
            cout << "Error, missed bad input." << endl;
        }
    }

    return 0;
}

void DisplayMenu(){
    cout << "Main Menu" << endl;
    cout << "Options" << endl;
    cout << "(0) Encrypt" << endl;
    cout << "(1) Decrypt (known shift)" << endl;
    cout << "(2) Decrypt (unknown shift)" << endl;
    cout << "(3) Quit" << endl;
}

char GetValidOption(){
    char optionChoice = ' ';
    string options = "0123";
    DisplayMenu();
    cin >> optionChoice;
    while(options.find(optionChoice) == string::npos){
        cout << "Bad input. Try again." << endl;
        DisplayMenu();
        cin >> optionChoice;
    }
    return optionChoice;
}

string AllToLower(string str){
    for(int i=0; i<str.length(); i++){
        str.at(i) = tolower(str.at(i));
    }
    return str;
}

bool AllDigits(string str){
    for(int i=0; i<str.length(); i++){
        if(!isdigit(str.at(i))){
            return false;
        }
    }
    return true;
}

void HandleEncrypt(){
    string plaintext = "";
    string ciphertext = "";
    string shiftInput = "";
    int shift = 0;

    cout << "Enter plaintext: ";
    cin.ignore();
    getline(cin, plaintext);
    cout << "Plaintext: " << plaintext << endl;

    cout << "Enter shift: ";
    cin >> shiftInput;
    if(AllDigits(shiftInput)){
        shift = stoi(shiftInput);
    }
    else{
        cout << "Bad inputs" << endl << endl;
        return;
    }
    cout << "Shift: " << shift << endl;
    plaintext = AllToLower(plaintext);

    for(int i=0; i<plaintext.length(); i++){
        if(isalpha(plaintext.at(i))){
            int shiftedValue = (alphabet.find(plaintext.at(i)) + shift) % alphabet.length();
            ciphertext += alphabet.at(shiftedValue);
        }
        else{
            ciphertext += plaintext.at(i);
        }
    }

    cout << "Your ciphertext is: " << endl;
    cout << ciphertext << endl << endl;

}
void HandleDecryptKnown(){
    string ciphertext = "";
    string shiftInput = "";
    int shift = 0;

    cout << "Enter ciphertext: ";
    cin.ignore();
    getline(cin, ciphertext);
    cout << "Ciphertext: " << ciphertext << endl;

    cout << "Enter shift: ";
    cin >> shiftInput;
    if(AllDigits(shiftInput)){
        shift = stoi(shiftInput);
    }
    else{
        cout << "Bad inputs" << endl << endl;
        return;
    }
    cout << "Shift: " << shift << endl;

    cout << Decrypt(ciphertext, shift) << endl << endl;
}

void HandleDecryptUnknown(){
    string ciphertext = "";

    cout << "Enter ciphertext: ";
    cin.ignore();
    getline(cin, ciphertext);
    cout << "Ciphertext: " << ciphertext << endl;

    cout << "Shift | plaintext " << endl;
    for(int i=0; i<alphabet.length(); i++){
        cout << setw(3) << left << i;
        cout << "| " << Decrypt(ciphertext, i) << endl;
    }
    cout << endl;
}

string Decrypt(string ciphertext, int shift){
    string plaintext = "";
    
    ciphertext = AllToLower(ciphertext);

    for(int i=0; i<ciphertext.length(); i++){
        if(isalpha(ciphertext.at(i))){
            int shiftedValue = (alphabet.find(ciphertext.at(i)) + (alphabet.length() - shift)) % alphabet.length();
            plaintext += alphabet.at(shiftedValue);
        }
        else{
            plaintext += ciphertext.at(i);
        }
    }

    return plaintext;
}