/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 12. 기차표 예매 프로그램
        좌석은 10개이며, 예매할 좌석 수를 입력받아 빈 좌석부터 순서대로 예매한다.
        O이면 예매 가능, X면 예매 불가를 의미한다. 더 이상 예매할 수 없으면 프로그램을 종료한다.
    날짜 : 2025.11.26
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 함수 프로토타입 선언
void sit();
void sitPrint(int sitTrain[], int size);
void sitInput(int sitTrain[], int size);
void sitCheck(int sitTrain[], int size);

/*
    기능명: main. 프로그램 시작점
    내용: sit 함수를 호출하여 좌석 예매 프로그램을 실행한다.
    입력: 없음
    출력: 좌석 상태 및 예매 결과를 콘솔에 출력한다.
    오류: 없음
*/
int main()
{
    sit(); // 좌석 배열 초기화 및 예매 기능 시작
    return 0;
}

/*
    기능명: sit. 좌석 배열 초기화 및 예매 시작
    내용: 좌석 배열을 0으로 초기화한 뒤 sitInput 함수를 호출하여 예매 과정을 시작한다.
          0은 빈 좌석, 1은 예매된 좌석을 의미한다.
    입력: 없음
    출력: 없음
    오류: 없음
*/
void sit()
{
    int sitTrain[10] = { 0 }; // 기차 좌석 10개를 모두 빈 좌석 상태로 초기화
    int size = sizeof(sitTrain) / sizeof(sitTrain[0]); // 좌석 개수 계산

    sitInput(sitTrain, size); // 좌석 예매 기능 수행
}

/*
    기능명: sitPrint. 현재 좌석 상태 출력
    내용: 좌석 배열을 순회하며 0은 문자 O, 1은 문자 X로 변환해 출력하여 현재 좌석 상태를 보여준다.
    입력: int sitTrain[] 좌석 배열, int size 좌석 수
    출력: 좌석 상태를 콘솔에 한 줄로 출력한다.
    오류: 없음
*/
void sitPrint(int sitTrain[], int size)
{
    printf("현재 좌석 : [ ");

    for (int i = 0; i < size; i++)
    {
        if (sitTrain[i] == 0) // 값이 0이면 아직 예매되지 않은 좌석
            printf("O ");
        else // 값이 1이면 이미 예매된 좌석
            printf("X ");
    }
    printf("]\n");
}

/*
    기능명: sitInput. 좌석 예매 처리
    내용: 반복해서 예매할 좌석 수를 입력받고, 남은 좌석 수를 계산한 뒤
          남은 좌석보다 적거나 같은 경우 앞에서부터 순서대로 예매한다.
          남은 좌석보다 많은 수를 요청하면 예약 좌석이 부족하다는 메시지를 출력하고 반복을 종료한다.
    입력: int sitTrain[] 좌석 배열, int size 좌석 수
    출력: 예매된 좌석 번호와 예매 후 좌석 상태를 콘솔에 출력한다.
    오류: 남은 좌석보다 많은 좌석 수를 요청한 경우 예매 불가 메시지를 출력하고 반복문을 종료한다.
*/
void sitInput(int sitTrain[], int size)
{
    int num = 0;   // 사용자가 입력한 예매할 좌석 수

    while (1)
    {
        int sitReserved[10] = { 0 }; // 이번에 새로 예매된 좌석 번호를 저장할 배열
        int reserved = 0; // 이번 회차에서 실제로 예매된 좌석 개수
        int remain = 0; // 현재 남아 있는 빈 좌석 수

        // 현재 좌석 상태 출력
        sitPrint(sitTrain, size);

        // 예매할 좌석 수 입력
        printf("예매할 좌석수? ");
        if (scanf("%d", &num) != 1)
        {
            // 잘못된 입력을 한 경우 프로그램을 안전하게 종료
            printf("잘못된 입력입니다.\n");
            return;
        }

        // 남은 좌석 수 계산
        for (int i = 0; i < size; i++)
        {
            // 아직 예매되지 않은 좌석
            if (sitTrain[i] == 0)
            {
                remain++;
            }
        }

        // 예매 불가 조건 검사
        if (remain < num) // 남은 좌석 수보다 더 많은 좌석을 요청한 경우
        {
            printf("예약 좌석이 부족합니다.\n");
            break; // 더 이상 예매를 진행하지 않고 반복 종료
        }

        // 예약 가능한 좌석부터 순서대로 예매
        for (int i = 0; reserved < num && i < size; i++)
        {
            // 비어 있는 좌석을 발견하면 예매 처리
            if (sitTrain[i] == 0)
            {
                sitTrain[i] = 1; // 좌석을 예매된 상태로 변경
                sitReserved[reserved] = i + 1; // 실제 출력용 좌석 번호는 1부터 시작하므로 인덱스에 1을 더한다
                reserved++; // 예매된 좌석 수 증가
            }
        }

        // 이번에 예매된 좌석 번호 출력
        for (int j = 0; j < reserved; j++)
            printf("%d ", sitReserved[j]);
        printf("번 좌석을 예매했습니다.\n");

        // 모든 좌석이 예매되었는지 확인
        sitCheck(sitTrain, size);
    }
}

/*
    기능명: sitCheck. 모든 좌석 예매 완료 여부 확인
    내용: 좌석 배열을 검사하여 하나라도 빈 좌석이 남아 있으면 계속 진행하고,
          모든 좌석이 예매된 상태면 안내 메시지를 출력한 뒤 프로그램을 종료한다.
    입력: int sitTrain[] 좌석 배열, int size 좌석 수
    출력: 모든 좌석 예매 완료 시 메시지 출력
    오류: 없음
*/
void sitCheck(int sitTrain[], int size)
{
    int all = 1; // 처음에는 모든 좌석이 예매되었다고 가정하고 검사 시작

    for (int i = 0; i < size; i++)
    {
        if (sitTrain[i] == 0) // 하나라도 빈 좌석이 있으면
        {
            all = 0; // 아직 예매가 끝나지 않았음을 표시
            break;
        }
    }

    if (all == 1) // 모든 좌석이 예매된 상태라면
    {
        printf("모든 좌석 예매 완료.\n");
        exit(0); // 프로그램을 즉시 종료
    }
}
