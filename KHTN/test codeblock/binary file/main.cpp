#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ifstream in("output.dat", ios::binary);
    in.seekg(0,ios::end);
    int n = in.tellg() / 4;
    in.seekg(0,ios::beg);
    cout << n;
    in.read((char*)&n,4);
    cout << "\n" << n;
    in.close();
}
