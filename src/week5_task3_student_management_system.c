/*
Shivang Dash
231ADB209
File: week5_task3_student_management_system.c
Desc: Student management system with file persistence
*/

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 200

typedef struct {
    int id;
    char name[64];
    float gpa;
} Student;

int load_students(const char *fname, Student *arr, int *count) {
    *count = 0;
    FILE *fp = fopen(fname, "r");
    if (!fp) return 1; /* Empty/missing file is fine */
    while (*count < MAX_STUDENTS) {
        Student s;
        int r = fscanf(fp, "%d %63s %f", &s.id, s.name, &s.gpa);
        if (r != 3) break;
        arr[*count] = s;
        (*count)++;
    }
    fclose(fp);
    return 1;
}

int save_students(const char *fname, const Student *arr, int count) {
    FILE *fp = fopen(fname, "w");
    if (!fp) return 0;
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %.2f\n", arr[i].id, arr[i].name, arr[i].gpa);
    }
    fclose(fp);
    return 1;
}

int add_student(Student *arr, int *count) {
    if (*count >= MAX_STUDENTS) return 0;
    Student s;
    printf("Enter name: ");
    if (scanf("%63s", s.name) != 1) return 0;
    printf("Enter ID: ");
    if (scanf("%d", &s.id) != 1) return 0;
    printf("Enter GPA: ");
    if (scanf("%f", &s.gpa) != 1) return 0;
    arr[*count] = s;
    (*count)++;
    printf("Student added successfully!\n");
    return 1;
}

void list_students(const Student *arr, int count) {
    if (count == 0) {
        printf("No students.\n");
        return;
    }
    printf("ID     Name                         GPA\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-28s %.2f\n", arr[i].id, arr[i].name, arr[i].gpa);
    }
}

int main(void) {
    const char *file = "students.txt";
    Student students[MAX_STUDENTS];
    int count = 0;

    load_students(file, students, &count);

    while (1) {
        int opt;
        printf("\n=== Student Management System ===\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Save and Exit\n");
        printf("Select an option: ");
        if (scanf("%d", &opt) != 1) {
            fprintf(stderr, "Invalid input.\n");
            return 1;
        }
        if (opt == 1) {
            list_students(students, count);
        } else if (opt == 2) {
            if (!add_student(students, &count)) {
                printf("Failed to add student.\n");
            }
        } else if (opt == 3) {
            if (!save_students(file, students, count)) {
                fprintf(stderr, "Save failed.\n");
                return 1;
            }
            printf("Data saved. Goodbye!\n");
            break;
        } else {
            printf("Unknown option.\n");
        }
    }
    return 0;
}
