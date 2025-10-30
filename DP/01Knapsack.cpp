#include<iostream>

using namespace std ;

int Knapsack_Rec(int *weight, int *price, int n, int idx, int cap)
{
    if(idx == n || cap == 0)
        return 0 ;

    // exclude
    int exclude = Knapsack_Rec(weight, price, n, idx+1, cap) ;

    // include
    int include = 0 ;
    if(cap >= weight[idx])
        include = Knapsack_Rec(weight, price, n, idx+1, cap-weight[idx]) + price[idx] ;

    int ans = max(exclude, include) ;

    return ans ;
}

int Knapsack_TD(int *weight, int *price, int n, int idx, int cap, int **strg)
{
    if(idx == n || cap == 0)
        return 0 ;

    if(strg[idx][cap] != -1)
        return strg[idx][cap] ;

    // exclude
    int exclude = Knapsack_TD(weight, price, n, idx+1, cap, strg) ;

    // include
    int include = 0 ;
    if(cap >= weight[idx])
        include = Knapsack_TD(weight, price, n, idx+1, cap-weight[idx], strg) + price[idx] ;

    int ans = max(exclude, include) ;

    strg[idx][cap] = ans ;

    return ans ;
}

int Knapsack_BU(int *weight, int *price, int n, int cap)
{
    int strg[n+1][cap+1] ;

    // td bc => bu fill
    for(int col = 0 ; col <= cap ; col++)
        strg[n][col] = 0 ;
    for(int row = 0 ; row <= n ; row++)
        strg[row][0] = 0 ;
    
    // filling
    for(int row = n-1 ; row >=0 ; row--)
    {
        for(int col = 1 ; col <= cap ; col++)
        {
            // exclude
            int exclude = strg[row+1][col] ;

            // include
            int include = 0 ;
            if(col >= weight[row])
                include = strg[row+1][col-weight[row]] + price[row] ;

            int ans = max(exclude, include) ;

            strg[row][col] = ans ;
        }
    }

    return strg[0][cap] ;

}


int main()
{
    int weight[] = {1,3,4,5} ;
    int price[] = {1,4,5,7} ;
    int cap = 7 ;
    int n = sizeof(price) / sizeof(int) ;

    cout << Knapsack_Rec(weight, price, n, 0, cap) << endl ;

    int **strg = new int*[n] ;

    for(int i = 0 ; i < n ; i++)
    {
        strg[i] = new int[cap+1] ;
        for(int j=0 ; j <= cap ; j++)
            strg[i][j] = -1 ;
    }

    cout << Knapsack_TD(weight, price, n, 0, cap, strg) << endl ;
    cout << Knapsack_BU(weight, price, n, cap) << endl ;

    return 0 ;
}