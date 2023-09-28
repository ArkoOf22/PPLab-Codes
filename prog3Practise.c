#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 4
#define NUM_ITERATIONS 10

int main() {
    int i, tid;
    int chunk_size = 2;
    
    omp_set_num_threads(NUM_THREADS);
    omp_set_schedule(omp_sched_static, chunk_size);
    
    #pragma omp parallel private(i, tid)
    {
        tid = omp_get_thread_num();
        
        #pragma omp for schedule(static, chunk_size)
        for (i = 0; i < NUM_ITERATIONS; i++) {
            printf("Thread %d executing iteration %d\n", tid, i);
        }
    }
    
    return 0;
}