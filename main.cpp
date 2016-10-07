#include "FileHandler.cpp"
#include "NumberHandler.cpp"
#include "StringHandler.cpp"
#include "PolyAdd.cpp"
#include <stdlib.h>
//#include "string.h"
#include <iostream>
#include <list>
#include <stdexcept>

using namespace std;

int main(int argc, char** argv){
    try{
        if(argc > 3) {
            //TODO: Code for more arguments
            throw invalid_argument( "too many arguments" );
        }
        if(argc >= 3){
            File* file1 = new File(argv[1]);
            File* file2 = new File(argv[2]);
            string file1content = file1->readfile();
            string file2content = file2->readfile();
            delete(file1);
            delete(file2);
            
            list<string> file1list = parseText(file1content);
            list<string> file2list = parseText(file2content);
            
            list<long> file1long = stringToLong(file1list);
            list<long> file2long = stringToLong(file2list);
            
            cout << "Input 1: " << file1content << endl;
            cout << "Input 2: " << file2content << endl;
            cout << "Output : ";
            PollyAdd(file1long, file2long);
            
            //printing
            // for (long i: file1long){
            //     cout << "\"" << i << "\"" << endl;
            // }
            // for (long j: file2long){
            //     cout << "\"" << j << "\"" << endl;
            // }
            // for (string i: file1list){
            //     cout << "\"" << i << "\"" << endl;
            // }
            // for (string j: file2list){
            //     cout << "\"" << j << "\"" << endl;
            // }
        } else {
            throw invalid_argument( "too few arguments" );
        }
    } catch (invalid_argument const &e){
        cout << "Argument Error: " << e.what() << endl;
    } catch (bad_alloc const &e){
        cout << "Memory Error: " << e.what() << endl;
    }
}