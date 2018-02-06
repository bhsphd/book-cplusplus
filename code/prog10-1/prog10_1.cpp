#include<iostream>
#include<string>
#include<iomanip>//使用setw函数
#include<fstream>//文件输入输出
using namespace std;

int main() {
	int max_rst = 100 / 5, max_hen = 100 / 3;
	ofstream out("result.txt");//在当前目录创建文件
	if (out) { //判断文件是否成功打开
		out << setw(10) << "公鸡" << setw(10) << "母鸡" << setw(10) << "小鸡";
		for (int i = 0; i < max_rst; ++i) {
			for (int j = 0; j < max_hen; ++j) {
				int k = 100 - i - j;
				if (k % 3) continue;
				if (5 * i + 3 * j + k / 3 == 100)//向文件写入数据
					out << '\n' << setw(10) << i << setw(10) << j << setw(10) << k;
			}
		}
		out.close();//关闭文件
	}
	ifstream in("result.txt");//打开当前目录下的文件
	if (in) {//判断文件是否成功打开
		string head;
		getline(in, head);
		cout << head << endl;
		int r[3];
		while (!in.eof()) {
			in >> r[0] >> r[1] >> r[2];//从文件读取数据
			cout << setw(10) << r[0] << setw(10) << r[1] << setw(10) << r[2] << endl;
		}
		in.close();//关闭文件
	}
	return 0;
}