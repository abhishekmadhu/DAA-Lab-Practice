#include <stdio.h>
/*
 * CMAKE merges all the executables all by itself!!!
 * */
int main() {
    printf("Hello, World!\n");

    if(rodCutting()){
        printf("\nrod successfully cut!");
    }

    if(nQueen()){
        printf("\nQueens Successfully placed");
    }

    // Enable this to use the getchar() pause functionality
    // printf("\nPress Enter/Return key to exit!");
    // getchar();
    return 0;
}