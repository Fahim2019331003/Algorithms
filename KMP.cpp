#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;


bool kmp(string &a,string &b)
{
    
    int n=a.length(),m=b.length();

    //b="*"+b;

    int prefix[m+1]{};
    int cnt=0;
    for(int i=0,j=1;j<m;j++){
        if(b[j]==b[i]){
            prefix[j]=i+1;
            i++;
        }
        else{
            if(i==0) continue;
            else{
                while(i!=0 && b[i]!=b[j]){
                    i=prefix[i-1];
                }
                if(b[i]==b[j]){
                    prefix[j]=i+1;
                    i++;
                } 
                
            }
        }
    }

    for(int i=0,j=0;i<n;i++){
        //cout<<i<<endl;
        if(j>=m) return true;

        if(a[i]==b[j]){
            j++;
        }
        else{

            while(j!=0 && b[j]!=a[i]){
                j=prefix[j-1];
            }
            if(b[j]==a[i]) j++;
        }
        if(j>=m) return true;
    }


    return false;
}

int main() 
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string a,b;
    cin>>a>>b;

    if(kmp(a,b)) cout<<"There's a match!!!!"<<endl;
    else cout<<"Sad"<<endl;

    return 0;
}

//abayabccabababyabababyxabdabababyabctui
//abababyabc
//0012340120

//abacbaabbaaz
//*aab
//0120
