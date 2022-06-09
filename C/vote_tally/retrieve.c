#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define SIZE 4
#define PREC 5

typedef struct{
    char name[50];
    int vote[PREC], can_total;
    float percent;
}Record;

void declare(float *first, float *second);
void winner(float first, float second);
void table(float first, float second);

Record candidate[SIZE], temp;

int main(){
    FILE *VOTEREC;
    int i;
    float first, second, total;
    char file[20];

    system("cls");
    printf("Enter Filename where records will be retrieved: ");
    scanf("%s", &file);
    printf("\nRetrieving records from %s...\n\n",file);
    
    i = 0;
    VOTEREC = fopen(file, "r");
    fread(&temp, sizeof(temp), 1, VOTEREC);

    while(!feof(VOTEREC)){
        candidate[i]=temp;
        fread(&temp,sizeof(temp),1,VOTEREC);
        i++;
    }
    fclose(VOTEREC);

    printf("%d records retrieved!!!",i);
    printf("\nPress Any Key To Preview Results...");
    getch();
    system("cls");

    declare(&first, &second);
    table(first, second);

    getch();
    return(0);
}

void declare(float *first, float *second){
    float temp;
    int i, j; 

    *first = candidate[0].percent;
    *second = candidate[1].percent;

    if(*second > *first){
        temp = *first;
        *first = *second;
        *second = temp;
    }

    for(i = 2; i < SIZE; i++){
        if(candidate[i].percent > *first){
            *second = *first;
            *first = candidate[i].percent;
        }else if(candidate[i].percent > *second && candidate[i].percent != *first){
            *second = candidate[i].percent;
        }
    }
}

void winner(float first, float second){
    int i, j;

    if(first >= 50){
        for(i = 0; i < SIZE; i++){
            if(first == candidate[i].percent){
                printf("The winner %s!\n", candidate[i].name);
            }
        }
    }else{
        for(i = 0; i < SIZE; i++){
            for(j = 0; j < SIZE; j++){
                if(first == candidate[i].percent && second == candidate[j].percent){
                    printf("There is going to be a run-off between %s and %s!", candidate[i].name, candidate[j].name);
                }
            }
        }
    }
}

void table(float first, float second){
    int i, j;

    printf("TALLY OF VOTE PER PRECINCT\n");
    printf("--------------------------------------------------------------------------\n");
    printf("\tCandidate\tCandidate\tCandidate\tCandidate\n");

    for(i = 0; i < SIZE; i++){
        printf("\t%s", candidate[i].name);
        printf("\t");
    }

    printf("\nPrecincts\n");
    for(j = 0; j < PREC; j++){
        printf("%d", j+1);
        for(i = 0; i < SIZE; i++){
            printf("\t%d", candidate[i].vote[j]);
            printf("\t");
        }
        printf("\n\n");
    }

    printf("Percentage\n");
    for(i = 0; i < SIZE; i++){
        printf("\t%0.2f", candidate[i].percent);
        printf("\t");
    }

    printf("\n\n");
    winner(first, second);
}