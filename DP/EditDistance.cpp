#include<iostream>

using namespace std ;

int EDRec(string s1, int idx1, string s2, int idx2)
{
    if(idx1 == s1.length()|| idx2 == s2.length())
    {
        return max(s1.length()-idx1, s2.length()-idx2) ;
    }

    int ans = 0 ;

    if(s1[idx1] == s2[idx2])
    {
        ans = EDRec(s1, idx1+1, s2, idx2+1) ;
    }
    else
    {
        int o_insert = EDRec(s1, idx1+1, s2, idx2) ;
        int o_delete = EDRec(s1, idx1, s2, idx2+1) ;
        int o_replace = EDRec(s1, idx1+1, s2, idx2+1) ;

        ans = min(o_insert, min(o_delete, o_replace)) + 1 ;
    }

    return ans ;

}

int EDTD(string s1, int idx1, string s2, int idx2, int **strg)
{
    if(idx1 == s1.length()|| idx2 == s2.length())
    {
        return max(s1.length()-idx1, s2.length()-idx2) ;
    }

    if(strg[idx1][idx2] != -1) // re-use
        return strg[idx1][idx2] ;

    int ans = 0 ;

    if(s1[idx1] == s2[idx2])
    {
        ans = EDTD(s1, idx1+1, s2, idx2+1, strg) ;
    }
    else
    {
        int o_insert = EDTD(s1, idx1+1, s2, idx2, strg) ;
        int o_delete = EDTD(s1, idx1, s2, idx2+1, strg) ;
        int o_replace = EDTD(s1, idx1+1, s2, idx2+1, strg) ;

        ans = min(o_insert, min(o_delete, o_replace)) + 1 ;
    }

    strg[idx1][idx2] = ans ;

    return ans ;

}

int EDBU(string s1, string s2)
{
    // strg array
    int nr = s1.length() + 1 ;
    int nc = s2.length() + 1 ;

    int **strg = new int*[nr] ;
    for(int i = 0 ; i < nr ; i++)
        strg[i] = new int[nc] ;

    // TD BC -> BU Fill
    // last row fill
    for(int j = 0 ; j < nc ; j++)
        strg[nr-1][j] = s2.length()-j ;
    // last col fill
    for(int i = 0 ; i < nr ; i++)
        strg[i][nc-1] = s1.length()-i ;

    // fill
    for(int i = nr-2 ; i >=0 ; i--)
    {
        for(int j = nc-2 ; j >=0 ; j--)
        {
            if(s1[i] == s2[j])
            {
                strg[i][j] = strg[i+1][j+1] ;
            }
            else
            {
                int o_insert = strg[i+1][j];
                int o_delete = strg[i][j+1] ;
                int o_replace = strg[i+1][j+1] ;

                strg[i][j] = min(o_insert, min(o_delete, o_replace)) + 1 ;
            }
        }
    }

    return strg[0][0] ;

}


int main()
{
    string s1 = "saturdaycbdvhcgvshjdfgchjegfucgrefbcsdvhfcgrsgvfgfiuve" ;
    string s2 = "sundaycvhsdvchjsdghjcsgdjvhcbjregbvuegbrucvgsjdhvcgudr" ;

    // cout << EDRec(s1,0,s2,0) << endl ;

    int **strg = new int*[s1.length()] ;

    for(int i = 0 ; i < s1.length() ; i++)
    {
        strg[i] = new int[s2.length()] ;

        for(int j=0 ; j < s2.length() ; j++)
            strg[i][j] = -1 ;
    }

    cout << EDTD(s1,0,s2,0,strg) << endl ;
    cout << EDBU(s1, s2) << endl ;
    
    return 0 ;
}