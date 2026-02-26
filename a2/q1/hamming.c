#include <stdio.h>

/** compares
two natural numbers in a particular base and prints out the base-10 number which represents
the Hamming distance of those two numbers in the particular base (followed by a newline).
Your program should take three command line arguments, the first represents one base-10
natural number, the second represents another base-10 natural number, and the third is
another base-10 natural number greater than one which represents the base to compare the
previous two numbers in. 
**/

void hamming(int n) {
    int a, b, base;
    scanf("%d %d %d", &a, &b, &base);
    
    int distance = 0;
    
    while (a > 0 || b > 0) {
        int digitA = a % base;
        int digitB = b % base;
        
        if (digitA != digitB) {
            distance++;
        }
        
        a /= base;
        b /= base;
    }
    
    printf("%d\n", distance);
} 

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        hamming(n);
    }
    
    return 0;
}