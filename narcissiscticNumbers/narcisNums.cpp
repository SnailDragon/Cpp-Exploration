#include <iostream>
#include <cmath>

using namespace std;

void GetRange(int& lower, int& upper);
void CalcNarcNums(int lower, int upper);
void GetDigitArray(int num);

int main(){
    int upperLimit = 0;
    int lowerLimit = 0;

    cout << "Hello" << endl;
    cout << "This program discovered Narcissistic Numbers - numbers who equal the sum of each of their digits raised to the power of the number of digits." << endl;
    cout << "(ex. 153 = 1^3 + 5^3 + 3^3)" << endl;
    GetRange(lowerLimit, upperLimit);
    
    cout << "Searching " << lowerLimit << " to " << upperLimit << "..." << endl;

    CalcNarcNums();

    return 0;
}

void GetRange(int& lower, int& upper){
    while(upper <= lower){
        cout << "Enter range (lowerLimit upperLimit): " << endl;
        cin >> lower >> upper;
        if(upper <= lower){
            cout << "Bad inputs - upper limit must be greater than lower limit." << endl;
        }
    }
    
}

void CalcNarcNums(int lower, int upper){
    for(int i=lower; i<upper; i++){
        int digits[] = GetDigitArray(i);
        int sum = 0;
        for(int j=0; j<digits.size(); j++){
            sum += pow(digits[j], digits.size());
        }
        if(i == sum){
            cout << i << endl;
        }
    }
}

int[] GetDigitArray(int num){
    int[] digits = new int[static_cast<string>(num).length()];
    for(int i=digits.size(); i>=0; i--){
        digits[i] = num % 10;
        num /= 10;
    }
}