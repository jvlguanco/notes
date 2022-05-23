#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 30

void push(char ch);
char pop();
int operator(char symbol);
int precedence(char symbol);
void ToPost(char infix[], char postfix[]);

char stack[SIZE];
int top=-1;

int main(){
    char infix[SIZE], postfix[SIZE];

    system("cls");
    printf("ASSUMPTION: The infix expression contains single letter variables and single digit constants only.\n");
	printf("Enter Infix expression: ");
    gets(infix);

    ToPost(infix, postfix);
    printf("Postfix Expression: ");
    puts(postfix);

    system("pause");
    return(0);
}

void push(char ch){
    if(top >= SIZE-1){
		printf("\nStack Overflow.");
	}else{
		top++;
		stack[top] = ch;
	}
}

char pop(){
    char ch;

    if(top<0){
        printf("Stack Under Flow: Invalid Infix Expression");
		getch();
        exit(1);
    }else{
        ch=stack[top];
        top--;
        return(ch);
    }
}

int operator(char symbol){
    if(symbol=='^' || symbol=='*' || symbol=='/' || symbol=='+' || symbol=='-' || symbol == '#' || symbol == '(' || symbol == ')'){
		return 1;
	}else{
	    return 0;
	}
}

int precedence(char symbol){
    if(symbol == '^'){
		return(4);
	}else if(symbol == '*' || symbol == '/'){
		return(3);
	}else if(symbol == '+' || symbol == '-'){
		return(2);
	}else if(symbol == '#' || symbol == '(' || symbol == ')'){
        return(1); 
    }else{
		return(0);
	}
}

void ToPost(char infix[], char postfix[]){
    int i, j=0;
    char symbol;

    stack[++top]='#';

    for(i=0; i<strlen(infix); i++){
        symbol=infix[i];

        if(operator(symbol) == 0){
            postfix[j]=symbol;
			j++;
        }else{
            if(symbol=='('){
				push(symbol);
			}else if(symbol == ')') {
				while (stack[top]!='('){
					postfix[j]=pop();
					j++;
				}
				pop();
            }else{
                if(precedence(stack[top]) <= precedence(symbol)){
                    push(symbol);
                }else{
                    while(precedence(stack[top]) >= precedence(symbol)){
                        postfix[j]=pop(); 
						j++;
                    }

                    push(symbol);
                }
            }
        }
    }

    while(stack[top]!='#'){
		postfix[j]=pop();
		j++;
	}

    postfix[j] = '\0';
}