#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) x.begin(),x.end()
#define printv(x) for(auto i:x)cout<<i<<" "
#define nl cout<<endl
#define inputv(x) for(ll i=0;i<n;i++)cin>>x[i];

//FOR ORDERED SET
//template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
const int mod=1e9+7;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

bool isprime(ll num){
    for(ll i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }

    return true;
}

ll power(ll a,ll b){
    if(b==0){
        return 1;
    }
    ll half=power(a,b/2);
    if(b%2==0){
        return (half*half)%mod;
    }
    else
    {
        return ((half*half)%mod * (a%mod)) % mod;
    }  
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //Even or odd
    int a=3;
    int least_significant=a&1;
    if(least_significant==1){
        cout<<"odd";
    }
    else
    {
        cout<<"even";
    }

    //Power of two
    a=6;
    if(a==0)cout<<"NOT A POWER OF 2";//Explicitly this edge case should be handled
    if(a & (a-1)){
        cout<<"NOT A POWER OF 2";
    }
    else
    {
        cout<<"YES";
    }

    //Manipulating kth(least_significant) bit=>toggling,set and unset
    a=10;
    int k=2;//bits start from 0
    //10 = 1010 , 2 bit from last will be 0
    int toggle_a=a^(1<<k);
    cout<<endl<<toggle_a;

    int set_k=a | (1<<k);
    cout<<endl<<set_k;

    int unset_k=a & ~(1<<k);
    cout<<endl<<unset_k;

    //Multiplication and division by a power of two
    a=10;
    //b=8 ,for this k=3
    k=3;
    int mul=a<<k;
    int div=a>>k;
    cout<<endl<<mul;
    cout<<endl<<div;

    //finding a % 2^k ,i.e a is the kth power of 2 or not
    a=128;
    k=7;
    cout<<endl<<(1<<k);
    int yeah=a & ((1<<k)-1);
    if(yeah==0)yes();
    else no();

    //Swap numbers
    a=10;
    int b=20;

    a=a^b;
    b=a^b;
    a=a^b;
    cout<<endl<<a<<'\t'<<b;

    //Property of set bits:
    //number of set bits in A=x and
    //number of set bits in B=y and
    //number of set bits in A^B=z then
    //if z is even if x+y is even
    //and z is odd if x=y is odd

    //Toggling b/w two numbers

    // if(x==a){
    //     x=b
    // }
    // else if(x==b){
    //     x=a;
    // }

    //The above code can be written as:

    //x=x^a^b;

    



    

    //Count number of set bits in x=>O(1) approach
    a=7;
    int set_bits=__builtin_popcount(a);
    // if a is long long then use __builtin_popcountll(a)
    cout<<endl<<set_bits;


}
