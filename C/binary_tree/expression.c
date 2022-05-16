#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30

void push(int ch);
int pop();
void prefix();
void postfix();

int stack[SIZE], top=-1;

int main(){
    int select;

    while(1){
        system("cls");
        printf("Prefix and Postfix Evaluation\n");
        printf("-------------------------------------------\n");
        printf("Selection:\n");
        printf("1.\tPrefix\n");
        printf("2.\tPostfix\n");
        printf("3.\tEND\n");
        printf("-------------------------------------------\n");
        printf("Enter Selection: ");
        scanf("%d", &select);

        switch(select){
            case 1:
                system("cls");
                prefix();
                memset(stack, '\0', SIZE);
                break;
            case 2:
                system("cls");
                postfix();
                memset(stack, '\0', SIZE);
                break;
            case 3:
                exit(0);
        }
    }
    return(0);
}

void push(int ch){
    top++;
    stack[top]=ch;
}

int pop(){
    int ch;
    ch=stack[top];
	top--;
	return(ch);
}

void prefix(){
    int a, b, c=0, i;
    char prefix[SIZE], temp;

    scanf("%c", &temp);
    printf("Enter Prefix Expression: ");
    gets(prefix);

    for(i=strlen(prefix)-1;i>=0;i--){
        if(prefix[i]=='+'){
            c=pop()+pop();
            push(c);
        }else if(prefix[i]=='-'){
            a=pop();
			b=pop();
            c=b-a;
			push(c);
        }else if(prefix[i]=='*'){
            a=pop();
			b=pop();
            c=b*a;
			push(c);
        }else if(prefix[i]=='/'){
            a=pop();
			b=pop();
            c=b/a;
			push(c);
        }else{
            push(prefix[i]-48);
			printf("INT=%d - CHAR=%d\n",prefix[i]-48,c);
        }
    }

    printf("Answer: %d",pop());
    getch();
}

void postfix(){
    int a, b, c=0, i;
    char postfix[50], temp;

    scanf("%c", &temp);
    printf("Enter Postfix Expression: ");
    gets(postfix);

    for(i=0;i<=strlen(postfix)-1;i++){
        if(postfix[i]=='+'){
            c=pop()+pop();
            push(c);
        }else if(postfix[i]=='-'){
            a=pop();
			b=pop();
            c=b-a;
			push(c);
        }else if(postfix[i]=='*'){
            a=pop();
			b=pop();
            c=b*a;
			push(c);
        }else if(postfix[i]=='/'){
            a=pop();
			b=pop();
            c=b/a;
			push(c);
        }else{
            push(postfix[i]-48);
			printf("INT=%d - CHAR=%d\n",postfix[i]-48,c);
        }
    }

    printf("Answer: %d",pop());
    getch();
}