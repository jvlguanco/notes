#include <stdio.h>
#include <conio.h>
#include <string.h>

void push(int ch);
int pop();

int stack[50], top=-1;

int main(){
    int a, b, c, i;
    char postfix[50];

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
            c=pop()*pop();
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