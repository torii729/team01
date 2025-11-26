/*
    등비수열은 앞의 항에 항상 일정한 수(공비)를 곱하여 만들어가는 수열이다.크기가 10인 실수형 배 열에 대하여 등비수열로 값을 채우려고 한다.
    첫 번째 항의 값과 공비(common ratio)를 입력받아 서 배열을 채우고 출력하는 프로그램을 작성하시오.
*/

#include <stdio.h>

int main(void) {
    double arr[10];
    double first;
    double ratio;
    printf("첫 번째 항? ");
    scanf_s("%lf", &first);

    printf("공비? ");
    scanf_s("%lf", &ratio);

    arr[0] = first;

    for (int i = 1; i < 10; i++) {
        arr[i] = arr[i - 1] * ratio;
    }

    printf("등비수열: ");

    for (int i = 0; i < 10; i++) {
        printf("%g", arr[i]);
        if (i < 9) printf(" ");
    }

    printf("\n");

    return 0;
}