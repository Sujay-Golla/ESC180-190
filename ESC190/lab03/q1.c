#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void set_int1(int x)
{
    x = 42;
}

void set_int2(int *p_x)
{
    *p_x = 42;
}

void print_student(student1 *person)
{
    printf("\nName: %s\n", person->name);
    printf("Student number: %s\n", person->student_number);
    printf("Name: %d\n", person->year);
}

void set_default_name(student1 *person){
    char default_n[] = "Default Name";
    char *pointer = default_n;
    int i = 0;

    while (*pointer != '\0')
    {
        *(person->name + i) = *pointer;
        pointer++;
        i++;
    }

    *pointer = '\0';
    printf("New name: %s\n", person->name);
}

void set_default_name_wrong(student1 person){
    char default_n[] = "Default Name";
    char *pointer = default_n;
    int i = 0;

    while (*pointer != '\0')
    {
        person.name[i] = *pointer;
        pointer++;
        i++;
    }

    *pointer = '\0';
    printf("New name: %s\n", person.name);
}

void create_block1(student1 **p_p_s, int n_students)
{
    *p_p_s = (student1 *)malloc(sizeof(student1) * n_students);
    (*p_p_s)[0] = (student1){"John", "0000000000", 2023};
    (*p_p_s)[1] = (student1){"Jane", "0000012010", 2022};
}

void set_name(student1 *person, const char *name)
{
    const char *pointer = name;
    int i = 0;
    int size = 0;

    while (*(pointer + size) != '\0')
    {
        size++;
    }

    if (size >= 200)
    {
        size = 199;
    }
    
    for (i = 0; i < size; i++)
    {
        *(person->name + i) = *(pointer + i);
    }

    *(person->name + i) = '\0';
}

void destroy_block1(student1 **p_p_s)
{
    free(*p_p_s);
    *p_p_s = NULL;
}

typedef struct student2{
    char *name;
    char *student_number;
    int year;
} student2;

void create_block2(student2 **p_p_s, int num_students)
{
    *p_p_s = (student2 *)malloc(sizeof(student2) * num_students);
    (*p_p_s)[0].name = "0";
    (*p_p_s)[0].student_number = "0";
    (*p_p_s)[0].year = 2023;

    (*p_p_s)[1].name = "1";
    (*p_p_s)[1].student_number = "1";
    (*p_p_s)[1].year = 2022;
}

void set_name2(student2 *person, const char *name)
{
    int size = 0;
    const char *pointer = name;

    while (*(pointer + size) != '\0')
    {
        size++;
    }

    person->name = (char *)malloc(sizeof(char) * (size + 1));

    for (int i = 0; i < size; i++)
    {
        *(person->name + i) = *(pointer + i);
    }

    *(person->name + size) = '\0';
}

void destroy_block2(student2 **p_p_s, int num_students)
{
    for (int i = 0; i < num_students; i++)
    {
        free((*p_p_s)[i].name);
    }
    free(*p_p_s);
    *p_p_s = NULL;
}

void q10_function(student1 s1, student2 s2)
{
    s1.name[0] = 'A';
    s2.name[0] = 'B';
}

void print_file_content(const char *filename, int N)
{
    char line[200];
    FILE *fp = fopen(filename, "r");
    for(int i = 0; i < N; i++){
        fgets(line, sizeof(line), fp); //read in at most sizeof(line) characters
        //(including ’\0’) into line.
    }
    fclose(fp);
}

int main()
{
    // Q1
    int x = 10;
    printf("%d\n", x);

    set_int1(x);
    printf("%d\n", x);

    set_int2(&x);
    printf("%d\n", x);

    // Q2
    student1 p1 = {"Jane Doe", "1234567890", 2025};
    print_student(&p1);

    // Q3 a)
    set_default_name(&p1);
    printf("New name: %s\n", p1.name);

    // Q3 b)
    student1 p2 = {"Jane Doe", "1234567890", 2025};
    print_student(&p2);
    set_default_name_wrong(p2);
    printf("New name: %s\n", p2.name);

    // Q4
    student1 *p_s = &p1;
    student1 **p_p_s = &p_s;
    create_block1(p_p_s, 3);
    print_student(&((*p_p_s)[0]));
    print_student(&((*p_p_s)[1]));

    // Q5
    set_name(&((*p_p_s)[1]), "Alice");
    printf("New name: %s\n", (*p_p_s)[1].name);

    // Q6
    destroy_block1(p_p_s);

    // Q7
    student2 p3;
    student2 *p_s2 = &p3;
    student2 **p_p_s2 = &p_s2;
    create_block2(p_p_s2, 2);

    // Q8
    set_name2(&((*p_p_s2)[0]), "Bob");
    set_name2(&((*p_p_s2)[1]), "Anderson");

    printf("New name: %s\n", (*p_p_s2)[0].name);

    // Q9
    destroy_block2(p_p_s2, 2);

    // Q10
    student1 s1 = {"Charlie", "0987654321", 2024};
    student2 s2 = {"David", "0987654333", 2017};
    printf("Before q10_function: s1.name = %s, s2.name = %s\n", s1.name, s2.name);
    // q10_function(s1, s2);
    // printf("After q10_function: s1.name = %s, s2.name = %s\n", s1.name, s2.name);


    // Q11
    
}