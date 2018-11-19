//
// Created by abhis on 11/19/2018.
//

#include<stdio.h>

#define N 5
#define INFINITY 99999
#define NEG_INFINITY -99998

int dimen[N+1][2+1];
int cost[6][6];
int p[N+1];

void populateP(){
    int i;
    p[0] = dimen[1][1];

    for (i=1; i<=N; i++){
        p[i] = dimen[i][2];
    }
}



void printDimenMatrix(){
    //printAny2DMatrixStart1(dimen, N+1, 2+1);
    int i;
    for(i=1; i<=N; i++){
        printf("%d x %d\n", dimen[i][1], dimen[i][2]);
    }
}

void printCostMatrix(){
    int i;
    int j;
    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            printf("%6d", cost[i][j]);
        }
        printf("\n");
    }
}

void printP(){
    int i;
    for(i=0; i<=N; ++i){
        printf("%6d", p[i]);
    }
}

void inputDimensions(){
    int i;
    printf("Enter the dimensions of %d matrices separated by spaces:\n", N);
    for(i=1; i<=N; i++){
        scanf("%d%d", &dimen[i][1], &dimen[i][2]);
    }
    // printDimenMatrix();
}

void initiateCostMatrix(){
    int i,j;
    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            if(i==j){
                cost[i][j] = 0;
            }
            else if(i>j){
                cost[i][j] = NEG_INFINITY;
            }
            else{
                cost[i][j] = INFINITY;
            }
        }
    }
}


void arrangeMatrices(){
    int i=0,j=0,k=0,spread=0,tempCost=0;
    initiateCostMatrix();
    populateP();

//    printP();
//    printCostMatrix();

    for(spread=1; spread<=N-1; ++spread){
        for(i=1; i<=N-spread; ++i){
            j=i+spread;

            for(k=i; k<j; k++){

                tempCost = cost[i][k] + cost[k+1][j] + p[i-1]*p[k]*p[j];
                if(tempCost<cost[i][j]){
                    cost[i][j] = tempCost;
                }

            }
        }
    }
}

int main(){
    inputDimensions();
    arrangeMatrices();
//    printf("\nkjsdhfkjhadskjf    %d", cost[N+1][N+1]);
    printCostMatrix();
    getchar();
    return 0;
}
