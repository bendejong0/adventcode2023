#include <fstream>
#include <iostream>
#include <vector>

using namespace std;



int main()
{
    int rollingSum;
    ifstream file;
    string stringFromFile;
    cout << "Opening file..." << endl;
    file.open("input.txt");
    
    // lambda that takes a line from the file and returns a string.
    auto getLine = [&file, &stringFromFile](){
        getline(file, stringFromFile);
    };
    
    // lambda gets a number from a line, and adds it to the rolling sum.
    auto sumLine = [&stringFromFile, &rollingSum](){
        // getting first number
        int number = 0;
        for(auto i : stringFromFile){
            if(isdigit(i)){
                number = i - '0';
                break;
            }
        }
        for(int i = stringFromFile.size()-1; i >= 0; i--){
            if(isdigit(stringFromFile[i])){
                number *=10;
                number+= stringFromFile[i]-'0';
                break;
            }
        }
        rollingSum+=number;
    };
    
    // if we couldnt open the file
    if(!file.is_open()){
        cout << "Couldn't open file!" << endl;
        return 1;
    }
    // if we opened the file
    else{
        cout << "File opened successfully." << endl;
    }
    
    
    
    cout << endl;
    while(!file.eof()){
        getLine();
        sumLine();
        cout << "Sum: " << rollingSum << endl;
    }
    cout << endl;






    // closing the file.
    {cout << "Closing file..." << endl;
    file.close();
    if(!file.is_open()){
        cout << "Closed file successfully!" << endl;
    }}

    return 0;
}
