/*
Shivang Dash
231ADB209
File: week5_task2_struct_save_load.c
Desc: Save and load a Student struct using text I/O
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[64];
    int age;
    float gpa;
} Student;

int save_student(const char *filename, const Student *s) {
    FILE *fp = fopen(filename, "w");
    if (!fp) return 0;
    /* Save format: name age gpa */
    int ok = fprintf(fp, "%s %d %.2f\n", s->name, s->age, s->gpa) > 0;
    fclose(fp);
    return ok;
}

int load_student(const char *filename, Student *out) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return 0;
    int ok = fscanf(fp, "%63s %d %f", out->name, &out->age, &out->gpa) == 3;
    fclose(fp);
    return ok;
}

int main(void) {
    const char *file = "student.txt";
    Student a = {0}, b = {0};

    strcpy(a.name, "Alice");
    a.age = 21;
    a.gpa = 3.75f;

    printf("Saving student to file...\n");
    if (!save_student(file, &a)) {
        fprintf(stderr, "Save failed.\n");
        return 1;
    }

    printf("Loading student from file...\n");
    if (!load_student(file, &b)) {
        fprintf(stderr, "Load failed.\n");
        return 1;
    }

    printf("Loaded student: %s, %d, GPA %.2f\n", b.name, b.age, b.gpa);
    return 0;
}
