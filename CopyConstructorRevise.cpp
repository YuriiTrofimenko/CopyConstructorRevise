// CopyConstructorRevise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Member {
    const char* firstName;
    const char* lastName;
    const char* middleName;
public:
    Member() {
        firstName = nullptr;
        lastName = nullptr;
        middleName = nullptr;
    }
    Member(const char* firstName, const char* lastName, const char* middleName) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->setMiddleName(middleName);

    }
    Member(Member &m) {
        this->firstName = m.firstName;
        this->lastName = m.lastName;
        this->setMiddleName(m.middleName);
    }
    void setMiddleName(const char* middleName) {
        if (middleName == nullptr)
        {
            throw exception("Null pointer exception: middleName equals nullptr.");
        }
        this->middleName = middleName;
    }
    void print() {
        cout << "Member { First Name: " << firstName << ", Last Name: " << lastName << ", Middle Name: " << middleName << " }" << endl;
    }
};

int main()
{
    Member m1;
    Member* m1Pointer = &m1;
    cout << m1Pointer << endl;

    Member m2("John", "Doe", "-");
    m2.print();

    // если нужно "изменить" ФИО человека, то можно создать новый объект,
    // хранящий данные о нём, скопировать в него оставшиеся неизменными составляющие ФИО,
    // добавить изменившиеся,
    // и начать пользоваться этим объектом вместо прежнего

    /* Member m2Modified(m2.firstName, m2.lastName, "2");
    m2Modified.print(); */

    try {
        Member m2Modified(m2);
        m2Modified.setMiddleName(nullptr);
        m2Modified.print();
    }
    catch (exception &ex) {
        cout << ex.what() << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
