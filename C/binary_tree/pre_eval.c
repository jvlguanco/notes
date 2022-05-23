#include <stdio.h>
#include <conio.h>
#include <string.h>

void push(int ch);
int pop();

int stack[50], top=0;

int main(){
    int a, b, c, i;
    char prefix[50];

    printf("Enter Prefix Expression: ");
    gets(prefix);

    for(i=strlen(prefix)-1;i>=0;i--){
        if(prefix[i]=='+'){
            c=pop()+pop();
            push(c);
        }else if(prefix[i]=='-'){
            a=pop();
			b=pop();
            c=a-b;
			push(c);
        }else if(prefix[i]=='*'){
            c=pop()*pop();
			push(c);
        }else if(prefix[i]=='/'){
            a=pop();
			b=pop();
            c=a/b;
			push(c);
        }else{
            push(prefix[i]-48);
			//printf("INT=%d - CHAR=%d\n",prefix[i]-48,c);
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
	top=top-1;
	return(ch);
}