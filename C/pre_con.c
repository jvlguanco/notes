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
void ToPre(char infix[], char prefix[]);
char reverse(char array[]);

char stack[SIZE];
int top=-1;

int main(){
    char infix[SIZE], prefix[SIZE];

    system("cls");
    printf("ASSUMPTION: The infix expression contains single letter variables and single digit constants only.\n");
	printf("Enter Infix expression: ");
    gets(infix);

    ToPre(infix,prefix);
    reverse(prefix);
    printf("Prefix Expression: ");
    puts(prefix);

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
    if(symbol=='^' || symbol=='*' || symbol=='/' || symbol=='+' || symbol=='-' || symbol == '$' || symbol == '#' || symbol == '(' || symbol == ')'){
		return 1;
	}else{
	    return 0;
	}
}

int precedence(char symbol){
    if(symbol == '^' || symbol == '$'){
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

char reverse(char array[SIZE]){
    int i,j;
    char temp[SIZE];

    for(i=strlen(array)-1,j=0; i+1 != 0;--i, ++j){
        temp[j]=array[i];
    }

    temp[j]='\0';
    strcpy(array,temp);
	return array;
}

void ToPre(char infix[], char prefix[]){
    int i,j=0;
	char symbol;

    stack[++top]='#';
    reverse(infix);

    for(i=0; i<strlen(infix); i++){
        symbol=infix[i];

        if(operator(symbol) == 0){
            prefix[j]=symbol;
			j++;
        }else{
            if(symbol==')'){
				push(symbol);
			}else if(symbol == '(') {
				while (stack[top]!=')'){
					prefix[j]=pop();
					j++;
				}
				pop();
            }else{
                if(precedence(stack[top]) <= precedence(symbol)){
                    push(symbol);
                }else{
                    while(precedence(stack[top]) >= precedence(symbol)){
                        prefix[j]=pop();
						j++;
                    }

                    push(symbol);
                }
            }
        }
    }

    while (stack[top]!='#') {
		prefix[j]=pop();
		j++;
	}
	prefix[j]='\0';
}