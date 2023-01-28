#include<stdio.h>
#include<stdlib.h>
#define size 3
int CQ[size];
int front = -1, rear = -1;
void enqueue(){
    int data;
    printf("Enter data to enqueue : ");
    scanf("%d", &data);
    if((front == 0 && rear == size - 1) || (front == rear + 1)){
        printf("Queue Overflow! Data is not pushed in Queue!\n\n");
        return;
    }
    else if(rear == size - 1){
        rear = (rear + 1) % size;
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
    }
    else{
        rear++;
    }
    CQ[rear] = data;
    printf("%d is enqueued in Queue\n\n", data);
}
void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue Underflow!\n\n");
    }
    else if(front == rear && front != -1){
        front = rear = -1;
    }
    else if(front == size - 1){
        front = (front + 1) % size;
    }
    else{
        front++;
    }
}
void display(){
    printf("Queue is : ");
    if(front < rear){
        for(int i = front; i <= rear; i++){
            printf("%d\t", CQ[i]);
        }
        printf("\n");
    }
    else{
        for(int i = front; i < size; i++){
            printf("%d\t", CQ[i]);
        }
        for(int i = 0; i <= rear; i++){
            printf("%d\t", CQ[i]);
        }
        printf("\n");
    }
}
int main()
{
    int ch;
    while(1){
        printf("Enter Your Choice : \n");
        printf("1 to ENQUEUE\t");
        printf("2 to DEQUEUE\t");
        printf("3 to DISPLAY\t");
        printf("4 to EXIT\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Program Ended!");
            exit(1);
        default:
            printf("Invalid Choice !");
            break;
        }
    }
    return 0;
}