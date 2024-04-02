// S17 Mary Erika Culala & Gleezell Vina Uy

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

extern void asmhello(int n, double* x, double* y, int* new_n);

void print_result(double* Y, int n) {
    int k = 10;


    printf("Y = [");
    if (n <= 10) {
        for (int j = 0; j < n; j++) {
            if (j == n - 1) {
                printf("%.lf", Y[j]);
            }
            else {
                printf("%.lf, ", Y[j]);
            }
        }
    }
    else if (n > 10) {
        for (int j = 0; j < k; j++) {
            if (j == k - 1) {
                printf("%.lf", Y[j]);
            }
            else {
                printf("%.lf, ", Y[j]);
            }
        }
    }
    printf("]\n");
}


void c_stencil(int n, double* X, double* Y, int* new_n) {
    int flag = 0;
    int y_count = 0;

    for (int i = 0; i < n; i++) {
        double sum = 0;

        for (int offset = -3; offset <= 3; offset++) {
            int index = i + offset;
            if (index >= 0 && index < n) {
                sum += X[index];
                flag = 0;
            }
            else {
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


void checker(double* Z, double* Y, int y_count) {

    printf("\nSANITY CHECKER: C\n");
    for (int i = 0; i < y_count; i++) {
        if (Z[i] != Y[i]) {
            printf("x86-64 has incorrect output\n");

        }
    }
    printf("x86 - 64 has correct output\n");

}


int main() {

    // get input n from user
    const int sizes[] = { 1048576,  16777216, 134217728 };
    //const int sizes[] = {8, 1048576};
    const int num_sizes = sizeof(sizes) / sizeof(int);
    int num_runs = 35;
    int* new_n = 0;

    printf("\n");
    printf("==============================================================\n");
    for (int size = 0; size < num_sizes; size++) {
        int n = sizes[size];
        printf("Vector size: 2^%.f\n\n", log2(n));

        double* y = (double*)malloc(n * sizeof(double));
        double* x = (double*)malloc(n * sizeof(double));
        double* z = (double*)malloc(n * sizeof(double));

        if (x == NULL || y == NULL) {
            printf("Memory allocation failed.\n");
            return 0;
        }

        // initialize X array to store 1 to num
        for (int count = 0; count < n; count++) {
            x[count] = count + 1;
        }

        // call c kernel
        clock_t start_time = clock();
        for (int i = 0; i < num_runs; i++) {
            c_stencil(n, x, y, &new_n);
        }
        clock_t end_time = clock();
        double c_elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC / num_runs;
        printf("C Kernel: Average time taken: %f seconds\n", c_elapsed_time);

        printf("C Kernel: ");
        print_result(y, new_n);
        int y_counter = new_n;


        /**
        * TODO: Uncomment for assembly
        */
        // call assembly kernel
        clock_t start_time2 = clock();
        for (int i = 0; i < num_runs; i++) {
            asmhello(n, x, z, &new_n);
        }
        clock_t end_time2 = clock();
        double c_elapsed_time2 = ((double)(end_time2 - start_time2)) / CLOCKS_PER_SEC / num_runs;
        printf("Assembly Kernel: Average time taken: %f seconds\n", c_elapsed_time2);

        printf("Assembly Kernel: ");
        print_result(z, new_n);
        int z_counter = new_n;


        checker(z, y, y_counter);
        printf("==============================================================\n");


        free(z);
        free(x);
        free(y);
    }


    return 0;
}