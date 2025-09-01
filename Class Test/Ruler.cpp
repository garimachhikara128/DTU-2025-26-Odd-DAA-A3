// https://www.hackerrank.com/contests/a3-daa-lab-odd-2025-26-recursion/challenges/ruler-cp
#include<iostream>

using namespace std ;

void ruler(int) ;

int main()
{
    int inches ;
    cin >> inches ;
    int major ;
    cin >> major ;

    for(int i = 0 ; i <= inches ; i++)
    {
        // - - - - 0
        for(int j = 1 ; j <= major ; j++)
            cout << "- " ;
        cout << i << endl ;

        if(i < inches)
            ruler(major-1) ;
    }
    
    return 0 ;
}

void ruler(int n)
{
    if(n == 0)
        return ;

    // sp
    ruler(n-1) ;

    // work
    for(int i = 1 ; i <= n ; i++)
        cout << "- " ;
    cout << endl ;

    // sp
    ruler(n-1) ;
}