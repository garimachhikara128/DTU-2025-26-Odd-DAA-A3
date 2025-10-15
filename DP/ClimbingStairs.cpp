#include<iostream>

using namespace std ;

int climbingStairs(int curr, int n)
{
    if(curr == n)
        return 1 ;

    if(curr > n)
        return 0 ;

    int r1 = climbingStairs(curr+1, n) ;
    int r2 = climbingStairs(curr+2, n) ;
    int r3 = climbingStairs(curr+3, n) ;

    int res = r1+ r2+ r3 ;

    return res ;
}

int climbingStairsTD(int curr, int n, int *strg)
{
    if(curr == n)
        return 1 ;

    if(curr > n)
        return 0 ;

    if(strg[curr] != 0)
        return strg[curr] ;

    int r1 = climbingStairsTD(curr+1, n, strg) ;
    int r2 = climbingStairsTD(curr+2, n, strg) ;
    int r3 = climbingStairsTD(curr+3, n, strg) ;

    int res = r1+ r2+ r3 ;

    strg[curr] = res ;

    return res ;
}

// TC: O(n)
// SC: O(n)
int climbingStairsBU(int n)
{
    int *strg = new int[n+3] ;

    strg[n] = 1 ;
    strg[n+1] = 0 ;
    strg[n+2] = 0 ;

    for(int i = n-1 ; i >=0 ; i--)
    {
        strg[i] = strg[i+1] + strg[i+2] + strg[i+3] ;
    }

    return strg[0] ;

}

// TC: O(n)
// SC: O(1)
int climbingStairsBUSE(int n)
{
    int *strg = new int[3] ;
    strg[0] = 1 ;
    strg[1] = 0 ;
    strg[2] = 0 ;

    for(int slide = 1 ; slide <= n ; slide++)
    {
        int sum = strg[0] + strg[1] + strg[2] ;
        strg[2] = strg[1] ;
        strg[1] = strg[0] ; 
        strg[0] = sum ;
    }

    return strg[0] ;

}

int main()
{
    int n = 600000;
    // cout << climbingStairsTD(0, n, new int[n]) << endl ;
    cout << climbingStairsBU(n) << endl ;
    cout << climbingStairsBUSE(n) << endl ;

    return 0 ;
}
