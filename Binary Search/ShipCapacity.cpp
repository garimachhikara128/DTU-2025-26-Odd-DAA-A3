#include<iostream>

using namespace std ;

int shipWithinDays(vector<int>& weights, int days) ;
bool isItPossibleToShip(vector<int>&  weights, int nb, int days, int mid) ;

int main()
{
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5 ;

    cout << shipWithinDays(weights, days) << endl ;

    return 0 ;
}

int shipWithinDays(vector<int>& weights, int days) 
{    
    int nb = weights.size() ;

    int lo = weights[0] ;
    int hi = 0 ;
    for(int i = 0 ; i < nb ; i++)
        hi += weights[i] ;

    int ans = 0 ;

    while(lo <= hi) // log n times run
    {
        int mid = lo + (hi-lo)/2 ;

        if(isItPossibleToShip(weights,nb,days,mid)) // n
        {
            ans = mid ;
            hi = mid-1 ;
        }
        else
        {
            lo = mid+1 ;
        }
    }

    return ans ;
        
}

bool isItPossibleToShip(vector<int>&  weights, int nb, int days, int mid)
{
   int daysUsed = 1 ;
   int weightLoad = 0 ;

   int i = 0 ;
   while(i < nb)
   {
        if(weightLoad + weights[i] <= mid)
        {
            weightLoad += weights[i] ;
            i++ ;
        }
        else
        {
            daysUsed ++ ;
            weightLoad = 0 ;

            if(daysUsed > days)
                return false ;
        }
   }

   return true ;
}