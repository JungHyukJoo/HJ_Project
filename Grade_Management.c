// Student grade management system
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// maximum number of student is 150
#define MAX_STUDENT_NUM 150
// maximum length of name is 30
#define NAME_LENGTH 30

// define Student structure
// include name, ID, score of 4 elements, average score, grade
typedef struct {
    char name[NAME_LENGTH];
    int StudentID;
    float attendance;
    float assignment;
    float midtermExam;
    float finalExam;
    float totalScore;
    char grade[3];
} Student;

// function of calculating the score
float calculateTotalScore(Student* student) {
    float totalScore = 0.0;
    totalScore += student->attendance * 0.1;
    totalScore += student->assignment * 0.2;
    totalScore += student->midtermExam * 0.3;
    totalScore += student->finalExam * 0.4;

    return totalScore;
}

// function of calculating the grade
void Grade(Student* student) {
    if (student->totalScore >= 90) {
        strcpy(student->grade, "A+");
    } else if (student->totalScore >= 80) {
        strcpy(student->grade, "A0");
    } else if (student->totalScore >= 70) {
        strcpy(student->grade, "B+");
    } else if (student->totalScore >= 60) {
        strcpy(student->grade, "B0");
    } else if (student->totalScore >= 50) {
        strcpy(student->grade, "C+");
    } else if (student->totalScore >= 40) {
        strcpy(student->grade, "C0");
    } else if (student->totalScore >= 30) {
        strcpy(student->grade, "D+");
    } else if (student->totalScore >= 20) {
        strcpy(student->grade, "D0");
    } else {
        strcpy(student->grade, "F");
    }
}

// function of entering student information
void enterStudentInfo(Student* student, int* Student_num) {
    if (*Student_num >= MAX_STUDENT_NUM) {
        printf("The number of students is full.\n");
        return;
    }

    Student newStudent;
    printf("Enter the name of the student: ");
    scanf("%s", newStudent.name);

    printf("Enter the Student ID: ");
    scanf("%d", &newStudent.StudentID);

    printf("Enter the attendance Score: ");
    scanf("%f", &newStudent.attendance);
    // if user enters a value other than between 0 and 100, print an error message.
    if (newStudent.attendance < 0 || newStudent.attendance > 100) {
        printf("You entered an incorrect value. Please enter a value between 0 and 100.\n");
        return;
    }

    printf("Enter the assignment Score: ");
    scanf("%f", &newStudent.assignment);
    // if user enters a value other than between 0 and 100, print an error message.
    if (newStudent.attendance < 0 || newStudent.attendance > 100) {
        printf("You entered an incorrect value. Please enter a value between 0 and 100.\n");
        return;
    }

    printf("Enter the midtermExam Score: ");
    scanf("%f", &newStudent.midtermExam);
    // if user enters a value other than between 0 and 100, print an error message.
    if (newStudent.attendance < 0 || newStudent.attendance > 100) {
        printf("You entered an incorrect value. Please enter a value between 0 and 100.\n");
        return;
    }

    printf("Enter the finalExam Score: ");
    scanf("%f", &newStudent.finalExam);
    // if user enters a value other than between 0 and 100, print an error message.
    if (newStudent.attendance < 0 || newStudent.attendance > 100) {
        printf("You entered an incorrect value. Please enter a value between 0 and 100.\n");
        return;
    }

    // calculate the Total score
    newStudent.totalScore = calculateTotalScore(&newStudent);

    // calculate the grade
    Grade(&newStudent);

    // add the student to the student array
    student[*Student_num] = newStudent;
    *Student_num += 1;
}

// function of printing the student information
void printStudentInfo(Student* student, int Student_num) {
    printf("\n===== Student Information =====\n");

    for (int i = 0; i < Student_num; i++) {
        printf("Name: %s\n", student[i].name);
        printf("Student ID: %d\n", student[i].StudentID);
        printf("Attendance Score: %.2f\n", student[i].attendance);
        printf("Assignment Score: %.2f\n", student[i].assignment);
        printf("Midterm Exam Score: %.2f\n", student[i].midtermExam);
        printf("Final Exam Score: %.2f\n", student[i].finalExam);
        printf("Total Score: %.2f\n", student[i].totalScore);
        printf("Grade: %s\n", student[i].grade);
        printf("\n");
    }
}

// function of sorting by student ID
void sortStudentByID(Student* student, int Student_num) {
    for (int i = 0; i < Student_num - 1; i++) {
        for (int j = 0; j < Student_num - i - 1; j++) {
            if (student[j].StudentID > student[j + 1].StudentID) {
                Student temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
}

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