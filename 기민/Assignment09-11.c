/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 11. 영어 단어 끝말잇기 게임
    날짜 : 2025.11.26
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 함수 프로토타입 선언
void test(void);
int chain_ok(char a[], char b[]);
void to_lower(char s[]);

/*
    기능명: main. 프로그램 시작점
    내용: test 함수를 호출하여 끝말잇기 게임을 실행한다.
    입력: 없음
    출력: 없음
    오류: 없음
*/
int main(void)
{
    test(); // 끝말잇기 게임 실행
    return 0;
}

/*
    기능명: test. 테스트 코드
    내용: 사용자가 단어를 계속 입력하게 하고,
          첫 단어 이후부터는 끝말잇기 규칙을 검사한다.
          단어 길이가 3 미만이면 다시 입력받고,
          규칙을 어기면 실패 메시지와 지금까지 맞춘 횟수를 출력한 뒤 종료한다.
    입력: "word? "를 출력한 뒤 단어를 반복해서 입력받는다.
    출력: 규칙을 어기면 실패 메시지와 연속 성공 횟수를 출력한다.
    오류: 단어 입력에 실패하면 함수는 바로 종료한다.
*/
void test(void)
{
    char a[101] = ""; // 이전에 입력한 단어를 저장하는 배열, 처음에는 빈 문자열
    char b[101]; // 이번에 입력한 단어를 저장하는 배열
    int count; // 규칙을 지키며 연속으로 맞춘 단어 개수
    int ok; // 입력 성공 여부

    count = 0; // 아직 맞춘 단어가 없으므로 0으로 시작

    while (1)
    {
        printf("word? ");
        // 최대 100글자까지 단어 입력
        ok = scanf_s("%100s", b, sizeof(b));
        if (ok != 1) // 입력에 실패한 경우
        {
            return; // 더 이상 진행하지 않고 종료
        }

        // 단어 길이가 3 미만이면 게임 규칙상 다시 입력받는다.
        if (strlen(b) < 3)
        {
            printf("too short, try again\n");
            continue; // count는 그대로 두고 다시 입력
        }

        // 대소문자 구분 없이 비교하기 위해 현재 단어를 모두 소문자로 바꾼다.
        to_lower(b);

        // 첫 번째 단어인 경우에는 이전 단어가 없으므로 규칙 검사 없이 통과
        if (count == 0)
        {
            // prev에 현재 단어를 복사하고 count 증가
            strcpy_s(a, sizeof(a), b);
            count++;
            continue;
        }

        // 두 번째 단어부터는 끝말잇기 규칙 검사
        if (chain_ok(a, b))
        {
            // 규칙을 지키면 현재 단어를 prev에 저장하고 count 증가
            strcpy_s(a, sizeof(a), b);
            count++;
        }
        else
        {
            // 규칙을 어기면 실패 메시지와 지금까지 맞춘 횟수 출력 후 종료
            printf("WRONG WORD!!! YOU FAILED!!!\n");
            printf("count: %d\n", count);
            break;
        }
    }
}

/*
    기능명: chain_ok. 끝말잇기 규칙 검사
    내용: 이전 단어 a의 마지막 문자와
          현재 단어 b의 첫 문자가 같은지 확인한다.
          같으면 규칙을 지킨 것으로 본다.
    입력: a는 이전 단어가 들어 있는 문자열
          b는 현재 단어가 들어 있는 문자열
    출력: 규칙이 맞으면 1, 규칙을 어기면 0을 반환한다.
    오류: 없음 (문자열이 정상적으로 끝난다고 가정)
*/
int chain_ok(char a[], char b[])
{
    char last;  // 이전 단어의 마지막 문자
    char first; // 현재 단어의 첫 문자

    // a의 마지막 글자
    last = a[strlen(a) - 1]; // a의 길이를 구한다. 그리고 -1를 하면 a의 인덱스 중에서 마지막 인덱스가 구해진다.
    // b의 첫 글자
    first = b[0];

    if (last == first)
    {
        return 1; // 두 문자가 같으면 규칙을 지킨 것
    }
    else
    {
        return 0; // 다르면 규칙을 어긴 것
    }
}

/*
    기능명: to_lower. 소문자 변환
    내용: 문자열의 모든 문자에 대해 알파벳이면 소문자로 바꾼다.
          영문 대소문자를 구분하지 않고 비교하기 위한 준비 작업이다.
    입력: s  변환할 문자열
    출력: 없음 (문자열 s 안의 내용이 직접 바뀐다)
    오류: 없음
*/
void to_lower(char s[])
{
    int i;

    // 문자열 끝의 '\0'을 만날 때까지 반복
    for (i = 0; s[i] != '\0'; i++)
    {
        s[i] = tolower(s[i]); // s[i]가 영문 대문자이면 소문자로 바꾼다.
    }
}
