#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
int binaryToDecimal(int ch[], int len)
{
    int sum = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        sum += (ch[len - i - 1]) * pow(2, i);
    }
    return sum;
}
string add(string a, string b)
{
    string res = "";
    int tmp = 0;
    int a_len = a.size() - 1;
    int b_len = b.size() - 1;
    while (a_len >= 0 || b_len >= 0 || tmp == 1)
    {
        tmp += ((a_len >= 0) ? a[a_len] - '0' : 0);
        tmp += ((b_len >= 0) ? b[b_len] - '0' : 0);
        res = char(tmp % 2 + '0') + res;
        tmp = tmp / 2;
        a_len--;
        b_len--;
    }
    return res;
}
string checkSum(int len,int parts,char data[])
{
    int n = len / parts;
    int mat[parts][n];
    int j = parts - 1, k = n - 1, i = len - 1;
    for (j = parts - 1; j >= 0; j--)
    {
        for (k = n - 1; k >= 0; k--)
        {
            mat[j][k] = data[i] - '0';
            i--;
        }
    }
    int res = 0;
    for (i = 0; i < parts; i++)
    {
        int tmp[n];
        for (int j = 0; j < n; j++)
        {
            tmp[j] = mat[i][j];
        }
        res += binaryToDecimal(tmp, n);
    }
    char bin[10];
    itoa(res, bin, 2);
    int cnt = 0;
    i = 0;
    while (bin[i] != '\0')
    {
        cnt += 1;
        i++;
    }
    string carry = "", str = "";
    for (i = 0; i < cnt - n; i++)
        carry = carry + bin[i];
    for (int j = i; j < cnt; j++)
        str = str + bin[j];
    string ans = add(str, carry);
    i = 0;
    while (ans[i] != '\0')
    {
        if (ans[i] == '0')
            ans[i] = '1';
        else
            ans[i] = '0';
        i++;
    }
    string str1=ans+data;
    cout << "Check sum bits : " << ans;
    return str1;
}
int main()
{
    cout << "Enter length of data : ";
    int len;
    cin >> len;
    char data[len];
    cout << "Enter data : ";
    cin >> data;
    cout << "No.of parts : ";
    int parts;
    cin >> parts;
    if (len % parts != 0)
        cout << "Partition not possible!";
    else
    {
        string res=checkSum(len,parts,data);
        cout << "\nTransfered data : " << res;
        cout << "\nEnter received data : ";
        int n=len/parts;
        len+=n;
        parts+=1;
        char received[len];
        cin >> received;
        string checkbits=checkSum(len,parts,received);
        string res1="";
        for(int i=0;i<n;i++)
            res1+=checkbits[i];
        int i=0;
        for(i=0;i<n;i++)
        {
            if(res1[i]!='0')
            {
                cout<<"\nIncorrect data received";
                break;
            }
        }
        if(i==len/parts)
            cout<<"\nReceived correctly";
    }
}