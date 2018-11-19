//
// Created by abhishek on 11/17/2018.
//

#include <stdio.h>
#include <malloc.h>
#include <limits.h>

int color;

int * initiate(int * column){
    int i;
    for (i = 0; i < color; ++i) {
        column[i] = INT_MAX;
    }
}

void print(int * column){
    for (int i = 0; i < color; ++i ) {
        printf("%4d", column[i]);
    }
}

int checkPlacement(int * column, int i, int j){
    int k,l;
    // Check if possible to place ith queen at jth column
        //row

        //column
    for (k = 0; k < i; ++k)
        if(column[k]==j)
            return 0;

        //diagonal
    k = i;
    l = j;
    while(k>=0 && l>=0){
        if(column[k]==l)
            return 0;
        k--;
    }

    return 1;
}

void placeQueens(int * column){
    int i, j, k;
    for (i = 0; i < color; ++i) {
        for (j = 0; j < color; ++j) {
            if(checkPlacement(column, i, j)){
                column[i] = j;
            }
        }
    }

}

int nQueen(){
    printf("\n\nN-QUEEN With BackTrack!");

    int * column;
    int ret;

    printf("\nEnter the number of Queens:   ");
    scanf("%d", &color);
    column = (int*)malloc(color * sizeof(int));
    column = initiate(column);

    print(column);      //

    // ret = checkPlacement(column, 3, 3);
    // printf("\nReturned Value is %d", ret);

    placeQueens(column);


    return 1;
}