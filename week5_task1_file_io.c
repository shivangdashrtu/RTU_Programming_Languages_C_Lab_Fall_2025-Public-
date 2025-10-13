/*
Shivang Dash
231ADB209
File: week5_task1_file_io.c
Desc: Write lines to a text file and read them back
*/

#include <stdio.h>

int main(void) {
    const char *fname = "data.txt";
    FILE *fp = fopen(fname, "w");
    if (!fp) {
        perror("fopen for write");
        return 1;
    }

    printf("Writing lines to %s...\n", fname);
    fprintf(fp, "Hello, file I/O in C!\n");
    fprintf(fp, "This is another line.\n");
    fclose(fp);

    fp = fopen(fname, "r");
    if (!fp) {
        perror("fopen for read");
        return 1;
    }

    printf("Reading contents:\n");
    char buf[256];
    while (fgets(buf, (int)sizeof(buf), fp)) {
        fputs(buf, stdout);
    }
    fclose(fp);
    return 0;
}
