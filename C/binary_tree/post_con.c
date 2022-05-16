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
		top = top+1;
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
        top = top-1;
        return(ch);
    }
}

int operator(char symbol){
    if(symbol=='^' || symbol=='*' || symbol=='/' || symbol=='+' || symbol=='-'){
		return 1;
	}else{
	    return 0;
	}
}

int precedence(char symbol){
    if(symbol == '^'){
		return(3);
	}else if(symbol == '*' || symbol == '/'){
		return(2);
	}else if(symbol == '+' || symbol == '-'){
		return(1);
	}else{
		return(0);
	}
}

void ToPost(char infix[], char postfix[]){
    int i=0, j=0;
    char ch, x;

    push('('); // push '(' in the stack
    strcat(infix,")"); // concatinate ')' in the infix expression

    ch=infix[i];

    while(ch != '\0'){
        if(ch == '('){
            push(ch);
        }else if(isdigit(ch) || isalpha(ch)){
            postfix[j]=ch; // add operand symbol to postfix
            j++;
        }else if(operator(ch)==1){
            x=pop();
            while(operator(x)==1 && precedence(x)>=precedence(ch)){
                postfix[j]=x; // pops higher precedence
                j++;
                x=pop(); // adds to postfix
            }
            push(x);
            push(ch);
        }else if(ch == ')'){
            x=pop();
            while(x != '('){
                postfix[j]=x;
                j++;
                x=pop();
            }
        }else{
            printf("Invalid infix Expression.\n");
            getch();
            exit(1);
        }
        i++;

        ch = infix[i];
    }

    if(top>0){
        printf("Invalid infix Expression.\n");
        getch();
        exit(1);
    }

    postfix[j] = '\0';
}