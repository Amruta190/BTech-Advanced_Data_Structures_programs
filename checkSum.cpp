#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int binaryToDecimal(int ch[],int len)
{
    int sum=0;
    for(int i=len-1;i>=0;i--)
    {
        sum+=(ch[len-i-1])*pow(2,i);
    }
    return sum;
}
string add(string a,string b)
{
    string res="";
    int tmp=0;
    int a_len=a.size()-1;
    int b_len=b.size()-1;
    while(a_len>=0 || b_len>=0 || tmp==1)
    {
        tmp+=((a_len>=0)?a[a_len]-'0':0);
        tmp+=((b_len>=0)?b[b_len]-'0':0);
        res=char(tmp % 2 +'0')+res;
        tmp=tmp/2;
        a_len--;
        b_len--;
    }
    return res;
}
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
        int j=parts-1,k=n-1,i=len-1;
        for(j=parts-1;j>=0;j--)
        {
            for(k=n-1;k>=0;k--)
            {
                mat[j][k]=data[i]-'0';
                i--;
            }
        }
        int res=0;
        for(i=0;i<parts;i++)
        {
            int tmp[n];
            for(int j=0;j<n;j++)
            {
                tmp[j]=mat[i][j];
            }
            res+=binaryToDecimal(tmp,n);
        }
        char bin[10];
        itoa(res,bin,2);
        int cnt=0;
        i=0;
        while(bin[i]!='\0')
        {
            cnt+=1;
            i++;
        }
        string carry="",str="";
        for(i=0;i<cnt-n;i++)
            carry=carry+bin[i];
        for(int j=i;j<cnt;j++)
            str=str+bin[j];
        string ans=add(str,carry);
        i=0;
        while(ans[i]!='\0')
        {
            if(ans[i]=='0')
                ans[i]='1';
            else
                ans[i]='0';
            i++;
        }
        cout<<"Check sum bits : "<<ans;
        cout<<"\nTransfered data : "<<ans+data;
    }
}