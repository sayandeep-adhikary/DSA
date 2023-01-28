#include<stdio.h>
#include<stdlib.h>
#define size 5
int Q[size];
int front = -1;
int rear = -1;
void enqueue(int data){
    if(rear == size - 1){
        printf("Queue Overflow! data is not pushed!\n\n");
        return;
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
    }
    else{
        rear++;
    }
    Q[rear] = data;
    printf("%d is enqueued in Queue\n\n", data);
}
void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue Underflow!\n\n");
        return;
    }
    else if(front == rear && front != -1){
        front = rear = -1;
        return;
    }
    printf("%d is dequeued from Queue\n\n", Q[front]);
    front++;
}
void display(){
    printf("Queue is : ");
    if(front == -1){
        printf("EMPTY!\n");
        return;
    }
    else{
        for(int i = front; i <= rear; i++){
        printf("%d\t", Q[i]);
        }
        printf("\n\n");
    }
}
int main()
{
    int ch;
    int data;
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
            printf("Enter the data to ENQUEUE : ");
            scanf("%d", &data);
            enqueue(data);
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