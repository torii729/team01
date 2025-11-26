/* 등차수열은 앞의 항에 항상 일정한 수(공차)를 더하여 만들어가는 수열이다.크기가 10인 정수험 배 < 5 열에 대하여 등차수열로 값을 채우려고 한다.
    첫 번째 항의 값과 공차(common difference 입력받아서 배열을 채우고 출력하는 프로그램을 작성하시오 */
#include <stdio.h>

int main(void) 
{
    int arr[10];

    int first;
    int diff;

    printf("첫 번째 항? ");
    scanf_s("%d", &first);

    printf("공차? ");
    scanf_s("%d", &diff);

    arr[0] = first;

    for (int i = 1; i < 10; i++) {
        arr[i] = arr[i - 1] + diff;
    }

    printf("등차수열: ");
    for (int i = 0; i < 10; i++) {
        printf("%d", arr[i]);

        if (i < 9) {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}