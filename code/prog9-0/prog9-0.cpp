#include<iostream>
#include <string>
using namespace std;

class Person {
protected:
	string m_name; //����
	int m_age; //����
public:
	Person(const string &name = "", int age = 0) : m_name(name), m_age(age) {
		//cout << "Constr of Person" << endl;
	}
	virtual ~Person() = default; //default�ؼ��ּ�6.2.1�ڣ���127ҳ��
	//~Person() {
	//	cout << "Destr of Person" << endl;
	//}
	const string& name() const { return m_name; }
	int age() const { return m_age; }
	void plusOneYear() { ++m_age; } //��������
};

class PartTimeWorker :public Person { //��ְ��Ա�࣬���м̳�Person
private:
	double m_hour; //����Сʱ��
	static double ms_payRate; //ÿСʱ����
public:
	PartTimeWorker(const string &name, int age, double h = 0) :Person(
		name, age), m_hour(h) {}
	void setHours(double h) { m_hour = h; }
	double salary() { return m_hour*ms_payRate; }
};
//��̬��Ա��ʼ������6.4.2�ڣ���140ҳ��
double PartTimeWorker::ms_payRate = 7.53;

class Course { //�γ���
	string m_name; //�γ���
	int m_score; //�ɼ�
public:
	Course(const string &name = "", int score = 0) : m_name(name), m_score(score) { }
	//Course(const Course &rhs) :m_name(rhs.m_name),
	//	m_score(rhs.m_score) {
	//	cout << "Copy constr of Course" << endl;
	//}
	//~Course() {
	//	cout << "Destr of Course" << endl;
	//}
	void setScore(int score) { m_score = score; }
	int score() const { return m_score; }
	const string& name()const { return m_name; }
};

class Student :public Person { //ѧ���࣬���м̳�Person
private:
	Course m_course; //�γ���Ϣ
public:
	Student(const string &name, int age, const Course &c) :
		Person(name, age),/*��ʼ�������Ա*/
		m_course(c)/*��ʼ�����г�Ա*/ {
		//cout << "Constr of Student" << endl;
	}
	//~Student() {
	//	cout << "Destr of Student" << endl;
	//}
	Course& course() { return m_course; }
};

class Base {
private:
	int m_pri; //private��Ա
protected:
	int m_pro; //protected��Ա
	int m_data;
public:
	int m_pub; //public��Ա
	void foo(int) { /*...*/ }
};

class PubDerv :public Base {
public:
	using Base::m_pro; //����Ϊ���е�

	void foo() {
		//m_pri = 10;//���󣺲��ܷ���Base��˽�г�Ա
		m_pro = 1; //��ȷ�����Է���Base���ܱ�����Ա
	}
};
void test() {
	Base b;
	//b.m_pro = 10;//���󣺲��ܷ���Base�ܱ�����Ա
}

class PriDerv :private Base {//˽�м̳в�Ӱ���������Ա�Ի���ķ���
	void foo() {
		m_pro = 1; //��ȷ�����Է���Base���ܱ�����Ա
		m_pub = 1; //��ȷ�����Է���Base�๫�г�Ա
	}
};

class Derived : public Base {
protected:
	int m_data;// ����m_data������
public:
	//using Base::foo;
	int foo() {// ����foo��Ա������
		//return m_data;// ����Derived::m_data
		return Base::m_data;// ����Base::m_data
	}
};

class A {/*...*/ };
class B : public A {
	string m_d;
public:
	B(const B &d) :A(d)/*����A �ĳ�Ա*/,
		m_d(d.m_d)/*����B�ĳ�Ա*/ {
		/*...*/
	}
	B(B &&d) :A(std::move(d))/*�ƶ�A�ĳ�Ա*/,
		m_d(std::move(d.m_d))/*�ƶ�B�ĳ�Ա*/ {
		/*...*/
	}
	B& operator=(const B &d) {
		if (this == &d) return *this;
		A::operator=(d); //��ֵA �ĳ�Ա
		m_d = d.m_d; //��ֵ�����Ա
		return *this;
	}
};

class Shape {
protected:
	string m_name;
public:
	Shape(const string &s = "") :m_name(s) { }
	virtual double area() const { return 0; } //�˺���Ϊ�麯��
	//virtual double area() const = 0; //���麯��
	const string& name() { return m_name; }
	//virtual ~Shape() { cout << "Destr of Shape" << endl; }
};
class Circle :public Shape {
private:
	double m_rad;
public:
	Circle(double r = 0, const string &s = "") :Shape(s), m_rad(r) { }
	double area() const { return 3.1415926*m_rad*m_rad; }
	//~Circle() { cout << "Destr of Circle" << endl; }
};
class Square :public Shape {
private:
	double m_len;
public:
	Square(double l = 0, const string &s = "") :Shape(s), m_len(l) { }
	double area()const { return m_len*m_len; }
};

bool operator>(const Shape &s1, const Shape &s2) {
	return s1.area() > s2.area();
}

struct B1 {
	virtual void fun1(int) {}
	virtual void fun2() {}
	void fun3() {}
};
struct D1 :public B1 {
	//void fun1() override {} //���󣺻���û�в���������fun1����
	void fun2() final {} //D1::fun2Ϊ���հ汾
	//void fun3() override {} //���󣺻���û�пɸ��ǵĺ���
};
struct D2 :public D1 {
	//void fun2() {} //���󣺲������ǻ���D1 �е�fun2����
};

class Mamal {
protected:
	string m_name;
public:
	virtual void sounding() = 0;
};

class Dog :public Mamal {
protected:
	void bark() {
		cout << "barking" << endl;
	}
public:
	void sounding() override {
		bark();
	}
};

class Cat :public Mamal {
protected:
	void meow() {
		cout << "meowing" << endl;
	}
public:
	void sounding() override {
		meow();
	}
};

int main() {

	{
		PubDerv d1;
		PriDerv d2;
		d1.m_pub = 10; //��ȷ��m_pub��PubDerv���ǹ��е�
		//d2.m_pub = 1; //����m_pub ��PriDerv ����˽�е�
	}

	{
		PubDerv d;
		d.m_pro; //��ȷ
	}

	{
		Base b;
		Derived d;
		b.foo(10); //��ȷ������Base::foo
		d.foo(); //��ȷ������Derived::foo
		//d.foo(10); //����Base::foo��������
		d.Base::foo(10); //��ȷ������Base::foo
		//d.foo(10); //��ȷ������Base::foo
	}

	{
		PartTimeWorker w("Kevin", 21);
		Person p, *ptr;
		ptr = &w; //����ָ��ptrָ�����������w
		Person &p2 = w; //�������ð󶨵����������w
		p = w; //���������ֵ���������
	}

	{
		//PartTimeWorker *w2 = &p; //���󣺲��ܽ�����ת��Ϊ������
		//w = p; //���󣺲��ܽ�����ת��Ϊ������
	}

	{
		PartTimeWorker w("Kevin", 21); //���������
		Person p(w); //���������������������
	}

	{
		PriDerv d; //PriDerv ˽�м̳�Base
		//Base b(d); //����PriDerv ����ת��ΪBase
	}

	{
		Student s("Kevin", 19, Course("Math"));
	}

	{
		Course c("Math");
		{
			Student s("Kevin", 19, c);
		}
	}

	{
		Base *p; //ָ��p�ľ�̬����ΪBase
	}
	
	{
		Derived d;
		Base *p = &d; //ָ��p�Ķ�̬����ΪDerived
	}

	{
		Shape sh, *p = &sh; //pָ��Shape �����
		Square sq(1.0);
		cout << p->area() << endl; //��ӡ���0
		p = &sq; //��p�󶨵�sq
		cout << p->area() << endl; //��ӡ���1.0
	}

	{
		Shape *p = nullptr;
		Square sq(2.0);
		Circle ci(1.0);
		if (sq > ci) //�������ص������>
			p = &sq;
	}

	{
		Shape *p = new Circle();
		delete p;
	}

	{
		//Shape sh; //���󣺲��ܴ����������ʵ��
	}

	{
		Dog dog;
		Cat cat;
		dog.sounding(); //dog��������������
		cat.sounding(); //cat��������������
	}
}