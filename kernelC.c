#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void print_c_result(double *Y, int n){
    int k = 10;


    printf("C kernel: Y = [");
    if (n <= 10){
        for (int j = 0; j < n; j++){
            if (j == n-1){
                printf("%.lf", Y[j]);
            } else {
                printf("%.lf, ", Y[j]);
            }
        }
    } else if (n > 10){
        for (int j = 0; j < k; j++){
            if (j == k-1){
                printf("%.lf", Y[j]);
            } else {
                printf("%.lf, ", Y[j]);
            }
        }
    }
    printf("]\n");
}


void c_stencil(int n, double *X, double *Y, int *new_n) {
    int flag = 0;
    int y_count = 0;

    for (int i = 0; i < n; i++) {
        double sum = 0;

        for (int offset = -3; offset <= 3; offset++) {
            int index = i + offset;
            if (index >= 0 && index < n) {
                sum += X[index];
                flag = 0;
            } else {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            Y[y_count] = sum; 
            y_count++;
            *new_n = y_count;
        }
    }
}




/**
 * TODO: Call extern *assembly_function_name*
*/


int main(){

    // get input n from user
    const int sizes[] = {1048576, 16777216, 134217728};
    // const int sizes[] = {8};
    const int num_sizes = sizeof(sizes) / sizeof(int);
    int num_runs = 35;
    int new_n = 0;

    printf("\n");
    printf("==============================================================\n");
    for (int size = 0; size < num_sizes; size++){
        int n = sizes[size];
        printf("Vector size: 2^%.f\n\n", log2(n));
    
        double* Y = malloc(n * sizeof(double)); 
        double* X = malloc(n * sizeof(double)); 

        if (Y == NULL || X == NULL) {
            printf("Memory allocation failed.\n");
            return 0;
        }

        // initialize X array to store 1 to num
        for (int count = 0; count < n; count++){
            X[count] = count + 1;
        }

        // call c kernel
        clock_t start_time = clock();
        for (int i = 0; i < num_runs; i++) {
            c_stencil(n, X, Y, &new_n);
        }
        clock_t end_time = clock();
        double c_elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC / num_runs;
        printf("C Kernel: Average time taken: %f seconds\n", c_elapsed_time);


        /**
        * TODO: Uncomment for assembly
        */
        // call assembly kernel
        // clock_t start_time = clock();
        // for (int i = 0; i < num_runs; i++) {
            /**
             * TODO: call assembly function here
            */
        // }
        // clock_t end_time = clock();
        // double c_elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC / num_runs;
        // printf("Assembly Kernel: Average time taken: %f seconds\n", c_elapsed_time);

        print_c_result(Y, new_n);
        printf("==============================================================\n");

        free(Y);
        free(X);
    }
    return 0;
}