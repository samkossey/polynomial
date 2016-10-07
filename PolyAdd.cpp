#include <stdlib.h>
#include "string.h"
#include <iostream>
#include <list>
#include <stdexcept>

using namespace std;
//check if leads with 0?
void PollyAdd(list<long> poly1, list<long> poly2){
    //cout << "called " << endl;
    list<long>::iterator i = poly1.begin();
    list<long>::iterator j = poly2.begin();
    //check if length of polys match first numbers?
    if (poly1.size() != *i + 1 || poly2.size() != *j + 1){
        throw invalid_argument( "actual length of polynomial did not match expected" );
    }
    //long max = *i ^ ((*i ^ *j) & -(*i < *j)); 
    list<long>::iterator max = ((*i >  *j) ? i : j);
    list<long>::iterator min = ((*i <= *j) ? i : j);
    //(*i > *j) ? max = i
    
    //cout << "here1s" << endl;

    
    long diff;
    list<long>::iterator end;
    if (max == i){
        diff = poly1.size() - poly2.size();
        end = poly1.end();
    } else {
        diff = poly2.size() - poly1.size();
        end = poly2.end();
    }
    cout << *max << " ";
    if (*max == 0 || *min == 0){
        throw invalid_argument( "degree was 0" );
    }
    min++;
    max++;
    if (*max == 0 || *min == 0){
        throw invalid_argument( "first term was 0" );
    }
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
    
    
    // if (max == *i){

    // else if (max == *j){
    //     i++;
    //     j++;
    //     if (*i == 0 || *j == 0){
    //         throw invalid_argument( "first term was 0" );
    //     }
    //     long diff = poly2.size() - poly1.size();
    //     for (; j != poly2.end(); j++){
    //         if (diff <= 0){
    //             cout << (*i + *j) << " ";
    //             i++;
    //         }
    //         else{
    //             cout << *j << " ";
    //         }
    //         diff--;
    //     }
    // }
    // else {
    //     // you broke something :)
    // }
    
}

// void adder(){
//             i++;
//         j++;
//         if (*i == 0 || *j == 0){
//             throw invalid_argument( "first term was 0" );
//         }
//         long diff = poly1.size() - poly2.size();
//         for (; i != poly1.end(); i++){
//             if (diff <= 0){
//                 cout << (*i + *j) << " ";
//                 j++;
//             }
//             else{
//                 cout << *i << " ";
//             }
//             diff--;
//         }
// }

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