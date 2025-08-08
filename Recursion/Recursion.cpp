#include<iostream>

using namespace std ;

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

bool isPalindrome(string str)
{
    int i = 0 ; 
    int j = str.length()-1 ;

    while(i < j)
    {
        if(str[i] != str[j])
            return false ;

        i++ ;
        j-- ;
    }

    return true ;
}

void palindromicPartition(string ques, string ans)
{
    if(ques.length() == 0)
    {
        cout << ans << endl ;
        return ;
    }

    for(int i = 1 ; i <= ques.length() ; i++)
    {
        string part = ques.substr(0,i) ;
        string roq = ques.substr(i) ;
        if(isPalindrome(part))
            palindromicPartition(roq, ans + part + " ") ;
    }
}

vector<int> diffWaysToCompute(string str) {
        
    vector<int> mr ;

    if(str.find('+') == string::npos && str.find('-') == string::npos && str.find('*') == string::npos)
    {
        mr.push_back(stoi(str)) ;
        return mr ;
    }

    for(int i = 0 ; i < str.length() ; i++)
    {
        char ch = str[i] ;

        if(ch == '+' || ch == '-' || ch == '*')
        {
            vector<int> rr1 = diffWaysToCompute(str.substr(0,i)) ;
            vector<int> rr2 = diffWaysToCompute(str.substr(i+1)) ;

            for(int val1 : rr1)
            {
                for(int val2: rr2)
                {
                    if(ch == '+')
                        mr.push_back(val1+val2) ;
                    else if(ch == '-')
                        mr.push_back(val1-val2) ;
                    else if(ch == '*')
                        mr.push_back(val1*val2) ;
                }
            }
        }

    }

    return mr ;
}

void TOH(int n, string src, string dst, string helper)
{
    if(n == 0)
        return ;

    TOH(n-1, src, helper, dst) ;
    cout << "move " << n << " disc from " << src << " to " << dst << endl ;
    TOH(n-1, helper, dst, src) ;
}

int main()
{
    // subsequences("abc", "") ;
    // permutation("aab", "") ;
    // cout << climbingStairs(0, "", 20) << endl  ;
    // cout << ways << endl ;
    // lexicoCounting(0,1000) ;
    // palindromicPartition("abccb", "") ;
    vector<int> res = diffWaysToCompute("2*3-4*5") ;

    for(int val: res)
        cout << val << endl ;

    // TOH(3, "S", "D", "H") ;
    return 0 ;
}

