#include <stdio.h>
#include <stdlib.h>
#include <vector>

int main ( void ){

    // State the dimensions of the array

    int n = 3; // n columns
    int m = 3; // m rows



    // 2D static array
    int static_2D[m][n]; // m rows, n columns





    /* 
    2D dynamic array using new (here we are creating an array of pointers)
    */

    // Part 1 : Creation of empty pointer array
    int ** dynamic_2D = new int * [m];

    // Part 2 : Populating the pointer array with pointers to integer arrays
    for (int i = 0; i < m; i++) {
        dynamic_2D[i] = new int[n];
    }

    // Part 3 : Freeing up the space at the end of the program
    for (int i; i < m; i++) {
        delete[] dynamic_2D[i];
    }
    delete[] dynamic_2D;





    /* 
    2D dynamic array using malloc
    */

    // Part 1 : Creation of 2d pointer array
    int ** dynamic_2D_malloc = (int **) malloc(m * sizeof(int * ));

    // Part 2 : Populating pointer array with pointers linked to integer arrays
    for (int i = 0; i<m; i++) {
        dynamic_2D_malloc[i] = (int *)malloc(n * sizeof(int));
    }

    // Part 3 : Freeing up the space at the end of the program
    for (int i = 0; i<m; i++){
        free(dynamic_2D_malloc[i]);
    }
    free(dynamic_2D_malloc);

    printf("Complete");
    

    return (0);

}