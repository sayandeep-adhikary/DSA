#include<stdio.h>
void insertionSort(int arr[], int size){
    for(int i=1; i<size; i++){ //1 3 4 2 5
    //Let 1st element is sorted, loop from 1st index to length of array.
        int temp = arr[i];
        int j = i - 1;
        while(temp < arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
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
    insertionSort(arr, size);
    printf("The Sorted Array is : \n");
    for(int i = 0; i<size; i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}