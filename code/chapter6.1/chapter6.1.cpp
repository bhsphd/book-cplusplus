#include "Fraction.h"
//#include <complex>

//6.1.5 ��Ԫ��
class Circle;
class Point {
	friend class Circle;
private:
	double m_x = 0, m_y = 0;
};

class Circle {
	Point m_center;
	double m_radius = 1.0;
public:
	void moveXTo(double val) {
		m_center.m_x = val;
	}
};

int main(){
	//6.1.2
	{
		Fraction a;					//����һ������ a��a �����ݳ�Աʹ��Ĭ��ֵ
//		cout << a.value() << endl;	//ͨ������ a ���ó�Ա���� value
	}
	return 0;
}