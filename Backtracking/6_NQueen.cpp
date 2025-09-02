#include<iostream>

using namespace std ;
int c = 1 ;

bool isItSafeToPlace(bool **board, int row, int col, int n)
{
    // vertically up
    int r = row-1 ;
    int c = col ;

    while(r >= 0)
    {
        if(board[r][c])
            return false ;
        r -- ;
    }

    // diagonally left
    r = row-1 ;
    c = col-1 ;

    while(r >= 0 && c >= 0)
    {
        if(board[r][c])
            return false ;
        r-- ;
        c -- ;
    }

    // diagonally right
    r = row-1 ;
    c = col+1 ;

    while(r >= 0 && c < n)
    {
        if(board[r][c])
            return false ;
        r -- ;
        c ++ ;
    }

    return true ;
}

void queen(bool **board, int n, int row, string ans)
{
    if(row == n)
    {
        cout << c++ << ". " << ans << endl ;
        return ;
    }

    for(int col = 0 ; col < n ; col++)
    {
        if(isItSafeToPlace(board, row,col,n))
        {
            board[row][col] = true ;
            queen(board, n, row+1, ans + "{" + to_string(row) + "," + to_string(col) + "}") ;
            board[row][col] = false ;
        }
    }
} 

int main()
{
    int n = 4 ;

    bool **board = new bool*[n] ;

    for(int i = 0 ; i < n ; i++)
    {
        board[i] = new bool[n] ;

        for(int j=0 ; j < n ; j++)
            board[i][j] = false ; 
    }

    queen(board, n, 0, "") ;

    return 0 ;

}