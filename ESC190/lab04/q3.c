#include <stdio.h>
#include <stdlib.h>

typedef struct student 
{
    char name[50];
    int age;
} student;

void set_name(student *person, const char *name)
{
    int i = 0;
    int size = 0;

    while (name[size] != '\0')
    {
        size++;
    }

    if (size >= 50)
    {
        size = 49;
    }
    
    for (i = 0; i < size; i++)
    {
        person->name[i] = name[i];
    }

    person->name[i] = '\0';
}

int main() 
{
    //change_name1_wrong() does not exist in python as strings are immutable + local variable not global
    //change_name1_righta() does not exist in python as strings are immutable (even as a global variable)
    //change_name1_rightb() does not exist in python as locations of individual characrters cannot be accessed directly to replace specific characters
    student s;
    set_name(&s, "Bob");
    printf("Student name: %s\n", s.name);



    set_name(&s, "Charlie");
    printf("Student name: %s\n", s.name);


    // Memory table - OLD
    // Address    Variable      Value
    // 0x7ffee3bff5c0   s.name[0]     'C'
    // 0x7ffee3bff5c1   s.name[1]     'h'
    // 0x7ffee3bff5c2   s.name[2]   'a'
    // 0x7ffee3bff5c3   s.name[3]   'r'
    // 0x7ffee3bff5c4   s.name[4]   'l'
    // 0x7ffee3bff5c5   s.name[5]   'i'
    // 0x7ffee3bff5c6   s.name[6]   'e'
    // 0x7ffee3bff5c7   s.name[7]   '\0'

    // Memory table - NEW
    // Address    Variable      Value
    // 0x7ffee3bff5c0   s.name[0]     'B'
    // 0x7ffee3bff5c1   s.name[1]     'o'
    // 0x7ffee3bff5c2   s.name[2]   'b'
    // 0x7ffee3bff5c3   s.name[3]   '\0'
}