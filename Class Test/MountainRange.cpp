// https://www.hackerrank.com/contests/a3-daa-lab-odd-2025-26-backtracking/challenges/mountain-range-1
#include<iostream>

using namespace std ;

void display(char **arr, int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j =0 ; j < 2*n ; j++)
            cout << arr[i][j] ;
        cout << endl ;
    }
}

void mountain(char **arr, int row, int col, int up, int down, int n, string journey)
{
    if(row < 0 || col < 0 || row >= n || col >= 2*n)
        return ;

    if(journey == "up")
    {
        arr[row][col] = '/' ;
        mountain(arr, row-1, col+1, up+1, down, n, "up") ;
        mountain(arr, row, col+1, up+1, down, n, "down") ;
        arr[row][col] = ' ' ;
    }
    else
    {
        arr[row][col] = '\\' ;

        if(up == n && down == n-1)
        {
            display(arr,n) ;
            return ;
        }

        mountain(arr, row, col+1, up, down+1, n, "up") ;
        mountain(arr, row+1, col+1, up, down+1, n, "down") ;
        arr[row][col] = ' ' ;
    }
}

int main()
{

    int n ;
    cin >> n ;
    char **arr = new char*[n] ;
    for(int i = 0 ; i < n ; i++)
    {
        arr[i] = new char[n] ;

        for(int j =0 ; j < 2*n ; j++)
            arr[i][j] = ' ' ;
    }

    mountain(arr, n-1, 0, 0, 0, n, "up") ;

    return 0 ;
}