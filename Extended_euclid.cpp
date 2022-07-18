#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;

// ax + by = g           ----------1
// b * x1 + (a%b) *y1 = g
// b * x1 + (a-(a/b)*b) *y1 = g    ------2

// from 1 & 2
// x = y1
// y = x1 - (a/b)* y1 

ll ex_gcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll g=ex_gcd(b,a%b,x1,y1);

    x= y1;
    y= x1- (a/b)*y1 ;
    return g;

}

int main() 
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ll a,b,x,y;
    cin>>a>>b;
    if(a<b) swap(a,b);
    ll g=ex_gcd(a,b,x,y);
    cout<<"a-> "<<a<<" b-> "<<b<<" "<<x<<" "<<y<<" "<<endl;
    cout<<"GCD is "<<g<<endl;

    return 0;
}
