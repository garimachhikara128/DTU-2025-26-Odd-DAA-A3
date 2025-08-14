#include<iostream>

using namespace std ;
bool isItPossibleToPlaceCows(int *stalls, int ns, int nc, int mid) ;

int main()
{
    int ns = 5 ;
    int nc = 3 ;
    int stalls[] = {1,2,8,4,9} ;

    sort(stalls, stalls+ns) ; // nlogn 

    int lo = 0 ;
    int hi = stalls[ns-1] - stalls[0] ;

    int ans = 0 ;

    while(lo <= hi) // log n times run
    {
        int mid = lo + (hi-lo)/2 ;

        if(isItPossibleToPlaceCows(stalls, ns,nc,mid)) // n
        {
            ans = mid ;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1 ;
        }
    }

    cout << ans << endl ;
    return 0 ;
}

bool isItPossibleToPlaceCows(int *stalls, int ns, int nc, int mid)
{
    int cowsPlaced = 1 ;
    int pos = stalls[0] ;

    for(int i = 1 ; i <= ns-1 ; i++)
    {
        if(stalls[i] - pos >= mid)
        {
            cowsPlaced ++ ;
            pos = stalls[i] ;

            if(cowsPlaced == nc)
                return true ;
        }
    }

    return false ;

}