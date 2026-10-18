#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    float gpa;
    char email[50];
};

Student students[100];
int count = 0;

// Function to add student
void addStudent() {
    printf("Enter ID: ");
    scanf("%d", &students[count].id);

    printf("Enter name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter age: ");
    scanf("%d", &students[count].age);

    printf("Enter GPA: ");
    scanf("%f", &students[count].gpa);

    printf("Enter email: ");
    scanf("%s", &students[count].email);

    count++;
    printf("Student added successfully!\n");
}

// Function to display students
void displayStudents() {
    if (count == 0) {
        printf("No students found.\n");
        return;
    }

    printf("\n===STUDENT LIST===\n");

    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Age: %d | GPA: %.2f | Email: %s\n", 
            students[i].id, 
            students[i].name, 
            students[i].age, 
            students[i].gpa, 
            students[i].email);
    }
}

// Function to search student by ID
void searchStudent() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Found!\n");
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("GPA: %.2f\n", students[i].gpa);
            return;
        }
    }

    printf("Student not found.\n");
}

// Function to delete student
void deleteStudent() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student deleted.\n");
            return;
        }
    }

    printf("Student not found.\n");
}

void clearAll()
{
    count = 0;
    printf("All students cleared!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Student Management System ===\n");
        printf("1. Add student\n");
        printf("2. Show students\n");
        printf("3. Search student\n");
        printf("4. Delete student\n");
        printf("5. Clear all students\n");
        printf("6. Exit\n");

        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            clearAll();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
