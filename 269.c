#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student
{
    int rollNumber;
    char name[50];
    char fatherName[50];
    int age;
    float cgpa;
    char intake[20];
    char section;
    char blood[5];
};

struct FundAccount
{
    int rollNumber;
    char password[20];
    float balance;
};

struct Student studentDatabase[MAX_STUDENTS];
struct FundAccount fundDatabase[MAX_STUDENTS];
int totalStudents = 0;
int totalAccounts = 0;

// Required function for options in info management
void addStudent()
{
    struct Student newStudent;
    printf("Enter student roll number: ");
    scanf("%d", &newStudent.rollNumber);
    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    printf("Enter father's name: ");
    scanf("%s", newStudent.fatherName);
    printf("Enter age: ");
    scanf("%d", &newStudent.age);
    printf("Enter CGPA: ");
    scanf("%f", &newStudent.cgpa);
    printf("Enter intake: ");
    scanf("%s", newStudent.intake);
    printf("Enter section: ");
    scanf(" %c", &newStudent.section);
    printf("Enter blood group: ");
    scanf("%s", newStudent.blood);
    studentDatabase[totalStudents] = newStudent;
    totalStudents++;
    printf("Student added successfully.\n");
}

void removeStudent()
{
    int rollNumber, found = 0;
    printf("Enter student roll number to remove: ");
    scanf("%d", &rollNumber);
    for (int i = 0; i < totalStudents; i++)
    {
        if (studentDatabase[i].rollNumber == rollNumber)
        {
            for (int j = i; j < totalStudents - 1; j++)
            {
                studentDatabase[j] = studentDatabase[j + 1];
            }
            totalStudents--;
            printf("Student removed successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Student not found.\n");
    }
}

void searchStudent()
{
    int rollNumber, found = 0;
    printf("Enter student roll number to search: ");
    scanf("%d", &rollNumber);
    for (int i = 0; i < totalStudents; i++)
    {
        if (studentDatabase[i].rollNumber == rollNumber)
        {
            printf("Student found.\n");
            printf("Name: %s\nFather's Name: %s\nAge: %d\nCGPA: %.2f\nIntake: %s\nSection: %c\nBlood Group: %s\n",
                   studentDatabase[i].name,
                   studentDatabase[i].fatherName,
                   studentDatabase[i].age,
                   studentDatabase[i].cgpa,
                   studentDatabase[i].intake,
                   studentDatabase[i].section,
                   studentDatabase[i].blood);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Student not found.\n");
    }
}

void displayAllStudents()
{
    if (totalStudents == 0)
    {
        printf("No records found.\n");
    }
    else
    {
        printf("Roll Number\tName\tFather's Name\tAge\tCGPA\tIntake\tSection\tBlood Group\n");
        for (int i = 0; i < totalStudents; i++)
        {
            printf("%d\t\t%s\t%s\t\t%d\t%.2f\t%s\t%c\t%s\n",
                   studentDatabase[i].rollNumber,
                   studentDatabase[i].name,
                   studentDatabase[i].fatherName,
                   studentDatabase[i].age,
                   studentDatabase[i].cgpa,
                   studentDatabase[i].intake,
                   studentDatabase[i].section,
                   studentDatabase[i].blood);
        }
    }
}

void editStudent()
{
    int rollNumber, found = 0;
    printf("Enter student roll number to edit: ");
    scanf("%d", &rollNumber);
    for (int i = 0; i < totalStudents; i++)
    {
        if (studentDatabase[i].rollNumber == rollNumber)
        {
            printf("Enter student name: ");
            scanf("%s", studentDatabase[i].name);
            printf("Enter father's name: ");
            scanf("%s", studentDatabase[i].fatherName);
            printf("Enter age: ");
            scanf("%d", &studentDatabase[i].age);
            printf("Enter CGPA: ");
            scanf("%f", &studentDatabase[i].cgpa);
            printf("Enter intake: ");
            scanf("%s", studentDatabase[i].intake);
            printf("Enter section: ");
            scanf(" %c", &studentDatabase[i].section);
            printf("Enter blood group: ");
            scanf("%s", studentDatabase[i].blood);
            printf("Student information edited successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Student not found.\n");
    }
}

// main function for info management
void studentDataManagement()
{
    int choice;
    do
    {
        printf("\nStudent Data Management\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Search Student\n");
        printf("4. Display All Students\n");
        printf("5. Edit Student\n");
        printf("0. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Add Student
            addStudent();
            break;
        case 2:
            // Remove Student
            removeStudent();
            break;
        case 3:
            // Search Student
            searchStudent();
            break;
        case 4:
            // Display All Students
            displayAllStudents();
            break;
        case 5:
            // Edit Student
            editStudent();
            break;
        case 0:
            // Go Back
            printf("Driven to the Main Menu");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

// Required option functions for Student fund account management

void openNewAccount()
{
    struct FundAccount newAccount;
    printf("Enter student roll number: ");
    scanf("%d", &newAccount.rollNumber);
    printf("Create a password: ");
    scanf("%s", newAccount.password);
    newAccount.balance = 0;
    fundDatabase[totalAccounts] = newAccount;
    totalAccounts++;
    printf("Account created successfully.\n");
}

void checkBalance(int rollNumber, char *password)
{
    for (int i = 0; i < totalAccounts; i++)
    {
        if (fundDatabase[i].rollNumber == rollNumber && strcmp(fundDatabase[i].password, password) == 0)
        {
            printf("Balance for roll number %d: %.2f\n", rollNumber, fundDatabase[i].balance);
            return;
        }
    }
    printf("Invalid Password or Account not found.\n");
}

void deposit(int rollNumber, char *password, float amount)
{
    for (int i = 0; i < totalAccounts; i++)
    {
        if (fundDatabase[i].rollNumber == rollNumber && strcmp(fundDatabase[i].password, password) == 0)
        {
            fundDatabase[i].balance += amount;
            printf("Amount %.2f deposited successfully. Current balance: %.2f\n", amount, fundDatabase[i].balance);
            return;
        }
    }
    printf("Invalid Password or account not found.\n");
}

void withdraw(int rollNumber, char *password, float amount)
{
    for (int i = 0; i < totalAccounts; i++)
    {
        if (fundDatabase[i].rollNumber == rollNumber && strcmp(fundDatabase[i].password, password) == 0)
        {
            if (fundDatabase[i].balance >= amount)
            {
                fundDatabase[i].balance -= amount;
                printf("Amount %.2f withdrawn successfully. Current balance: %.2f\n", amount, fundDatabase[i].balance);
            }
            else
            {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }
    printf("Invalid Password or Account not found.\n");
}

// Main function for Student Fund Account Management

void studentFundAccountManagement()
{
    int choice;
    do
    {
        printf("\nStudent Fund Account Management\n");
        printf("1. Open New Account\n");
        printf("2. Check Balance\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("0. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Open New Account
            openNewAccount();
            break;
        case 2:
            // Check Balance
            {
                int rollNumber;
                char password[20];
                printf("Enter your roll number: ");
                scanf("%d", &rollNumber);
                printf("Enter your password: ");
                scanf("%s", password);
                checkBalance(rollNumber, password);
                break;
            }
        case 3:
            // Deposit Money
            {
                int rollNumber;
                char password[20];
                float amount;
                printf("Enter your roll number: ");
                scanf("%d", &rollNumber);
                printf("Enter your password: ");
                scanf("%s", password);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(rollNumber, password, amount);
                break;
            }
        case 4:
            // Withdraw Money
            {
                int rollNumber;
                char password[20];
                float amount;
                printf("Enter your roll number: ");
                scanf("%d", &rollNumber);
                printf("Enter your password: ");
                scanf("%s", password);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(rollNumber, password, amount);
                break;
            }
        case 0:
            // Go Back
            printf("Driven to the Main Menu");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

int main()
{
    int option;
    do
    {
        printf("\nStudent Database and Fund Management\n");
        printf("1. Student Data Management\n");
        printf("2. Student Fund Management\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            studentDataManagement();
            break;
        case 2:
            studentFundAccountManagement();
            break;
        case 0:
            printf("Thank you for using our System.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (option != 0);

    return 0;
}
