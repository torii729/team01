/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 15. POINT 구조체 배열을 x좌표 기준 선택 정렬
    날짜 : 2025.11.26
*/

#include <stdio.h>

/*
    기능명: POINT 구조체
    내용: 2차원 평면 상의 한 점을 나타내기 위한 구조체.
    멤버: x - x좌표, y - y좌표
*/
typedef struct
{
    int x; // x좌표
    int y; // y좌표
} POINT;

// 함수 프로토타입 선언
void test(void);
void swap_point(POINT* a, POINT* b);
void selection_sort_by_x(POINT arr[], int n);
void print_points(const POINT arr[], int n);

/*
    기능명: main. 프로그램 시작점
    내용: 테스트 함수를 호출하여 구조체 배열 정렬 프로그램을 실행한다.
    입력: 없음
    출력: 없음
    오류: 없음
*/
int main(void)
{
    test(); // 테스트 코드 실행
    return 0;
}

/*
    기능명: test. 테스트 코드
    내용: 크기 10의 POINT 배열을 초기화하고 x좌표 기준으로 선택 정렬한다.
          정렬 전과 정렬 후의 좌표 리스트를 출력한다.
    입력: 없음
    출력: 정렬 전후 좌표 출력.
    오류: 없음
*/
void test(void)
{
    // 초기 좌표 데이터(정렬 대상)
    POINT arr[10] =
    {
        { 7, 4 }, { 12, 93 }, { 22, 31 }, { 1, 20 }, { 34, 53 },
        { 41, 2 }, { 32, 9 }, { 21, 31 }, { 8, 2 }, { 3, 5 }
    };

    printf("<정렬 전>\n");
    print_points(arr, 10); // 정렬 전 배열 출력

    selection_sort_by_x(arr, 10); // x좌표 기준 선택 정렬 수행

    printf("<정렬 후>\n");
    print_points(arr, 10); // 정렬 후 배열 출력
}

/*
    기능명: swap_point. POINT 교환
    내용: 두 POINT 변수의 값을 서로 맞바꾼다.
          선택 정렬에서 최소값을 현재 위치로 옮길 때 사용한다.
    입력: POINT 포인터 2개 (서로 교환할 대상의 주소)
    출력: 없음 (포인터를 통해 실제 배열 내용이 변경된다)
    오류: 없음
*/
void swap_point(POINT* a, POINT* b)
{
    POINT temp; // 임시로 값을 보관할 변수

    temp = *a; // a가 가리키는 POINT 값을 temp에 저장
    *a = *b; // b가 가리키는 POINT 값을 a 위치로 복사
    *b = temp; // temp에 있던 원래 a의 값을 b 위치로 복사
}

/*
    기능명: selection_sort_by_x. 선택 정렬
    내용: x좌표 오름차순 기준으로 POINT 배열을 선택 정렬한다.
          선택 정렬은 매 회전마다 남은 구간에서 최소값의 인덱스를 찾아
          현재 위치의 원소와 교환하는 방식이다.
    입력: POINT arr[]  정렬할 배열
          int n - 배열의 원소 개수
    출력: 없음 (배열 arr의 내용이 정렬된 상태로 바뀐다)
    오류: 없음
*/
void selection_sort_by_x(POINT arr[], int n)
{
    int i;
    int j;
    int min_idx; // 현재 구간에서 x좌표가 가장 작은 원소의 인덱스

    // i: 정렬되지 않은 구간의 첫 번째 위치
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;  // 처음에는 i번째 원소가 최소라고 가정

        // i 이후의 구간에서 더 작은 x값을 찾는다.
        for (j = i + 1; j < n; j++)
        {
            // 현재까지의 최소 x값보다 더 작은 x값을 발견하면 인덱스 갱신
            if (arr[j].x < arr[min_idx].x)
            {
                min_idx = j;
            }
        }

        // 최소값의 위치가 i와 다르면 서로 교환
        if (min_idx != i)
        {
            swap_point(&arr[i], &arr[min_idx]);
        }
    }
}

/*
    기능명: print_points. 좌표 출력
    내용: POINT 배열의 모든 원소를 (x, y) 형식으로 한 줄에 출력한다.
    입력: const POINT arr[] - 출력할 배열
          int n - 배열의 원소 개수
    출력: 좌표들을 "(x, y) " 형식으로 출력한 뒤 개행 출력
    오류: 없음
*/
void print_points(const POINT arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("(%d, %d) ", arr[i].x, arr[i].y);
    }
    printf("\n");
}
