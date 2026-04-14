#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char name[200];
    int grade;
} student;

student **create_class(const char **names, const int *grades, int n) {
    student **students = (student **)malloc(n * sizeof(student*));
    for (int i = 0; i < n; i++) {
        students[i] = (student *)malloc(sizeof(student));
        printf("Enter name and grade for student %d: ", i + 1);
        scanf("%s %d", students[i]->name, &students[i]->grade);
    }
    return students;
}

void destroy_class(student **students, int n) {
    for (int i = 0; i < n; i++) {
        free(students[i]);
    }
    free(students);
}

int main() {
    
}