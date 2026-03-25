#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

typedef struct student{
    int grade;
} student;

student * create_student(int grade){
    student *s = (student *)malloc(sizeof(student));
    s->grade = grade;
    return s;
}

student ** create_student_array(int n){
    student **arr = (student **)malloc(n * sizeof(student *));
    return arr;
}

int main(){
    int n = 3;
    student **students = create_student_array(n);
    students[0] = create_student(90);
    students[1] = create_student(91);
    students[2] = create_student(92);
    printf("Student 1 grade: %d\n", students[0]->grade);
    printf("Student 2 grade: %d\n", students[1]->grade);
    printf("Student 3 grade: %d\n", students[2]->grade);

    for (int i = 0; i < n; i++) {
        free(students[i]);
    }
    free(students);
}