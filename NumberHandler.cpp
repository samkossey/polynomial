#include <stdlib.h>
#include "string.h"
#include <iostream>
#include <regex>
#include <list>
#include <stdexcept>

using namespace std;

//checks if the string entered fits a long friendly format
bool isNumber(string aString){
    try{
        regex integer("(\\+)?[0-9]+", regex_constants::extended);
        return regex_match(aString,integer);
    } catch (regex_error const &e){
        throw runtime_error("Regex Failed, Did you compile with g++ >= v4.9?");
    }
}

//takes in a list of string and returns a list of long consisting of the
//strings from the input list in the form of longs
list<long> stringToLong(list<string> stringList){
    list<long> result;
    for (list<string>::iterator i = stringList.begin(); i != stringList.end(); i++){
        if(isNumber(*i)){
            result.push_back(atol(i->c_str())); //although atol is an insecure function, we make sure the input is valid via regex
        } else {
            throw runtime_error( "Received string is not a valid long" );
        }
    }
    return result;
}

int main4(void){
    
    string hi = "+12340948665";
    long newHi = atol(hi.c_str());
    cout << newHi << endl;
    cout << "test 1: ";
    if(isNumber("+123")){
        cout << "success";
    } else {
        cout << "failure";
    }
    cout << endl;
        cout << "test 2: ";
    if(!isNumber("++123")){
        cout << "success";
    } else {
        cout << "failure";
    }
    cout << endl;

}