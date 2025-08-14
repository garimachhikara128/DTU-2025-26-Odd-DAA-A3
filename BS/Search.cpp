#include<iostream>

using namespace std ;

int main()
{

    int arr[] = {10,20,30,40,50} ;
    int n = sizeof(arr) / sizeof(arr[0]) ;
    int item = 30 ;

    int lo = 0 ;
    int hi = n-1 ;

    while(lo <= hi)
    {
        int mid = lo + (hi-lo)/2 ;

        if(arr[mid] < item) // RHS
            lo = mid + 1 ;
        else if(arr[mid] > item) // LHS
            hi = mid-1 ;
        else
        {
            cout << mid << endl ;
            break ;
        }
    }

    return 0 ;

}