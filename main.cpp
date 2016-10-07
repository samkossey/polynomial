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
    if (argc == 1){
        cout << argv[0] << " file1 file2" << endl << endl;
        cout << "Description:" << endl;
        cout << "   Adds two polynomials from file and prints the result" << endl << endl;
        cout << "Parameter List:" << endl;
        cout << "   file1       Specifies the first file containing a polynomial" << endl << endl;
        cout << "   file2       Specifies the second file containing a polynomial" << endl << endl;
        cout << "NOTE: Files should contains a single line with the number format [degree n] [nth term] [n-1th term} ... [1st term]" << endl << endl;
        cout << "Examples:" << endl;
        cout << "   " << argv[0] << " file1.txt file2.txt" << endl;
        cout << "   " << "file1.txt: 2 1 2" << endl;
        cout << "   " << "file2.txt: 4 3 2 1 1" << endl;
        cout << "   " << "output: 4 3 2 2 3" << endl;
        
        return 1;
    }
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
        return 1;
    } catch (bad_alloc const &e){
        cout << "Memory Error: " << e.what() << endl;
        return 2;
    } catch (runtime_error const &e){
        cout << "Runtime Error: " << e.what() << endl;
        return 3;
    } catch (exception const &e){
        cout << "Other Error: " << e.what() << endl;
        return 4;
    }
}