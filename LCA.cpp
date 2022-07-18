#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;

#define SZ 100000

vector<ll>adjlst[SZ];
ll n,root;
bool vis[SZ];
ll level[SZ];
ll par[SZ][25];

void dfs(ll x,ll lvl)
{
    vis[x]=true;
    level[x]=lvl;
    for(auto i:adjlst[x]){
        if(!vis[i]){
            par[i][0]=x;
            dfs(i,lvl+1LL);
        }
    }
    return;
}

void build_lcs()
{
    ll k=log2(n)+1;

    for(int i=1;i<k;i++){
        for(int j=0; j <n;j++){
            if(par[j][i-1]!=-1) par[j][i]= par[ par[j][i-1] ][i-1];
        }
    }

    // for(int i=0;i<n;i++){
    //     cout<<"for "<<i<<"-> "<<endl;
    //     for(int j=0;j<k;j++) cout<<par[i][j]<<" ";
    //     cout<<endl;
    // }
}

ll find_lcs(ll x,ll y)
{
    ll k=log2(n)+1;

    if(level[x]!=level[y]){
        if(level[x]<level[y]) swap(x,y);

        for(int i=k;i>=0;i--){
            if(level[x]-(1<<i) >= level[y] ){
                x=par[x][i];
            }
        }
    }

    if(x==y) return x;

    for(int i=k;i>=0;i--){
        if(par[x][i]!=-1 && par[x][i]!=par[y][i]){
            x=par[x][i];
            y=par[y][i];
        }
    }

    return par[x][0];
}

int main() 
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    
    cin>>n>>root;

    for(int i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;

        adjlst[x].pb(y);
        adjlst[y].pb(x);
    }

    memset(par,-1,sizeof(par));
    dfs(root,0);
    build_lcs();


    ll q;
    cin>>q;
    for(int i=0;i<q;i++){
        ll x,y;
        cin>>x>>y;
        cout<<find_lcs(x,y)<<endl;
    }


    return 0;
}
