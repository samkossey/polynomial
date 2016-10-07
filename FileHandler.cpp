#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdexcept>

#include <unistd.h>

using namespace std;

class File {
    private:
        string file;
    
    public:
    File(string filename){
        if(access( filename.c_str(), F_OK ) != -1) {
            file=filename;
        } else {
            throw invalid_argument( "Invalid File" );
        }
    }
    ~File(){}
    
    string readfile(){
        if(access( file.c_str(), F_OK ) != -1) {
            string line;
            string text;
            ifstream inFile;
            
            inFile.open(file);
    
            while (getline(inFile, line))
            {
                text+=line;
                text+=" ";
            }
            if (text.length() > 0){
                text.pop_back(); //take of the trailing space
            } else {
                throw invalid_argument("Couldn't Read File or Empty File");
            }
            inFile.close();
            return text;
        } else {
            throw invalid_argument( "Invalid File" );
        }
    }
};

int main3() {
    string tweet;
    File* file = new File("tweet.txt");
    tweet = file->readfile();
    std::cout << "\"" << tweet << "\"" << endl;
    delete(file);
}