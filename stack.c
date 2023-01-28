#include<stdio.h>
#include<stdlib.h>
#define size 5
int stack[size];
int top = -1;
void push(int data){
    if(top == size-1){
        printf("Stack Overflow! Data is not pushed!\n");
        return;
    }
    top++;
    stack[top] = data;
    printf("%d is pushed in the stack\n\n", data);
}
void pop(){
    if(top == -1){
        printf("Stack Underflow!\n\n");
        return;
    }
    printf("%d is deleted\n\n", stack[top]);
    top--;
}
void display(){
    printf("The Stack is : ");
    for(int i = top; i >= 0; i--){
        printf("%d\t", stack[i]);
    }
    printf("\n\n");
}
void peek(){
    if(top == -1){
        printf("Stack is EMPTY!\n\n");
        return;
    }
    else{
        printf("The Top Element is %d\n\n", stack[top]);
    }
}
int main()
{
    int ch;
    int data;
    while(1){
        printf("Enter Your Choice : \n");
        printf("1 to PUSH\t");
        printf("2 to POP\t");
        printf("3 to DISPLAY\t");
        printf("4 to PEEK\t");
        printf("5 to EXIT\n");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            printf("Enter the data to PUSH : ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            printf("\n");
            break;
        case 4:
            peek();
            break;
        case 5:
        printf("Program Ended!");
            exit(1);
        default:
            printf("Invalid Choice !\n");
            break;
        }
    }
    return 0;
}