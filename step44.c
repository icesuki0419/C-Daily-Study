#include <stdio.h>

int main() {
    int ary1[4] = {11, 12, 13, 14};
    int ary2[4] = {15, 16, 17, 18};
    int ary3[4] = {19, 20, 21, 22};
    int *ptr[3] = {ary1, ary2, ary3};
    int i, j;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            printf("%5d", ptr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
