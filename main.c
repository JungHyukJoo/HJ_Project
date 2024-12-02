#include <stdio.h>
#include "student.h"
#include "sort.h"

// main function
int main() {
    Student student[MAX_STUDENT_NUM];
    int Student_num = 0;
    int menu;

    while (1) {
        printf("\n===== Student Grade Management System =====\n");
        printf("1. Enter Student Information\n");
        printf("2. Print Student Information\n");
        printf("3. Sort by Student ID\n");
        printf("4. Exit\n");
        printf("Select the menu: ");
        scanf("%d", &menu);

        // if user enters a value other than 1, 2, 3, or 4, including any non-numeric input, print an error message.
        if (getchar() != '\n') {
            printf("You entered an incorrect value. Please select the correct menu.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (menu) {
            case 1:
                enterStudentInfo(student, &Student_num);
                break;
            case 2:
                printStudentInfo(student, Student_num);
                break;
            case 3:
                sortStudentByID(student, Student_num);
                printStudentInfo(student, Student_num);
                break;
            case 4:
                printf("Exit the program.\n");
                return 0;
            default:
                printf("Please select the correct menu.\n");
        }
    }

    return 0;
}