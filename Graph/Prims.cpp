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

    class PrimsNode
    {
        public:
        int vname ;
        int acqvname ;
        int cost ;

        PrimsNode(int vname, int acqvname, int cost)
        {
            this->vname = vname ;
            this->acqvname = acqvname ;
            this->cost = cost ;
        }
    } ;

    struct compare
    {
        bool operator()(PrimsNode* n1, PrimsNode* n2)
        {
            return n1->cost > n2->cost ;
        }
    } ;

    void prims()
    {
        priority_queue<PrimsNode*, vector<PrimsNode*>, compare> pq ;
        pq.push(new PrimsNode(0,-1,0)) ;

        bool visited[V] ;
        fill(visited, visited+V, false) ;

        while(pq.size() != 0)
        {
            // remove
            PrimsNode *rn = pq.top() ;
            pq.pop() ;

            // if something is already visited ignore
            if(visited[rn->vname])
                continue ;

            // visited mark
            visited[rn->vname] = true ;

            // print
            if(rn->acqvname != -1)
                cout << rn->acqvname << " -> " << rn->vname << " @ " << rn->cost << endl ;

            // nbrs
            map<int,int>::iterator itr ;

            for(itr = strg[rn->vname].begin() ; itr != strg[rn->vname].end() ; itr++)
            {
                int nbr = itr->first ;
                int cost = itr->second ;

                // work only for unvisited nbrs
                if(!visited[nbr])
                    pq.push(new PrimsNode(nbr, rn->vname, cost)) ;
            }
        }

    }

} ;

int main()
{
    Graph g(7) ;

    g.addEdge(0,1,2) ;
    g.addEdge(0,3,6) ;
    g.addEdge(1,2,3) ;
    g.addEdge(2,3,1) ;
    g.addEdge(3,4,8) ;
    g.addEdge(4,5,5) ;
    g.addEdge(5,6,9) ;
    g.addEdge(4,6,7) ;

    // g.display() ;

    g.prims() ;

    return 0 ;
}