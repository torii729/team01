/*
    한 줄의 문자열을 입력받아서 공백 문자(' ', 'In', 'It', 'If', 'Ir', 'Iv')의 개수를 세는 프로- 램을 작성하시오.
*/
#include <stdio.h>

int main() {
    char str[200];
    int count = 0;

    printf("문자열? ");

    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
            str[i] == '\f' || str[i] == '\r' || str[i] == '\v') {
            count++;
        }
    }
    printf("\n공백 문자의 개수: %d\n", count);

    return 0;
}