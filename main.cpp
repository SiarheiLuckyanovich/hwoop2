#include <iostream>

using namespace std;
//============================================================================================================
/*1. Создать класс Person (человек) с полями: имя, возраст, пол и вес.V
Определить методы переназначения имени, изменения возраста и веса.V
Создать производный класс Student (студент), имеющий поле года обучения.V
Определить методы переназначения и увеличения этого значения.V
Создать счетчик количества созданных студентов.V
В функции main() создать несколько (не больше трёх) студентов. Вывести информацию о них.V*/

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

/* 2. Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).V
У Fruit есть две переменные-члена: name (имя) и color (цвет).V
Добавить новый класс GrannySmith, который наследует класс Apple. V*/

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
    /*Код, приведенный выше, должен давать следующий результат:
    My apple is red.
    My banana is yellow.
    My Granny Smith apple is green. V */

//============================================================================================================

    return 0;
}
//============================================================================================================
/*3. Изучить правила игры в Blackjack.V
Подумать, как написать данную игру на С++, используя объектно-ориентированное программирование.
Сколько будет классов в программе? Какие классы будут базовыми, а какие производными?
Продумать реализацию игры с помощью классов и записать результаты в виде комментария в основном файле сдаваемой работы.V */

/*Так как игра карточная, базовый класс - карты. В нем прописать переменные "масть", "значение" и "ценность".
Дальше производный клас "колода" - тут надо собрать карты каждой масти и каждого значения по 1шт в массив, перетусовать рандомайзером
и выдавать на стол, пока остаток карт в массиве не достигнет установленного предела, потом заново перетусовать.
За столом игроки и диллер, у каждого своя "рука" и своя "ставка". Значит вводим класс "игрок" и даем ему переменные
"кошелек" с начальной суммой по умолчанию, "ставка" не может быть больше остатка в кошельке, "очередность хода или номер за столом"
установить рандомайзером перед началом игры, динамический массив с набраными картами "рука" обнуляется каждый раунд.
Диллер производный от игрока класс, отличается, наверное, отсутствием кошелька и статическим номером за столом.
Когда всё собрано, нужно определить правила победы/поражения - <=21/>21 очко, коэфициента выигрыша от ставки
(что-то сложное там в правилах), и после чего игра заканчивается (21 у одного из игроков, еще не значит победа,
надо чтоб все игроки закончили набор, но при этом с 21м можно забрать выйгрыш сразу - сложная схема,
 надо внимательно прописать условия).
Игра начинается: из массива колода сдаются карты в массив рука каждому игроку по очереди,
при этом игрок делает ставку получая карты, потом переход хода к следующему. Диллер последний, ставок не делает.
На следующем круге у игрока спрашиваем "еще карту?" и "ставку?" И так до победы. Спросить играем ли еще?*/

//============================================================================================================
