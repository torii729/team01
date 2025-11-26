/*
    크기가 3인 double형 배열의 모든 원소의 주소를 출력하는 프로그램을 작성하시오. 
    단, 주소3 /하기 연산자를 사용하지 마시오.
*/
#include <stdio.h>

int main() {
    double x[3];

    printf("x[0]의 주소: %p\n", (x));
    printf("x[1]의 주소: %p\n", (x + 1));
    printf("x[2]의 주소: %p\n", (x + 2));

    return 0;
}