#include<iostream>
#include <string>
using namespace std;

class Person {
protected:
	string m_name; //名字
	int m_age; //年龄
public:
	Person(const string &name = "", int age = 0) : m_name(name), m_age(age) {
		//cout << "Constr of Person" << endl;
	}
	virtual ~Person() = default; //default关键字见6.2.1节（第127页）
	//~Person() {
	//	cout << "Destr of Person" << endl;
	//}
	const string& name() const { return m_name; }
	int age() const { return m_age; }
	void plusOneYear() { ++m_age; } //年龄自增
};

class PartTimeWorker :public Person { //兼职人员类，公有继承Person
private:
	double m_hour; //工作小时数
	static double ms_payRate; //每小时工资
public:
	PartTimeWorker(const string &name, int age, double h = 0) :Person(
		name, age), m_hour(h) {}
	void setHours(double h) { m_hour = h; }
	double salary() { return m_hour*ms_payRate; }
};
//静态成员初始化（见6.4.2节，第140页）
double PartTimeWorker::ms_payRate = 7.53;

class Course { //课程类
	string m_name; //课程名
	int m_score; //成绩
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

class Student :public Person { //学生类，公有继承Person
private:
	Course m_course; //课程信息
public:
	Student(const string &name, int age, const Course &c) :
		Person(name, age),/*初始化基类成员*/
		m_course(c)/*初始化自有成员*/ {
		//cout << "Constr of Student" << endl;
	}
	//~Student() {
	//	cout << "Destr of Student" << endl;
	//}
	Course& course() { return m_course; }
};

class Base {
private:
	int m_pri; //private成员
protected:
	int m_pro; //protected成员
	int m_data;
public:
	int m_pub; //public成员
	void foo(int) { /*...*/ }
};

class PubDerv :public Base {
public:
	using Base::m_pro; //声明为公有的

	void foo() {
		//m_pri = 10;//错误：不能访问Base类私有成员
		m_pro = 1; //正确：可以访问Base类受保护成员
	}
};
void test() {
	Base b;
	//b.m_pro = 10;//错误：不能访问Base受保护成员
}

class PriDerv :private Base {//私有继承不影响派生类成员对基类的访问
	void foo() {
		m_pro = 1; //正确：可以访问Base类受保护成员
		m_pub = 1; //正确：可以访问Base类公有成员
	}
};

class Derived : public Base {
protected:
	int m_data;// 基类m_data被隐藏
public:
	//using Base::foo;
	int foo() {// 基类foo成员被隐藏
		//return m_data;// 返回Derived::m_data
		return Base::m_data;// 返回Base::m_data
	}
};

class A {/*...*/ };
class B : public A {
	string m_d;
public:
	B(const B &d) :A(d)/*复制A 的成员*/,
		m_d(d.m_d)/*复制B的成员*/ {
		/*...*/
	}
	B(B &&d) :A(std::move(d))/*移动A的成员*/,
		m_d(std::move(d.m_d))/*移动B的成员*/ {
		/*...*/
	}
	B& operator=(const B &d) {
		if (this == &d) return *this;
		A::operator=(d); //赋值A 的成员
		m_d = d.m_d; //赋值自身成员
		return *this;
	}
};

class Shape {
protected:
	string m_name;
public:
	Shape(const string &s = "") :m_name(s) { }
	virtual double area() const { return 0; } //此函数为虚函数
	//virtual double area() const = 0; //纯虚函数
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
	//void fun1() override {} //错误：基类没有不带参数的fun1函数
	void fun2() final {} //D1::fun2为最终版本
	//void fun3() override {} //错误：基类没有可覆盖的函数
};
struct D2 :public D1 {
	//void fun2() {} //错误：不允许覆盖基类D1 中的fun2函数
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
		d1.m_pub = 10; //正确：m_pub在PubDerv中是公有的
		//d2.m_pub = 1; //错误：m_pub 在PriDerv 中是私有的
	}

	{
		PubDerv d;
		d.m_pro; //正确
	}

	{
		Base b;
		Derived d;
		b.foo(10); //正确：调用Base::foo
		d.foo(); //正确：调用Derived::foo
		//d.foo(10); //错误：Base::foo被隐藏了
		d.Base::foo(10); //正确：调用Base::foo
		//d.foo(10); //正确：调用Base::foo
	}

	{
		PartTimeWorker w("Kevin", 21);
		Person p, *ptr;
		ptr = &w; //基类指针ptr指向派生类对象w
		Person &p2 = w; //基类引用绑定到派生类对象w
		p = w; //派生类对象赋值给基类对象
	}

	{
		//PartTimeWorker *w2 = &p; //错误：不能将基类转换为派生类
		//w = p; //错误：不能将基类转换为派生类
	}

	{
		PartTimeWorker w("Kevin", 21); //派生类对象
		Person p(w); //利用派生类对象构造基类对象
	}

	{
		PriDerv d; //PriDerv 私有继承Base
		//Base b(d); //错误：PriDerv 不能转换为Base
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
		Base *p; //指针p的静态类型为Base
	}
	
	{
		Derived d;
		Base *p = &d; //指针p的动态类型为Derived
	}

	{
		Shape sh, *p = &sh; //p指向Shape 类对象
		Square sq(1.0);
		cout << p->area() << endl; //打印输出0
		p = &sq; //将p绑定到sq
		cout << p->area() << endl; //打印输出1.0
	}

	{
		Shape *p = nullptr;
		Square sq(2.0);
		Circle ci(1.0);
		if (sq > ci) //调用重载的运算符>
			p = &sq;
	}

	{
		Shape *p = new Circle();
		delete p;
	}

	{
		//Shape sh; //错误：不能创建抽象类的实例
	}

	{
		Dog dog;
		Cat cat;
		dog.sounding(); //dog正常地汪汪叫了
		cat.sounding(); //cat正常地喵喵叫了
	}
}