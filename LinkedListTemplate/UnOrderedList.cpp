//=================================================================
// @file:		UnOrderedList.cpp
// @author:     Ana Macavei
// @version:   1.2
//
// Demonstrates the class use of a function template.
//
//=================================================================================

#include <iostream>
#include "UnOrderedList.h"
#include "Student.h"

using namespace std;

int main() {
	cout << "Ana Macavei's Unordered Linked List" << std::endl;
	
	cout << '\n';
	////test code for part 1
	//UnOrderedList intList;
	//
	//intList.prepend(10); // List contains: 10
	//intList.prepend(20); // List contains: 20, 10
	//intList.prepend(5); // Beginning of list contains: 5, 20, 10
	//intList.append(15);
	//intList.append(25);
	//intList.print();

	//cout << "5 is in position " << intList.find(5) << endl;
	//cout << "15 is in position " << intList.find(15) << endl;
	//cout << "20 is in position " << intList.find(20) << endl;
	//cout << "8 is in position " << intList.find(8) << endl;

	//intList.remove(15);
	//intList.remove(5);
	//intList.remove(25);
	//intList.print();

	//cout << '\n';
	//intList.append(33);
	//intList.prepend(44);
	//intList.print();

	//intList.removeAll();
	//intList.print();

	//cout << endl << endl;

	//=================================================================

	//test template with ints --------------------------------
	UnOrderedList<int> intList;

	cout << "Original list of integers: " << endl;
	intList.prepend(10);
	intList.prepend(20);
	intList.prepend(5);
	intList.append(15);
	intList.append(25);
	intList.print();

	cout << '\n';
	cout << "The position of the numbers: " << endl;
	cout << "5 is in position " << intList.find(5) << endl;
	cout << "15 is in position " << intList.find(15) << endl;
	cout << "20 is in position " << intList.find(20) << endl;
	cout << "8 is in position " << intList.find(8) << endl;

	cout << '\n';
	cout << "List after integers were removed: " << endl;
	intList.remove(15);
	intList.remove(25);
	intList.remove(5);
	intList.print();

	intList.removeAll();
	intList.print();
	cout << endl << endl;

	// test on list of chars --------------------------------
	UnOrderedList<char>* charList = new UnOrderedList<char>;

	cout << "Original list of characters: " << endl;
	charList->append('k');
	charList->append('s');
	charList->prepend('r');
	charList->prepend('o');
	charList->prepend('w');
	charList->print();

	cout << '\n';
	cout << "List after characters were removed: " << endl;
	charList->remove('r');
	charList->remove('w');
	charList->remove('s');
	charList->print();

	charList->removeAll();
	charList->print();
	delete charList;

	// test it on Students ------------------------------------
	UnOrderedList<Student>* studentList = new UnOrderedList<Student>;

	cout << "\nOriginal list of students: " << endl;
	studentList->append(Student("Roman",'A'));
	studentList->append(Student("Ana", 'A'));
	studentList->append(Student("Christie", 'A'));
	studentList->prepend(Student("Emanuel", 'A'));
	studentList->print();

	cout << '\n';
	cout << "The position of the names: " << endl;
	cout << "Roman is in position " << studentList->find(Student("Roman", 'A')) << endl;
	cout << "Ana is in position " << studentList->find(Student("Ana", 'A')) << endl;
	cout << "Christie is in position " << studentList->find(Student("Christie", 'A'))<< endl;
	cout << "Emanuel is in position " << studentList->find(Student("Emanuel", 'A'))<< endl;

	cout << '\n';
	cout << "List after names were removed: " << endl;
	studentList->remove(Student("Ana", 'A'));
	studentList->remove(Student("Christie", 'A'));
	studentList->print();


	studentList->removeAll();
	studentList->print();
	delete studentList;

	return 1;
}
