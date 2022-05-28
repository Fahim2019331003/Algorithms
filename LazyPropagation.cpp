#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;
#define SIZE 10000
ll v[SIZE];

class Weight
{
public:
    int w;
    int carry;
    Weight()
    {
        w=0;
        carry=0;
    }
}W[SIZE*4];


void segment(int i,int j,int k)
{
    if(i>j) return;
    if(i==j){
        W[k].w=v[i];
        return;
    }
    int mid=(i+j)>>1;
    segment(i,mid,k*2);
    segment(mid+1,j,k*2+1);
    W[k].w=W[k*2].w+W[k*2+1].w;
    return;
}

void update(int i,int j,int a,int b,int c,int k)
{
    if(i>b || j<a) return;
    
    if(i>=a && j<=b){
        W[k].w+=(j-i+1)*c;
        W[k].carry+=c;
        return;
    }
    int mid=(i+j)>>1; 

    update(i,mid,a,b,c,k*2);
    update(mid+1,j,a,b,c,k*2+1);
    W[k].w=W[k*2].w+W[k*2+1].w+W[k].carry*(j-i+1);
    return;
}

int query(int i,int j,int a,int b,int k,int C)
{
    if(i>b || j<a ) return 0;
    if(i>=a && j<=b){
        return W[k].w+C*(j-i+1);
    }
    int mid=(i+j)>>1;
    int ans=0;
    ans+=query(i,mid,a,b,k*2,W[k].carry+C);
    ans+=query(mid+1,j,a,b,k*2+1,W[k].carry+C);
    return ans;
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    
    segment(1,n,1);
    //cout<<"No"<<endl;

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        //cout<<"yes"<<endl;
        if(x==1){
            int a,b,c;
            cin>>a>>b>>c;
            update(1,n,a,b,c,1); //from a to b update with +c. 
        }
        else{
            int a,b;
            cin>>a>>b;
            cout<<query(1,n,a,b,1,0)<<endl;
        }
    }

    return 0;
}