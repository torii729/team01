/*
    배열 원소를 가리키는 포인터와 포인터 연산을 이용해서 실수형 배열의 모든 원소를 출력하는 프 그램을 작성하시오.
*/
#include <stdio.h>

int main() {
    float arr[10];
    float* p = arr;
    for (int i = 0; i < 10; i++) {
        scanf_s("%f", &arr[i]);
    }

    printf("실행결과\n");

    for (int i = 0; i < 10; i++) {
        printf("%.2f ", *(p + i));
    }

    return 0;
}