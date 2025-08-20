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

    int left = lo ;
    int right = hi ;
    int mid = (lo+hi) / 2 ;

    // partitioning step
    int pivot = arr[mid] ;

    while(left <= right)
    {
        // left stop problem
        while(arr[left] < pivot)
            left++ ;

        // right stop problem
        while(arr[right] > pivot)
            right-- ;

        // problem solve -> swap
        if(left <= right)
        {
            int temp = arr[left] ;
            arr[left] = arr[right] ;
            arr[right] = temp ;
            left++; 
            right-- ;
        }
    }

    quickSort(arr, lo, right) ;
    quickSort(arr, left, hi) ;
}