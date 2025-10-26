#include<iostream>

using namespace std ;

bool isPalindrome(string s, int si, int ei)
{
    int left = si ;
    int right = ei ;

    while(left < right)
    {
        if(s[left] != s[right])
            return false ;

        left ++ ;
        right -- ;
    }

    return true ;
}

int PalindromeParitioning_Rec(string s, int si, int ei)
{
    if(isPalindrome(s, si, ei))
        return 0 ;

    int ans = INT_MAX ;

    for(int k = si; k <= ei-1 ; k++)
    {
        int fp = PalindromeParitioning_Rec(s, si, k) ;
        int sp = PalindromeParitioning_Rec(s, k+1, ei) ;

        int total = fp + sp + 1 ;

        ans = min(ans, total) ;
    }

    return ans ;
}

int PalindromeParitioning_TD(string s, int si, int ei, int **strg)
{
    if(isPalindrome(s, si, ei))
        return 0 ;

    if(strg[si][ei] != -1)
        return strg[si][ei] ;

    int ans = INT_MAX ;

    for(int k = si; k <= ei-1 ; k++)
    {
        int fp = PalindromeParitioning_TD(s, si, k, strg) ;
        int sp = PalindromeParitioning_TD(s, k+1, ei, strg) ;

        int total = fp + sp + 1 ;

        ans = min(ans, total) ;
    }

    strg[si][ei] = ans ;

    return ans ;
}

bool** palindromeInfo(string s)
{   
    int n = s.length() ;

    bool **pinfo = new bool*[n] ;

    for(int i = 0 ; i < n ; i++)
    {
        pinfo[i] = new bool[n] ;

        for(int j=0 ; j < s.length() ; j++)
            pinfo[i][j] = true ;
    }

    for(int row = n-2 ; row >= 0 ; row--)
    {
        for(int col = row+1 ; col <= n-1 ; col++)
        {
            if(s[row] == s[col])
                pinfo[row][col] = pinfo[row+1][col-1] ;
            else
                pinfo[row][col] = false ;
        }
    }

    return pinfo ;

}

int PalindromeParitioning_BU(string s)
{
    bool** pinfo = palindromeInfo(s) ;

    int n = s.length() ;
    int strg[n][n] ;

    for(int slide = 0 ; slide <= n-1 ; slide++)
    {
        for(int si = 0 ; si <= n-slide-1 ; si++)
        {
            int ei = si + slide ;

            if(pinfo[si][ei])
                strg[si][ei] = 0 ;
            else
            {
                int ans = INT_MAX ;

                for(int k = si; k <= ei-1 ; k++)
                {
                    int fp = strg[si][k] ;
                    int sp = strg[k+1][ei] ;

                    int total = fp + sp + 1 ;

                    ans = min(ans, total) ;
                }

                strg[si][ei] = ans ;
            }

        }
    }

    return strg[0][n-1] ;
}

int main()
{
    string s = "abaccbvhcgvhjdvjdhfvuidhfiuvhreiuhvuierhviehrvihriv" ;
    // cout << PalindromeParitioning_Rec(s, 0, s.length()-1) << endl ;

    int **strg = new int*[s.length()] ;

    for(int i = 0 ; i < s.length() ; i++)
    {
        strg[i] = new int[s.length()] ;

        for(int j=0 ; j < s.length() ; j++)
            strg[i][j] = -1 ;
    }

    cout << PalindromeParitioning_TD(s, 0, s.length()-1, strg) << endl ;
    cout << PalindromeParitioning_BU(s) << endl ;

    return 0 ;
}