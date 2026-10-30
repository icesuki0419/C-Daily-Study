#include <stdio.h>

void selectionSort(int arr[], int n, int *comparisons, int *swaps) {
    *comparisons = 0;
    *swaps = 0;

    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            (*comparisons)++; // 비교할 때마다 증가
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // 실제로 값이 바뀌든 안 바뀌든 교환 로직이 실행되는 횟수
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        (*swaps)++;
    }
}

void bubbleSort(int arr[], int n, int *comparisons, int *swaps) {
    *comparisons = 0;
    *swaps = 0;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            (*comparisons)++; // 비교할 때마다 증가
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*swaps)++; // 실제로 교환이 일어날 때만 증가
            }
        }
    }
}

int main() {
    int comp1 = 0, swap1 = 0;
    int arr1[] = {4, 1, 7, 3, 8, 2, 6, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]); 

    selectionSort(arr1, n1, &comp1, &swap1);

    printf("선택 정렬 결과: ");
    for(int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n(비교 횟수: %d회, 교환 횟수: %d회)\n\n", comp1, swap1);


    int comp2 = 0, swap2 = 0;
    int arr2[] = {4, 1, 7, 3, 8, 2, 6, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]); 
    
    bubbleSort(arr2, n2, &comp2, &swap2);
    
    printf("버블 정렬 결과: ");
    for(int i = 0; i < n2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n(비교 횟수: %d회, 교환 횟수: %d회)\n", comp2, swap2);

    return 0; 
}