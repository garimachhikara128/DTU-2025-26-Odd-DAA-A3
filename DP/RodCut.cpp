#include<iostream>

using namespace std ;

int RodCut_Rec(int *price, int n)
{
    int ans = price[n] ;

    int left = 1 ;
    int right = n-1 ;

    while(left <= right)
    {
        int leftp = RodCut_Rec(price, left) ;
        int rightp = RodCut_Rec(price, right) ;
        int total = leftp + rightp ;

        ans = max(ans, total) ;

        left++ ;
        right-- ;
    }

    return ans ;
}

int RodCut_TD(int *price, int n, int *strg)
{
    if(strg[n] != 0)
        return strg[n] ;

    int ans = price[n] ;

    int left = 1 ;
    int right = n-1 ;

    while(left <= right)
    {
        int leftp = RodCut_TD(price, left, strg) ;
        int rightp = RodCut_TD(price, right, strg) ;
        int total = leftp + rightp ;

        ans = max(ans, total) ;

        left++ ;
        right-- ;
    }

    strg[n] = ans ;

    return ans ;
}

int RodCut_BU(int *price, int tl)
{
    int *strg = new int[tl+1] ;
    strg[0] = price[0] ;

    for(int n = 1 ; n <= tl ; n++)
    {
        int ans = price[n] ;

        int left = 1 ;
        int right = n-1 ;

        while(left <= right)
        {
            int leftp = strg[left] ;
            int rightp = strg[right] ;
            int total = leftp + rightp ;

            ans = max(ans, total) ;

            left++ ;
            right-- ;
        }

        strg[n] = ans ;
    }

    return strg[tl] ;

}

int main()
{
    int price[] = {0,3,5,8,9,10,17,17,20} ;
    int n = sizeof(price)/sizeof(int) ;
    
    // cout << RodCut_Rec(price, n-1) << endl ;
    cout << RodCut_TD(price, n-1, new int[n]) << endl ;
    cout << RodCut_BU(price, n-1) << endl ;

    return 0 ;
}