#include<iostream>

using namespace std ;

bool isItSafeToPlace(bool **board, int row, int col, int n)
{
    int rows[] = {-1,-2,-2,-1} ;
    int cols[] = {-2,-1,+1,+2} ; 

    for(int i = 0 ; i < 4 ; i++)
    {
        if(row+rows[i] >= 0 && row + rows[i] < n && col+cols[i] >= 0 && col + cols[i] < n && board[row+rows[i]][col+cols[i]])
            return false ;
    }

    return true ;
}

void queen(bool **board, int row, int col, int kpsf, int n , int k, string ans)
{   
    if(kpsf == k)
    {
        cout << ans << endl ;
        return ;
    }

    if(col == n)
    {
        row ++ ;
        col = 0 ;
    }

    if(row == n)
        return ;

    // place
    if(isItSafeToPlace(board,row,col,n))
    {
        board[row][col] = true ;
        queen(board, row, col+1, kpsf+1, n, k, ans + "{" + to_string(row) + "," + to_string(col) + "}") ;
        board[row][col] = false ;
    }

    // not place
    queen(board, row, col+1, kpsf,n, k, ans) ;

}

int main()
{
    int n = 2 ;
    int k = 2 ;
    bool **board = new bool*[n] ;

    for(int i = 0 ; i < n ; i++)
    {
        board[i] = new bool[n] ;

        for(int j=0 ; j < n ; j++)
            board[i][j] = false ; 
    }

    queen(board, 0, 0, 0, n, k, "") ;

    return 0 ;

}