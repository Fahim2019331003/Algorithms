#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;

vector<ll>v;
ll st[100010][20];
ll k;

void Sparse(ll n)
{
    k=log2(n)+1;
    
    for(int i=0;i<n;i++) st[i][0]=v[i];

    for(int j=1;j<k;j++){
        for(int i=0;(i+(1<<j)-1) < n;i++){
            st[i][j]= min(st[i][j-1],st[i +(1<<(j-1))][j-1] );
            
        }
    }

}

ll RMQ(ll x,ll y)
{   
    ll ans=LLONG_MAX;
    for(int i=k-1;i>=0;i--){
        if(x+(1<<i)-1 <= y ){
            //cout<<i<<" "<<st[x][i]<<endl;
            ans=min(ans,st[x][i]);
            x+=(1<<i);
        }
    }
    return ans;
}

void test()
{
    ll n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        v.pb(x);
    }
    Sparse(n);
    ll m;
    cin>>m;
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        cout<<RMQ(x,y)<<"\n";
    }
}

int main() 
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    test();

    return 0;
}
