#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;

int main() 
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ll n;
    cin>>n;
    vector<ll>v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];

    

    ll dp[n+1];
    memset(dp,1,sizeof(dp));

    for(int i=1;i<=n;i++) dp[i]=1;
    

    for(int j=2;j<=n;j++){
        for(int i=1;i<j;i++){
            if(v[i]<v[j] && dp[j]<=dp[i]){
                dp[j]=dp[i]+1;
            }
        }
    }
    ll ans=1;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);

    for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
    cout<<endl;

    cout<<ans<<endl;

    return 0;
}

/**
 * @brief 
 * 17
 * 5 2 2 -1 2 93 11 88 28 111 2 3 4 5 6 3 4 
 * 
 * 6
 * 2 -1 3 2 3 4
 * 
 */
