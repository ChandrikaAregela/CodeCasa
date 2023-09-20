#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Student 
{
public:
    string name;
    string studentID;
    string course;
    Student(string n, string id, string c) : name(n), studentID(id), course(c) {}
};
class Assignment 
{
public:
    string title;
    string description;
    Assignment(string t, string desc) : title(t), description(desc) {}
};
class Exam 
{
public:
    string subject;
    int score;
    Exam(string sub, int sc) : subject(sub), score(sc) {}
};
class Teacher 
{
public:
    string name;
    string teacherID;
    Teacher(string n, string id) : name(n), teacherID(id) {}
    void assignAssignment(Student& student, Assignment& assignment) 
    {
        cout << "Assigned assignment '" << assignment.title << "' to student '" << student.name << "'" << endl;
    }

    void gradeStudent(Student& student, Assignment& assignment, int grade) 
    {
        cout << "Graded assignment '" << assignment.title << "' of student '" << student.name << "' with grade: " << grade << endl;
    }

    void addOrUpdateStudentInfo(Student& student, string newInfo)
    {
        cout << "Added/Updated information for student '" << student.name << "': " << newInfo << endl;
    }
};

int main()
{
    Student student1("sam", "501", "Java");
    Student student2("sree", "502", "Python");
    Assignment assignment1("Java Assignment", "Finish Assignment.");
    Assignment assignment2("Python Assignment", "Finish Assignment.");
    Teacher teacher("Mr.Ravi", "AD008");
    teacher.assignAssignment(student1, assignment1);
    teacher.gradeStudent(student1, assignment1, 95);
    teacher.addOrUpdateStudentInfo(student1, "Email: sam@example.com");
    teacher.assignAssignment(student2, assignment2);
    teacher.gradeStudent(student2, assignment2, 40);
    teacher.addOrUpdateStudentInfo(student2, "Email: sree@example.com");   
    return 0;
}
