#include<iostream>

using namespace std ;

int Wine_Rec(int *arr, int si, int ei, int yr)
{
    if(si == ei)
        return arr[si] * yr ;

    int left = Wine_Rec(arr, si+1, ei, yr+1) + arr[si]*yr ;
    int right = Wine_Rec(arr, si, ei-1, yr+1) + arr[ei]*yr  ;

    int ans = max(left, right) ;

    return ans ;
}

int Wine_Rec1(int *arr, int n, int si, int ei)
{
    int yr = n - ei + si ;

    if(si == ei)
        return arr[si] * yr ;

    int left = Wine_Rec1(arr, n, si+1, ei) + arr[si]*yr ;
    int right = Wine_Rec1(arr, n, si, ei-1) + arr[ei]*yr  ;

    int ans = max(left, right) ;

    return ans ;
}

int Wine_TD(int *arr, int n, int si, int ei, int **strg)
{
    int yr = n - ei + si ;

    if(si == ei)
        return arr[si] * yr ;

    if(strg[si][ei] != -1)
        return strg[si][ei] ;

    int left = Wine_TD(arr, n, si+1, ei, strg) + arr[si]*yr ;
    int right = Wine_TD(arr, n, si, ei-1, strg) + arr[ei]*yr  ;

    int ans = max(left, right) ;

    strg[si][ei] = ans ;

    return ans ;
}


int Wine_BU(int *arr, int n)
{
    int strg[n][n] ;

    for(int slide = 0 ; slide <= n-1 ; slide++)
    {
        for(int si = 0 ; si <= n-slide-1 ; si++)
        {
            int ei = si + slide ;
            int yr = n - ei + si ;

            if(si == ei)
                strg[si][ei] = arr[si] * yr ;
            else
            {
                int left = strg[si+1][ei] + arr[si]*yr ;
                int right = strg[si][ei-1] + arr[ei]*yr  ;

                int ans = max(left, right) ;

                strg[si][ei] = ans ;
            }
        }
    }

    return strg[0][n-1] ;
}

int main()
{
    int arr[] = {2,3,5,1,4,2,3,5,1,4,2,3,5,1,4,2,3,5,1,4,2,3,5,1,4,2,3,5,1,4,2,3,5,1,4,2,3,5,1,4,2,3,5,1,4};
    int n = sizeof(arr)/sizeof(int) ;

    // cout << Wine_Rec(arr, 0, n-1, 1) << endl ;
    // cout << Wine_Rec1(arr, n, 0, n-1) << endl ;

    int **strg = new int*[n] ;

    for(int i = 0 ; i < n ; i++)
    {
        strg[i] = new int[n] ;

        for(int j=0 ; j < n ; j++)
            strg[i][j] = -1 ;
    }

    cout << Wine_TD(arr, n, 0, n-1, strg) << endl ;
    cout << Wine_BU(arr, n) << endl ;

    return 0 ;
}