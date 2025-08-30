#include<iostream>

using namespace std ;

class Heap2
{
    int *arr ;
    int N ;

    public :

    void make_heap(int *arr, int N)
    {
        this->arr = arr ;
        this->N = N ;

        for(int i = N/2-1 ; i >=0 ; i--)
            downheapify(i) ;
    }

    void downheapify(int pi)
    {
        int lci = 2*pi+1 ;
        int rci = 2*pi+2 ;

        int mini = pi ;

        if(lci < N && arr[lci] < arr[mini])
            mini = lci ;

        if(rci < N && arr[rci] < arr[mini])
            mini = rci ;

        if(mini != pi)
        {
            swap(arr[mini], arr[pi]) ;
            downheapify(mini) ;
        }
    }

    int remove()
    {
        swap(arr[0], arr[N-1]) ;
        int rv = arr[N-1] ;
        N-- ;
        downheapify(0) ;
        return rv ;
    }

} ;

int main()
{
    int arr[] = {10,5,15,3,4,6} ;
    int N = sizeof(arr)/ sizeof(arr[0]) ;

    Heap2 h ;
    h.make_heap(arr,N) ;
    cout << h.remove() << endl ;
    cout << h.remove() << endl ;
    cout << h.remove() << endl ;
    cout << h.remove() << endl ;

    return 0 ;


}
