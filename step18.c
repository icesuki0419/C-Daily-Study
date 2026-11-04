#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int *)malloc(sizeof(int) * n);
    if (arr == NULL) return 1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int m;
    if (scanf("%d", &m) != 1) {
        free(arr);
        return 0;
    }

    for (int i = 0; i < m; i++) {
        int target;
        scanf("%d", &target);
        
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == target) {
                found = 1;
                break;
            }
        }
        printf("%d", found);
        if (i < m - 1) {
            printf(" ");
        }
    }
    printf("\n");

    free(arr);
    return 0;
}
