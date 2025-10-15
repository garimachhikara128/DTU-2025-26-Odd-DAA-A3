#include<iostream>

using namespace std ;

// TC: 2^N
// SC: N
int FibRec(int n)
{
    if(n == 0 || n == 1)
        return n ;

    int fnm1 = FibRec(n-1) ;
    int fnm2 = FibRec(n-2) ;

    int fn = fnm1 + fnm2 ;

    return fn ;
}

// TC: N
// SC: N
int FibTD(int n, int *strg)
{
    if(n == 0 || n == 1)
        return n ;

    if(strg[n] != 0) // re-use
        return strg[n] ;

    int fnm1 = FibTD(n-1, strg) ;
    int fnm2 = FibTD(n-2, strg) ;

    int fn = fnm1 + fnm2 ;

    strg[n] = fn ; // store

    return fn ;
}

// TC: N
// SC: N
int FibBU(int n)
{
    // n+1 size array create
    int *strg = new int[n+1] ;

    // TD bc -> BU already fill
    strg[0] = 0 ;
    strg[1] = 1 ;

    // filling drn
    for(int i = 2 ; i <= n ; i++)
        strg[i] = strg[i-1] + strg[i-2] ;

    // final answer store index
    return strg[n] ;

}

// TC: N
// SC: constant
int FibBUSE(int n)
{
    int *strg = new int[2] ;

    strg[0] = 0 ;
    strg[1] = 1 ;

    for(int slide = 1 ; slide <= n-1 ; slide++)
    {
        int sum = strg[0] + strg[1] ;
        strg[0] = strg[1] ;
        strg[1] = sum ;
    }

    return strg[1] ;
}

int main()
{
    int n = 600000 ;
    // cout << FibTD(n, new int[n+1]) << endl ;
    cout << FibBU(n) << endl ;
    cout << FibBUSE(n) << endl ;
    return 0 ;

}