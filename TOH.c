#include<stdio.h>
void TOH(char source, char helping, char destination, int n){
    if(n == 1){
        printf("Move disk from %c to %c\n", source, destination);
    }
    else{
        TOH(source, destination, helping, n-1);
        TOH(source, helping, destination, 1);
        TOH(helping, source, destination, n-1);
    }
}
int main()
{
    int n;
    printf("Enter the number of disks : ");
    scanf("%d", &n);
    TOH('a', 'b', 'c', n);
    return 0;
}