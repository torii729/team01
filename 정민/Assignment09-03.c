#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 1024

void convert_case(char* str) {
    while (*str) {
        unsigned char ch = (unsigned char)*str;

        if (islower(ch))
            *str = (char)toupper(ch);
        else if (isupper(ch))
            *str = (char)tolower(ch);

        str++;
    }
}

int main(void) {
    char input[MAX_LEN];

    printf("문자열? ");
    if (fgets(input, MAX_LEN, stdin) == NULL)
        return 0;

    printf("변환 후 : ");
    convert_case(input);
    printf("%s", input);

    return 0;
}