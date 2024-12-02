#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENT_NUM 150
#define NAME_LENGTH 30

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

float calculateTotalScore(Student* student);
void Grade(Student* student);
void enterStudentInfo(Student* student, int* Student_num);
void printStudentInfo(Student* student, int Student_num);

#endif