#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>
#include <conio.h>


typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

/* Helper function that allocates a new node with the given data
and NULL left and right pointer */
struct node *NewNode(int data){
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;

    return(node);
};

void insert();
void search();
void delete();
void Inorder(struct node *root);
void Preorder(struct node *root);
void Postorder(struct node *root);
int height(struct node *node);
void PrintLevel(struct node *root, int level);
void LevelOrder(struct node *root);

node *root;

int main(){
    int select;

    while(1){
        system("cls");
        printf("BINARY TREE\n");
        printf("-------------------------------------------\n");
        printf("Selection:\n");
        printf("1.\tInsert a Value to the Tree.\n");
        printf("2.\tSearch a Value.\n");
        printf("3.\tDelete A Value.\n");
        printf("4.\tTraverse Inorder.\n");
        printf("5.\tTraverse Preorder.\n");
        printf("6.\tTraverse Postorder.\n");
        printf("7.\tShow Level Order.\n");
        printf("8.\tEND\n");
        printf("-------------------------------------------\n");
        printf("Enter Selection: ");
        scanf("%d", &select);

        switch(select){
            case 1:
                system("cls");
                insert();
                break;
            case 2:
                system("cls");
                search();
                break;
            case 3:
                system("cls");
                delete();
                break;
            case 4:
                system("cls");
                printf("Inorder Traversal\n");
                Inorder(root);
                printf("END\n");
                printf("Continue...");
                getch();
                break;
            case 5:
                system("cls");
                printf("Preorder Traversal\n");
                Preorder(root);
                printf("END\n");
                printf("Continue...");
                getch();
                break;
            case 6:
                system("cls");
                printf("Postorder Traversal\n");
                Postorder(root);
                printf("END\n");
                printf("Continue...");
                getch();
                break;
            case 7:
                system("cls");
                printf("Level Order traversal of binary tree is \n");
                LevelOrder(root);
                printf("END\n");
                printf("Continue...");
                getch();
                break;
            case 8:
                exit(0);
            default:
                system("CLS");
                printf("Invalid Selection!");
                getch();
                break;
        }
    }

    return(0);
}

void insert(){
    node *NewNode, *Current, *Previous;

    NewNode = (node*)malloc(sizeof(node));
    printf("Insert a Value to the Tree\n");
    printf("Enter Value: ");
    scanf("%d", &NewNode->data);

    if(root==NULL){
        root = NewNode;
        root->left=NULL;
        root->right=NULL;
    }else{
        Previous = NULL;
        Current = root;

        while(Current!=NULL){
            Previous = Current;

            if(Current->data < NewNode->data){
                Current = Current->right;
            }else{
                Current = Current->left;
            }
        }

        if(Previous->data < NewNode->data){
            Previous->right = NewNode;
            Previous->right->right=NULL;
            Previous->right->left=NULL;
        }else{
            Previous->left = NewNode;
            Previous->left->right=NULL;
            Previous->left->left=NULL;
        }
    }
    printf("\n%d is inserted!", NewNode->data);
    getch();
    
    NewNode=Previous=NULL;
}

void search(){
    node *Search;
    int value, flag=0;
    char temp;

    printf("What value are you searching?\n");
    printf("Enter Value: ");
    scanf("%d", &value);

    Search=root;

    while(Search!=NULL && flag!=1){
        if(Search->data==value){
            flag=1;
        }else if(Search->data < value){
            Search = Search->right;
        }else{
            Search = Search->left;
        }
    }

    if(flag==1){
        printf("%d was found!", value);
        getch();
    }else{
        printf("%d is not found!", value);
        getch();
    }
}

void delete(){
    node *Search, *Previous, *Current, *ptr1, *ptr2;
    int value, flag=0;

    printf("What value are you deleting?\n");
    printf("Enter Value: ");
    scanf("%d", &value);

    Search=root;

    while(Search != NULL && flag!=1){
        //node is a root and a leaf at the same time
        if(root->data==value && root->left==NULL && root->right==NULL){
            root=NULL;
            flag=1;
        }else if(value < Search->data){
            Previous=Search;
            Search=Search->left;
        }else if(value > Search->data){
            Previous=Search;
            Search=Search->right;
        }else{
            flag=1;

            //node is a leaf

            if(Search->left==NULL && Search->right==NULL){
                //node has no child
                
                if(Previous->left==Search){
                    Previous->left=NULL;
                }else{
                    Previous->right=NULL;
                }

                free(Search);
            }else if(Search->left==NULL||Search->right==NULL){
                //node has one child

                if(Search->left!=NULL){
                    if(Search->left->data > Previous->data){
                        Previous->right=Search->left;
                    }else{
                        Previous->left=Search->left;
                    }
                }else{
                    Previous->right=Search->right;
                }
            }else{
                //node has two child

                ptr1=Search->right;
                ptr2=Search->left;
                Current=Search->right;

                while(Current->left!=NULL){
                    Current=Current->left;
                }

                if(Search->data > Previous->data){
                    Previous->right=ptr1;
                }else{
                    Previous->left=ptr1;
                }

                Current->left=ptr2;
            }
        }
    }

    printf("%d has been deleted!", value);
    getch();
}

//Functions on Inorder, Preorder, and Postorder Traversal
void Inorder(struct node* root){
    //Left->Root->Right
    if(root!=NULL){
        Inorder(root->left);
        printf("%d -> ", root->data);
        Inorder(root->right);
    }else{
        return;
    }
}

void Preorder(struct node *root){
    //Root->Left->Right
    if(root!=NULL){
        printf("%d -> ", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }else{
        return;
    }
}

void Postorder(struct node *root){
    //Left->Right->Root
    if(root!=NULL){
        Postorder(root->left);
        Postorder(root->right);
        printf("%d -> ", root->data);
    }else{
        return;
    }
}

//Level Order Functions
//Computes the height of the tree
int height(struct node *node){
    if(node!=NULL){
        int lheight, rheight;

        lheight = height(node->left);
        rheight = height(node->left);

        if(lheight > rheight){
            return(lheight + 1);
        }else{
            return(rheight + 1);
        }
    }else{
        return(0);
    }
}

//Displays the nodes at a current level
void PrintLevel(struct node *root, int level){
    if(root == NULL){
        return;
    }else if(level == 1){
        printf("%d -> ", root->data);
    }else if(level > 1){
        PrintLevel(root->left, level-1);
        PrintLevel(root->right, level-1);
    }
}

//Function to display the level order
void LevelOrder(struct node *root){
    int h, i;

    h = height(root);

    for(i=1; i<=h; i++){
        PrintLevel(root, i);
    }
}