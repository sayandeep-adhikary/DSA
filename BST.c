#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node * root = NULL;

void createBST(int data){
    struct Node* root1, *temp;
    root1 = root;
    while(1){
        if(root1 == NULL){
            root1 = (struct Node*)malloc(sizeof(struct Node));
            root1->data = data;
            root1->left = NULL;
            root1->right = NULL;
            root = root1;
            break;
        }
        else{
            if(data < root1->data){
                if(root1->left == NULL){
                    temp = (struct Node*)malloc(sizeof(struct Node));
                    temp->data = data;
                    temp->left = NULL;
                    temp->right = NULL;
                    root1->left = temp;
                    break;
                }
                else{
                    root1 = root1->left;
                }
            }
            else{
                if(root1->right == NULL){
                    temp = (struct Node*)malloc(sizeof(struct Node));
                    temp->data = data;
                    temp->left = NULL;
                    temp->right = NULL;
                    root1->right = temp;
                    break;
                }
                else{
                    root1 = root1->right;
                }
            }
        }
    }
    
}
void inorder(struct Node * root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}
void preorder(struct Node * root){
    if(root == NULL){
        return;
    }
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node * root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}
int height(struct Node* root){
    if(root != NULL){
        int leftSubtree = height(root->left);
        int rightSubtree = height(root->right);
        if(leftSubtree > rightSubtree){
            return leftSubtree + 1;
        }
        else{
            return rightSubtree + 1;
        }
    }
    
}
int main()
{
    int ch;
    while(1){
        printf("\nPress 1 to CREATE BST\n\n");
        printf("Press 2 to INORDER TRAVERSAL\t");
        printf("Press 3 to PREORDER TRAVERSAL\t");
        printf("Press 4 to POSTORDER TRAVERSAL\n\n");
        printf("Press 5 to GET THE HEIGHT OF BST\t");
        printf("Press 6 to EXIT\n\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        printf("\n");
        int n, i, h;
        switch (ch)
        {
        case 1:
            printf("Enter the no of Nodes : ");
            scanf("%d", &n);
            printf("\n");
            i = 1;
            printf("Enter The Elements : ");
            while(i<=n){
                int data;
                scanf("%d", &data);
                createBST(data);
                i++;
            }
            break;
        case 2:
            printf("INORDER TRAVERSAL : ");
            inorder(root);
            printf("\n\n");
            break;
        case 3:
            printf("PREORDER TRAVERSAL : ");
            preorder(root);
            printf("\n\n");
            break;
        case 4:
            printf("POSTORDER TRAVERSAL : ");
            postorder(root);
            printf("\n\n");
            break;
        case 5:
            h = height(root) - 1;
            printf("The HEIGHT of BST is : %d\n\n", h);
            break;
        case 6:
            printf("Program Ended!");
            exit(1);
        default:
            printf("Invalid Choice!\n\n");
            break;
        }
    }
    return 0;
}