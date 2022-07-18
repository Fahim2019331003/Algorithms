#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;


#define SZ 1000

ll n,edge;
ll g[SZ][SZ];
bool visited[SZ];
ll parent[SZ];
bool found=0;

ll dfs(ll cur,ll t,ll flag)
{
    visited[cur]=true;

    ll x=LLONG_MAX;

    for(int i=0;i<n;i++){
        if(g[cur][i]>0 && visited[i]==0){
            if(i==t){
                found=true;
                parent[t]=cur;
                return flag=min(flag,g[cur][i]);
                
            }
            //cout<<"Node "<<cur<<" to "<<i<<" "<<min(flag,g[cur][i])<<endl;
            ll x=dfs(i,t, min(flag,g[cur][i]) );

            

            if(found){
                parent[i]=cur;
                return x;
            } 
        }
    }

    return flag;
}


ll ford_fulkerson(ll s,ll t)
{

    ll max_flow=0;

    while(1){
        found=0;
        ll flag=LLONG_MAX;
        memset(visited,0,sizeof(visited));
        memset(parent,-1,sizeof(parent));
        ll x=dfs(s,t,flag);
        //cout<<"---------------------------"<<x<<endl;
        if(!found) break;

        max_flow+=x;

        ll p=t;
        while(p!=s){
            ll q=p;
            p=parent[p];

            g[p][q]-=x;
            g[q][p]+=x;

        }

        



    }

    return max_flow;
}


int main() 
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    
    cin>>n>>edge;

    for(int i=0;i<edge;i++){
        ll x,y,w;
        cin>>x>>y>>w;
        g[x][y]=w;
    }

    //cout<<"YES"<<endl;
    cout<<ford_fulkerson(0,n-1)<<endl;
    

    return 0;
}
