#include <stdlib.h>
#include "string.h"
#include <iostream>
#include <list>
#include <stdexcept>

using namespace std;

//adds two polynomials together (input format is list of longs), and output
//is printed
void PollyAdd(list<long> poly1, list<long> poly2){
    
    list<long>::iterator i = poly1.begin();
    list<long>::iterator j = poly2.begin();
    //check if length of polys match the first number in the lists (the degree)
    if (poly1.size() != *i + 1 || poly2.size() != *j + 1){
        throw invalid_argument( "actual length of polynomial did not match expected" );
    }
     
    //keeping track of which polynomial has the higher degree 
    list<long>::iterator max = ((*i >  *j) ? i : j);
    list<long>::iterator min = ((*i <= *j) ? i : j);
    
    long diff;
    list<long>::iterator end;
    if (max == i){
        diff = poly1.size() - poly2.size();
        end = poly1.end();
    } else {
        diff = poly2.size() - poly1.size();
        end = poly2.end();
    }
    //prints the degree of the final result
    cout << *max << " ";
    if (*max == 0 || *min == 0){
        throw invalid_argument( "degree was 0" );
    }
    min++;
    max++;
    if (*max == 0 || *min == 0){
        throw invalid_argument( "first term was 0" );
    }
    //adding of the like terms
    for (; max != end; max++){
        if (diff <= 0){
            long total = *max + *min;
            cout << total << " ";
            min++;
        }
        else{
            cout << *max << " ";
        }
        diff--;
    }
    cout << endl;
}
    
int main5 (){
    int x = -10;
    int y = -10;
    int z = x ^ ((x ^ y) & -(x < y));
    cout << z << endl;
    
    list<long> list1;
        list1.push_back(4);
        list1.push_back(6);
        list1.push_back(2);
        list1.push_back(3);
        list1.push_back(1);
    cout << endl;
    list<long> list2;
    list2.push_back(1);
    list2.push_back(2);
    cout << endl;
    PollyAdd(list1, list2);
}