#include <iostream>
#include <string>

using namespace std;

string decToBin(string s)
{
    int num = stoi(s);
    //check if the number is valid or not
    if(num > 255 || num < 0) 
    {
        cout << "Error!";
        return " ";
    }

    // convert to binary
    string a, result;
    while(num > 0)
    {
        int tmp = num % 2;
        string a = to_string(tmp);
        a += result;
        result = a;
        num /= 2;
    }

    // add missing 0 
    int size = result.size();
    if(size - 8 < 0) // less than 8 bit
        for(; size != 8; size++)
        {
            string s = "0" + result;
            result = s;
        }

    return result;
}

string decToHex(string s)
{
    int num = stoi(s);
    //check if the number is valid or not
    if(num > 255 || num < 0) 
    {
        cout << "Error!";
        return " ";
    }

    // convert to binary
    string a, result;
    while(num > 0)
    {
        int tmp = num % 16;
        if(tmp < 10)
        {
            a = to_string(tmp);
            a += result;
            result = a;
        }
        else
        {
            tmp = tmp + 55; // using ascii
            a = char(tmp);
            a += result;
            result = a;
        }
        num /= 16;
    }
    return result;
}

string hexToDec(string s)
{
    int size = s.size();
    int a, num = 0, multiply = 1;
    if(size == 0)
        return "0";

    while(size != 0)
    {
        if(s[size - 1] > 'F') // check if invalid
        {
            cout << "Error!";
            return " ";
        }
        if(s[size - 1] < 'A') // < 9
        {
            a = (s[size - 1] - '0') * multiply;
            num += a;
        }
        else // >= 10
        {
            a = (s[size - 1] - 'A' + 10) * multiply;
            num += a;
        }
        multiply *= 16;
        size--;
    }
    string result = to_string(num);
    return result;
}

string binToDec(string s)
{
    int size = s.size();
    // check if size > 8
    if(size > 8)
    {
        cout << "Error!";
        return " ";
    }

    int num = 0, multiply = 1;
    while(size != 0)
    {
        if(s[size - 1] != '1' && s[size - 1] != '0')
        {
            cout << "Error!";
            return " ";
        }
        if(s[size - 1] == '1')
            num += multiply;
        multiply *= 2;
        size--;
    }
    string result = to_string(num);
    
    return result;
}

string binToHex(string s)
{
    int size = s.size();
    // check if size > 8
    if(size > 8)
    {
        cout << "Error!";
        return " ";
    }

    string result = "", a; 
    int tmp = 0, multiply = 1;
    while(size > 0)
    {
        if(s[size - 1] != '1' && s[size - 1] != '0')
        {
            cout << "Error!";
            return " ";
        }
        // convert to integer
        for (int i = 0; i < 4; i++)
        {
            if(s[size - 1] == '1')
            {
                tmp += multiply;
            }
            multiply *= 2;
            size--;
            if(size < 0)
            {
                cout << "Error!";
                return " ";
            }
        }
        // convert to hexadecimal
        if(tmp < 10)
        {
            a = to_string(tmp);
            a += result;
            result = a;
        }
        else
        {
            a = tmp - 10 + 'A';
            a += result;
            result = a;
        }
        multiply = 1;
        tmp = 0;
    }
    return result;
}

string hexToBin(string s)
{
    int size = s.size();
    if(size > 2)
    {
        cout << "Error";
        return " ";
    }
    string a, result = "";
    int tmp = 0;
    while(size > 0)
    {
        if(s[size - 1] > 'F')
        {
            cout << "Error";
            return " ";
        }
        else
        {
            int num = (s[size - 1] < 'A') ? (s[size - 1] - '0') : (s[size - 1] - 'A' + 10);
            for(int i = 0; i < 4; i++)
            {
                a = (num % 2 == 0) ? "0" : "1";
                num /= 2;
                a += result;
                result = a;
            }
        }
        size--;
    }
    return result;
}

int main()
{   
    int n;
    do
    {
        cout << "1. Decimal to binary\n2. Decimal to Hexadecimal\n3. Hexadecimal to decimal\n4. Binary to Decimal\n5. Binary to Hexadecimal\n6. Hexadecimal to Binary\n7. Exit\n";
        cout << "Function: ";
        cin >> n;
        if (n == 7) continue;
        cout << "Input: ";
        cin.ignore();
        string s,result = " ";
        getline(cin,s);
        switch (n)
        {
            case 1:
            result = decToBin(s);
            break;
            case 2:
            result = decToHex(s);
            break;
            case 3:
            result = hexToDec(s);
            break;
            case 4:
            result = binToDec(s);
            break;
            case 5:
            result = binToHex(s);
            break;
            case 6:
            result = hexToBin(s);
        }
        if(result != " ")
            cout <<  "Output: " << result << "\n";
        else cout << "\n";
    } while (n != 7);
    
    return 0;
}