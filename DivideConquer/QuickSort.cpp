#include<iostream>
#include<vector>

using namespace std ;
void quickSort(int *arr, int lo, int hi) ;


int main()
{
    int n ;
    cin >> n ;
    int *input = new int[n] ;
    for(int i = 0 ; i < n ; i++)
        cin >> input[i] ;

    quickSort(input,0,n-1) ;
    for(int i = 0 ; i < n ; i++)
        cout << input[i] << " " ;
    cout << endl ;

    return 0 ;
}

void quickSort(int *arr, int lo, int hi)
{
    if(lo >= hi)
        return ;

    // partitioning
    int mid = (lo+hi)/2 ;
    int pivot = arr[mid] ;

    int left = lo ;
    int right = hi ;

    while(left <= right)
    {
        // left problem stop
        while(arr[left] < pivot)
            left++ ;

        // right problem stop
        while(arr[right] > pivot)
            right-- ;

        if(left <= right)
        {
            swap(arr[left],arr[right]) ;
            left++ ;
            right-- ;
        }
    }

    // calls
    quickSort(arr,lo,right) ;
    quickSort(arr,left,hi) ;

}