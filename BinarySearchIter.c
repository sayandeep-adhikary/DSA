#include<stdio.h>
int binarySearch(int arr[], int size, int key){
    int s = 0;
    int e = size - 1;
    while(s<=e){
        int mid = s + (e - s)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            e = mid - 1; 
        }
        else{
            s = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    int arr[100];
    printf("Enter the elements : ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the key to search : ");
    scanf("%d", &key);
    int check = binarySearch(arr, size, key);
    check == -1 ? printf("%d is not found!", key) : printf("%d is found at position %d", key, check+1);
    return 0;
}