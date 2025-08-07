#include<iostream>

using namespace std ;

int climbingStairs(int curr, string ans, int n)
{
    if(curr == n)
    {
        cout << ans << endl ;
        return 1 ;
    }

    if(curr > n)
        return 0 ;

    // int r1 = climbingStairs(curr+1, ans + "1", n) ;
    // int r2 = climbingStairs(curr+2, ans + "2", n) ;
    // int r3 = climbingStairs(curr+3, ans + "3", n) ;

    // return r1+ r2+ r3 ;

    int res = 0 ;
    for(int jump=1 ; jump <=3 ; jump++)
        res += climbingStairs(curr+jump, ans + to_string(jump), n) ;

    return res ;
}

void lexicoCounting(int curr, int n)
{
    if(curr > n)
        return ;

    cout << curr << endl ;
    int i = 0 ;

    if(curr == 0)
        i = 1 ;
        
    for(; i <= 9 ; i++)
        lexicoCounting(curr*10+i, n) ;

}

void subsequences(string ques, string ans)
{
    if(ques.length() == 0)
    {
        cout << ans << endl ;
        return ;
    }

    char ch = ques[0] ; // a
    string roq = ques.substr(1) ; // bc

    subsequences(roq, ans) ;
    subsequences(roq, ans+ch) ;
}

void permutation(string ques, string ans)
{
    if(ques.length() == 0)
    {
        cout << ans << endl ;
        return ;
    }

    for(int i = 0 ; i < ques.length() ; i++)
    {
        char ch = ques[i] ;
        string roq = ques.substr(0,i) + ques.substr(i+1) ;

        permutation(roq, ans + ch) ;
    }
}

int main()
{
    // subsequences("abc", "") ;
    // permutation("aab", "") ;
    // cout << climbingStairs(0, "", 20) << endl  ;
    // cout << ways << endl ;
    lexicoCounting(0,1000) ;
    return 0 ;
}

