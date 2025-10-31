#include<iostream>
#include<map>
#include<queue>
#include<vector>

using namespace std ;

class Graph
{
    map<int, map<int,int> > strg ;
    int V ;

    public :

    Graph(int V)
    {
        this->V = V ;
    }

    void addEdge(int u, int v, int cost)
    {
        strg[u][v] = cost ; 
        strg[v][u] = cost ; 
    }

    void display()
    {
        for(int i = 0 ; i < V ; i++)
        {
            cout << i << "\t" ;

            map<int, int>::iterator itr ;

            for(itr = strg[i].begin() ; itr != strg[i].end() ; itr++)
                cout << itr->first << "@" << itr->second << ", " ;
            cout << endl ;
        }
    }

    bool isItSafe(int *path, int nbr)
    {
        for(int i = 0 ; i < V ; i++)
        {
            if(path[i] == nbr)
                return false ;
        }

        return true ;
    }

    int tsp(int src, int curr, int visited)
    {
        if(visited == ((1 << V) - 1))
        {
            if(strg[curr].count(src) != 0)
                return strg[curr][src] ;
            else
                return 100000;
        }

        int ans = 100000 ;
        map<int, int>::iterator itr ;
        for(itr = strg[curr].begin() ; itr != strg[curr].end() ; itr++)
        {
            int nbr = itr->first ;

            if((visited & (1 << nbr)) == 0)
            {
                int rr = tsp(src, nbr, visited | (1 << nbr)) ;
                ans = min(ans, rr+strg[curr][nbr]) ;
            }
        }

        return ans ;
    }

    int tsp_td(int src, int curr, int visited, int **dp)
    {
        if(visited == ((1 << V) - 1))
        {
            if(strg[curr].count(src) != 0)
                return strg[curr][src] ;
            else
                return 100000;
        }

        if(dp[curr][visited] != -1)
            return dp[curr][visited] ;

        int ans = 100000 ;
        map<int, int>::iterator itr ;
        for(itr = strg[curr].begin() ; itr != strg[curr].end() ; itr++)
        {
            int nbr = itr->first ;

            if((visited & (1 << nbr)) == 0)
            {
                int rr = tsp_td(src, nbr, visited | (1 << nbr), dp) ;
                ans = min(ans, rr+strg[curr][nbr]) ;
            }
        }

        dp[curr][visited] = ans ;

        return ans ;
    }

} ;

int main()
{
    int n = 5 ;
    Graph g(n) ;
    
    g.addEdge(0,1,3) ;
    g.addEdge(0,3,7) ;
    g.addEdge(1,2,2) ;
    g.addEdge(1,3,5) ;
    g.addEdge(1,4,1) ;
    g.addEdge(3,4,2) ;
    g.addEdge(2,4,2) ;

    g.display() ;
    cout << g.tsp(0,0, 1) << endl ;

    int **strg = new int*[n] ;

    for(int i = 0 ; i < n ; i++)
    {
        int cols = (1 << n);
        strg[i] = new int[cols] ;

        for(int j=0 ; j < cols ; j++)
            strg[i][j] = -1 ;
    }

    cout << g.tsp_td(0,0, 1, strg) << endl ;
    
    return 0 ;
}