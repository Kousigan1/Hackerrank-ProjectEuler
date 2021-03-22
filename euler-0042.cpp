// ////////////////////////////////////////////////////////
// # Title
// Coded triangle numbers
//
// # URL
// https://projecteuler.net/problem=42
// http://euler.stephan-brumme.com/42/
//
// # Problem
// The nth term of the sequence of triangle numbers is given by, `t_n = frac{n(n+1)}{2}`; so the first ten triangle numbers are:
//
// 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
//
// By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value.
// For example, the word value for SKY is 19 + 11 + 25 = 55 = `t_10`. If the word value is a triangle number then we shall call the word a triangle word.
//
// Using [words.txt](https://projecteuler.net/project/resources/p042_words.txt) (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?
//
// # Solved by
// Stephan Brumme
// February 2017
//
// # Algorithm
// My function ''getTriangle'' returns either ''NoTriangle = -1'' or the triangle index if the parameter ''x'' is a triangle number.
// E.g. ''getTriangle(55) = 10''.
//
// I use my own approximation formula for the triangle index which can be derived as follows:
// A triangle number `t_n` is a defined as
// `t_n = n (n + 1) / 2`
//
// Ff `x` is such a triangle number `t_n` then
// ` x = n (n + 1) / 2`
// `2x = n (n + 1)`
// `2x = n^2 + n`
//
// For any `a^2` we know for `a`'s successor
// `(a + 1)^2 = a^2 + 2a + 1`
//
// Therefore the relationship:
// `n^2 <  n^2 + n < n^2 + 2n + 1`
// `n^2 <    2x    < (n + 1)^2`
// ` n  < sqrt{2x} < (n + 1)^2`
//
// In order to find the triangle index `n`, I just compute `n = sqrt{2x}`.
// If `t_n = n (n + 1) / 2 = x` then `n` is indeed what we were looking for - else the function returns ''-1''.
//
// # Note
// Solving the quadratic equation leads to the same result:
// `t_n = x`
// `x = n (n + 1) / 2`
// `x = (n^2 + n) / 2`
// `2x = n^2 + n`
// `0 = n^2 + n - 2x`
//
// `n` must be positive so only one solution is left:
// `n = frac{sqrt{1 + 8x} - 1}{2}`
//
// In the end you have to check this result as well: only if it an integer then `n` is our result.
//
// Project Euler's file can be easily parsed in C++.
// Initially I included it in my source code (which works flawlessly) but then decided to read from STDIN.
//
// # Hackerrank
// I just have to check numbers whether they are triangle numbers or not.
// The major problem was that input values can be up to `10^18`.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(a,b,c)                for(int a=b;a<c;a++)
#define s(x)                    scanf("%d",&x);
#define sl(x)                   scanf("%lld",&x);
#define p(x)                    printf("%d\n",x);
#define p2(x,y)                 printf("%d %d\n",x,y);
#define pl(x)                   printf("%lld\n",x);
#define pl2(x,y)                printf("%lld %lld\n",x,y);
#define p1d(a,n)                for(int ix=0;ix<n;ix++) printf("%d ",a[ix]); printf("\n");
#define p2d(a,n,m)              for(int ix=0;ix<n;ix++){ for(int jx=0;jx<m;jx++) printf("%d ",a[ix][jx]); printf("\n");}
void input(){
    #ifdef Megamind
            #define DEBUG
            #define TRACE
            freopen("inp.txt","r",stdin);
            //freopen("out1.txt","w",stdout);
    #endif
}
#ifdef TRACE
    #define trace(x)                       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
    #define trace2(x,y)                    cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
    #define trace3(x,y,z)                  cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
#else
    #define trace(x)
    #define trace2(x,y)
    #define trace3(x,y,z) 
#endif

inline ll power(ll a, ll b, ll m) {
    ll r = 1;
    while(b) {
        if(b & 1) r = r * a % m;
        a = (a * a)% m;
        b >>= 1;
    }
    return r;
}
inline ll power(ll a, ll b) {
     ll r = 1;
    while(b) {
        if(b & 1) r = r * a ;
        a = a * a;
        b >>= 1;
    }
    return r;
}
 
/*........................................................END OF TEMPLATES.......................................................................*/

ll findroot(ll num){
	ll low = 0, high = 10000000003,mid;
	
	while(low<high){
		mid = (low+high)/2;
		
		if(mid*mid == num) return mid;
		if(mid*mid < num)  low = mid+1;
		else               high = mid;
	}
	
	return -1;
}


int main(){
	input();
	int t;
	ll v;
	s(t);
	while(t--){
		sl(v);
		ll squareroot = (findroot(1 + 8*v) - 1)/2;
        
		if(squareroot*(squareroot+1)/2 != v) puts("-1");
		else 				                 pl(squareroot);
	}
	
	#ifdef Megamind
		cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    #endif
}
