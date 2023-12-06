#include <stdio.h>

typedef struct
{
    int student_no;
    char name[20];
    int batch;
    int marks_course1;
    int marks_course2;
    int marks_course3;
    char grade;
} Student;

int main()
{
    Student stu[100];

    FILE *fp = fopen("student.dat", "rb");
    int i = 0;
    while (fread(&stu[i], sizeof(stu[i]), 1, fp))
    {
        printf("\n\nStudent No    : %d\n", stu[i].student_no);
        printf("Name          : %s\n", stu[i].name);
        printf("Batch         : %d\n", stu[i].batch);
        printf("Course 1      : %d\n", stu[i].marks_course1);
        printf("Course 2      : %d\n", stu[i].marks_course2);
        printf("Course 3      : %d\n", stu[i].marks_course3);
        printf("Grade         : %c\n", stu[i].grade);
        i++;
    }
    fclose(fp);

    return 0;
}