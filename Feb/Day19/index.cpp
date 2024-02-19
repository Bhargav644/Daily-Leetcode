#include <bits/stdc++.h>
// -----------Solution 1: Using Remainder-divident methods --------------

bool isPowerOfTwo(int n){
    if(n<=0) return false;
    while(n%2==0) n/=2;
    return n==1;
}

// -----------Solution 2: Using Rcursion --------------------

bool isPowerOfTwo(int n){
    if(n<=0) return false;
    return (n==1 || (n%2==0 && isPowerOfTwo(n/2)));
}


// -----------Solution 3: Bit Manipulation ------------------

bool isPowerOfTwo(int n){
    if(n<=0) return false;
    return ((n&(n-1))==0);
}


// -----------Solution 4: Bit Manipulation ----------------

bool isPowerOfTwo(int n){
    if(n<=0) return false;
    return (ceil(log2(n))==floor(log2(n)));
}


// -----------Solution 5: Using STL ----------------

bool isPowerOfTwo(int n){
    if(n<0) return false;
    int bits=__builtin_popcount(n);
    if(bits==1) return true;
    return false;
}
