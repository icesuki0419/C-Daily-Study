#include <stdio.h>
#define MUL(a, b) (a * b)
#define SUB(a, b) (a - b)
#define SWAP(a, b) {int temp = a; a = b; b = temp;}

int main() {
    int a = 20, b = 10;
    printf("Sub : %d\n", SUB(a, b));
    printf("Product: %d\n", (400/MUL(a, b)));
    SWAP(a, b);
    printf("swap_Sub: %d\n", SUB(a, b));
    return 0;
} 
