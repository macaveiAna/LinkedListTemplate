#include "LL.h"
int main() {
    cout << "YOUR_NAME" << endl;

    // test template with ints --------------------------------
    UnOrderedList<int> intList;
    intList.prepend(10);
    intList.prepend(20);
    intList.prepend(5);
    intList.append(15);
    intList.append(25);
    intList.print();

    cout << "5 is in position " << intList.find(5) << endl;
    cout << "15 is in position " << intList.find(15) << endl;
    cout << "20 is in position " << intList.find(20) << endl;
    cout << "8 is in position " << intList.find(8) << endl;

    intList.remove(15);
    intList.remove(5);
    intList.remove(25);
    intList.print();

    intList.removeAll();
    intList.print();
    cout << endl << endl;

    // test on list of chars --------------------------------
    UnOrderedList<char>* charList = new UnOrderedList<char>;
    charList->append('k');
    charList->append('s');
    charList->prepend('r');
    charList->prepend('o');
    charList->prepend('w');
    charList->print();

    charList->remove('r');
    charList->remove('w');
    charList->remove('s');
    charList->print();

    charList->removeAll();
    charList->print();
    delete charList;

    // test it on Students ------------------------------------
    // Add code here that tests it on Student objects

    return 1;
}
