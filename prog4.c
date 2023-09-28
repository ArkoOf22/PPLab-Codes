#include <stdio.h>
#include <omp.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else {
        int x, y;
        #pragma omp task shared(x)
        x = fibonacci(n-1);
        #pragma omp task shared(y)
        y = fibonacci(n-2);
        #pragma omp taskwait
        return x + y;
    }
}

int main() {
    int n = 10; // Fibonacci number to calculate
    int result;

    #pragma omp parallel
    {
        #pragma omp single
        result = fibonacci(n);
    }

    printf("Fibonacci number at position %d is %d\n", n, result);

    return 0;
}

// In this code: 
 
// 1. The  fibonacci()  function is defined to calculate the Fibonacci number recursively. 
// 2. Inside the  fibonacci()  function, the base case for  n <= 1  is handled. 
// 3. For  n > 1 , the Fibonacci calculation is divided into two tasks using  #pragma omp task . 
//Each task calculates the Fibonacci number for  n-1  and  n-2  respectively. 
// 4. The  #pragma omp taskwait  directive is used to ensure that both tasks complete before returning the result. 
// 5. In the  main()  function, the variable  n  is set to the position of the Fibonacci number to calculate. 
// 6. The  result  variable is declared outside the parallel region and is shared among threads. 
// 7. The parallel region is created using  #pragma omp parallel . 
// 8. The calculation of the Fibonacci number is initiated using  #pragma omp single  to ensure that
// only one thread spawns the initial task. 
// 9. The result is stored in the  result  variable. 
// 10. After the parallel region, the result is printed using  printf() . 
 
// By using OpenMP parallelism and task-based parallelism, the Fibonacci calculation can be efficiently
// parallelized, with different threads working on different parts of the calculation.