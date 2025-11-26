/*
    특정 값으로 초기화된 정수형 배열에 대하여 배열의 원소 중 최댓값과 최솟값을 찾아서 출력하는 프 1 로그램을 작성하시오.
    배열의 초기값은 마음대로 정하시오.
*/
#include <stdio.h>

int main(void) {
    int arr[10] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };
    int max = arr[0];
    int min = arr[0];

    printf("배열: ");
    for (int i = 0; i < 10; i++) {
        printf("%d", arr[i]);
        if (i < 9) printf(" ");
    }
    printf("\n");

    for (int i = 1; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("최댓값: %d\n", max);
    printf("최솟값: %d\n", min);

    return 0;
}