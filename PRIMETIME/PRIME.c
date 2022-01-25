    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    
    bool isPrime(int n, int i)
    {
 
        // Base cases
        if (n <= 2) {
            return (n == 2) ? true : false;
        }
        if (n % i == 0) {
            return false;
        }
        if (i * i > n) {
            return true;
        }
     
        // Check for next divisor
        return isPrime(n, i + 1);
    }
     
     
    
    void main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
 
        if (isPrime(n, 2))
            printf("Number is prime");
        else
            printf("Number is not prime");
    }