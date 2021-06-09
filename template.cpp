/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
#include <bits/stdc++.h>
using namespace std;
//OPTIMIZATION
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define rep2(i,k,n,a) for(llint i=k;(i<n)&&(a);i++)
#define rep3(i,k,n,a) for(llint i=k;(i>n)&&(a);i--)
#define rep0(i,k,n) rep2(i,k,n,1)
#define rep1(i,k,n) rep3(i,k,n,1)
#define br cout<<"\n";
#define yea cout<<"YES\n"
#define nah cout<<"NO\n"
#define print0(x) for(auto i:x) cout<<i<<" "; br;
#define print1(x) for(auto i:x) cout<<i.first<<" "<<i.second<<"\n"; br;
#define input0(x) for(auto &i:x) cin>>i;
#define input1(x) for(auto &i:x) cin>>i.first>>i.second;
#define input2(x,n) rep0(i,0,n) llint inp,cin>>inp,x.insert(inp);
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define ifn(x) if(!(x))
#define setbits(x) __builtin_popcountll(x)
#define tzerobits(x) __builtin_ctzll(x)
#define lzerobits(x) __builtin_clzll(x)
#define gcd __gcd
#define lcm(x,y) (x*y/gcd(x,y))
#define fileinput freopen("input.txt","r",stdin);
#define fileoutput freopen("output.txt","w",stdout);
#define clock1 tttt=clock();
#define clock0 cout<<"\ntime taken: "<<(((double)clock())-tttt)/((double)CLOCKS_PER_SEC) <<"\n\n";
//#define a(i,j,n) a[i][j]
//#define a(i,j,n) a[i*n+j]
typedef long long llint;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<llint> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef pair<llint,llint> pll;
typedef pair<llint,string> pls;
typedef map<llint,llint> mll;
const uint uintMax=4294967295;         //+(1<<32) - 1
const int intMax=2147483647;           //+(1<<31) - 1
const int intMin=-2147483648;          //-(1<<31)
const ull ullMax=18446744073709551615; //+(1<<64) - 1
const llint Max=9223372036854775807;   //+(1<<63) - 1
const llint Min=-9223372036854775808;  //-(1<<63)
////////////////////////////////////////////////////////////////////////////////////////////////////////////
llint power(llint n,llint exp);
void ts(vector<llint>& v,llint od);
////////////////////////////////////////////////////////////////////////////////////////////////////////////
inline void codechaser(){
    llint n,ans=0;
    cin>>n;
    vector<llint> v(n);
    input0(v);
    
    cout<<ans<<"\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    llint t=1;
    cin>>t;
    while(t--) codechaser();
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
llint power(llint n, llint exp){
    llint res=1;
    while(exp){
        if(exp&1) res*=n,exp--;
        else n*=n,exp>>=1;
    }
    return res;
}
void ts(vector<llint>& v,llint od){
    if(!v.size()) return;
    llint n=v.size(),max=abs(v[0]);
    rep0(i,1,n) if(abs(v[i])>max) max=abs(v[i]);
    llint k=log10(max)+1;
    rep0(i,0,ceil((double)k/od)){
        vector<vector<llint>> record(power(10,od));
        rep0(j,0,n) (record[(llint)abs((llint)((v[j])%((llint)power(10,od*(i+1))))/power(10,od*i))]).pb(v[j]);
        llint counter=0;
        rep0(j,0,power(10,od)) for(auto k:record[j]) v[counter]=k,counter++;
    }
    return;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |---------------------------------------------------|
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////