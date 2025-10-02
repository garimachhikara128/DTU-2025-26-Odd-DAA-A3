#include<iostream>
#include<map>
#include<queue>

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
        for(int i=0 ; i < V ; i++)
        {
            cout << i << "\t" ;

            map<int,int>::iterator itr ;

            for(itr = strg[i].begin() ; itr != strg[i].end() ; itr++)
                cout << itr->first << "@" << itr->second << ", " ;
            cout << endl ;
        }
    }

    class DijkstraNode
    {
        public:
        int vname ;
        string vpath ;
        int cost ;

        DijkstraNode(int vname, string vpath, int cost)
        {
            this->vname = vname ;
            this->vpath = vpath ;
            this->cost = cost ;
        }
    } ;

    struct compare
    {
        bool operator()(DijkstraNode* n1, DijkstraNode* n2)
        {
            return n1->cost > n2->cost ;
        }
    } ;

    void dijkstra(int src)
    {
        priority_queue<DijkstraNode*, vector<DijkstraNode*>, compare> pq ;
        pq.push(new DijkstraNode(src,to_string(src),0)) ;

        bool visited[V] ;
        fill(visited, visited+V, false) ;

        while(pq.size() != 0)
        {
            // remove
            DijkstraNode *rn = pq.top() ;
            pq.pop() ;

            // if something is already visited ignore
            if(visited[rn->vname])
                continue ;

            // visited mark
            visited[rn->vname] = true ;

            // print
            cout << rn->vname << " via " << rn->vpath << " @ " << rn->cost << endl ;

            // nbrs
            map<int,int>::iterator itr ;

            for(itr = strg[rn->vname].begin() ; itr != strg[rn->vname].end() ; itr++)
            {
                int nbr = itr->first ;
                int cost = itr->second ;

                // work only for unvisited nbrs
                if(!visited[nbr])
                    pq.push(new DijkstraNode(nbr, rn->vpath + to_string(nbr), rn->cost + cost)) ;
            }
        }

    }

} ;

int main()
{
    Graph g(7) ;

    g.addEdge(0,1,2) ;
    g.addEdge(0,3,10) ;
    g.addEdge(1,2,3) ;
    g.addEdge(2,3,1) ;
    g.addEdge(3,4,8) ;
    g.addEdge(4,5,5) ;
    g.addEdge(5,6,4) ;
    g.addEdge(4,6,6) ;

    // g.display() ;

    g.dijkstra(0) ;

    return 0 ;
}