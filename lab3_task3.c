/*
Shivang Dash
231ADB209
File: lab3_task3.c
Desc: Manual string handling (strlen, strcpy)
*/

#include <stdio.h>

/* Prototypes */
int my_strlen(const char *str);
void my_strcpy(char *dest, const char *src);

int my_strlen(const char *str) {
    if (!str) return 0;
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

void my_strcpy(char *dest, const char *src) {
    if (!dest || !src) return;
    int i = 0;
    while ((dest[i] = src[i]) != '\0') i++;
}

int main(void) {
    char text[] = "hello";
    int len = my_strlen(text);
    printf("Length: %d\n", len);

    char buffer[100];
    my_strcpy(buffer, text);
    printf("%s\n", buffer);
    return 0;
}
