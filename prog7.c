#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0;

    #pragma omp parallel for
    for (int i = 1; i <= 100; i++) {
        #pragma omp critical
        sum += i;
    }

    printf("Sum of the first 100 numbers: %d\n", sum);

    return 0;
}

/*In this program: 
 
1. The  main()  function is defined. 
 
2. The variable  sum  is initialized to 0, which will store the sum of the numbers. 
 
3. The  #pragma omp parallel for  directive is used to distribute the loop iterations among multiple threads. 
 
4. Inside the loop, the  #pragma omp critical  directive ensures that only one thread at a time can access and update the shared variable  sum . This prevents data races and ensures correct accumulation of the sum. 
 
5. After the parallel region, the final value of  sum  is printed using  printf() . 
 
By using the  critical  directive, we ensure that the addition of each number to the sum is performed atomically, preventing any race conditions that may occur when multiple threads try to update the shared variable simultaneously.*/