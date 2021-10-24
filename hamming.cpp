#include<iostream>
#include<math.h>
#include<string>
using namespace std;
int binaryToDecimal(int arr[],int len)
{
    int res=0,k=0;
    for(int i=len-1;i>=0;i--)
        res+=arr[i]*pow(2,k++);
    return res;
}
int main()
{
    string data;
    cout<<"Enter the data : ";
    cin>>data;
    int len=data.length();
    int p=0;
    while(pow(2,p)<p+len+1)
        p++;
    int arr[p+len+1],k=p-1,j=0;
    for(int i=1;i<=p+len;i++)
    {
        if(pow(2,k)==p+len-i+1)
        {
            arr[i]=2;
            k--;
        }
        else
            arr[i]=data[j++]-'0';
    }
    k=0;
    for(int i=p+len;i>0;i--)
    {
        if(pow(2,k)==p+len-i+1)
        {
            int parity=pow(2,k),s=0;
            for(j=parity;j<=p+len;j=j+parity)
            {
                int q=parity;
                while(q>0)
                {
                    if(arr[p+len+1-j]!=2)
                        s+=arr[p+len+1-j];
                    q--;j++;
                }
            }
            if(s%2!=0)
                arr[i]=0;
            else
                arr[i]=1;
            k++;
        }
    }
    cout<<"Hamming code : ";
    for(int i=1;i<=p+len;i++)
        cout<<arr[i];
    cout<<"\nEnter receiver data : ";
    string receiver;
    cin>>receiver;
    int arr1[p+len+1],tmp[p];
    for(int i=1;i<=p+len;i++)
        arr1[i]=receiver[i-1]-'0';
    k=0;
    int h=p-1;
    for(int i=p+len;i>0;i--)
    {
        if(pow(2,k)==p+len-i+1)
        {
            int parity=pow(2,k),s=0;
            for(j=parity;j<=p+len;j=j+parity)
            {
                int q=parity;
                while(q>0 && j<=p+len)
                {
                    s+=arr1[p+len+1-j];
                    q--;j++;
                }
            }
            if(s%2!=0)
                tmp[h--]=0;
            else
                tmp[h--]=1;
            k++;
        }
    }
    int bit=binaryToDecimal(tmp,p);
    if(bit<=p+len && bit>0)
    {
        cout<<"\n-----Using Odd Parity-----\nCorrection bit is : ";
        for(int i=0;i<p;i++)
            cout<<tmp[i];
        cout<<" = "<<bit;
        cout<<"\nCorrected hamming code : ";
        if(arr1[p+len-bit+1]==0)
            arr1[p+len-bit+1]=1;
        else
            arr1[p+len-bit+1]=0;
        for(int i=1;i<=p+len;i++)
            cout<<arr1[i];
        cout<<"\nCorrected message : ";
        k=p-1;
        for(int i=1;i<=p+len;i++)
        {
            if(pow(2,k)==p+len+1-i)
                k--;
            else
                cout<<arr1[i];
        }
    }
    else
    {
        cout<<"No error is detected";
        cout<<"\nMessage is : ";
        k=p-1;
        for(int i=1;i<=p+len;i++)
        {
            if(pow(2,k)==p+len+1-i)
                k--;
            else
                cout<<arr1[i];
        }
    }
}