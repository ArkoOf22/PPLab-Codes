#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
// iterns
void main()
{
    int iterns, i, itern[8];

    //Iterns store the number of iterations 
    //and itern array stores the iteration count for each thread
    
    printf("enter iterns:");
    
    scanf("%d", &iterns);

#pragma omp parallel for schedule(static, 2)
    
    for (i = 1; i <= iterns; i++)
    
    {
        int t = omp_get_thread_num();
        itern[t] += 1;
        printf("thread %d itern %d value: %d\n", t, itern[t], i);
    }
    
}

// This code is an example of using OpenMP to parallelize a loop and distribute the iterations among multiple threads. Here's a breakdown of what the code does:

// 1. The necessary header files,  `<stdio.h>` ,  `<stdlib.h>` , and  `<omp.h>` , are included.

// 2. The  `main()`  function is defined.

// 3. Several variables are declared, including  `iterns`  (to store the number of iterations),  `i`  (used for iteration), and  `itern`  (an array to store the iteration count for each thread).

// 4. The user is prompted to enter the value of  `iterns`  using  `printf()`  and  `scanf()` .

// 5. The  `#pragma omp parallel for schedule(static, 2)`  directive is used to parallelize the following loop. It specifies that the loop iterations should be divided among the threads using a static scheduling, with a chunk size of 2.

// 6. Inside the parallel region, each thread executes its assigned iterations in the loop.

// 7. The  `omp_get_thread_num()`  function is called to obtain the thread ID, which is stored in the variable  `t` .

// 8. Each thread increments its corresponding element in the  `itern`  array by 1, indicating the number of iterations it has executed.

// 9. The thread ID, iteration count for that thread, and the value of  `i`  are printed using  `printf()` .

// The code demonstrates how OpenMP can distribute the loop iterations among multiple threads, with each thread executing a subset of the iterations. It also shows how to access and update thread-specific variables (in this case, the  `itern`  array) within the parallel region.