#include<iostream>

using namespace std ;

bool WildcardMatching_Rec(string src, string pat, int sidx, int pidx)
{
    if(sidx == src.length() && pidx == pat.length())
        return true ;
    
    if(sidx != src.length() && pidx == pat.length())
        return false ;
    
    if(sidx == src.length() && pidx != pat.length())
    {
        for(int i = pidx ; i < pat.length() ; i++)
        {
            if(pat[i] != '*')
                return false ;
        }

        return true ;
    }

    char chs = src[sidx] ;
    char chp = pat[pidx] ;

    bool ans ;

    if(chs == chp || chp == '?')
    {
        ans = WildcardMatching_Rec(src, pat, sidx+1, pidx+1) ;
    }
    else if(chp == '*')
    {
        bool blank = WildcardMatching_Rec(src, pat, sidx, pidx+1) ;  
        bool multiple = WildcardMatching_Rec(src, pat, sidx+1, pidx) ;

        ans = blank || multiple ;
    }
    else
    {
        ans = false ; // pattern 1st char and source 1st char are not matching
    }

    return ans ;
}

bool WildcardMatching_TD(string src, string pat, int sidx, int pidx, int **strg)
{
    if(sidx == src.length() && pidx == pat.length())
        return true ;
    
    if(sidx != src.length() && pidx == pat.length())
        return false ;
    
    if(sidx == src.length() && pidx != pat.length())
    {
        for(int i = pidx ; i < pat.length() ; i++)
        {
            if(pat[i] != '*')
                return false ;
        }

        return true ;
    }

    if(strg[sidx][pidx] != -1)
        return ((strg[sidx][pidx] == 1) ? true : false) ;

    char chs = src[sidx] ;
    char chp = pat[pidx] ;

    bool ans ;

    if(chs == chp || chp == '?')
    {
        ans = WildcardMatching_TD(src, pat, sidx+1, pidx+1, strg) ;
    }
    else if(chp == '*')
    {
        bool blank = WildcardMatching_TD(src, pat, sidx, pidx+1, strg) ;  
        bool multiple = WildcardMatching_TD(src, pat, sidx+1, pidx, strg) ;

        ans = blank || multiple ;
    }
    else
    {
        ans = false ; // pattern 1st char and source 1st char are not matching
    }

    strg[sidx][pidx] = ((ans == true) ? 1: 0) ;

    return ans ;
}

bool WildcardMatching_BU(string src, string pat)
{
    int nr = src.length() + 1 ;
    int nc = pat.length() + 1 ;

    bool strg[nr][nc] ;

    // last col
    for(int row = 0 ; row <= nr - 2 ; row ++)
        strg[row][nc-1] = false ;
    // last row and last col cell
    strg[nr-1][nc-1] = true ;
    // last row
    for(int col = nc-2 ; col >=0 ; col--)
    {
        if(pat[col] == '*')
            strg[nr-1][col] = strg[nr-1][col+1] ;
        else 
            strg[nr-1][col] = false ;
    }

    // filling
    for(int row = nr-2 ; row >=0 ; row--)
    {
        for(int col = nc-2 ; col >=0 ; col--)
        {
            char chs = src[row] ;
            char chp = pat[col] ;

            bool ans ;

            if(chs == chp || chp == '?')
            {
                ans = strg[row+1][col+1] ;
            }
            else if(chp == '*')
            {
                bool blank = strg[row][col+1] ;  
                bool multiple = strg[row+1][col] ;

                ans = blank || multiple ;
            }
            else
            {
                ans = false ; // pattern 1st char and source 1st char are not matching
            }

            strg[row][col] = ans ;
        }
    }

    return strg[0][0] ;

}

int main()
{
    string src = "abacdechdbvhgdvhdusvhdshvbuisdhvuidhvdshvidh" ;
    string pat = "*********************************************dd" ;

    // cout << WildcardMatching_Rec(src, pat, 0, 0) << endl ;

    int **strg = new int*[src.length()] ;

    for(int i = 0 ; i < src.length() ; i++)
    {
        strg[i] = new int[pat.length()] ;

        for(int j=0 ; j < pat.length() ; j++)
            strg[i][j] = -1 ;
    }

    cout << WildcardMatching_TD(src, pat, 0, 0, strg) << endl ;
    cout << WildcardMatching_BU(src, pat) << endl ;

    return 0 ;
}