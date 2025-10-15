#include<iostream>

using namespace std ;

int LCSRec(string s1, int idx1, string s2, int idx2)
{
    if(idx1 == s1.length() || idx2 == s2.length())
        return 0 ;

    int ans = 0 ;

    if(s1[idx1] == s2[idx2])
    {
        ans = LCSRec(s1, idx1+1, s2, idx2+1) + 1 ;
    }
    else
    {
        int o1 = LCSRec(s1, idx1, s2, idx2+1) ;
        int o2 = LCSRec(s1, idx1+1, s2, idx2) ;

        ans = max(o1, o2) ;
    }

    return ans ;
}

int LCSTD(string s1, int idx1, string s2, int idx2, int **strg)
{
    if(idx1 == s1.length() || idx2 == s2.length())
        return 0 ;

    if(strg[idx1][idx2] != -1) // re-use
        return strg[idx1][idx2] ;

    int ans = 0 ;

    if(s1[idx1] == s2[idx2])
    {
        ans = LCSTD(s1, idx1+1, s2, idx2+1, strg) + 1 ;
    }
    else
    {
        int o1 = LCSTD(s1, idx1, s2, idx2+1, strg) ;
        int o2 = LCSTD(s1, idx1+1, s2, idx2, strg) ;

        ans = max(o1, o2) ;
    }

    strg[idx1][idx2] = ans ; // store

    return ans ;
}

int main()
{
    string s1 = "abcdefghijklmnopqrstuvwxyz" ;
    string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;

    // cout << LCSRec(s1,0,s2,0) << endl ;

    int **strg = new int*[s1.length()] ;

    for(int i = 0 ; i < s1.length() ; i++)
    {
        strg[i] = new int[s2.length()] ;

        for(int j=0 ; j < s2.length() ; j++)
            strg[i][j] = -1 ;
    }

    cout << LCSTD(s1,0,s2,0,strg) << endl ;

    // cout << LCSBU(s1,s2) << endl ;

    return 0 ; 
}