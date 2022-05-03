#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>

void implementation(); //Creation of Node
void dis_td(); //Traversal Top Down
void dis_dt(); //Traversal Bottom Top
void ins_head(); //Insert at Start
void ins_tail(); //Insert at End
void ins_bef(); //Insert Before a Specific Value
void ins_af(); //Insert After a Specific Value
void del_head(); //Delete Start
void del_tail(); //Delete End
void del_val(); //Delete a Specific Value
void del_bef(); //Delete Before a Specific Value
void del_af(); //Delete Before a Specific Value

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

node *head, *tail;
int ctr=0;

int main(){
    int select;

    while(1){
        system("CLS");
        printf("DOUBLY LINKED LIST\n");
        printf("-------------------------------------------\n");
        printf("Selection:\n");
        printf("1.\tCreate a List.\n");
        printf("2.\tDisplay List Top to Bottom.\n");
        printf("3.\tDisplay List Bottom to Top.\n");
        printf("4.\tInsert Value at the Start.\n");
        printf("5.\tInsert Value at the End.\n");
        printf("6.\tInsert Value Before a Value.\n");
        printf("7.\tInsert Value After a Value.\n");
        printf("8.\tDelete the Starting Value.\n");
        printf("9.\tDelete the Last Value.\n");
        printf("10.\tDelete a Specific Value.\n");
        printf("11.\tDelete a Value Before a Specific Value.\n");
        printf("12.\tDelete a Value After a Specific Value.\n");
        printf("13.\tEND\n");
        printf("-------------------------------------------\n");
        printf("Enter Selection: ");
        scanf("%d", &select);
        
        switch(select){
            case 1:
                system("CLS");
                implementation();
                break;
            case 2:
                system("CLS");
                dis_td();
                break;
            case 3:
                system("CLS");
                dis_dt();
                break;
            case 4:
                system("CLS");
                ins_head();
                break;
            case 5:
                system("CLS");
                ins_tail();
                break;
            case 6:
                system("CLS");
                ins_bef();
                break;
            case 7:
                system("CLS");
                ins_af();
                break;
            case 8:
                system("CLS");
                del_head();
                break;
            case 9:
                system("CLS");
                del_tail();
                break;
            case 10:
                system("CLS");
                del_val();
                break;
            case 11:
                system("CLS");
                del_bef();
                break;
            case 12:
                system("CLS");
                del_af();
                break;
            case 13:
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

void implementation(){
    node *NewNode;
    char yn, temp;
    
    ctr=0;

    NewNode = (node*)malloc(sizeof(node)); //Allocating Memory
    head = NewNode;
    tail = NewNode;
    head->prev = NULL;

    printf("Creating List\n\n");
    do{
        ctr++;
        printf("Node No. %d\n", ctr);
        printf("Enter Data => ");
        scanf("%d", &NewNode->data); //Input value
        scanf("%c", &temp);
        printf("\nAdd a New Node [Y/N]? ");
        scanf("%c", &yn);
        printf("\n");

        if(toupper(yn) == 'Y'){
            NewNode->next = (node*)malloc(sizeof(node)); //Allocating new memory for the next value
            NewNode->next->prev = NewNode;
            NewNode = NewNode->next;
            tail = NewNode;
        }
    }while(toupper(yn)=='Y');
    tail->next=NULL; //Declaring the last pointed value
    NewNode=NULL;
}

void dis_td(){
    node *TravNode; //Variable Declaration
    ctr=0;

    TravNode = head;

    if(TravNode==NULL){
        printf("List is Empty...");
        getch();
    }else{
        printf("Displaying Content of the List:\n\n");

        //Looping through the nodes
        do{
            ctr++;
            printf("Node %d Content:\n", ctr);
            printf("\tData => %d\n", TravNode->data);

            TravNode=TravNode->next; //Change nodes
        }while(TravNode!=NULL);

        printf("\nContinue...");
        getch();
    }
}

void dis_dt(){
    node *TravNode; //Variable Declaration
    
    TravNode = tail;

    if(TravNode==NULL){
        printf("List is Empty...");
        getch();
    }else{
        printf("Displaying Content of the List:\n\n");

        //Looping through the nodes
        do{
            printf("Node %d Content:\n", ctr);
            printf("\tData => %d\n", TravNode->data);

            TravNode=TravNode->prev; //Change nodes
            ctr--;
        }while(TravNode!=NULL);

        printf("\nContinue...");
        getch();
    }
}

void ins_head(){
    node *NewNode;

    NewNode = (node*)malloc(sizeof(node));

    printf("Enter Value to Insert at Start: ");
    scanf("%d", &NewNode->data); //Input value

    NewNode->next = NULL;
    NewNode->prev = NULL;

    if(head==NULL){
        head=tail=NewNode;
    }else{
        NewNode->next=head;
        head->prev=NewNode;
        head=NewNode;
    }

    NewNode=NULL;
    printf("Value has been added...");
    getch();
}

void ins_tail(){
    node *NewNode;

    NewNode = (node*)malloc(sizeof(node));

    printf("Enter Value to Insert at End: ");
    scanf("%d", &NewNode->data); //Input value

    NewNode->next = NULL;
    NewNode->prev = NULL;

    if(head==NULL){
        head=tail=NewNode;
    }else{
        NewNode->prev=tail;
        tail->next=NewNode;
        tail=NewNode;
    }

    NewNode=NULL;
    printf("Value has been added...");
    getch();
}

void ins_bef(){
    node *NewNode, *Current;
    int value, flag=0;

    NewNode = (node*)malloc(sizeof(node));
    Current=head;

    if(Current==NULL){
        printf("The list is empty...");
        getch();
    }else{
        printf("Enter Value to be Added: ");
        scanf("%d", &NewNode->data); //Input value

        NewNode->next = NULL;
        NewNode->prev = NULL;

        printf("Enter the value where is it going to be inserted (Before the Value): ");
        scanf("%d", &value); //Input value

        while(flag!=1 && Current!=NULL){
            if(Current->data==value){
                flag=1;
            }else{
                Current=Current->next;
            }
        }

        if(flag==1){
            if(Current==head){
                NewNode->next=head;
                head->prev=NewNode;
                head=NewNode;
            }else{
                NewNode->next=Current;
                NewNode->prev=Current->prev;
                Current->prev->next=NewNode;
                Current->prev=NewNode;
            }

            printf("\nValue has been added...");
            getch();
        }else{
            printf("\nValue Does Not Exist!");
            getch();
        }
    }
    Current=NewNode=NULL;
}

void ins_af(){
    node *NewNode, *Current;
    int value, flag=0;

    NewNode = (node*)malloc(sizeof(node));
    Current=head;

    if(Current==NULL){
        printf("The list is empty...");
        getch();
    }else{
        printf("Enter Value to be Added: ");
        scanf("%d", &NewNode->data); //Input value

        NewNode->next = NULL;
        NewNode->prev = NULL;

        printf("Enter the value where is it going to be inserted (After the Value): ");
        scanf("%d", &value); //Input value

        while(flag!=1 && Current!=NULL){
            if(Current->data==value){
                flag=1;
            }else{
                Current=Current->next;
            }
        }

        if(flag==1){
            if(Current==tail){
                NewNode->prev=tail;
                tail->next=NewNode;
                tail=NewNode;
            }else{
                NewNode->next=Current->next;
                NewNode->prev=Current;
                Current->next->prev=NewNode;
                Current->next=NewNode;
            }
            printf("\nValue has been added...");
            getch();
        }else{
            printf("\nValue Does Not Exist!");
            getch();
        }
    }
    Current=NewNode=NULL;
}

void del_head(){
    node *DelNode;

    DelNode=head;

    if(DelNode==NULL){
        printf("The list is empty...");
        getch();
    }else{
        if(tail==head){
            head=NULL;
            tail=NULL;
            ctr--;
        }else{
            head=head->next;
            head->prev=NULL;
            DelNode->next=NULL;
            ctr--;
        }
        
        free(DelNode);
        DelNode=NULL;
        
        printf("The Starting Value has been deleted...");
        getch();
    }
}

void del_tail(){
    node *DelNode;

    DelNode=tail;

    if(DelNode==NULL){
        printf("The list is empty...");
        getch();
    }else{
        if(tail==head){
            head=NULL;
            tail=NULL;
            ctr--;
        }else{
            tail=tail->prev;
            tail->next=NULL;
            DelNode->prev=NULL;
            ctr--;
        }

        free(DelNode);
        DelNode=NULL;

        printf("The Ending Value has been deleted...");
        getch();
    }
}

void del_val(){
    node *DelNode;
    int flag=0, value;

    DelNode=head;

    if(DelNode==NULL){
        printf("The list is empty...");
        getch();
    }else{
        printf("Enter the value you want to delete: ");
        scanf("%d", &value); //Input specific value to be deleted

        while(flag!=1 && DelNode!=NULL){
            if(DelNode->data==value){
                flag=1;
            }else{
                DelNode=DelNode->next;
            }
        }

        if(flag==1){
            if(tail==head){
                head=NULL;
                tail=NULL;
                ctr--;
            }else if(DelNode==head){
                head=head->next;
                head->prev=NULL;
                DelNode->next=NULL;
                ctr--;
            }
            else{
                DelNode->prev->next=DelNode->next;
                DelNode->next->prev=DelNode->prev;
                DelNode->next=NULL;
                DelNode->prev=NULL;
                ctr--;
            }

            free(DelNode);
            DelNode=NULL;

            printf("\n%d is deleted...", value);
            getch();
        }else{
            printf("\nValue Does Not Exist!");
            getch();
        }
    }
}

void del_bef(){
    node *DelNode, *Current;
    int value, flag=0;

    Current=head;
    DelNode=NULL;

    if(Current==NULL){
        printf("The list is empty...");
        getch();
    }else{
        printf("Delete the Value Before a Specific Node\n");
        printf("Enter the Value of the Node: ");
        scanf("%d", &value); //Node value

        while(flag!=1 && Current!=NULL){
            if(Current->data==value){
				flag=1;
            }else{
                DelNode=Current;
                Current=Current->next;
                ctr--;
			}
        }

        if(flag==1){
            if(DelNode==NULL){
                printf("\nNode before value %d does not exist...",value);
                getch();
            }else if(DelNode==head){
                head=Current;
                head->prev=NULL;
                DelNode->next=NULL;
                ctr--;

                printf("\nNode before value %d deleted...",value);
                getch();
            }else{
                DelNode->prev->next=DelNode->next;
                DelNode->next->prev=DelNode->prev;
                DelNode->next=NULL;
                DelNode->prev=NULL;
                ctr--;

                printf("\nNode before value %d deleted...",value);
                getch();
            }

            free(DelNode);
            DelNode=NULL;
        }else{
            printf("\nValue Does Not Exist!");
            getch();
        }
    }
}

void del_af(){
    node *DelNode, *Current;
    int value, flag=0;

    Current=head;
    DelNode=NULL;

    if(Current==NULL){
        printf("The list is empty...");
        getch();
    }else{
        printf("Delete the Value After a Specific Node\n");
        printf("Enter the Value of the Node: ");
        scanf("%d", &value);//Input the Node Value

        while(flag!=1 && Current!=NULL){
            if(Current->data==value){
				flag=1;
            }else{
                Current=Current->next;
			}
        }

        if(flag==1){
            if(Current->next==NULL){
                printf("\nNode after value %d does not exist...",value);
                getch(); 
            }else{
                DelNode=Current->next;

                if(DelNode==tail){
                    tail=tail->prev;
                    tail->next=NULL;
                    DelNode->prev=NULL;
                    free(DelNode);
                    DelNode=NULL;
                    ctr--;
                }else{
                    DelNode->prev->next=DelNode->next;
                    DelNode->next->prev=DelNode->prev;
                    DelNode->next=NULL;
                    DelNode->prev=NULL;
                    ctr--;
                }
                printf("\nNode after value %d deleted...",value);
                getch();
            }
        }
    }
}