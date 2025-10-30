#include<iostream>

using namespace std ;

int CT_Rec(int n)
{
    if(n <= 1)
        return 1 ;

    int ans = 0 ;

    for(int i = 1 ; i <= n ; i++)
    {
        int left_bsts = CT_Rec(i-1) ;
        int right_bsts = CT_Rec(n-i) ;

        int total = left_bsts * right_bsts ;
        ans += total ;
    }

    return ans ;
}

int CT_TD(int n, int *strg)
{
    if(n <= 1)
        return 1 ;

    if(strg[n] != 0)
        return strg[n] ;

    int ans = 0 ;

    for(int i = 1 ; i <= n ; i++)
    {
        int left_bsts = CT_TD(i-1, strg) ;
        int right_bsts = CT_TD(n-i, strg) ;

        int total = left_bsts * right_bsts ;
        ans += total ;
    }

    strg[n] = ans ;

    return ans ;
}

int CT_BU(int tn)
{
    int *strg = new int[tn+1] ;
    strg[0] = strg[1] = 1 ;

    for(int n = 2 ; n <= tn ; n++)
    {
        int ans = 0 ;

        for(int i = 1 ; i <= n ; i++)
        {
            int left_bsts = strg[i-1] ;
            int right_bsts = strg[n-i] ;

            int total = left_bsts * right_bsts ;
            ans += total ;
        }

        strg[n] = ans ;
    }

    // catalan series print
    for(int i = 0 ; i <= tn ; i++)
        cout << strg[i] << " " ;
    cout << endl ;

    return strg[tn] ;

}

int main()
{
    int n = 10;
    // cout << CT_Rec(90) << endl ;
    cout << CT_TD(n, new int[n+1]) << endl ;
    cout << CT_BU(n) << endl ;

    return 0 ;
}