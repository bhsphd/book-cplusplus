#include "Array.h"
#include <iostream>
using namespace std;


int main()
{
	// 7.2.2 节
	{
		cout << "7.2.2 节：" << endl;
		Array<char, 5> a;				//创建一个Array<char, 5>类型对象a
		Array<int, 5> b = { 1,2,3 };	//创建一个Array<int, 5>类型对象b
		for (size_t i = 0; i < b.size(); ++i)
			cout << b[i] << " ";
		cout << endl;
	}

	// 7.2.3 节
	{
		cout << "7.2.3 节：" << endl;
		Array<int> a = { 2,1,3 }; //a的默认元素个数为10
		Array<int, 5> b;			//指定b的元素数目为5
		for (int i = 0; i < a.size(); ++i)
			cout << a[i] << " ";
	}

    return 0;
}

