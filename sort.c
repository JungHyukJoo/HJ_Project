#include "sort.h"

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