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

int main()
{
    cout << CT_Rec(9) << endl ;

    return 0 ;
}