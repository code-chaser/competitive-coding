/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
//COMPILER SUPPORT : STD=GNU C++14 or ABOVE
#include <bits/stdc++.h>
using namespace std;
//OPTIMIZATION
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
//DEFINE STATEMENTS
#define rep2(i,k,n,a) for(llint i=k;(i<n)&&(a);i++)
#define rep3(i,k,n,a) for(llint i=k;(i>n)&&(a);i--)
#define rep0(i,k,n) rep2(i,k,n,1)
#define rep1(i,k,n) rep3(i,k,n,1)
#define br cout<<"\n"
#define yea cout<<"YES\n"
#define nah cout<<"NO\n"
#define print0(x) for(auto i:x) cout<<i<<" "; br;
#define print1(x) for(auto i:x) cout<<i.first<<" "<<i.second<<"\n"; br;
#define input0(x) for(auto &i:x) cin>>i;
#define input1(x) for(auto &i:x) cin>>i.first>>i.second;
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define FIX cout<<fixed<<setprecision(12);
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ifn(x) if(!(x))
#define setbits(x) __builtin_popcountll(x)
#define tzerobits(x) __builtin_ctzll(x) //000001101(00) -> 2
#define lzerobits(x) __builtin_clzll(x) //(00000)110100 -> 5
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) ((x*y)/gcd(x,y))
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
typedef vector<pll> vll;
typedef pair<llint,string> pls;
typedef map<llint,llint> mll;
const uint uintMax=4294967295;          //+(1<<32) - 1
const int intMax=2147483647;            //+(1<<31) - 1
const int intMin=-2147483648;           //-(1<<31)
const ull ullMax=18446744073709551615;  //+(1<<64) - 1
const llint Max=9223372036854775807;    //+(1<<63) - 1
const llint Min=-9223372036854775808;   //-(1<<63)
////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

Stars: [06], [07], [08], [09], [10], [11], [12]

[01]. 1LL<<n;              // value of 2 raised to the power n;
[02]. a|=(1LL<<n);         // set nth bit in a;
[03]. a&=(~(1LL<<n));      // unset nth bit in a;
[04]. a^=(1LL<<n);         // toggle nth bit in a;
[05]. a&(1LL<<n);          // check if nth bit is set in a;
--
[06]. a=a^b^(b=a);         // swap values of a and b; OR a=a+b-(b=a);
--
[07]. K=((n^(n-1))+1)>>1;  // K is the value of rightmost 1 bit (lssb) in n;
[08]. K=n&(~(n-1));        // K is the value of rightmost 1 bit (lssb) in n;
[09]. K=n&(~(n+1))+1;      // K is the value of rightmost 0 bit (lsub) in n;
[10]. K=__builtin_ctzll(n) // K is the index of rightmost 1 bit (lssb) in n; (0-based indexing)
[11]. x|=x>>1,x|=x>>2,     // for 064 or less bits integer x, go upto x|=x>>32;
      x|=x>>4,x|=x>>8,     // for 128 or less bits integer x, go upto x|=x>>64;
      x|=x>>16,x|=x>>32,   // and so on...;
      x+=1,x>>=1; K=x      // x is the value of leftmost 1 bit (mssb) in n; same as floor(log2(x));
[12]. x=__builtin_clzll(n),// n must be 64 bits signed integer;
      K=63-x;              // K is the index of leftmost 1 bit (mssb) in n; (0-based indexing)
--

*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    llint t=1;
    cin>>t;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////