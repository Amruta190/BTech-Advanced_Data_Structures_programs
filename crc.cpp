#include<iostream>
#include<string>
using namespace std;
string binaryDivision(string dividend,string divisor)
{
    int dend=stoi(dividend);
    int div=stoi(divisor);
    int arr[dividend.length()],arr1[divisor.length()],tmp[dividend.length()];
    for(int i=dividend.length()-1;i>=0;i--)
    {
        arr[i]=dend%10;
        tmp[i]=arr[i];
        dend=dend/10;
    }
    for(int i=divisor.length()-1;i>=0;i--)
    {
        arr1[i]=div%10;
        div=div/10;
    }
    for(int i=0;i<dividend.length()-divisor.length()+1;i++)
    {
        int j=0,k=i;
        if(arr[k]>=arr1[j])
        {
            for(j=0,k=i;j<divisor.length();j++,k++)
            {
                if(arr[k]==arr1[j])
                    arr[k]=0;
                else
                    arr[k]=1;
            }
        }
    }
    string str;
    for(int i=dividend.length()-divisor.length()+1;i<=dividend.length();i++)
        tmp[i]=arr[i];
    for(int i=0;i<dividend.length();i++)
    {
        str.push_back(tmp[i]+'0');
    }
    return str;
}
int main()
{
    string dividend,divisor,tmp;
    cout<<"Enter dividend : ";
    cin>>dividend;
    cout<<"Enter divisor : ";
    cin>>divisor;
    int len=divisor.length()-1;
    cout<<"Sender side :\nNo.of 0's to be appended : "<<len<<"\n";
    for(int i=0;i<len;i++)
        dividend.append("0");
    cout<<"Message after appending 0's : "<<dividend<<"\n";
    tmp=binaryDivision(dividend,divisor);
    cout<<"CRC bits : ";
    for(int i=dividend.length()-len;i<dividend.length();i++)
        cout<<tmp[i];
    cout<<"\nTransmitted data : "<<tmp;
    cout<<"\nReceiver side : \nReceived Data : ";
    string tmp1;
    cin>>tmp1;
    tmp1=binaryDivision(tmp1,divisor);
    int i=0;
    for(i=0;i<tmp1.length();i++)
    {
        if(dividend[i]!=tmp1[i])
            break;
    }
    if(i==tmp1.length())
    {
        cout<<"Remainder : ";
        for(int j=0;j<len;j++)
            cout<<"0";
        cout<<"\nData received correctly\n";
    }
    else
        cout<<"Data received incorrectly\n";
}