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
template<const llint MOD>
class MLLINT{
private:
    llint value;
public:
    MLLINT(llint value=0);

//assignment operator (" = ")
    llint operator=(llint);
    MLLINT operator=(MLLINT);
//---------------------------

//arithmetic binary operators
    MLLINT operator+(llint);
    MLLINT operator+(MLLINT);
    MLLINT operator+(bool);
    MLLINT operator-(llint);
    MLLINT operator-(MLLINT);
    MLLINT operator-(bool);
    MLLINT operator*(llint);
    MLLINT operator*(MLLINT);
    MLLINT operator*(bool);
    MLLINT operator/(llint);
    MLLINT operator/(MLLINT);
    MLLINT operator/(bool);
    MLLINT operator+=(llint);
    MLLINT operator+=(MLLINT);
    MLLINT operator+=(bool);
    MLLINT operator-=(llint);
    MLLINT operator-=(MLLINT);
    MLLINT operator-=(bool);
    MLLINT operator*=(llint);
    MLLINT operator*=(MLLINT);
    MLLINT operator*=(bool);
    MLLINT operator/=(llint);
    MLLINT operator/=(MLLINT);
    MLLINT operator/=(bool);
//---------------------------

//arithmetic unary operators
//prefix incr./dec. operators)
    MLLINT operator++();
    MLLINT operator--();
//---------------------------
//postfix inc./dec. operators
    MLLINT operator++(int);
    MLLINT operator--(int);
//---------------------------
//---------------------------
    
//modular binary operators
    MLLINT operator%(llint);
    MLLINT operator%(MLLINT);
    MLLINT operator%(bool);
    MLLINT operator%=(llint);
    MLLINT operator%=(MLLINT);
    MLLINT operator%=(bool);
//---------------------------

//bitwise binary operators
    MLLINT operator&(llint);
    MLLINT operator&(MLLINT);
    MLLINT operator&(bool);
    MLLINT operator|(llint);
    MLLINT operator|(MLLINT);
    MLLINT operator|(bool);
    MLLINT operator^(llint);
    MLLINT operator^(MLLINT);
    MLLINT operator^(bool);
    MLLINT operator<<(llint);
    MLLINT operator<<(MLLINT);
    MLLINT operator<<(bool);
    MLLINT operator>>(llint);
    MLLINT operator>>(MLLINT);
    MLLINT operator>>(bool);
    MLLINT operator&=(MLLINT);
    MLLINT operator&=(llint);
    MLLINT operator&=(bool);
    MLLINT operator|=(llint);
    MLLINT operator|=(MLLINT);
    MLLINT operator|=(bool);
    MLLINT operator^=(llint);
    MLLINT operator^=(MLLINT);
    MLLINT operator^=(bool);
    MLLINT operator<<=(llint);
    MLLINT operator<<=(MLLINT);
    MLLINT operator<<=(bool);
    MLLINT operator>>=(llint);
    MLLINT operator>>=(MLLINT);
    MLLINT operator>>=(bool);
//---------------------------

//bitwise unary operator ("~")
    MLLINT operator~();
//---------------------------
    
//logical binary operators
    bool operator&&(llint);
    bool operator&&(MLLINT);
    bool operator&&(bool);
    bool operator||(llint);
    bool operator||(MLLINT);
    bool operator||(bool);
//---------------------------

//logical unary operator ("!")
    bool operator!();
//---------------------------

//comparison binary operators
    bool operator==(llint);
    bool operator==(MLLINT);
    bool operator==(bool);
    bool operator!=(llint);
    bool operator!=(MLLINT);
    bool operator!=(bool);
    bool operator<(llint);
    bool operator<(MLLINT);
    bool operator<(bool);
    bool operator<=(llint);
    bool operator<=(MLLINT);
    bool operator<=(bool);
    bool operator>(llint);
    bool operator>(MLLINT);
    bool operator>(bool);
    bool operator>=(llint);
    bool operator>=(MLLINT);
    bool operator>=(bool);
//---------------------------

//istream & ostream operators
    template<const llint M>
    friend ostream& operator<<(ostream&, MLLINT<M>);
    template<const llint M>
    friend istream& operator>>(istream&, MLLINT<M>&);
//---------------------------
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<const llint MOD>
MLLINT<MOD>::MLLINT(llint value):value((value<0)?(((value%MOD)+MOD)%MOD):(value%MOD)){
}

//assignment operator (" = ")
template<const llint MOD>
MLLINT<MOD> MLLINT<MOD>::operator=(MLLINT<MOD> A){
    value=A.value;
    return A;
}

template<const llint MOD>
llint MLLINT<MOD>::operator=(llint A){
    value=(A%MOD);
    if(value<0) value+=MOD;
    return A;
}
//---------------------------

//arithmetic binary operators
template<const llint MOD>
MLLINT<MOD> MLLINT<MOD>::operator+(llint A){
    MLLINT<MOD> B(A);
    (B.value)-=(MOD-value);
    if(B.value<0) B.value+=MOD;
    return B;
}

template<const llint MOD>
MLLINT<MOD> MLLINT<MOD>::operator+(MLLINT<MOD> A){
    // A.value-=(MOD-value);
    // if(A.value<0) A.value+=MOD;
    return (*this)+A.value;
}

template<const llint MOD>
MLLINT<MOD> MLLINT<MOD>::operator+(bool A){
    return (*this)+(llint)A;
}

template<const llint MOD>
MLLINT<MOD> MLLINT<MOD>::operator-(llint A){
    MLLINT<MOD> B(A);
    B.value=value-B.value;
    if(B.value<0) B.value+=MOD;
    return B;
}

template<const llint MOD>
MLLINT<MOD> MLLINT<MOD>::operator-(MLLINT<MOD> A){
    A.value=value-A.value;
    if(A.value<0) A.value+=MOD;
    return A;
}

template<const llint MOD>
MLLINT<MOD> MLLINT<MOD>::operator-(bool A){
    return (*this)-(llint)A;
}

template<const llint MOD>
MLLINT<MOD> operator*(llint A){
    MLLINT<MOD> B;
    return B;
}

/*
template<const llint MOD>
MLLINT operator*(MLLINT){
    
}
template<const llint MOD>
MLLINT operator*(bool){

}
template<const llint MOD>
MLLINT operator/(llint){

}
template<const llint MOD>
MLLINT operator/(MLLINT){

}
template<const llint MOD>
MLLINT operator/(bool){

}
template<const llint MOD>
MLLINT operator+=(llint){

}
template<const llint MOD>
MLLINT operator+=(MLLINT){

}
template<const llint MOD>
MLLINT operator+=(bool){

}
template<const llint MOD>
MLLINT operator-=(llint){

}
template<const llint MOD>
MLLINT operator-=(MLLINT){

}
template<const llint MOD>
MLLINT operator-=(bool){

}
template<const llint MOD>
MLLINT operator*=(llint){

}
template<const llint MOD>
MLLINT operator*=(MLLINT){

}
template<const llint MOD>
MLLINT operator*=(bool){

}
template<const llint MOD>
MLLINT operator/=(llint){

}
template<const llint MOD>
MLLINT operator/=(MLLINT){

}
template<const llint MOD>
MLLINT operator/=(bool){

}
//---------------------------
*/

//arithmetic unary operators
//prefix incr./dec. operators)
template<const llint MOD>
MLLINT<MOD> MLLINT<MOD>::operator++(){
    (this->value)++;
    (this->value)%=MOD;
    return *this;
}

template<const llint MOD>
MLLINT<MOD> MLLINT<MOD>::operator--(){
    (this->value)--;
    (this->value)%=MOD;
    if((this->value)<0) (this->value)+=MOD;
    return *this;
}
//---------------------------
//postfix inc./dec. operators
template<const llint MOD>
MLLINT<MOD> MLLINT<MOD>::operator++(int){
    MLLINT<MOD> backup=*this;
    (this->value)++;
    (this->value)%=MOD;
    return backup;
}

template<const llint MOD>
MLLINT<MOD> MLLINT<MOD>::operator--(int){
    MLLINT<MOD> backup=*this;
    (this->value)--;
    (this->value)%=MOD;
    if((this->value)<0) (this->value)+=MOD;
    return backup;
}
//---------------------------
//---------------------------

/*
//modular binary operators
MLLINT operator%(llint);
MLLINT operator%(MLLINT);
MLLINT operator%(bool);
MLLINT operator%=(llint);
MLLINT operator%=(MLLINT);
MLLINT operator%=(bool);
//---------------------------

//bitwise binary operators
MLLINT operator&(llint);
MLLINT operator&(MLLINT);
MLLINT operator&(bool);
MLLINT operator|(llint);
MLLINT operator|(MLLINT);
MLLINT operator|(bool);
MLLINT operator^(llint);
MLLINT operator^(MLLINT);
MLLINT operator^(bool);
MLLINT operator<<(llint);
MLLINT operator<<(MLLINT);
MLLINT operator<<(bool);
MLLINT operator>>(llint);
MLLINT operator>>(MLLINT);
MLLINT operator>>(bool);
MLLINT operator&=(MLLINT);
MLLINT operator&=(llint);
MLLINT operator&=(bool);
MLLINT operator|=(llint);
MLLINT operator|=(MLLINT);
MLLINT operator|=(bool);
MLLINT operator^=(llint);
MLLINT operator^=(MLLINT);
MLLINT operator^=(bool);
MLLINT operator<<=(llint);
MLLINT operator<<=(MLLINT);
MLLINT operator<<=(bool);
MLLINT operator>>=(llint);
MLLINT operator>>=(MLLINT);
MLLINT operator>>=(bool);
//---------------------------

//bitwise unary operator ("~")
MLLINT operator~();
//---------------------------

//logical binary operators
bool operator&&(llint);
bool operator&&(MLLINT);
bool operator&&(bool);
bool operator||(llint);
bool operator||(MLLINT);
bool operator||(bool);
//---------------------------

//logical unary operator ("!")
bool operator!();
//---------------------------
*/

//istream & ostream operators
template<const llint MOD>
ostream& operator<<(ostream& cout, MLLINT<MOD> A){
    cout<<A.value;
    return cout;
}

template<const llint MOD>
istream& operator>>(istream& cin, MLLINT<MOD>& A){
    cin>>A.value;
    A.value%=MOD;
    if(A.value<0) A.value+=MOD;
    return cin;
}
//---------------------------

////////////////////////////////////////////////////////////////////////////////////////////////////////////
inline void codechaser(){
    MLLINT<100> a(-10223);
    MLLINT<100> b(-129);
    MLLINT<100> c=a+b; 
    cout<<c<<endl;
    cin>>a;
    cout<<--a<<endl<<a--<<endl<<c+a-10<<endl;
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
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////