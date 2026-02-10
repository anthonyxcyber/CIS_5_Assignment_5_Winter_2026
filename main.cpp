Code:
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_STUDENTS 5

struct Student {
	int studentId;
	string studentName;
	float studentGrades;
};

/*!
* Function Prototypes
*/
void printMenu();
void highestGrade(Student students[], int count);
void lowestGrade(Student students[], int count);
void averageGrade(Student students[], int count);
void printStudentId(Student students[], int count);
void printStudentName(Student students[], int count);

int main() {
	Student students[MAX_STUDENTS];
	int count = 0;
	int choice;

	/*!
	* Add the students here!
	*/
	//----------------------------------------------------------------------------------------
	students[0] = { 1001, "Tony", 92.5f };
	students[1] = { 1002, "Natalie", 85.0f };
	students[2] = { 1003, "Jake", 78.5f };
	students[3] = { 1004, "Thomas", 98.0f };
	students[4] = { 1005, "Leon", 88.0f };
	count = 5;
	//----------------------------------------------------------------------------------------

	// Complete the menu with the associated function
	do {
		printMenu();
		cout << "Enter your choice: ";
		cin >> choice;

		// handle non-number input so it doesn't loop forever
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input. Please enter a number.\n";
			continue;
		}
		cin.ignore(10000, '\n');

		switch (choice) {
		case 1:
			highestGrade(students, count);
			break;
		case 2:
			lowestGrade(students, count);
			break;
		case 3:
			averageGrade(students, count);
			break;
		case 4:
			printStudentId(students, count);
			break;
		case 5:
			printStudentName(students, count);
			break;
		case 6:
			cout << "Goodbye!\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 6);

	return 0;
}

void printMenu() {
	cout << "\n=== Student Record System ===\n";
	cout << "1. Find student with the highest grade\n";
	cout << "2. Find the student with the lowest grade\n";
	cout << "3. Find the average grade in the class\n";
	cout << "4. Print all the student's ID\n";
	cout << "5. Print all the student's names\n";
	cout << "6. Exit\n";
}

void highestGrade(Student students[], int count)
{
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

	float maxGrade = students[0].studentGrades;

	for (int i = 1; i < count; i++) {
		if (students[i].studentGrades > maxGrade) {
			maxGrade = students[i].studentGrades;
		}
	}

	cout << fixed << setprecision(2);
	cout << "Highest grade: " << maxGrade << endl;
}

void lowestGrade(Student students[], int count)
{
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

	float minGrade = students[0].studentGrades;

	for (int i = 1; i < count; i++) {
		if (students[i].studentGrades < minGrade) {
			minGrade = students[i].studentGrades;
		}
	}

	cout << fixed << setprecision(2);
	cout << "Lowest grade: " << minGrade << endl;
}

void averageGrade(Student students[], int count)
{
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

	float sum = 0.0f;

	for (int i = 0; i < count; i++) {
		sum += students[i].studentGrades;
	}

	float avg = sum / count;

	cout << fixed << setprecision(2);
	cout << "Average grade: " << avg << endl;
}

void printStudentId(Student students[], int count)
{
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

	cout << "Student IDs:\n";
	for (int i = 0; i < count; i++) {
		cout << students[i].studentId << endl;
	}
}

void printStudentName(Student students[], int count)
{
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

	cout << "Student Names:\n";
	for (int i = 0; i < count; i++) {
		cout << students[i].studentName << endl;
	}
}
