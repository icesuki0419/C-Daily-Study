#include <stdio.h>

int main(void) {
    char str[14] = "Hello, World"; //배열이름 -> 시작주소 ex)str
    printf("%s\n", str);

    scanf("%s", str);
    printf("%s\n", str+5);
    return 0;
}