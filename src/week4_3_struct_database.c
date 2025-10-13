/*
Shivang Dash
231ADB209
File: src/week4_3_struct_database.c
Desc: In-memory database with dynamic array of Students
*/

#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    int n;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid count.\n");
        return 1;
    }

    struct Student *students = (struct Student *)malloc((size_t)n * sizeof(struct Student));
    if (!students) {
        fprintf(stderr, "Allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter data for student %d: ", i + 1);
        if (scanf("%49s %d %f", students[i].name, &students[i].id, &students[i].grade) != 3) {
            fprintf(stderr, "Input error.\n");
            free(students);
            return 1;
        }
    }

    printf("\nID     Name                 Grade\n");
    for (int i = 0; i < n; i++) {
        printf("%-6d %-20s %.2f\n", students[i].id, students[i].name, students[i].grade);
    }

    free(students);
    return 0;
}
