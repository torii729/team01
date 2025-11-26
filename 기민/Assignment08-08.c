/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 8. 정수형 배열을 특정 값으로 채우는 fill_array 함수와 테스트 프로그램
    날짜 : 2025.11.26
*/

#include <stdio.h>

// 함수 프로토타입 선언
void test(void);
void fill_array(int* arr, int size, int value);
void print_array(const int* arr, int size);

/*
    기능명: main. 프로그램 시작점
    내용: 테스트 함수를 호출하여 배열 채우기 프로그램을 실행한다.
    입력: 없음
    출력: 없음
    오류: 없음
*/
int main(void)
{
    test(); // 테스트용 함수 호출
    return 0;
}

/*
    기능명: test. 테스트 코드
    내용: 크기 20인 int 배열과 값을 입력받아 fill_array로 채운 뒤 출력한다.
    입력: 배열에 저장할 값 하나를 입력받는다.
    출력: 채워진 배열을 출력한다.
    오류: 입력 실패 시 함수를 바로 종료한다.
*/
void test(void)
{
    int arr[20]; // 크기 20인 int형 배열
    int value; // 배열 모든 원소에 채울 값
    int ok; // 입력 성공 여부를 저장할 변수

    printf("배열의 원소에 저장할 값? ");
    ok = scanf_s("%d", &value); // 정수 하나를 입력받는다.
    if (ok != 1) // 입력에 실패한 경우
    {
        return;  // 더 이상 진행하지 않고 종료
    }

    // 배열 전체를 value 값으로 채운다.
    fill_array(arr, 20, value);

    // 채워진 배열 내용을 출력한다.
    print_array(arr, 20);
}

/*
    기능명: fill_array. 배열 채우기
    내용: 포인터와 역참조 연산자를 사용해 배열의 모든 원소를 동일한 값으로 채운다.
    입력: int* arr - 배열의 시작 주소
          int size - 배열의 크기
          int value - 각 원소에 저장할 값
    출력: 없음 (배열 내용이 직접 변경된다)
    오류: 없음
*/
void fill_array(int* arr, int size, int value)
{
    int i;

    // 0번 인덱스부터 size - 1 인덱스까지 순서대로 접근
    for (i = 0; i < size; i++)
    {
        // arr[i]와 동일한 표현
        // 현재 위치의 원소에 value 값을 저장한다.
        *(arr + i) = value;
    }
}

/*
    기능명: print_array. 배열 출력
    내용: 배열의 모든 원소를 공백으로 구분해 한 줄에 출력한다.
    입력: const int* arr - 배열의 시작 주소
          int size - 배열 크기
    출력: "배열: " 다음에 배열 원소들을 차례대로 출력한다.
    오류: 없음
*/
void print_array(const int* arr, int size)
{
    int i;

    printf("배열: ");
    // 0번 인덱스부터 size - 1 인덱스까지 값 출력
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
