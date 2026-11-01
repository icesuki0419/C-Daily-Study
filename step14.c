#include <stdio.h>

int swap(int* x, int* y) { //포인터 변수사용해서 주소 저장하고 swap함수 사용가능
    int temp; 
    temp = *x;
    *x = *y;
    *y = temp;
    return 0;
}

int main(void) {
    int x = 10, y = 20; //주소가 달라서 swap함수 사용 안됨
    printf("swap 함수 호출 전 : a = %d, b = %d\n", x, y);
    swap(&x, &y);
    printf("swap 함수 호출 후 : a = %d, b = %d\n", x, y);
    return 0;
} 