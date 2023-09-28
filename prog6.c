#include <stdio.h>
#include <omp.h>

#define SIZE 10

void vectorAdd(int* a, int* b, int* c, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        c[i] = a[i] + b[i];
    }
}

int main() {
    int a[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int c[SIZE];

    vectorAdd(a, b, c, SIZE);

    printf("Resultant vector after addition: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}

/*In this program: 
 
1. The  vectorAdd()  function is defined to perform the vector addition. It takes three integer arrays  a ,  b , and  c , and the size of the arrays as input. 
 
2. The parallel region is created using  #pragma omp parallel for , which distributes the loop iterations among multiple threads. 
 
3. Inside the loop, each thread adds the corresponding elements of arrays  a  and  b  and stores the result in array  c . 
 
4. In the  main()  function, two integer arrays  a  and  b  are initialized with values, and an array  c  is declared to store the result of the addition. 
 
5. The  vectorAdd()  function is called to perform the parallel vector addition. 
 
6. Finally, the resultant vector  c  is printed using  printf() . 
 
By using the parallel directive in OpenMP, the vector addition operation is parallelized, allowing multiple threads to perform the addition simultaneously and potentially improving the performance and speed of the computation.*/