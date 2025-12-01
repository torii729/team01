/*
    문제: 대소문자를 구분하지 않고 문자열을 비교하는 strcmp_ic함수를 작성하시오.
          strcmp_ic(lhs, rhs) 함수의 리턴값은 strcmp와 마찬가지로 lhs가 rhs보다 크면 0보다 큰 값, 두 문자열이 같으면 0,
          lhs가 rhs보다 작으면 0보다 작은 값을 리턴한다. strcmp_ic 함수를 이용해서 입력받은 두 문자열을 비교하는 프로그램을 작성하시오.
    출력예시:  첫 번째 문자열? how long
              두 번째 문자열? How Long
              how long와 How Long가 같습니다.
*/

#include <stdio.h> // 표준 입출력 함수(printf, fgets 등) 사용
#include <ctype.h> // tolower() 사용 → 대소문자 무시 비교 구현
#include <string.h> // strchr() 사용 → 개행 문자 제거할 때 필요

// ------------------------------
// 함수 원형 선언
// ------------------------------
void input_str(void); // 전체 프로그램 흐름 담당
int strcmp_ic(const char* lhs, const char* rhs); // 대소문자 무시 문자열 비교(리턴값 반환)
void print_result(int result, const char* s1, const char* s2); // 리턴값 기반 출력 담당


// -------------------------------------------------------
// main : 프로그램 시작점. 오직 input_str 함수만 호출하는 구조.
// -------------------------------------------------------
int main(void)
{
    input_str(); // input_str 호출 → 나머지 기능은 모두 해당 함수에서 실행
    return 0; // 프로그램 정상 종료
}


// -------------------------------------------------------
// input_str
// 문자열 입력 → 개행 제거 → strcmp_ic로 비교 → print_result로 출력
// -------------------------------------------------------
void input_str(void)
{
    char str1[100]; // 첫 번째 문자열 저장 배열 (최대 99글자 + '\0')
    char str2[100]; // 두 번째 문자열 저장 배열
    char* pos; // 개행 문자의 위치를 저장할 포인터

    // ---------- 첫 번째 문자열 입력 ----------
    printf("첫 번째 문자열? "); // 사용자 입력 안내 출력
    fgets(str1, sizeof(str1), stdin); // 공백 포함 입력 (fgets는 개행 문자까지 읽어옴)

    pos = strchr(str1, '\n'); // str1 내부에서 '\n' 첫 위치 탐색
    if (pos) *pos = '\0'; // 개행 문자를 '\0'으로 치환하여 제거

    // ---------- 두 번째 문자열 입력 ----------
    printf("두 번째 문자열? "); // 사용자 입력 안내
    fgets(str2, sizeof(str2), stdin); // 두 번째 문자열 입력

    pos = strchr(str2, '\n'); // '\n' 위치 찾기
    if (pos) *pos = '\0'; // '\n' 제거

    // ---------- 문자열 비교 수행 ----------
    int result = strcmp_ic(str1, str2); // strcmp_ic 호출 → 양수/0/음수 반환

    // ---------- 결과 출력 ----------
    print_result(result, str1, str2); // 반환값 기반으로 비교 결과 출력
}


// -------------------------------------------------------
// strcmp_ic
// 대소문자를 무시하고 문자열을 비교하는 함수.
// 리턴값은 strcmp와 동일한 의미: 양수/0/음수.
// -------------------------------------------------------
int strcmp_ic(const char* lhs, const char* rhs)
{
    while (*lhs && *rhs) // 두 문자열 모두 끝나지 않은 동안 반복
    {                       
        char c1 = tolower((unsigned char)*lhs); // lhs 현재 문자를 소문자로 변환
        char c2 = tolower((unsigned char)*rhs); // rhs 현재 문자를 소문자로 변환
        // unsigned char 캐스팅 → 음수 문자 처리 문제 방지(표준 규칙)

        if (c1 != c2) // 문자가 다르다면 즉시 비교 종료
        {
            return c1 - c2; // 양수/음수/0 반환 → strcmp 규칙 동일
        }

        lhs++; // 다음 문자로 포인터 이동
        rhs++; // 다음 문자로 포인터 이동
    }

    // 여기까지 왔다는 것은 앞부분은 모두 같음.
    // 이제 문자열 끝('\0') 도달 여부로 길이 기반 비교.

    if (*lhs == '\0' && *rhs == '\0') // 두 문자열 모두 동시에 종료
        return 0; // → 완전히 동일

    else if (*lhs == '\0') // lhs쪽 문자열이 먼저 끝남
        return -1; // → lhs가 더 짧으므로 lhs < rhs

    else // rhs가 먼저 끝났거나 rhs가 짧음
        return 1; // → lhs가 더 김 → lhs > rhs
}


// -------------------------------------------------------
// print_result
// strcmp_ic의 리턴값을 해석하여 사용자에게 문장으로 출력하는 함수
// -------------------------------------------------------
void print_result(int result, const char* s1, const char* s2)
{
    if (result == 0) // 두 문자열이 같을 때
        printf("%s와 %s가 같습니다.\n", s1, s2);
    else if (result > 0) // s1 > s2
        printf("%s가 %s보다 큽니다.\n", s1, s2);
    else // s1 < s2
        printf("%s가 %s보다 작습니다.\n", s1, s2);
}