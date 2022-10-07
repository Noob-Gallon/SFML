#include <iostream>
#include <string>

using namespace std;

class Person {

public:
	Person(string _name, string _sex, int _age) : name(_name), sex(_sex), age(_age) {
		cout << "Person " << name << " has born" << endl;
	}
	void status() {
		cout << "Person name : " << name << endl;
		cout << "sex : " << sex << endl;
		cout << "age : " << age << endl;
	}

protected:
	string name;
	string sex;
	int age;

};

class Student : public Person {

public:
	void print() {
		cout << this->name << endl;
		cout << this->sex << endl;
		cout << this->age << endl;
	}
	Student() : Person(string _name, string _sex, int age) {

	}

};

int main(void) {

	Person person("정동교", "남자", 23);
	person.status();

	Student student;
	student.print();

	return 0;
}