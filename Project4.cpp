#include <iostream>
using namespace std;

// Function to calculate total marks
float calculateTotal(const float marks[], int size)
{
    float total = 0.0;

    for (int i = 0; i < size; ++i)
    {
        total += marks[i];
    }

    return total;
}

// Function to calculate average marks
float calculateAverage(const float marks[], int size)
{
    return calculateTotal(marks, size) / size;
}

// Function to determine grade
char calculateGrade(float marks)
{
    if (marks >= 90.0) return 'A';
    else if (marks >= 80.0) return 'B';
    else if (marks >= 70.0) return 'C';
    else if (marks >= 60.0) return 'D';
    else if (marks >= 50.0) return 'E';
    else return 'F';
}

int main()
{
    cout << "====================================\n";
    cout << "     Student Grade Calculator       \n";
    cout << "====================================\n";

    int subjectCount;
    string name;
    cout << "Enter Student Name: ";
    cin >> name;

    // Input validation for number of subjects
    do
    {
        cout << "\nEnter total number of subjects: ";
        cin >> subjectCount;

        if (subjectCount < 0)
        {
            cout << "Error: Number of subjects cannot be negative.\n";
        }

    } while (subjectCount < 0);

    if (subjectCount == 0)
    {
        cout << "No subjects entered. Exiting program.\n";
        return 0;
    }

    // Dynamic allocation of marks array
    float* marks = new float[subjectCount];

    // Input marks with validation
    for (int i = 0; i < subjectCount; ++i)
    {
        do
        {
            cout << "\nEnter marks for subject " << (i + 1) << ": ";
            cin >> marks[i];

            if (marks[i] < 0)
            {
                cout << "Error: Marks cannot be negative.\n";
            }

        } while (marks[i] < 0);
    }

    float total = calculateTotal(marks, subjectCount);
    float avg = calculateAverage(marks, subjectCount);

    cout << "\n========== Result ==========" << endl << endl;
    cout << "Name          : " << name << endl;
    cout << "Total Marks   : " << total << endl;
    cout << "Average Marks : " << avg << endl;
    cout << "Final Grade   : " << calculateGrade(avg) << endl;

    cout << "\nSubject Wise Grades:\n";
    for (int i = 0; i < subjectCount; ++i)
    {
        cout << "Subject " << (i + 1) << " : " << calculateGrade(marks[i]) << endl;
    }

    delete[] marks;
    system("pause");
    return 0;
}