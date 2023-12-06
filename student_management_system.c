#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAX 100

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

Student stu[MAX];
int noOfStudent;
bool isCalculate = false;

void print_image();
void delay(char[]);
void menu();
void studentDataEntry();
void computeGrade();
void displayStudentInformation();
void displayStudentListyByBatch();
void displayStudentListyByGrade();
void studentEnquiry();
void saveToFile();

int main()
{
    int opt = 0;
    char ans;

    system("clear");
    print_image();
    sleep(5);
    system("clear");

    delay("\n\n\t\t\t\t\tStudent Management System\n");
    delay("\t\t\t\t\t*************************\n");
    delay("\t\t\t\t\t     MIIT 2019-Batch\n");
    delay("\t\t\t\t\t     ^^^^^^^^^^^^^^^\n");
    delay("\t\t\t\t\t    <Group I Members/>\n");
    delay("\t\t\t\t\t    ----------------\n");
    delay("\t\t\t\t\t1. Ye Min Aung     - 2019-MIIT-ECE-050\n");
    delay("\t\t\t\t\t2. Kaung Sat Lin   - 2019-MIIT-CSE-012\n");
    delay("\t\t\t\t\t3. Hein Htet Paing - 2019-MIIT-CSE-006\n\n");
    sleep(3);

    do
    {
        printf("Press \'ENTER\' to continue the program...");
        ans = getchar();
        if (ans == '\n')
            break;
        getchar();
    } while (!(ans == '\n'));
    ans = ' ';
    system("clear");

    do
    {
        menu();

        do
        {
            printf("Select option number : (1-8) => ");
            scanf("%d", &opt);
            getchar();
        } while (!(opt >= 1 && opt <= 8));

        switch (opt)
        {
        case 1:
            studentDataEntry(stu);
            break;
        case 2:
            computeGrade();
            break;
        case 3:
            displayStudentInformation();
            break;
        case 4:
            displayStudentListyByBatch();
            break;
        case 5:
            displayStudentListyByGrade();
            break;
        case 6:
            studentEnquiry();
            break;
        case 7:
            saveToFile();
            break;
        case 8:
            printf("\nThe project is terminated...\n\n");
            exit(1);
        default:
            printf("\nInvalid\n\n");
        }

        printf("\n");

        do
        {
            printf("Press \'ENTER\' to continue...");
            ans = getchar();
            if (ans == '\n')
                break;
            getchar();
        } while (!(ans == '\n'));

    } while (true);
}

void delay(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
        for (int i = 0; i < 9999999; i++)
        {
        }
    }
}

void menu()
{
    system("clear");
    printf("\nStudent Information System\n");
    printf("**************************\n");
    printf("1. Student Data Entry\n");
    printf("2. Compute grade of each student\n");
    printf("3. Display student Information in Detail\n");
    printf("4. Display student List by Batch (Descending order)\n");
    printf("5. Display student List by grade (Descending order)\n");
    printf("6. Student Enquiry\n");
    printf("7. Save Student Data into File named student.dat\n");
    printf("8. Exit\n\n");
}

void studentDataEntry()
{
    system("clear");

    char ans;
    int c = 0;

    fflush(stdin);
    do
    {
        printf("\n\nStudent Data Entry\n");
        printf("*******************\n");
        printf("Student No  :\t");
        scanf("%d", &stu[c].student_no);
        getchar();
        printf("Name        :\t");
        scanf("%[^\n]s", stu[c].name);
        getchar();
        printf("Batch       :\t");
        scanf("%d", &stu[c].batch);
        printf("Marks of Course 1 :\t");
        scanf("%d", &stu[c].marks_course1);
        printf("Marks of Course 2 :\t");
        scanf("%d", &stu[c].marks_course2);
        printf("Marks of Course 3 :\t");
        scanf("%d", &stu[c].marks_course3);
        getchar();

        c++;
        noOfStudent++;

        do
        {
            printf("\nAny more data(y/n)? => ");
            ans = getchar();
            ans = tolower(ans);
            getchar();
        } while (!(ans == 'y' || ans == 'n'));

    } while (ans == 'y');
}

void computeGrade()
{
    int total_marks = 0;

    if (noOfStudent > 0)
    {
        printf("\nWait a few seconds....\n");
        sleep(3);

        for (int i = 0; i < noOfStudent; i++)
        {
            total_marks = stu[i].marks_course1 + stu[i].marks_course2 + stu[i].marks_course3;

            if (total_marks >= 250 && total_marks <= 300)
                stu[i].grade = 'A';
            else if (total_marks >= 200 && total_marks < 250)
                stu[i].grade = 'B';
            else if (total_marks >= 150 && total_marks < 200)
                stu[i].grade = 'C';
            else if (total_marks >= 100 && total_marks < 150)
                stu[i].grade = 'D';
            else if (total_marks < 100)
                stu[i].grade = 'E';
            else
                stu[i].grade = '-';
        }
        printf("\nGrades are calculated\n");
        isCalculate = true;
    }
    else
    {
        printf("\n=>>>  You haven't entered student data.!!!\n");
    }
}

void displayStudentInformation()
{
    char ans;

    if (noOfStudent > 0)
    {
        if (isCalculate)
        {
            system("clear");

            printf("\nStudent Information in Detail\n");
            printf("*****************************\n");
            printf("Student_No\tName\t\tBatch\t\tCourse 1\tCourse 2\tCourse 3\tGrade\n");
            printf("****\t\t*****\t\t*****\t\t*****\t\t*****\t\t*****\t\t*****\n\n");

            for (int i = 0; i < noOfStudent; i++)
            {
                printf("%d\t\t", stu[i].student_no);
                printf("%-10s\t", stu[i].name);
                printf("%d\t\t", stu[i].batch);
                printf("%d\t\t", stu[i].marks_course1);
                printf("%d\t\t", stu[i].marks_course2);
                printf("%d\t\t", stu[i].marks_course3);
                printf("%c\n", stu[i].grade);
            }
        }
        else
        {
            printf("\n!!! Student's grades are not calculated.\n\n");

            do
            {
                printf("Do you still want to see student information (y/n)? => ");
                ans = getchar();
                ans = tolower(ans);
                getchar();
            } while (!(ans == 'y' || ans == 'n'));

            if (ans == 'y')
            {
                system("clear");

                printf("\nStudent Information in Detail\n");
                printf("*****************************\n");
                printf("Student_No\tName\t\tBatch\t\tCourse 1\tCourse 2\tCourse 3\tGrade\n");
                printf("****\t\t*****\t\t*****\t\t*****\t\t*****\t\t*****\t\t*****\n\n");

                for (int i = 0; i < noOfStudent; i++)
                {
                    printf("%d\t\t", stu[i].student_no);
                    printf("%-10s\t", stu[i].name);
                    printf("%d\t\t", stu[i].batch);
                    printf("%d\t\t", stu[i].marks_course1);
                    printf("%d\t\t", stu[i].marks_course2);
                    printf("%d\t\t", stu[i].marks_course3);
                    stu[i].grade = '-';
                    printf("%c\n", stu[i].grade);
                }
                printf("\n-> Go back to Main Menu and select \'2\' to calculate student's grades.\n\n");
            }
        }
    }
    else
    {
        printf("\n=>>>  You haven't entered student data.!!!\n");
    }
}

void displayStudentListyByBatch()
{
    Student temp;
    bool makeSwap = true;

    if (noOfStudent > 0)
    {
        system("clear");
        printf("\nStudent Information (Descending order by Batch.)\n");
        printf("*****************************************************\n");
        printf("Student_No\tName\t\tBatch\t\tCourse 1\tCourse 2\tCourse 3\tGrade\n");
        printf("****\t\t*****\t\t*****\t\t*****\t\t*****\t\t*****\t\t*****\n\n");

        while (makeSwap)
        {
            makeSwap = false;
            for (int i = 0; i < noOfStudent - 1; i++)
            {
                if (stu[i].batch < stu[i + 1].batch)
                {
                    temp = stu[i];
                    stu[i] = stu[i + 1];
                    stu[i + 1] = temp;
                    makeSwap = true;
                }
            }
        }

        for (int i = 0; i < noOfStudent; i++)
        {
            printf("%d\t\t", stu[i].student_no);
            printf("%-10s\t", stu[i].name);
            printf("%d\t\t", stu[i].batch);
            printf("%d\t\t", stu[i].marks_course1);
            printf("%d\t\t", stu[i].marks_course2);
            printf("%d\t\t", stu[i].marks_course3);
            printf("%c\n", stu[i].grade);
        }
    }
    else
    {
        printf("\n=>>>  You haven't entered student data.!!!\n");
    }
}

void displayStudentListyByGrade()
{
    Student temp;
    bool makeSwap = true;

    if (noOfStudent > 0)
    {
        system("clear");
        printf("\nStudent Information (Descending order by grade)\n");
        printf("*****************************************************\n");
        printf("Student_No\tName\t\tBatch\t\tCourse 1\tCourse 2\tCourse 3\tGrade\n");
        printf("****\t\t*****\t\t*****\t\t*****\t\t*****\t\t*****\t\t*****\n\n");

        while (makeSwap)
        {
            makeSwap = false;
            for (int i = 0; i < noOfStudent - 1; i++)
            {
                if (stu[i].grade > stu[i + 1].grade)
                {
                    temp = stu[i];
                    stu[i] = stu[i + 1];
                    stu[i + 1] = temp;
                    makeSwap = true;
                }
            }
        }

        for (int i = 0; i < noOfStudent; i++)
        {
            printf("%d\t\t", stu[i].student_no);
            printf("%-10s\t", stu[i].name);
            printf("%d\t\t", stu[i].batch);
            printf("%d\t\t", stu[i].marks_course1);
            printf("%d\t\t", stu[i].marks_course2);
            printf("%d\t\t", stu[i].marks_course3);
            printf("%c\n", stu[i].grade);
        }
    }
    else
    {
        printf("\n=>>>  You haven't entered student data.!!!\n");
    }
}

void studentEnquiry()
{
    int opt = 0;
    int i = 0;
    bool isFound = false;
    int student_no;
    char student_name[20];

    if (noOfStudent > 0)
    {
        system("clear");
        printf("Student Enquiry\n");
        printf("***************\n\n");
        printf("1. Search by Student No.\n");
        printf("2. Search by Name\n\n\n");

        do
        {
            printf("Select option number : (1 or 2) => ");
            scanf("%d", &opt);
        } while (!(opt >= 1 && opt <= 2));

        if (opt == 1)
        {
            printf("\nEnter Student No. (for option number 1) : ");
            scanf("%d", &student_no);
            getchar();

            while (i < noOfStudent && !isFound)
            {
                if (stu[i].student_no == student_no)
                {
                    printf("\n\nStudent No    :\t%d\n", stu[i].student_no);
                    printf("Name          :\t%s\n", stu[i].name);
                    printf("Batch         :\t%d\n", stu[i].batch);
                    printf("Course 1      :\t%d\n", stu[i].marks_course1);
                    printf("Course 2      :\t%d\n", stu[i].marks_course2);
                    printf("Course 3      :\t%d\n", stu[i].marks_course3);
                    printf("Grade         :\t%c\n\n", stu[i].grade);
                    isFound = true;
                }
                i++;
            }
            if (!isFound)
                printf("\n%d is not found in STUDENT DATABASE\n\n", student_no);
        }
        else if (opt == 2)
        {
            getchar();
            printf("\nEnter Name (for option number 2) : ");
            scanf("%[^\n]s", student_name);
            getchar();

            while (i < noOfStudent)
            {
                if (!strcmp(stu[i].name, student_name))
                {
                    printf("\n\nStudent No    :\t%d\n", stu[i].student_no);
                    printf("Name          :\t%s\n", stu[i].name);
                    printf("Batch         :\t%d\n", stu[i].batch);
                    printf("Course 1      :\t%d\n", stu[i].marks_course1);
                    printf("Course 2      :\t%d\n", stu[i].marks_course2);
                    printf("Course 3      :\t%d\n", stu[i].marks_course3);
                    printf("Grade         :\t%c\n", stu[i].grade);
                    isFound = true;
                }
                i++;
            }
            if (!isFound)
                printf("\n%s is not found in STUDENT DATABASE\n\n", student_name);
        }
    }
    else
    {
        printf("\n=>>>  You haven't entered student data.!!!\n");
    }
}

void saveToFile()
{
    if (noOfStudent > 0)
    {
        system("clear");
        printf("\n\nWriting into File...\n");
        printf("\nPlease wait a few seconds...\n\n");
        sleep(3);

        FILE *fp = fopen("student.dat", "wb");

        for (int i = 0; i < noOfStudent; i++)
        {
            fwrite(&stu[i], sizeof(stu[i]), 1, fp);
        }
        system("clear");
        printf("\nStudent information is saving as \'student.dat\' File\n");
        fclose(fp);
    }
    else
    {
        printf("\n=>>>  You haven't entered student data.!!!\n");
    }
}

void print_image()
{
    char *filename = "image.txt";
    FILE *fptr = NULL;

    if ((fptr = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "error opening %s\n", filename);
        printf("Error loading Header Image!\n");
    }

    char read_string[128];

    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
    {
        for (int i = 0; read_string[i] != '\0'; i++)
        {
            printf("%c", read_string[i]);
            for (int i = 0; i < 999999; i++)
            {
            }
            for (int i = 0; i < 999999; i++)
            {
            }
        }
    }
    fclose(fptr);
}