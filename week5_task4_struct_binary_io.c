/*
Shivang Dash
231ADB209
File: week5_task4_struct_binary_io.c
Desc: Binary I/O save/load for a Student record
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[64];
    int age;
    float gpa;
} Student;

int main(void) {
    const char *binfile = "student.bin";
    Student a = {0}, b = {0};
    strcpy(a.name, "Alice");
    a.age = 21;
    a.gpa = 3.75f;

    printf("Saving student in binary format...\n");
    FILE *fp = fopen(binfile, "wb");
    if (!fp) { perror("fopen"); return 1; }
    if (fwrite(&a, sizeof(Student), 1, fp) != 1) {
        fprintf(stderr, "Write failed.\n");
        fclose(fp);
        return 1;
    }
    fclose(fp);

    printf("Loading student from binary file...\n");
    fp = fopen(binfile, "rb");
    if (!fp) { perror("fopen"); return 1; }
    if (fread(&b, sizeof(Student), 1, fp) != 1) {
        fprintf(stderr, "Read failed.\n");
        fclose(fp);
        return 1;
    }
    fclose(fp);

    printf("Loaded student: %s, %d, GPA %.2f\n", b.name, b.age, b.gpa);
    return 0;
}
