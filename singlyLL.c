#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node* head = NULL;
//struct Node* tail = NULL;
void insertAtBeginning(){
    int data;
    printf("Enter the Data to Insert : ");
    scanf("%d", &data);
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(head == NULL){
        head = temp;
        temp->next = NULL;
        temp->data = data;
        return;
    }
    else{
        temp->next = head;
        head = temp;
        temp->data = data;
        return;
    }
}
void insertAtPos(){
    int pos, data;
    printf("Enter the position : ");
    scanf("%d", &pos);
    if(pos == 1){
        insertAtBeginning();
        return;
    }
    printf("Enter the Data to Insert : ");
    scanf("%d", &data);
    int i = 2;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node* curr = head;
    while(i < pos){
        curr = curr->next;
        i++;
    }
    temp->next = curr->next;
    curr->next = temp;
    temp->data = data;
}
void insertAtEnd(){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    int data;
    printf("Enter the Data to Insert : ");
    scanf("%d", &data);
    if(head == NULL){
        head = temp;
        temp->next = NULL;
        temp->data = data;
        return;
    }
    else{
        struct Node* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
        temp->data = data;
    }
}
void deleteFromBeginning(){
    struct Node* curr = head;
    head = curr->next;
    curr->next = NULL;
    printf("%d is deleted from List\n\n", curr->data);
    free(curr);
}
void deleteFromPos(){
    int pos;
    printf("Enter the Position to DELETE : ");
    scanf("%d", &pos);
    if(pos == 1){
        deleteFromBeginning();
        return;
    }
    struct Node* prev = NULL;
    struct Node* curr = head;
    int i = 1;
    while(i < pos){
        prev = curr;
        curr = curr->next;
        i++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    printf("%d is deleted from List\n\n", curr->data);
    free(curr);
}
void deleteFromEnd(){
    struct Node* prev = NULL;
    struct Node* curr = head;
    int i = 1;
    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;
        i++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    printf("%d is deleted from List\n\n", curr->data);
    free(curr);
}
void reverse(){
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
    return;
}
void display(){
    struct Node* temp = head;
    printf("The List is : ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("X \n\n");
    return;
}
int main()
{
    int ch;
    while(1){
        printf("\nEnter your choice :\n\n");
        printf("1 to INSERT AT BEGINNING    ");
        printf("2 to INSERT AT GIVEN POSITION    ");
        printf("3 to INSERT AT END\n\n");
        printf("4 to DELETE FROM BEGINNING    ");
        printf("5 to DELETE FROM GIVEN POSITION    ");
        printf("6 to DELETE FROM END    ");
        printf("7 to DISPLAY    \n\n");
        printf("8 to REVERSE THE LINKED LIST    ");
        printf("9 to EXIT\n");
        printf("\n");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            insertAtBeginning();
            break;
        case 2:
            insertAtPos();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromPos();
            break;
        case 6:
            deleteFromEnd();
            break;
        case 7:
            display();
            break;
        case 8:
            reverse();
            break;
        case 9:
            printf("Program Ended ! ");
            exit(1);
        default:
            printf("Invalid choice!");
            break;
        }
    }
    return 0;
}