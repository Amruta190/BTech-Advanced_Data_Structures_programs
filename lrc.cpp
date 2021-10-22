#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter length of data : ";
    int len;
    cin>>len;
    char data[len];
    cout<<"Enter data : ";
    cin>>data;
    cout<<"No.of parts : ";
    int parts;
    cin>>parts;
    if(len%parts!=0)
        cout<<"Partition not possible!";
    else
    {
        int n=len/parts;
        int mat[parts][n];
        int j,k,i=len-1;
        for(j=parts-1;j>=0;j--)
        {
            for(k=n-1;k>=0;k--)
            {
                mat[j][k]=data[i]-'0';
                i--;
            }
        }
        char tmp[n];
        for(i=n-1;i>=0;i--)
        {
            int sum=0;
            for(j=0;j<parts;j++)
            {
                sum+=mat[j][i];
            }
            cout<<sum<<"\n";
            if(sum%2==0)
                tmp[i]='0';
            else
                tmp[i]='1';
        }
        string res="";
        for(i=0;i<n;i++)
            res=res+tmp[i];
        cout<<"LRC bits : "<<res;
        for(i=0;i<len;i++)
            res=res+data[i];
        cout<<"\nTransmitted data : "<<res;
    }
}