#include <stdio.h>
#include <string.h>

struct student {
    char name[100];
    char department[100];
    int semester;
    char email[100];
    int roll_number;
};

void read_text(const char *prompt, char *dest, int size) {
    while (1) {
        printf("%s", prompt);
        if (fgets(dest, size, stdin) == NULL) {
            dest[0] = '\0';
            return;
        }
        if (strchr(dest, '\n') == NULL) {      /* input was too long */
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;                              /* throw away the extra letters */
        }
        dest[strcspn(dest, "\n")] = '\0';   /* remove the newline */
        if (dest[0] != '\0')
            return;
        printf("Input cannot be empty. Try again.\n");
    }
}

/* Read a whole number between min and max. Ask again if wrong. */
int read_int(const char *prompt, int min, int max) {
    char line[100];
    int value;
    while (1) {
        printf("%s", prompt);
        if (fgets(line, sizeof(line), stdin) == NULL)
            return min;
        if (sscanf(line, "%d", &value) == 1 && value >= min && value <= max)
            return value;
        printf("Please enter a number from %d to %d.\n", min, max);
    }
}

/* Read an email. It must contain @ and a dot after the @. */
void read_email(char *dest, int size) {
    while (1) {
        read_text("Enter student email: ", dest, size);
        char *at = strchr(dest, '@');
        if (at != NULL && at != dest && strchr(at, '.') != NULL)
            return;
        printf("Please enter a valid email.\n");
    }
}

int main() {
    struct student s;

    read_text("Enter student name: ", s.name, sizeof(s.name));
    read_text("Enter student department: ", s.department, sizeof(s.department));
    s.semester = read_int("Enter student semester (1-8): ", 1, 8);
    read_email(s.email, sizeof(s.email));
    s.roll_number = read_int("Enter student roll number: ", 1, 2147483647);

    printf("\nStudent Information:\n");
    printf("Name: %s\n", s.name);
    printf("Department: %s\n", s.department);
    printf("Semester: %d\n", s.semester);
    printf("Email: %s\n", s.email);
    printf("Roll Number: %d\n", s.roll_number);

    return 0;
}
