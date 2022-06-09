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

Record votes();
void percentage(float total, Record *p);
void declare(float *first, float *second);
void winner(float first, float second);
void table(float first, float second);

Record candidate[SIZE], temp;

int main(){
    FILE *VOTEREC;
    int i, j;
    float first, second, total;
    char file[20];

    system("cls");
    for(i = 0; i < SIZE; i++){
        candidate[i] = votes();
        system("cls");
    }

    for(i = 0; i < SIZE; i++){
        total += candidate[i].can_total;
    }
    

    for(i = 0; i < SIZE; i++){
        percentage(total, &candidate[i]);
    }

    declare(&first, &second);

    printf("Enter Filename where the records will be saved: ");
    scanf("%s", &file);
    VOTEREC = fopen(file, "wb");

    for(i = 0; i < SIZE; i++){
        temp = candidate[i];
        fwrite(&temp, sizeof(temp), 1, VOTEREC);
    }
    fclose(VOTEREC);

    table(first, second);

    getch();
    return(0);
}

Record votes(){
    Record candidate;
    int i;

    candidate.can_total = 0;

    printf("Name of Candidate: ");
    scanf("%s", &candidate.name);
    
    for(i = 0; i < PREC; i++){
        printf("Vote for Precinct %d: ", i+1);
        scanf("%d", &candidate.vote[i]);
        candidate.can_total += candidate.vote[i];
    }

    return candidate;
}

void percentage(float total, Record *p){
    p->percent = (p->can_total / total) * 100;
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

    printf("Percentage");
    for(i = 0; i < SIZE; i++){
        printf("\t%0.2f", candidate[i].percent);
        printf("\t");
    }

    printf("\n\n");
    winner(first, second);
}