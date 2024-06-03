#include <iostream>
#include <string>
#include <cstdint>
#include <ctime>
using namespace std;

string oppositeNumber(string m)
{
    int size = m.size();
    for(int i = 0; i < size; i++)
    {
        if(m[i] == '0')
            m[i] = '1';
        else m[i] = '0';
    }
    bool remember = 1;
    for(int i = size - 1; i >= 0; i--)
    {
        if(remember)
        {
            if(m[i] == '0')
            {
                m[i] = '1';
                remember = false;
            }
            else m[i] = '0';
        }
    }
    return m;
}

string decimalToBinary()
{
    int32_t x;
    cout << "Nhap so nguyen: ";
    cin >> x;
    string s = "";
    bool isNeg = (x < 0) ? 1 : 0;
    if(x == 0)
        return "0";
    x = (isNeg) ? -x : x;
    while(x > 0)
    {
        int tmp = x % 2;
        s = to_string(tmp) + s;
        x /= 2;
    }
    while(s.size() < 32)
        s = "0" + s;
    if(isNeg)
        s = oppositeNumber(s);
    return s;
}

void BinaryToDec()
{
    int32_t x = 0;
    int multiply = 1;
    int a[32];
    cout << "Nhap day so: ";
    for(int i = 0; i < 32; i++)
    {
        cin >> a[i];
        if(a[i] != 1 && a[i] != 0)
        {
            cout << "Invalid! Input again!\n";
            i--;
        }   
    }
    bool isNeg = false;
    if(a[0] == 1)
        isNeg = true;
    cout << "Result: ";
    if(!isNeg)
    {
        for(int i = 31; i >= 0; i--)
        {
            x += (a[i] == 1) ? (multiply) : 0;
            multiply *= 2;
        }
        cout << x << "\n";
    }
    else
    {
        bool remember = true;
        for(int i = 0; i < 32; i++)
            a[i] = (a[i] == 0) ? 1 : 0;
        for(int i = 31; i >= 0; i--)
        {
            if(remember)
            {
                if(a[i] == 0)
                {
                    a[i] = 1;
                    remember = false;
                }
                else a[i] = 0;
            }
        }
        for(int i = 31; i >= 0; i--)
        {
            x += (a[i] == 1) ? (multiply) : 0;
            multiply *= 2;
        }
        cout << -x << "\n";
    }
}

string plus_result(string a, string m)
{
    string tmp = "";
    bool remember = false;
    for(int i = 7; i >= 0; i--) 
    {
        if(m[i] == '0' && a[i] == '0') 
        { // 0 + 0
            if(!remember)
                tmp += "0";
            else 
            {
                tmp += "1";
                remember = false;
            }
        } 
        else if((m[i] == '1' && a[i] == '0') || (m[i] == '0' && a[i] == '1')) 
        { // 1 + 0
            if(!remember)
                tmp += "1";
            else
                tmp += "0";
        } 
        else if(m[i] == '1' && a[i] == '1') 
        { // 1 + 1
            if(!remember) 
            {
                tmp += "0";
                remember = true;
            } 
            else tmp += "1";
        }
    }
    string result = "";
    for(int i = 7; i >= 0; i--)
        result += tmp[i];
    return result;
}

string minus_result(string a, string m)
{
    m = oppositeNumber(m);
    string res = plus_result(a,m);
    return res;
}

string divide(string& q, string m) 
{
    m = oppositeNumber(m);
    string a = "00000000"; // Chuỗi a khởi tạo với 8 bit 0

    int size = a.size();
    for (int i = 0; i < 8; i++) 
    {
        // Dịch trái a và q, nhập bit 0 vào cuối a
        char a_beg = a[0];
        for (int j = 0; j < size - 1; j++) 
            a[j] = a[j + 1];
        a[size - 1] = q[0];

        // Dịch trái q, nhập bit a_beg vào cuối q
        for (int j = 0; j < size - 1; j++) 
            q[j] = q[j + 1];
        q[size - 1] = a_beg;

        // Cộng a với m
        string tmp = plus_result(a, m);
        if (tmp[0] != '1') 
            a = tmp;
            q[size - 1] = '1';
    }
    return a;
}

string multiply(string q, string m) 
{
    string a = "00000000"; 
    int size = a.size();
    bool q_1 = false; 

    for (int i = 0; i < 8; i++) 
    {
        
        if ((q[size - 1] == '1' && !q_1) || (q[size - 1] == '0' && q_1)) 
        {
            if (q[size - 1] == '1') 
                a = minus_result(a, m);
            else 
                a = plus_result(a, m);
            
        }

        
        q_1 = (q[size - 1] == '1');
        for (int j = size - 1; j > 0; j--) 
            q[j] = q[j - 1];
        
        q[0] = a[size - 1];
        for (int j = size - 1; j > 0; j--) 
            a[j] = a[j - 1];
        
        a[0] = q_1 ? '1' : '0';
    }

    return a + q; 
}

int main()
{
    string s,q,m,res;
    cout << "1. Decimal to Binary\n2. Binary to Decimal\n3. Plus\n4. Minus\n5.Multiply\n6.Divide\nChose your options: ";
    int choose;
    cin >> choose;
    switch (choose)
    {
    case 1:
    s = decimalToBinary();
    cout << "Result: " << s << "\n";
    break;
    
    case 2:
    BinaryToDec();
    break;

    case 3:
    cin.ignore();
    cout << "Nhap q: ";
    getline(cin,q);
    cout << "Nhap m: ";
    getline(cin,m);
    res = plus_result(q,m);
    cout << "Result: " << res << "\n";
    break;

    case 4:
    cin.ignore();
    cout << "Nhap q: ";
    getline(cin,q);
    cout << "Nhap m: ";
    getline(cin,m);
    res = minus_result(q,m);
    cout << "Result: " << res << "\n";
    break;

    case 5:
    cin.ignore();
    cout << "Nhap q: ";
    getline(cin,q);
    cout << "Nhap m: ";
    getline(cin,m);
    res = multiply(q,m);
    cout << "Result: " << res << "\n";
    break;

    case 6:
    cin.ignore();
    cout << "Nhap q: ";
    getline(cin,q);
    cout << "Nhap m: ";
    getline(cin,m);
    res = divide(q,m);
    cout << "So du: " << res << "\nThuong: " << q << "\n";
    break;
    }
    system("pause");
    return 0;
}


