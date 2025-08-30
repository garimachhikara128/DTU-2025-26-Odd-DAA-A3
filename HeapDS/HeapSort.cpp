#include<iostream>

using namespace std ;

void downheapify(int *arr, int pi, int N)
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
            downheapify(arr, mini, N) ;
        }
}

void heapsort(int *arr, int N)
{
    // create a heap
    for(int i = N/2-1 ; i >=0 ; i--)
        downheapify(arr, i, N) ;

    // sorting
    for(int i = N-1 ; i >=0 ; i--)
    {
        swap(arr[0],arr[i]) ;
        downheapify(arr,0,i) ;
    }
}

void display(int *arr, int N)
{
    for(int i=0 ; i < N ; i++)
        cout << arr[i] << " " ;
    cout << endl ;
}

int main()
{
    int arr[] = {10,5,15,3,4,6} ;
    int N = sizeof(arr)/ sizeof(arr[0]) ;
    display(arr,N) ;
    heapsort(arr,N) ;
    display(arr,N) ;
    return 0 ;
}