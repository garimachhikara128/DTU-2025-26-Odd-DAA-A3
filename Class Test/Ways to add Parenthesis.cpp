#include<iostream>

using namespace std ;

vector<string> diffWaysToCompute(string str) 
{        
    vector<string> mr ;

    if(str.find('+') == string::npos && str.find('-') == string::npos && str.find('*') == string::npos && str.find('/') == string::npos && str.find('%') == string::npos)
    {
        mr.push_back(str) ;
        return mr ;
    }

    for(int i = 0 ; i < str.length() ; i++)
    {
        char ch = str[i] ;

        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
        {
            vector<string> rr1 = diffWaysToCompute(str.substr(0,i)) ;
            vector<string> rr2 = diffWaysToCompute(str.substr(i+1)) ;

            for(string val1 : rr1)
            {
                for(string val2: rr2)
                {
                    if(ch == '+')
                        mr.push_back("(" + val1 + "+" + val2 + ")") ;
                    else if(ch == '-')
                        mr.push_back("(" + val1 + "-" + val2 + ")") ;
                    else if(ch == '*')
                        mr.push_back("(" + val1 + "*" + val2 + ")") ;
                    else if(ch == '/')
                        mr.push_back("(" + val1 + "/" + val2 + ")") ;
                    else if(ch == '%')
                        mr.push_back("(" + val1 + "%" + val2 + ")") ;
                }
            }
        }

    }
    return mr ;
}

int main()
{
    
    string str ;
    cin >> str ;
    vector<string> res = diffWaysToCompute(str) ;

    for(string val: res)
        cout << val << endl ;

    return 0 ;
}


