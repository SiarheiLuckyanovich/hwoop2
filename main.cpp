#include <iostream>

using namespace std;
//============================================================================================================
/*1. ������� ����� Person (�������) � ������: ���, �������, ��� � ���.V
���������� ������ �������������� �����, ��������� �������� � ����.V
������� ����������� ����� Student (�������), ������� ���� ���� ��������.V
���������� ������ �������������� � ���������� ����� ��������.V
������� ������� ���������� ��������� ���������.V
� ������� main() ������� ��������� (�� ������ ���) ���������. ������� ���������� � ���.V*/

//============================================================================================================
class Person
{
public:
    string m_name;
    string m_gender;
    int m_age;
    int m_weight;


    Person (const string name = "", const int age = 0, const string gender = "", const int weight = 0)
    : m_name(name), m_age(age), m_gender(gender), m_weight(weight)
    {
    }
    string getName() const { return m_name; }
    int getAge() const { return m_age; }
    string getGender() const { return m_gender; }
    int getWeight() const { return m_weight; }
    ~Person()
    {

    }
};
//============================================================================================================
class Student : public Person
{
public:
    static int counter;
    int m_term;

    Student( const string name = "", const int age = 0, const string gender = "", const int weight = 0, const int term=0)
    :  Person (name, age, gender, weight), m_term( term)
    {
    }
    int setStudent(const string name, const int age, const string gender, const int weight, const int term)
    {
        m_name = name;
        m_gender = gender;
        m_age = age;
        m_weight = weight;
        m_term =term;
        counter++;
        return counter;
    }

    void printfile ()
    {
    cout << "Student#" << counter << " Name: " << m_name << ". Age: "
    << m_age << ". Gender:  " << m_gender << "." << endl << " Weight:  " << m_weight
    << ". Term of study (years):  "  << m_term << endl << endl;
    }
    int addTerm ()
    {
        m_term++;
        return m_term;
    }
    ~Student()
    {
        counter--;
    }

};
int Student :: counter=0;
//============================================================================================================

/* 2. ������� ������ Apple (������) � Banana (�����), ������� ��������� ����� Fruit (�����).V
� Fruit ���� ��� ����������-�����: name (���) � color (����).V
�������� ����� ����� GrannySmith, ������� ��������� ����� Apple. V*/

//============================================================================================================

class Fruit
{
protected:
    string f_name;
    string f_color;
public:
    Fruit (const string color)
    {
        f_color = color;
    }
    const string& getName() { return f_name; }
    const string& getColor() { return f_color; }
};

//============================================================================================================
class Apple : public Fruit
{
public:
    Apple (const string color = "")
    :  Fruit (color)
    {
        f_name = "apple";
    }
};

class Banana : public Fruit
{
public:
    Banana (const string color = "yelow")
    :  Fruit (color)
    {
        f_name = "banan";
    }
};

class GrannySmith : public Apple
{
public:
    string g_name;
    GrannySmith (const string color = "green")
    :  Apple (color)
    {
        f_color = color;
        f_name = "GrannySmith apple";
    }
};
//============================================================================================================


int main()
{
//============================================================================================================

    cout << "Task 1. Student. " << endl << endl;
    Student Ivanov;
    Ivanov.setStudent ("Ivan", 23, "male", 65, 2);
    Ivanov.printfile ();

    Student Smirnov;
    Smirnov.setStudent ("Jan", 22, "male", 85, 1);
    Smirnov.printfile ();

    Student Sidorov;
    Sidorov.setStudent ("Petr", 20, "male", 69, 3);
    Sidorov.printfile ();
    /*Sidorov.addTerm();
    Sidorov.printfile ();*/
    cout << endl;

//============================================================================================================
    cout << "Task 2. Fruit. " << endl << endl;

    Apple a("red");
    Banana b;
    GrannySmith c;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    /*���, ����������� ����, ������ ������ ��������� ���������:
    My apple is red.
    My banana is yellow.
    My Granny Smith apple is green. V */

//============================================================================================================

    return 0;
}
//============================================================================================================
/*3. ������� ������� ���� � Blackjack.V
��������, ��� �������� ������ ���� �� �++, ��������� ��������-��������������� ����������������.
������� ����� ������� � ���������? ����� ������ ����� ��������, � ����� ������������?
��������� ���������� ���� � ������� ������� � �������� ���������� � ���� ����������� � �������� ����� ��������� ������.V */

/*��� ��� ���� ���������, ������� ����� - �����. � ��� ��������� ���������� "�����", "��������" � "��������".
������ ����������� ���� "������" - ��� ���� ������� ����� ������ ����� � ������� �������� �� 1�� � ������, ������������ �������������
� �������� �� ����, ���� ������� ���� � ������� �� ��������� �������������� �������, ����� ������ ������������.
�� ������ ������ � ������, � ������� ���� "����" � ���� "������". ������ ������ ����� "�����" � ���� ��� ����������
"�������" � ��������� ������ �� ���������, "������" �� ����� ���� ������ ������� � ��������, "����������� ���� ��� ����� �� ������"
���������� ������������� ����� ������� ����, ������������ ������ � ��������� ������� "����" ���������� ������ �����.
������ ����������� �� ������ �����, ����������, ��������, ����������� �������� � ����������� ������� �� ������.
����� �� �������, ����� ���������� ������� ������/��������� - <=21/>21 ����, ����������� �������� �� ������
(���-�� ������� ��� � ��������), � ����� ���� ���� ������������� (21 � ������ �� �������, ��� �� ������ ������,
���� ���� ��� ������ ��������� �����, �� ��� ���� � 21� ����� ������� ������� ����� - ������� �����,
 ���� ����������� ��������� �������).
���� ����������: �� ������� ������ ������� ����� � ������ ���� ������� ������ �� �������,
��� ���� ����� ������ ������ ������� �����, ����� ������� ���� � ����������. ������ ���������, ������ �� ������.
�� ��������� ����� � ������ ���������� "��� �����?" � "������?" � ��� �� ������. �������� ������ �� ���?*/

//============================================================================================================
