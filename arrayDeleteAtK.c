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
    printf("Enter the position to delete : ");
    scanf("%d", &pos);
    if(pos <= size && pos>= 0){
        // 1 2 3 4 5 
        for(int i = pos-1; i<size; i++){
            arr[i] = arr[i+1];
        }
        for(int i = 0; i<size-1;  i++){
            printf("%d\t", arr[i]);
        }
    }                       
    else{
        printf("Invalid Position!\n");
        goto label;
    }
    return 0;
}