#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;
#define SIZE 10000
ll v[SIZE];
ll w[SIZE*4];


void buildtree(int i,int j,int k)
{
    int mid=(i+j)/2;
    
    if(i==j){
        w[k]=v[i];
        return;
    }

    buildtree(i,mid,k*2);
    buildtree(mid+1,j,k*2+1);

    w[k]=w[k*2]+w[k*2+1];
    //cout<<k<<" ----> "<<w[k]<<endl;
    return;
}

void update(int i,int j,int k,int a)
{
    if(j<a || i>a){
        return;
    }
    if(i==j){
        w[k]=v[i];
        return;
    }
    int mid=(i+j)/2;

    update(i,mid,k*2,a);
    update(mid+1,j,k*2+1,a);

    w[k]=w[k*2]+w[k*2+1];
    
}

int query(int i,int j,int k,int a,int b)
{
    if(i>b || j<a) return 0;
    if(i>=a && j<=b) return w[k];
    int mid=(i+j)/2;

    int ans=0;
    ans+=query(i,mid,k*2,a,b)+query(mid+1,j,k*2+1,a,b);
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


    buildtree(1,n,1);

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        if(x==1){ //update indx a with b
            int a,b;
            cin>>a>>b;
            v[a]=b;
            update(1,n,1,a);
        }
        else{
            int a,b;
            cin>>a>>b;
            cout<<query(1,n,1,a,b)<<endl;
        }
    }

    


    return 0;
}