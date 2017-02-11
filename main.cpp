#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

int main()
{
    //declare variables.
    string name, age;
    fstream writer, inputFile, outputFile;

    // get name.
    cout << "please tell me your name, then press enter." << endl;
    getline(cin, name);

    // get age.
    cout << "please tell me your age, then press enter." << endl;
    getline(cin, age);

    // open text file.
    writer.open("mod5.txt", ios::app);

    // throw error if can't open file.
    if (!writer)
    {
        cout << "Can't open file." << endl;
        exit(1);
    }
    // write to fle, then close it.
    writer << name << " is " << age << " years old." << endl;
    writer.close();


    // declare character vector, and stream object.
    vector<char> charVec;
    fstream file;

    //open file.
    file.open("mod5.txt", ifstream::in | ifstream::binary);
    //find end
    file.seekg(0, ios::end);
    streampos length(file.tellg());
    // if statement to read get characters into vector.
    if (length)
    {
        file.seekg(0, ios::beg);
        charVec.resize(static_cast<size_t>(length));
        file.read(&charVec.front(), static_cast<size_t>(length));
    }

    // loop through vector in reverse.
    for (long i = charVec.size() - 1; i >= 0; i--)
    {
        //open new text file.
        file.open("new.txt", ifstream::in | ifstream::app);
        // write the new file in reverse.
        file << charVec[i];
        //close file.
        file.close();
    }

    return 0;
}