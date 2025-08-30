#include<iostream>

using namespace std;

void blockedMaze(int **arr, bool **visited, int cr, int cc, int er, int ec, string ans)
{
    // cout << cr << " " << cc << endl ;
    
    if(cr == er && cc == ec)
    {
        cout << ans << endl ;
        return ;
    }
    
    if(cr < 0 || cr > er || cc < 0 || cc > ec || visited[cr][cc] || arr[cr][cc]==0)
        return ;
    
    visited[cr][cc] = true ;
    
    blockedMaze(arr,visited,cr-1,cc,er,ec,ans+"T") ;
    blockedMaze(arr,visited,cr+1,cc,er,ec,ans+"D") ;
    blockedMaze(arr,visited,cr,cc-1,er,ec,ans+"L") ;
    blockedMaze(arr,visited,cr,cc+1,er,ec,ans+"R") ;
    
    visited[cr][cc] = false ;
}

int main()
{
    int n = 4 ;
    int **arr = new int*[n] ;
    arr[0] = new int[4]{1,0,1,1} ;
    arr[1] = new int[4]{1,1,1,1} ;
    arr[2] = new int[4]{1,0,1,1} ;
    arr[3] = new int[4]{1,1,0,1} ;
    
    bool **visited = new bool*[n] ;
    for(int i = 0 ; i < n ; i++)
    {
        visited[i] = new bool[n] ;
        for(int j = 0 ; j < n ; j++)
            visited[i][j] = false ;
    }

    blockedMaze(arr,visited,0,0,3,3,"") ;
    
    return 0;
}