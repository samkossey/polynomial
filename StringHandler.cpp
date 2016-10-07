#include <string>
#include <list>


//given a string, creates a list of the words contained in that string
list<string> parseText(string s){
    list<string> l;
    string currString = "";
    for (int i = 0; i < s.length(); i++){
        //a space indicates the start of a new word
        if (s.at(i) == ' '){
            l.push_back(currString);
            currString = "";
        }
        else{
            //if no space, continue building a word character by character
            currString += s.at(i);
        }
    }
    if (currString != ""){
        l.push_back(currString);
    }
    return l;
}