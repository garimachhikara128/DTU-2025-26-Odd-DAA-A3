#include<iostream>
int power(int , int) ;

using namespace std ;

int main()
{
    cout << power(2,10) << endl;

    return 0 ;
}

int power(int x, int n)
{
    if(n == 0)
        return 1 ;

    int sp = power(x,n/2) ;
    if(n % 2 == 0)
        return sp * sp ;
    else
        return sp * sp * x ;
}