#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std; 

int partition (int arr[], int low, int high) 
{ 
    int pivotElement = arr[low];    
    int j = low ;   
  
    for (int i = low+1; i <=high; i++) 
    {  
        if (arr[i] <pivotElement) 
        { 
            j=j+1; 
		
		if(i!=j)
           swap(arr[i], arr[j]); 
       }
         
    } 
    int pivot_point=j;
    if(low!=pivot_point)
    swap(arr[pivot_point],arr[low]); 
    
    return  pivot_point; 
}

  
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}
void printArray(int arr[], int size) 
{ 
    for (int i=0; i <=size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
int main() 
{ 
    int arr[] = {10, 7, 8, 9, 1,3,5}; 
    quickSort(arr, 0, 5); 
    printf("Sorted array: \n"); 
    printArray(arr, 5); 
    return 0; 
} 
