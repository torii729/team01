/*
피보나치 수열의 n번째 항을 구하는 fibonacci 함수를 재귀 함수로 정의하시오.
피보나치 수열은 바로 앞의 두 수의 합으로 구해지며, 처음 두 항은 1이다.
finonacci 함수를 이용해서 0~19번 항을 출력하는 프로그램을 작성하시오.
*/

#include <stdio.h>   // printf 사용을 위한 표준 입출력 헤더 포함

// 재귀 함수를 사용해 피보나치 수열의 n번째 항을 구하는 함수
int fibonacci(int n) {
    if (n == 0 || n == 1)   // 피보나치의 0번째와 1번째 항은 1이라는 규칙
        return 1;           // 기저 조건(Base Case): 재귀를 멈추는 지점

    // 재귀 호출: 앞의 두 항을 더해서 반환
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    for (int i = 0; i < 20; i++) {       // i가 0부터 19까지 반복 (총 20항 출력)
        printf("%d ", fibonacci(i));     // i번째 피보나치 수를 계산해서 출력
    }
    return 0;   // 프로그램 정상 종료
}