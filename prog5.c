#include <stdio.h>
#include <omp.h>

int isPrime(int num) {
    if (num <= 1)
        return 0;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

int main() {
    int n = 100; // Upper limit to find prime numbers
    printf("Prime numbers from 1 to %d:\n", n);

    #pragma omp parallel for
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            #pragma omp critical
            printf("%d\n", i);
        }
    }

    return 0;
}

/*In this program: 
 
1. The  isPrime()  function is defined to check if a number is prime or not. It returns 1 if the number is prime and 0 otherwise. 
 
2. The  main()  function is defined. 
 
3. The variable  n  is set to the upper limit until which prime numbers are to be calculated. 
 
4. The prime numbers are printed using  printf() . 
 
5. The parallel region is created using  #pragma omp parallel for , which distributes the loop iterations among multiple threads. 
 
6. Each thread checks if a number is prime using the  isPrime()  function. If a number is prime, it is printed using  printf() . 
 
7. The  #pragma omp critical  directive is used to ensure that only one thread at a time can print a prime number to avoid overlapping outputs. 
 
By using the parallel directive in OpenMP, the prime number calculation is divided among multiple threads, which can improve the performance and speed up the execution of the program.*/