#include <stdio.h>
int main(void) {
double a = 4.0, b = 1.2;
printf("%.1f + %.1f = %.1f\n", a, b, a + b);
printf("%.1f - %.1f = %.1f\n", a, b, a - b);
printf("%.1f * %.1f = %.1f\n", a, b, a * b);
printf("%.1f / %.1f = %.1f\n", a, b, a / b);

return 0;
}

#include <stdio.h>
int main(void) {
int a, b, tot;
double avg;

printf("두 과목의 점수 : ");
scanf("%d %d", &a, &b);
tot = a + b;
avg = tot / 2.0; //몇으로 나누어야 할지 생각해보기
printf("평균 : %.1f\n", avg);
return 0;
}
