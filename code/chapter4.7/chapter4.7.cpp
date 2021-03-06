#include <iostream>  
#include <string>  
using namespace std;

int main()
{	
	//4.7
	{
		{
			const int red = 0;
			const int green = 1;
			const int blue = 2;
		}
		{
			enum color { red, green, blue };
			//enum emotion { happy, calm, blue };	//错误：枚举成员blue已经定义过
			enum class stoplight { red, green, yellow };
			color c = red;			//正确，可以访问color类型的枚举成员
			//stoplight a = red;	//错误：stoplight类型的枚举成员red在此不可访问
									//或color类型的red与stoplight类型不匹配
			stoplight b = stoplight::red; //正确
			enum class week {
				Sunday = 7, Monday = 1, Tuesday, Wednesday,
				Thursday, Friday, Saturday
			};
			//color c1 = 1;			//错误：类型不匹配
			color c2 = static_cast<color>(1);
			stoplight l = stoplight::red;
			switch (l) {
			case stoplight::red:
				cout << "stop!" << endl;
				break;
			case stoplight::green:
				cout << "pass carefully" << endl;
				break;
			case stoplight::yellow:
				cout << "slow down" << endl;
				break;
			default:
				cout << "light broken, call 122" << endl;
				break;
			}
		}
	}
}

