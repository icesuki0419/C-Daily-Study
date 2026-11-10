#include <stdio.h>

int main(void) {
    int a = 10, b = 20, res;
    res = (a<0) && (++b > 20);
    printf("res: %d\n , a: %d\n, b: %d\n", res, a, b);
    return 0;
}
