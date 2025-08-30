#include<iostream>

using namespace std ;

class Heap
{
    vector<int> data ;

    public :

    void add(int item)
    {
        data.push_back(item) ;
        upheapify(data.size()-1) ;
    }

    void upheapify(int ci)
    {
        int pi = (ci-1)/2 ;

        if(data[ci] < data[pi])
        {
            swap(data[ci],data[pi]) ;
            upheapify(pi) ;
        }
    }

    void remove()
    {
        swap(data[0], data[data.size()-1]) ;
        data.pop_back() ;
        downheapify(0) ;
    }

    void downheapify(int pi)
    {
        int lci = 2*pi+1 ;
        int rci = 2*pi+2 ;

        int mini = pi ;

        if(lci < data.size() && data[lci] < data[mini])
            mini = lci ;

        if(rci < data.size() && data[rci] < data[mini])
            mini = rci ;

        if(mini != pi)
        {
            swap(data[mini], data[pi]) ;
            downheapify(mini) ;
        }
    }

    int get()
    {
        return data[0] ;
    }

    void display()
    {
        for(int val: data)
            cout << val << " " ;
        cout << endl ;
    }

} ;

