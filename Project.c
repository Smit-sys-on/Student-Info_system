#include<stdio.h>

struct student {
    char name[100];
    char department[100];
    int semester;
    char email[100];
    int roll_number;
};

int main() {
    struct student s;
    printf("Enter student name: ");
    scanf("%99s", &s.name);

    printf("Enter student department: ");
    scanf("%99s", &s.department);

    printf("Enter student semester: ");
    scanf("%d", &s.semester);

    printf("Enter student email: ");
    scanf("%99s", s.email);

    printf("Enter student roll number: ");
    scanf("%d", &s.roll_number);

    printf("\nStudent Information:\n");

    printf("Name: %s\n", s.name);
    printf("Department: %s\n", s.department);
    printf("Semester: %d\n", s.semester);
    printf("Email: %s\n", s.email);
    printf("Roll Number: %d\n", s.roll_number);

    return 0;
}