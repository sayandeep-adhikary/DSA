#include<stdio.h>
int partition(int *arr, int s, int e){
    int pivot = arr[s];
    int count = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    int pivotIndex = s + count;
    int temp = arr[s];
    arr[s] = arr[pivotIndex];
    arr[pivotIndex] = temp;
    int i = s, j = e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return pivotIndex;
}
void quickSort(int *arr, int s, int e){
    if(s>=e){
        return;
    }
    int p = partition(arr, s, e);

    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
    
}
int main()
{
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements : ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, size-1);
    printf("The Sorted Array is : \n");
    for(int i = 0; i<size; i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}