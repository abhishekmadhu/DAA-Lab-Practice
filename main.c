#include <stdio.h>
/*
 * CMAKE merges all the executables all by itself!!!
 * */
int main() {
    printf("Hello, World!\n");

    if(rodCutting()){
        printf("\nrod successfully cut!");
    }

    printf("\nPress Enter/Return key to exit!");
    getchar();
    return 0;
}