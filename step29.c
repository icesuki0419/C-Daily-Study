#include <stdio.h>

int main(void) {
    double apple;
    int banana;

    apple = 5.0/2.0;
    banana = 5 / 2;

    printf("Apple: %.1f\n", apple);
    printf("Banana: %d\n", banana);

    apple = 5 / 2.0;
    banana = 5.0 / 2;
    printf("Apple: %.1f\n", apple);
    printf("Banana: %d\n", banana);
    printf("5 / 2: %.1f\n", (float) 5 / 2); //형 변환 
    return 0;
}
