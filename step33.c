#include <stdio.h>

int main(void) {
    double k, e, m;            // 국어, 영어, 수학 학점 변수 선언 및 초기
    double tot;                // 전체 학점을 저장할 변수 선언 및 저장              
    double avg;
    int res;
                         // 점수의 평균을 저장할 변수 선언 및 저장
    int kor = 3, en = 5, ma = 4;
    int credit = kor + en + ma;
    k = 3.8, e = 4.4, m = 3.9;

    tot = k+e+m;    
    avg = tot / 3.0;

    res = (credit >= 10) && (avg > 4.0);
    printf("%d\n", res);
    
    // 전체 학점이 10학점 이상이고 점수 평균이 4.0보다 크면 1, 아니면 0 출력
}
