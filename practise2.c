//This program calculates an approximation of the mathematical constant π (pi) using the Monte Carlo method and parallelizes
//the computation using OpenMP. 

#include <stdio.h>
#include <omp.h>
#define NUM_THREADS 12
static long num_steps = 10000;
double step;

void main()
{
    int i;
    double pi;
    double sum[NUM_THREADS];
    double x;
    step=1.0/(double)num_steps;
    //The  #pragma omp parallel private(i, x)  directive is used to parallelize the following block of code. 
    //1 It specifies that the variables  i  and  x  should be private to each thread. 
#pragma omp parallel private(i,x)
{
        int id=omp_get_thread_num();
        double local_sum=0.0;
        for(i=id, sum[id]=0.0; i< num_steps; i+=NUM_THREADS)
        {
            x=(i+0.5)*step;
            local_sum+=4.0/(1.0+x*x);
        }
#pragma omp critical
        {
            sum[0]+=local_sum;
        }
    }
    pi = sum[0] / num_steps;
    printf("pi = %6.12f\n", pi);
}

// This program calculates an approximation of the mathematical constant π (pi) using the Monte Carlo method and parallelizes the computation using OpenMP.

// Here's a breakdown of what's happening in the program:

// 1. The necessary header files,  `<stdio.h>`  and  `<omp.h>` , are included.

// 2. The constant  `NUM_THREADS`  is defined as 12, representing the number of threads to be used for parallel execution.

// 3. The static variable  `num_steps`  is declared and assigned a value of 100,000. This variable determines the number of steps used in the Monte Carlo approximation.

// 4. The variable  `step`  is declared as a double and will store the calculated step size.

// 5. The  `main()`  function is defined.

// 6. Inside the  `main()`  function, several variables are declared, including  `i`  (used for iteration),  `pi`  (stores the calculated approximation of pi),  `sum`  (an array to store the partial sums calculated by each thread), and  `x`  (used to calculate the x-coordinate for each step).

// 7. The value of  `step`  is calculated by dividing 1.0 by  `num_steps` .

// 8. The  `#pragma omp parallel private(i, x)`  directive is used to parallelize the following block of code. It specifies that the variables  `i`  and  `x`  should be private to each thread.

// 9. Inside the parallel region, the  `omp_get_thread_num()`  function is called to obtain the thread ID, which is stored in the  `id`  variable.

// 10. A local variable  `local_sum`  is declared and initialized to 0.0 for each thread.

// 11. A for loop is used to divide the work among the threads. Each thread starts from its assigned  `id`  and iterates with a step of  `NUM_THREADS` . The loop calculates the value of  `x`  for each step and adds the corresponding term to the  `local_sum`  variable.

// 12. The  `#pragma omp critical`  directive is used to ensure that only one thread at a time can update the shared  `sum[0]`  variable. This prevents data races and ensures correct accumulation of the partial sums.

// 13. After the parallel region, the value of  `sum[0]`  is divided by  `num_steps`  to calculate the approximation of pi and stored in the  `pi`  variable.

// 14. Finally, the value of pi is printed using  `printf()` .

// The program uses parallelization to distribute the workload among multiple threads, improving the efficiency of the computation. Each thread calculates a partial sum, and the sum of these partial sums is used to approximate the value of pi.