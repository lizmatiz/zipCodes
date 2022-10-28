/*
Name: Elizabeth Hooton
Program: Project III (Barcodes)
Date: Oct 26 2022
Email: eh151720@ohio.edu
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string getDigitCode (char digit); // return a barcode for a single digit
void getDigitSum(string code, int &sum); // calculate sum of the digits
int calcCheckDigit(int sum); // return the check digit


int main(){

ifstream inFile; // input file variable
ofstream outFile; // output file variable
string code; // reads in each zip code from the input file
int count = 0; // counts the number of "int" chars in code
int sum = 0; // sum of all the digits in the zip
int check_digit; // the check digit of the code
char a; // first digit of code
char b; // second digit of code
char c; // third digit of code
char d; // fourth digit of code
char e; // fifth digit of code

// opens the input and output files
inFile.open("codes_in.txt");
outFile.open("codes_out.txt");
    if(!inFile.fail()){
        // while the end of the file is not reached, read in each zip code as code
        while(!inFile.eof()){
            count = 0;
            inFile >> code;
            // if the length of the zip code is correct, then you can continue
            if (code.length() == 5) {
                // for each digit or char in the code, change it to a char
                for(int i = 0; i < code.length(); i++){
                    char c = code[i];
                    // if the char is a digit, up the count by 1
                    if (isdigit(c)){
                        count ++;

                    }
                    // if any char in code is not a digit, you get an error message
                    else{
                        cout << "Illegal characters in zip code: " << code << endl;
                        outFile << "Illegal characters in zip code: " << code << endl;
                        break;
                    }
                }  
            } 
            // if the length of the zip code is incorrect, then you get an error message
            else{
                cout << "Zip code " << code << " is not 5 digits" << endl;
                outFile << "Zip code " << code << " is not 5 digits" << endl;
            }

            // if code can be an int, get the sum of all the digits, get the check digit, and change the check digit to it's ascii equivalent in char
            if (count == 5){
                getDigitSum(code, sum);
                check_digit = calcCheckDigit(sum);
                check_digit += 48;
                char z = static_cast<char>(check_digit);

                // sets each char of code to its own char   
                a = code[0];
                b = code[1];
                c = code[2];
                d = code[3];
                e = code[4];
        
                // prints and writes the zip code and the special bar code for each zip code in the file by accessing a function
                cout << a << b << c << d << e << endl;
                cout << "|" << getDigitCode(a) << getDigitCode(b) << getDigitCode(c) << getDigitCode(d) << getDigitCode(e) << getDigitCode(z) << "|" << endl;
                outFile << "|" << getDigitCode(a) << getDigitCode(b) << getDigitCode(c) << getDigitCode(d) << getDigitCode(e) << getDigitCode(z) << "|" << endl;
            
            }
            }
    }
        // closes both of the files
        inFile.close();
        outFile.close();
        return 0;

    }


// gets the sum of each of the digits in code
void getDigitSum(string code, int &sum){

    // declares string and int variables for the digits
    string a;
    string b;
    string c;
    string d;
    string e;
    int first_dig;
    int second_dig;
    int third_dig;
    int fourth_dig;
    int fifth_dig;
    
    // assigns each digit to its own string variable
    a = code[0];
    b = code[1];
    c = code [2];
    d = code [3];
    e = code [4];

    // converts each string to an int
    first_dig = stoi(a);
    second_dig = stoi(b);
    third_dig = stoi(c);
    fourth_dig = stoi(d);
    fifth_dig = stoi(e);   

    // adds all the digits together
    sum = first_dig + second_dig + third_dig + fourth_dig + fifth_dig;

}

//calculates the check digit
int calcCheckDigit(int sum){

    // evaluates the remainder when divided by 10
    int i = sum % 10;

    // based on the remainder, returns the number needed to get to a divisible by 10 number
    switch (i){

    case 1:
    return 9;

    case 2:
    return 8;

    case 3:
    return 7;

    case 4:
    return 6;

    case 5:
    return 5;

    case 6:
    return 4;

    case 7:
    return 3;

    case 8:
    return 2;

    case 9:
    return 1;

    default:
    return 0;
    }
}

// returns the special code for each digit in code
string getDigitCode (char digit){

    // depending on what the digit is, it returns a unique code
    switch (digit){
        case '0':
            return "||:::";
        case '1':
            return ":::||";
        case '2':
            return "::|:|";
        case '3':
            return "::||:";
        case '4':
            return ":|::|";
        case '5':
            return ":|:|:";
        case '6':
            return ":||::";
        case '7':
            return "|:::|";
        case '8':
            return "|::|:";
        case '9':
            return "|:|::";
        default:
            return "*";

    }

}