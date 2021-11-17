//=================================================================
// @author:     Ana Macavei
// @version:   1.2
//
// Demonstrates the creation and use of a function template
// in C++ and how to implement it to an unordered linked list.
//
//=================================================================

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include<string>


class Student {
public:
    //constructor
    Student(const std::string name = "anonymous", char letterGrade = 'W');

    //operator overloads
    friend bool operator== (const Student& stu1, const Student& stu2);
    friend std::ostream& operator<< (std::ostream& stream, const Student& student);
private:
    std::string name;
    char letterGrade;
};

//-----------------
//constructor
Student::Student(const std::string name, char letterGrade)
{
    this->name = name;
    this->letterGrade = letterGrade;
}
//operator overloads (provided because they aren’t covered in detail until CS202)
bool operator== (const Student& stu1, const Student& stu2)
{
    if (stu1.name == stu2.name && stu1.letterGrade == stu2.letterGrade)
        return true;
    else
        return false;
}
std::ostream& operator<< (std::ostream& stream, const Student& student)
{
    stream << student.name;
    stream << " (" << student.letterGrade << ") ";
    return stream;
}

#endif