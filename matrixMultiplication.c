#include<stdio.h>
int main()
{
    int a[10][10], b[10][10], mul[10][10], r, c;
    printf("Enter the number of rows : ");
    scanf("%d", &r);
    printf("Enter the number of columns : ");
    scanf("%d", &c);
    printf("Enter the first Matrix element : \n");
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the second Matrix element : \n");
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            scanf("%d", &b[i][j]);
        }
    }
    printf("Multiplication of the Matrix is : \n");
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            mul[i][j] = 0;
            for(int k = 0; k<c; k++){
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            printf("%d\t", mul[i][j]);
        }
        printf("\n");
    }
    return 0;
}