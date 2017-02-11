#include <iostream>
#include <fstream>
#include <string>
#include <vector>





using namespace std;

int main()
{
    string name, age;
    fstream writer, inputFile, outputFile;


    cout << "please tell me your name, then press enter." << endl;
    getline (cin, name);

    cout << "please tell me your age, then press enter."<< endl;
    getline (cin, age);

    writer.open("mod5.txt", ios::app);
    if (!writer)
    {
        cout << "Can't open file." << endl;
        exit(1);
    }
    writer << name << age << endl;
    writer.close();




    std::vector<char> charVec;
    std::fstream file;

    file.open("mod5.txt", std::ifstream::in | std::ifstream::binary);
    file.seekg(0, std::ios::end);
    std::streampos length(file.tellg());
    if (length)
    {
        file.seekg(0, std::ios::beg);
        charVec.resize(static_cast<std::size_t>(length));
        file.read(&charVec.front(), static_cast<std::size_t>(length));
    }

    for (int i = 0; i < charVec.size(); i++)
    {
        file.open("new.txt", std::ifstream::in | std:: ifstream:: app);
        cout << charVec[i] << endl;
        //file << charVec[i] << endl;
        file.close();
    }



    return 0;
}