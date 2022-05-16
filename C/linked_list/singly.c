#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>

void implement(); //Creating A List
void display(); //Display List
void ins_head(); //Insert a Value at the Start
void ins_tail(); //Insert a Value at the End
void ins_bef(); //Insert a Value before a Specific Node
void ins_af(); //Insert a Value after a Specific Node
void del_head(); //Delete the Starting Value
void del_tail(); //Delete the Last Value
void del_val(); //Delete a Value
void del_bef(); //Delete a Value before a Specific Node
void del_af();//Delete a Value after a Specific Node

typedef struct node{
    int data;
    struct node *next;
}node;

node *START;

int main(){
    int select;

    //Selection Phase
    while(1){
        system("CLS");
        printf("SINGLE LINKED LIST\n");
        printf("-------------------------------------------\n");
        printf("Selection:\n");
        printf("1.\tCreate a List.\n");
        printf("2.\tDisplay List.\n");
        printf("3.\tInsert Value at the Start.\n");
        printf("4.\tInsert Value at the End.\n");
        printf("5.\tInsert Value Before a Value.\n");
        printf("6.\tInsert Value After a Value.\n");
        printf("7.\tDelete the Starting Value.\n");
        printf("8.\tDelete the Last Value.\n");
        printf("9.\tDelete a Specific Value.\n");
        printf("10.\tDelete a Value Before a Specific Value.\n");
        printf("11.\tDelete a Value After a Specific Value.\n");
        printf("12.\tEND\n");
        printf("-------------------------------------------\n");
        printf("Enter Selection: ");
        scanf("%d", &select);

        switch (select){
            case 1:
                system("CLS");
                implement();
                break;
            case 2:
                system("CLS");
                display();
                break;
            case 3:
                system("CLS");
                ins_head();
                break;
            case 4:
                system("CLS");
                ins_tail();
                break;
            case 5:
                system("CLS");
                ins_bef();
                break;
            case 6:
                system("CLS");
                ins_af();
                break;
            case 7:
                system("CLS");
                del_head();
                break;
            case 8:
                system("CLS");
                del_tail();
                break;
            case 9:
                system("CLS");
                del_val();
                break;
            case 10:
                system("CLS");
                del_bef();
                break;
            case 11:
                system("CLS");
                del_af();
                break;
            case 12:
                exit(0);
                break;
            default:
                system("CLS");
                printf("Invalid Selection!");
                getch();
                break;
        }
    }
    return(0);
}

void implement(){
    node *NewNode;
    char yn, temp;
    int ctr=1;

    START=NULL;
    NewNode=(node*)malloc(sizeof(node)); //Allocating Memory
    START=NewNode; //Declaring the Starting variable
    printf("Creating List\n\n");

    do{
        printf("Node No. %d\n", ctr);
        printf("Enter Data => ");
        scanf("%d", &NewNode->data); //Input value
        scanf("%c", &temp);
        printf("\nAdd a New Node [Y/N]? ");
        scanf("%c", &yn);
        printf("\n");

        if(toupper(yn) == 'Y'){
            ctr++;
            NewNode->next=(node*)malloc(sizeof(node)); //Allocating new memory for the next value
            NewNode = NewNode->next;
        }
    }while(toupper(yn)=='Y');
    NewNode->next=NULL; //Declaring the last pointed value
    NewNode=NULL;
}

void display(){
    node *Current; //Variable Declaration
    int ctr=1;

    Current=START;

    if(Current==NULL){
        printf("The List is Empty!");
        getch();
    }else{
        printf("Displaying Content of the List:\n\n");

        //Looping through the nodes
        do{
            printf("Node %d Content:\n", ctr);
            printf("\tData => %d\n", Current->data);

            Current=Current->next; //Change nodes
            ctr++;
        }while(Current!=NULL);
        printf("\nContinue...");
        getch();
    }
}

void ins_head(){
    node *NewNode;
    char temp;

    NewNode=(node*)malloc(sizeof(node)); //Allocating Memory for the New Node
    
    scanf("%c", &temp);  
    printf("Enter Value: ");
    scanf("%d", &NewNode->data); //Input value

    NewNode->next=NULL;

    if(START==NULL){
        START=NewNode;
    }else{
        NewNode->next=START; //Redirecting pointer
        START=NewNode; //Declaring new starting value
    }
}

void ins_tail(){
    node *Previous, *Current; //Variable Declaration
    char temp;

    Current=(node*)malloc(sizeof(node)); //Allocating new memory

    scanf("%c", &temp);
    printf("Enter Value: ");
    scanf("%d",&Current->data); //Input Value

    Current->next=NULL;

    if(START==NULL){
        START=Current;
    }else{
        Previous=START;
        
        //Locating Value
        while(Previous->next!=NULL){
            Previous=Previous->next;
        }

        Previous->next = Current; //Declaration of final value
    }
}

void ins_bef(){
    node *Current, *Previous, *NewNode; //Variable declaration
    int bef_val, flag=0;
    char temp;

    NewNode=(node*)malloc(sizeof(node));//Allocating memory

    scanf("%c", &temp);
    printf("Enter the value: ");
    scanf("%d", &NewNode->data);//Input value to be added
    NewNode->next=NULL;

    Previous=NULL;
    Current=START; //Preparation for searching

    if(Current==NULL){
        printf("The List is Empty!");
        getch();
    }else{
        printf("Enter the value where is it going to be inserted (Before the Value): ");
        scanf("%d", &bef_val);//Input the node value  

        //Locating the value
        do{
            if(bef_val == Current->data){
                flag=1;
            }else{
                Previous=Current;
                Current=Current->next;
            }
        }while(flag!=1 && Current!=NULL);

        //Connecting the values
        if(flag==1){
            NewNode->next=Current;

            if(Previous==NULL){
                START=NewNode;
            }else{
                Previous->next=NewNode;
            }
            NewNode=NULL;
        }else{
            printf("Value Does Not Exist!");
            getch();
        }

        Previous=Current=NULL;  
    } 
}

void ins_af(){
    node *Current, *NewNode; //Variable declaration
    int af_val, flag=0;
    char temp;

    NewNode=(node*)malloc(sizeof(node));//Allocating memory

    scanf("%c", &temp);
    printf("Enter the value: ");
    scanf("%d", &NewNode->data); //Input value to be added
    NewNode->next=NULL;

    Current=START;//Preparation for searching

    if(Current==NULL){
        printf("The List is Empty!");
        getch();
    }else{
        printf("Enter the value where is it going to be inserted (After the Value): ");
        scanf("%d", &af_val); //Input Node Value

        //Searching
        do{
            if(af_val==Current->data){
                flag=1;
            }else{
                Current=Current->next;
            }
        }while(flag!=1 && Current!=NULL);

        //Connecting values
        if(flag==1){
            NewNode->next=Current->next;
            Current->next=NewNode;
            NewNode=NULL;
        }else{
            printf("Value Does Not Exist!");
            getch();
        }
        Current=NULL;
    }
}

void del_head(){
    node *DelNode; //Variable Declaration

    if(START==NULL){
        printf("The List is Empty!");
        getch();
    }else{
        //Deletion process of the starting value
        DelNode=START;
        START=START->next;
        DelNode->next=NULL;
        free(DelNode);
        DelNode=NULL;

        printf("The Starting Value has been deleted...");
        getch(); 
    }
}

void del_tail(){
    node *DelNode, *Previous; //Variable declaration

    Previous=NULL;
    DelNode=START; //Preparation for searching

    if(START==NULL){
        printf("The List is Empty!");
        getch();
    }else if(DelNode==START){
        DelNode=START;
        START=START->next;
        DelNode->next=NULL;
        free(DelNode);
        DelNode=NULL;

        printf("The Last Value has been deleted...");
        getch();
    }else{
        //Locating the end of the list
        while(DelNode->next!=NULL){
            Previous=DelNode;
            DelNode=DelNode->next;
        }
        //Deleting the last value
        Previous->next=NULL;
        Previous=NULL;
        free(DelNode);
        DelNode=NULL;

        printf("The Last Value has been deleted...");
        getch();
    }
    
}

void del_val(){
    node *Previous, *DelNode; //Variable declaration
    int flag=0, value;
    char temp;

    if(START==NULL){
        printf("The List is Empty!");
        getch();
    }else{
        scanf("%c", &temp);
        printf("Enter the value you want to delete: ");
        scanf("%d", &value); //Input specific value to be deleted

        Previous=NULL;
        DelNode=START; //Preparation for searching

        //Searching for value
        while(flag!=1 && DelNode!=NULL){
            if(value == DelNode->data){
                flag=1;
            }else{
                Previous=DelNode;
                DelNode=DelNode->next;
            }
        }

        if(flag==0){
            printf("The List is Empty!");
            getch();
        }else{
            //Deleting and reconneting remaining values
            if(DelNode==START){
                START=START->next;
                DelNode->next=NULL;
            }else{
                Previous->next=DelNode->next;
                DelNode->next=NULL;
            }
            free(DelNode);

            printf("\n\n%d is deleted...", value);
            getch();
        }
        Previous=DelNode=NULL;
    }
}

void del_bef(){
    node *DelNode, *Current, *Previous, *Temp; //Variable declaration
    int value, flag=0;

    //Preparation for searching
    DelNode=NULL;
    Previous=NULL;
    Current=START;

    if(START==NULL){
        printf("The List is Empty!");
        getch();
    }else{
        printf("Delete the Value Before a Specific Node\n");
        printf("Enter the Value of the Node: ");
        scanf("%d", &value); //Node value

        while(flag!=1 && Current!=NULL){
            if(Current->data==value){
				flag=1;
            }else{
				Previous=DelNode;
				DelNode=Current;
				Current=Current->next; //point to next node
			}
        }

        if(flag==0){
			printf("Data not found...");
            getch();
        }else{
            if(DelNode==NULL){
                printf("Node before value %d does not exist...",value);
                getch();
                Current=NULL;//detach delnode from start
            }else if(DelNode==START){
                START=Current;
                DelNode->next=NULL;
                free(DelNode);
                printf("Node before value %d deleted...",value);
                getch();
            }else{
                Previous->next=DelNode->next;
                DelNode->next=NULL;//detach node-to-be-deleted
                free(DelNode);
                printf("Node before value %d has been deleted...",value);
                getch();
            }
        } 
        Previous=DelNode=Current=NULL; //detach pointers
    }
}

void del_af(){
    node *DelNode, *Current; //Variable Declaration
    int value, flag=0;
    char temp;

    scanf("%c", &temp);

    DelNode=NULL;
    Current=START;

    if(Current==NULL){
        printf("The List is Empty!");
        getch();
    }else{
        printf("Delete the Value After a Specific Node\n");
        printf("Enter the Value of the Node: ");
        scanf("%d", &value);//Input the Node Value

        //Locating the Node Value
        while(Current!=NULL && flag!=1){
            if(Current->data==value){
                flag=1;
            }else{
                Current=Current->next;
            }
        }

        if(flag==0){
            printf("Data not found...");
            getch();
        }else{
            if(Current->next==NULL){
               printf("\nNode after value %d does not exist...",value);
               getch(); 
            }else{
                //Deleting and reconnecting the links
            DelNode=Current->next;
            Current->next=DelNode->next;
            DelNode->next=NULL;
            free(DelNode);
            printf("\n\nThe Node after the value %d is deleted...", value);
            getch();
            }
            DelNode=Current=NULL;
        }
    }
}