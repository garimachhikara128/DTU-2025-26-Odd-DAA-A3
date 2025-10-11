#include<iostream>

using namespace std ;

int FibRec(int n)
{
    if(n == 0 || n == 1)
        return n ;

    int fnm1 = FibRec(n-1) ;
    int fnm2 = FibRec(n-2) ;

    int fn = fnm1 + fnm2 ;

    return fn ;
}

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

int main()
{
    int n = 600000 ;
    cout << FibTD(n, new int[n+1]) << endl ;

    return 0 ;

}