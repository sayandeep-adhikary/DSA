#include<stdio.h>
void selectionSort(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            //1 3 4 2 5
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
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
    selectionSort(arr, size);
    printf("The Sorted Array is : \n");
    for(int i = 0; i<size; i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}