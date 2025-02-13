#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Base class for all users (Encapsulation & Inheritance)
class User {
protected:
    string name;
    string regNo;

public:
    User(string name, string regNo) : name(name), regNo(regNo) {}

    virtual void displayMenu() = 0; // Pure virtual function for Polymorphism

    string getName() const { return name; }
    string getRegNo() const { return regNo; }
};

// Derived class for students (Encapsulation)
class Student : public User {
public:
    Student(string name, string regNo) : User(name, regNo) {}

    void displayMenu() override {
        cout << "\n--- Student Menu ---\n";
        cout << "1. View Courses\n";
        cout << "2. Enroll in a Course\n";
    }

    void enrollInCourse();
};

// Derived class for teachers (Encapsulation)
class Teacher : public User {
public:
    Teacher(string name, string regNo) : User(name, regNo) {}

    void displayMenu() override {
        cout << "\n--- Teacher Menu ---\n";
        cout << "1. Add Course\n";
        cout << "2. Delete Course\n";
    }

    void addCourse();
    void deleteCourse();
};

// Class for Course (Encapsulation & Abstraction)
class Course {
private:
    string language, topics, hours, tools, teacherName;

public:
    Course(string lang, string topics, string hrs, string tools, string teacher)
        : language(lang), topics(topics), hours(hrs), tools(tools), teacherName(teacher) {}

    void saveCourseData() {
        ofstream courseFile("courses.txt", ios::app);
        courseFile << "Language: " << language << ", Topics: " << topics 
                   << ", Hours: " << hours << ", Tools: " << tools 
                   << ", Teacher: " << teacherName << endl;
        courseFile.close();
        cout << "Course added successfully!\n";
    }

    static void viewCourses() {
        ifstream courseFile("courses.txt");
        string line;
        cout << "\n--- Available Courses ---\n";
        while (getline(courseFile, line)) {
            cout << line << endl;
        }
        courseFile.close();
    }
};

// Function implementations for Student class
void Student::enrollInCourse() {
    string courseName;
    cout << "Enter course name to enroll: ";
    cin.ignore();
    getline(cin, courseName);

    ofstream enrollmentFile("enrollments.txt", ios::app);
    enrollmentFile << "Student: " << name << ", Course: " << courseName << endl;
    enrollmentFile.close();
    cout << "Enrolled successfully!\n";
}

// Function implementations for Teacher class
void Teacher::addCourse() {
    string language, topics, hours, tools;
    cout << "Enter programming language: ";
    cin.ignore();
    getline(cin, language);
    cout << "Enter topics: ";
    getline(cin, topics);
    cout << "Enter learning hours: ";
    getline(cin, hours);
    cout << "Enter tools needed: ";
    getline(cin, tools);

    Course newCourse(language, topics, hours, tools, name);
    newCourse.saveCourseData();
}

void Teacher::deleteCourse() {
    string courseName;
    cout << "Enter course name to delete: ";
    cin.ignore();
    getline(cin, courseName);

    ifstream courseFile("courses.txt");
    ofstream tempFile("temp.txt");
    string line;
    bool deleted = false;

    while (getline(courseFile, line)) {
        if (line.find(courseName) == string::npos || line.find(name) == string::npos) {
            tempFile << line << endl;
        } else {
            deleted = true;
        }
    }
    courseFile.close();
    tempFile.close();

    remove("courses.txt");
    rename("temp.txt", "courses.txt");

    if (deleted)
        cout << "Course deleted successfully!\n";
    else
        cout << "Course not found.\n";
}

// Function to register a user
void registerUser(bool isStudent) {
    string name, regNo;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your 8-digit registration number: ";
    cin >> regNo;

    if (isStudent) {
        ofstream file("students.txt", ios::app);
        file << "Name: " << name << ", Reg No: " << regNo << endl;
        file.close();
        cout << "Student registered successfully!\n";
    } else {
        ofstream file("teachers.txt", ios::app);
        file << "Name: " << name << ", Reg No: " << regNo << endl;
        file.close();
        cout << "Teacher registered successfully!\n";
    }
}

// Function to login a user
User* loginUser(bool isStudent) {
    string name, regNo;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your 8-digit registration number: ";
    cin >> regNo;

    ifstream file(isStudent ? "students.txt" : "teachers.txt");
    string line;
    while (getline(file, line)) {
        if (line.find(name) != string::npos && line.find(regNo) != string::npos) {
            file.close();
            cout << "Login successful!\n";
            if (isStudent) {
                return new Student(name, regNo);
            } else {
                return new Teacher(name, regNo);
            }
            
        }
    }
    file.close();
    cout << "Login failed. Please register first.\n";
    return nullptr;
}

// Main function
int main() {
    int choice;
    cout << "Welcome to Learn and Teach Programming Languages!\n";
    cout << "1. Learn Programming\n";
    cout << "2. Teach Programming\n";
    cout << "3. View Courses\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        User* user = loginUser(true);
        if (user) {
            user->displayMenu();
            dynamic_cast<Student*>(user)->enrollInCourse();
            delete user;
        }
    } else if (choice == 2) {
        User* user = loginUser(false);
        if (user) {
            user->displayMenu();
            int action;
            cout << "Enter your choice: ";
            cin >> action;
            if (action == 1) {
                dynamic_cast<Teacher*>(user)->addCourse();
            } else if (action == 2) {
                dynamic_cast<Teacher*>(user)->deleteCourse();
            }
            delete user;
        }
    } else if (choice == 3) {
        Course::viewCourses();
    } else {
        cout << "Exiting program. Goodbye!\n";
        exit(0);
    }

    return 0;
}
