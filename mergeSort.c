#include<stdio.h>
void merge(int *arr, int l, int m, int r){
    int left = m - l + 1;
    int right = r - m;
    int arr1[left], arr2[right];
    for(int i = 0; i < left; i++){
        arr1[i] = arr[l + i];
    }
    for(int i = 0; i < right; i++){
        arr2[i] = arr[m + i + 1];
    }
    int temp[left+right];

    int i = 0; 
    int j = 0;
    int k = 0;
    while(i<left && j<right){
        if(arr1[i] < arr2[j]){
            temp[k++] = arr1[i++];
        }
        else{    
            temp[k++] = arr2[j++];
        }
    }
    while(i<left){
        temp[k++] = arr1[i++];
    }
    while(j<right){
        temp[k++] = arr2[j++];
    }
    int size = sizeof(temp)/sizeof(temp[0]);
    for(int i = l, k = 0; k < size; i++, k++){
        arr[i] = temp[k];
    }
}
void mergeSort(int *arr, int s, int e){
    if(s<e){
        int mid = s + (e - s)/2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid+1, e);
        //merge func call
        merge(arr, s, mid, e);
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
    mergeSort(arr, 0, size-1);
    printf("The Sorted Array is : \n");
    for(int i = 0; i<size; i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}