/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
//COMPILER SUPPORT : STD=GNU C++14 or ABOVE
#include <bits/stdc++.h>
using namespace std;
//OPTIMIZATION
#pragma GCC optimize("O2")
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
#define input2(x,n) rep0(i,0,n) llint inp,cin>>inp,x.insert(inp);
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
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
{
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~|I|N|D|E|X|~~~~~~~~~~~~~~~~~~~~~~~~~~~
    _________________________________________________________________
    |~~~S. NO.~~~||~~~~~~~~~~~~~ TITLE ~~~~~~~~~~~~~||~~~COMMENTS~~~|
    |------------||---------------------------------||--------------|
    |      1     ||Brian Kernighan’s Algorithm      ||popcountll    |
    |      2     ||Checks if ith bit is set         ||              |
    |      3(i)  ||Sieve of Eratothenes             ||              |
    |      3(ii) ||Sieve of Eratothenes             ||              |
    |      4     ||First k prime numbers using sieve||              |
    |      5     ||Improved Sieve                   ||              |
    |      6(i)  ||Bitwise Sieve                    ||              |
    |      6(ii) ||Bitwise Sieve                    ||              |
    |      7     ||Primality Test O(sqrt(n))        ||              |
    |      8     ||Prime Factorization              ||              |
    |      9     ||PRIME FACTORIZATION: (i) & (ii)  ||              |
    |     10     ||Divisors of a number             ||              |
    |     11     ||Smallest Prime Factor            ||              |
    |     12     ||Binary Exponentiation Recursive  ||              |
    |     13     ||Binary Exponentiation Iterative  ||              |
    |     14     ||Modular Binary Exponentiation    ||              |
    |            ||Recursive                        ||              |
    |     15     ||Modular Binary Exponentiation    ||              |
    |            ||Iterative                        ||              |
    |     16     ||Euclidean GCD                    ||              |
    |     17     ||MATRIX EXPONENTIATION: (i) & (ii)||              |
    |     18     ||Matrix Multiplication            ||              |
    |     19     ||Greatest power of 2 <= given num ||              |
    |     20     ||Rightmost set bit in given number||ctzll         |
    |     21     ||Binary string to decimal int     ||              |
    |     22     ||RADIX SORT                       ||only for +ve  |
    |     23     ||Number to string                 ||              |
    |     24     ||Extended Euclidean Algorithm     ||              |
    |     25     ||MODULAR MULTIPLICATIVE INVERSE:  ||gcd(a,b)==1   |
    |            ||(i) & (ii)                       ||              |
    |     26     ||                                 ||              |
    |     27     ||                                 ||              |
    =================================================================
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~|||||||||||~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                                        by:codechaser
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Brian Kernighan’s Algorithm
//counts the number of set bits in the passed number;
//Alternative to __builtin_popcountll(n);
llint setBits(llint n){
    llint count=0;
    while(n){
        n&=(n-1);
        count++;
    }
    return count;
}
//CHECKED
//======================================================

//checks if the bit at ith index is set;
bool iBit(llint n, llint i){
    return (n>>i)&1;
}
//CHECKED
//======================================================

//Sieve of Eratothenes 
//***PASSED VECTOR MUST BE INITIALIZED WITH ZEROES***//
//Time Complexity: O(n(log(log(n))))
//changes prime indices inside the passed vector to 1 and rest 0;
void sieve(vector<bool>& v){
	llint n=v.size();
    v[0]=v[1]=false;
    for(llint i=2;(i*i)<n;i++){
        if(!v[i]) continue;
        for(llint j=(i*i);j<n;j+=i) 
            v[j]=false;
    }
    return;
}
//CHECKED
//======================================================

//Sieve of Erastothenes
//Time Complexity: O(n(log(log(n))))
//fills all the prime numbers upto n(inclusive) into the passed vector;
void sieve(vector<llint>& primes, llint n){
    vector<bool> v(n+1,true);
    v[0]=v[1]=false;
    for(llint i=2;(i*i)<n;i++){
        if(!v[i]) continue;
        for(llint j=(i*i);j<n+1;j+=i) 
            v[j]=false;
    }
    for(llint i=0;i<n+1;i++)
        if(v[i]) primes.pb(i);
    return;
}
//CHECKED
//======================================================

//First k prime numbers using sieve
vector<llint> sieve(llint k){
    llint n=k*10,count=0;
    vector<bool> v(n>>1,true);
    vector<llint> primes;
    //for 1 isn't prime;
    v[0]=false;
    for(llint i=3;(i*i)<n;i+=2){
        if(!(v[i>>1])) continue;
        for(llint j=i*i;j<n+1;j+=(i<<1))
            v[j>>1]=false;
    }
    //in vector v, ith index tells if (2*i+1) is prime;
    primes.pb(2);
    for(llint i=1;i<n+1&&count<k;i+=2)
        if(v[i>>1]) primes.pb(i),count++;
    return primes;
}
//CHECKED
//======================================================

//Improved Sieve (iterations over even numbers removed)
//fills all the prime numbers upto n(inclusive) into the passed vector;
void sieve(vector<llint>& primes, llint n){
    vector<bool> v(n>>1,true);
    //for 1 isn't prime;
    v[0]=false;
    for(llint i=3;(i*i)<n;i+=2){
        if(!(v[i>>1])) continue;
        for(llint j=i*i;j<n+1;j+=(i<<1))
            v[j>>1]=false;
    }
    //in vector v, ith index tells if (2*i+1) is prime;
    primes.pb(2);
    for(llint i=1;i<n+1;i+=2)
        if(v[i>>1]) primes.pb(i);
    return;
}
//CHECKED
//======================================================

//Bitwise Sieve (size of unsigned long long vector can be reduced to (n-3)/128 from n/2 using jth bit of ith long long to denote ((64*(i-1)+j)+3)th number);
//0th bit represents 3, 1st bit represents 5, 2nd bit represents 7, 3rd bit represents 9 and so on...
//0 1 2 3 4  5  6  7  8  9  10 11 12 13 14 15 16 17
//1 1 1 0 1  1  0  1  1  0  1  0  0  1  1  0  0  1
//3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37
//jth bit of ith long long tells whether ((64*i + j)*2 + 3) is prime or not;
vector<llint> bitwiseSieve(llint n){
    vector<llint> primes;
    if(n<2) return;
    vector<ull> v(ceil((ld)n/128),ullMax);
    for(llint i=3;i*i<n+1;i+=2){
        if(!(v[ceil((ld)i/128)-1]&(((ull)1)<<((i>>1)&63)))) continue; //here (i-1)>>1 will be equivalent to i>>1;
        for(llint j=i*i;j<n+1;j+=(i<<1))
            v[ceil((ld)j/128)-1]=((v[ceil((ld)j/128)-1])|((((ull)1)<<((j>>1)&63))))-(((ull)1)<<((j>>1)&63));
    }
    primes.pb(2);
    for(llint i=3;i<n+1;i+=2)
        if((v[ceil((ld)i/128)-1]&(((ull)1)<<((i>>1)&63)))) primes.pb(i);
    return primes;
}
//CHECKED
//======================================================

//Improved Bitwise Sieve
vector<llint> bitwiseSieve(llint n){
    vector<llint> primes;
    if(n<2) return primes;
    vector<ull> v(ceil(((ld)n-2.0)/128),ullMax);
    for(llint i=3;i*i<n;i+=2){
        if(!(v[ceil(((ld)i-2.0)/128)-1]&(((ull)1)<<(((i-3)>>1)&63)))) continue;        
        for(llint j=i*i;j<n+1;j+=(2*i))
            v[ceil(((ld)j-2.0)/128)-1]=((v[ceil(((ld)j-2.0)/128)-1]|(((ull)1)<<(((j-3)>>1)&63)))-(((ull)1)<<(((j-3)>>1)&63)));
    }
    primes.pb(2);
    for(llint i=3;i<n+1;i+=2)
        if((v[ceil(((ld)i-2.0)/128)-1]&(((ull)1)<<(((i-3)>>1)&63)))) primes.pb(i);
    return primes;
}
//CHECKED
//======================================================

//Primality Test
//checks if the given number is prime or not in O(sqrt(n));
bool isPrime(llint n){
    if(n<=1) return false;
    for(llint i=2;i*i<=n;i++)
        if(!(n%i)) return false;
    return true;
}
//CHECKED
//======================================================

//Prime Factorization
//returns all the prime factors of a number in a map as key and their exponents as the corresponding value;

// Explanation for not checking beyond sqrt(n): there can't be more than one prime factor:
// of (n) beyond sqrt(n) for obvious reasons, and that one prime factor also:
// (if it exists) can have exponent 1 at max and if there's just one prime factor of:
// (n) beyond sqrt(n), it will be considered in the second last line of code;
map<llint,llint> prmFactors(llint n){
    map<llint,llint> primeFactors;
    if(!(n&1)) primeFactors[2]=__builtin_ctzll(n),n>>=__builtin_ctzll(n);
    for(llint i=3;(i*i)<=n;i+=2){
        if(n%i) continue;
        llint exp=0;
        while(!(n%i)) exp++,n/=i;
        primeFactors[i]=exp;
    }
    if(n>1) primeFactors[n]=1;
    return primeFactors;
}
//CHECKED
//======================================================

//PRIME FACTORIZATION
//returns a vector with prime factors of the given number filled in it;
//eg: for n=4500, it returns {2,2,3,3,5,5,5}

//(i)  SPF
//returns a vector with each index filled with it's smallest prime factor upto n;
vector<llint> spf(llint n){
    vector<llint> v(n+1,1);
    for(llint i=0;i<n+1;i+=2) v[i]=2; 
    for(llint i=3;i<n+1;i+=2) if(v[i]==1) for(llint j=i;j<n+1;j+=(i<<1)) if(v[j]==1) v[j]=i;
    return v;
}

//(ii) Prime Factorization
vector<llint> prmFactors(llint n){
    vector<llint> primeFactors;
    vector<llint> v=spf(n);
    while(n!=1) primeFactors.pb(v[n]),n/=v[n];
    return primeFactors;
}
//CHECKED
//======================================================

//Divisors of a number
vector<llint> divisors(llint n){
    vector<llint> v;
    for(llint i=1;i*i<n;i++) if(!(n%i)) v.pb(i),v.pb(n/i);
    if(ceil(sqrt(n))==sqrt(n)) v.pb(sqrt(n));
    sort(v.begin(),v.end());
    return v;
}
//CHECKED
//======================================================


//Smallest Prime Factor using sieve
//returns a vector with each index filled with it's smallest prime factor upto n;
vector<llint> spf(llint n){
    vector<llint> v(n+1,1);
    for(llint i=0;i<n+1;i+=2) v[i]=2;
    for(llint i=3;i<n+1;i+=2) if(v[i]==1) for(llint j=i;j<n+1;j+=(i<<1)) if(v[j]==1) v[j]=i;
    return v;
}
//CHECKED
//======================================================

//Binary Exponentiation Recursive
llint power(llint n, llint exp){
    if(exp==1) return n;
    if(exp==0) return 1;
    if(exp&1) return n*power(n,exp-1);
    return power(n*n,exp>>1);
}
//CHECKED
//======================================================

//Binary Exponentiation Iterative
llint power(llint n, llint exp){
    llint res=1;
    while(exp){
        if(exp&1) res*=n,exp--;
        else n*=n,exp>>=1;
    }
    return res;
}
//CHECKED
//======================================================

//Modular Binary Exponentiation Recursive
llint power(llint n, llint exp, llint mod){
    if(exp==1) return n%mod;
    if(exp==0) return 1;
    if(exp&1) return ((n%mod)*(power(n,exp-1,mod)%mod))%mod;
    return power(((n%mod)*(n%mod))%mod,exp>>1,mod)%mod;
}
//CHECKED
//======================================================

//Modular Binary Exponentiation Iterative
llint power(llint n, llint exp, llint mod){
    llint res=1;
    while(exp){
        if(exp&1) res=(res*(n%mod))%mod,exp--;
        else n=((n%mod)*(n%mod))%mod,exp>>=1;
    }
    return (res%mod);
}
//CHECKED
//======================================================

//Euclidean GCD
//returns GCD of given numbers;
llint gcd(llint a, llint b){
    if(!a) return b;
    return gcd(b%a,a);
}
//CHECKED
//======================================================

//MATRIX EXPONENTIATION
//(i)  Matrix Multiplication
vector<vector<llint>> matPdt(vector<vector<llint>>& mat1, vector<vector<llint>>& mat2){
    llint r1=mat1.size(),c1=mat1[r1-1].size(),r2=mat2.size(),c2=mat2[r2-1].size();
    vector<vector<llint>> result(r1,vector<llint>(c2,0));
    if(c1!=r2 && c2==r1) matPdt(mat2,mat1);
    else if (c1==r2){
        for(llint i=0;i<r1;i++) for(llint j=0;j<c2;j++) for(llint k=0;k<(c1+r2)/2;k++) result[i][j]+=((mat1[i][k])*(mat2[k][j]));
        return result;
    }
    return result; 
}
//(ii) Matrix Exponentiation
vector<vector<llint>> matExp(vector<vector<llint>>& N, llint exp){
    llint d=N.size();
    vector<vector<llint>> result(d,vector<llint>(d,0));
    for(llint i=0;i<d;i++) result[i][i]=1;
    while(exp){
        if(exp&1) result=matPdt(result,N),exp--;
        N=matPdt(N,N);
        exp>>=1;
    }
    return result;
}
//CHECKED
//======================================================

//Matrix Multiplication
vector<vector<llint>> matPdt(vector<vector<llint>>& mat1, vector<vector<llint>>& mat2){
    llint r1=mat1.size(),c1=mat1[r1-1].size(),r2=mat2.size(),c2=mat2[r2-1].size();
    vector<vector<llint>> result(r1,vector<llint>(c2,0));
    if(c1!=r2 && c2==r1) matPdt(mat2,mat1);
    else if (c1==r2){
        for(llint i=0;i<r1;i++) for(llint j=0;j<c2;j++) for(llint k=0;k<(c1+r2)/2;k++) result[i][j]+=((mat1[i][k])*(mat2[k][j]));
        return result;
    }
    return result; 
}
//CHECKED
//======================================================

//returns the greatest power of 2 <= given number in constant time;
//OR
//returns the value of leftmost set bit i.e. most significant set bit;
llint leftmostSetBit(llint n){
    n=(n|n>>1);
    n=(n|n>>2);
    n=(n|n>>4);
    n=(n|n>>8);
    n=(n|n>>16);
    n=(n|n>>32);
    //if the required result was r, then, the value of n has now become 2*r-1;
    return ((n+1)>>1);
}
//CHECKED
//======================================================

//returns the greatest exponent of 2 that divides the passed number in O(log2(n));
//OR
//returns the index of rightmost set bit i.e. least significant set bit;
//OR
//returns the number of zeroes appearing before the least significant set bit;
//Alternative to __builtin_ctzll(n);
llint rightmostSetBit(llint n){
    llint exp=0;
    while(!(n&1)) exp++,n>>=1;
    return exp;
}
//CHECKED
//======================================================

//returns the decimal equivalent of a binary string;
llint binStrToNum(string s){
    llint res=0;
    rep0(i,0,s.size()) if(s[i]-'0') res+=((1<<(s.size()-1-i)));
    return res;
}
//CHECKED
//======================================================

//RADIX SORT
//(i)  binary exponentiation;
llint power(llint n, llint exp){
    llint res=1;
    while(exp){
        if(exp&1) res*=n,exp--;
        else n*=n,exp>>=1;
    }
    return res;
}
//(ii) Radix Sort;
//NOTE: try to keep order between 1 & 3 (incl.);
//NOTE: it considers absolute value of all the numbers while sorting;
//      i.e. {-2,0,1,3,4} will convert to {0,1,-2,3,4};
void rsort(vector<llint>& v, llint order){
    if(!v.size()) return;
    llint n=v.size(),maximum=abs(v[0]);
    rep0(i,1,n) maximum=max(maximum,abs(v[i]));
    ifn(maximum) return;
    llint k=log10(maximum)+1;
    rep0(i,0,ceil((double)k/order)){
        vector<vector<llint>> record(power(10,order));
        rep0(j,0,n) (record[(llint)abs((llint)((v[j])%((llint)power(10,order*(i+1))))/power(10,order*i))]).pb(v[j]);
        llint counter=0;
        rep0(j,0,power(10,order)) for(auto k:record[j]) v[counter]=k,counter++;
    }
    return;
}
//CHECKED
//======================================================
//NOTE:- If you wanna sort any map using this, just convert the map into vector<pair<llint,llint>>;
//and do some required changes in the algorithm above and you will be ready to go;
//======================================================

//NUMBER TO STRING
//(i)  binary exponentiation;
llint power(llint n, llint exp){
    llint res=1;
    while(exp){
        if(exp&1) res*=n,exp--;
        else n*=n,exp>>=1;
    }
    return res;
}
//(ii) number to string form converter;
string numToStr(llint n){
    llint digits=log10(n)+1;
    string s;
    rep0(i,0,digits) s.pb((char)floor((n%(power(10,digits-i)))/power(10,digits-i-1))+'0');
    return s;
}
//CHECKED
//======================================================

//Extended Euclidean Algorithm
llint gcdExt(llint a, llint b, llint& x, llint& y){
    if(!a){
        x=0,y=1;
        return b;
    }
    int x1,y1,g=gcdExt(b%a,a,x1,y1);
    y=x1;
    x=y1-(b/a)*y;
    return g;
}
//NOTE:- x,y might be negative as well;
//CHECKED
//======================================================

//MODULAR MULTIPLICATIVE INVERSE
//(i)  Extended Euclidean Algorithm
llint gcdExt(llint a, llint b, llint& x, llint& y){
    if(!a){
        x=0,y=1;
        return b;
    }
    llint x1,y1,g=gcdExt(b%a,a,x1,y1);
    y=x1;
    x=y1-(b/a)*y;
    return g;
}
//(ii) Modular Multiplicative Inverse
//returns modular multiplicative inverse of 'a' under mod 'b';
llint modInv(llint a, llint b){
    llint x,y;
    gcdExt(a,b,x,y);
    return x%b;
}
//NOTE:- makes sense iff gcd(a,b)==1;
//CHECKED
//======================================================

////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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

