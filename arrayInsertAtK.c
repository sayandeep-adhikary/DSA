#include<stdio.h>
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
    int pos;
    label:
    printf("Enter the position to insert : ");
    scanf("%d", &pos);
    if(pos <= size && pos>= 0){
        int data;
        printf("Enter the data to insert : ");
        scanf("%d", &data);
        // 1 2 3 4 5 
        for(int i = size-1; i>=pos-1; i--){
            arr[i+1] = arr[i];
        }
        arr[pos-1] = data;
        for(int i = 0; i<=size;  i++){
            printf("%d\t", arr[i]);
        }
    }                       
    else{
        printf("Invalid Position!\n");
        goto label;
    }
    return 0;
}