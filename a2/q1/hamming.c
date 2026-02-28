#include <stdio.h>


void hamming(int a, int b, int base) {

    int distance = 0;
    
    while (a > 0 || b > 0) {
        int A = a % base;
        int B = b % base;
        if(A != B){
            distance++;
        }
        a = a / base;
        b = b / base;
       
    }
    
    printf("%d\n", distance);
} 

int main() {
    int n, m, base;
    scanf("%d %d %d", &n, &m, &base);
    
    hamming(n, m , base);
    
    return 0;
}