#include <iostream>
#include <cmath>

using namespace std;

void GetRange(int& lower, int& upper);
void CalcNarcNums(int lower, int upper);

int main(){
    int upperLimit = 0;
    int lowerLimit = 0;

    cout << "Hello" << endl;
    cout << "This program discovered Narcissistic Numbers - numbers who equal the sum of each of their digits raised to the power of the number of digits." << endl;
    cout << "(ex. 153 = 1^3 + 5^3 + 3^3)" << endl;
    GetRange(lowerLimit, upperLimit);
    
    cout << "Searching " << lowerLimit << " to " << upperLimit << "..." << endl;

    CalcNarcNums(lowerLimit, upperLimit);

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
        int num = i;
        int sum = 0;
        string numString = to_string(num);
        while(num > 0){
            sum += pow(num % 10, numString.length());
            num /= 10;
        }

        if(i == sum){
            cout << i << endl;
        }
    }
}
