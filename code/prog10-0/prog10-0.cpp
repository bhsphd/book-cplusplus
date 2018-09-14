#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;
//ostream print(ostream) {}

int main() {
	{
		ifstream in1, in2; //���������ļ����������󣨼�10.3.1�ڣ���220ҳ��
		//in1 = in2; //���󣺲��ܶ�������ֵ
		//ostream print(ostream); //����ostream ����֧�ָ���
		//print(std::cout);
	}

	{
		//double x;
		//cin >> x;

		//while (cin >> x);

		//if (!cin)
		//	cin.clear();
	}

	{
		cout << "endl" << endl; //���endl��һ�����У�Ȼ��ˢ�»�����
		cout << "flush" << flush; //���flush���޶����ַ�����Ȼ��ˢ�»�����
		cout << "ends" << ends; //���ends��һ�����ַ�����\0������Ȼ��ˢ�»�����
	}

	{
		//for (char c; (c = cin.get()) != '\n'; )
		//	cout << c;
		//cout << endl;
	}

	{
		string s;
		//getline(cin, s);
	}

	{
		cout << showbase << uppercase; //��ʾ������Ϣ��ʮ���������Դ�д��ʽ���
		cout << "default:" << 26 << endl;
		cout << "octal:" << oct << 26 << endl;
		cout << "decimal:" << dec << 26 << endl;
		cout << "hex:" << hex << 26 << endl;
		cout << noshowbase << nouppercase << dec;
	}

	{
		int i, j;
		//cin >> oct >> i; //�˽�������
		//cin >> hex >> j; //ʮ����������
	}

	{
		double x = 1.2152;
		cout.precision(3);
		cout << "precision:" << cout.precision() << ", x=" << x << endl;
		cout << setprecision(4);
		cout << "precision:" << cout.precision() << ", x=" << x << endl;
	}

	{
		cout << "default format: " << 10 * exp(1.0) << endl;
		cout << "scientific: " << scientific << 10 * exp(1.0) << endl;
		cout << "fixed decimal: " << fixed << 10 * exp(1.0) << endl;
		cout << "default float: " << defaultfloat << 10 * exp(1.0) << endl;
	}

	{
		cout << 1.0 << endl; //��ӡ1
		cout << showpoint << 1.0 << noshowpoint << endl; //��ӡ1.00000
	}

	{
		int i = -10;
		double x = 1.2152;
		cout << "i:" << setw(10) << i << endl;
		cout << "x:" << setw(10) << x << endl;
		cout << setfill('*') << "x:" << setw(10) << x << endl;
	}

	{
		vector<string> wds; //�����ȡ�ĵ���
		string line, word;
		while (getline(cin, line)) {//����getline��ȡһ���ı�
			istringstream iss(line); //��������string�����󣬱���line��һ������
			while (iss >> word) //��ȡÿ������
				wds.push_back(word); //����ȡ�ĵ���β�嵽wds��

			ostringstream out; //�������string������
			for (auto &i : wds) //����ÿһ������
				out << i << ":" << i.length() << '\n'; //������д�������������
			cout << out.str(); //��ӡ���

			out.str(""); //���ԭ������
		}
	}
}