#include<iostream>
#include<string>
#include<iomanip>//ʹ��setw����
#include<fstream>//�ļ��������
using namespace std;

int main() {
	int max_rst = 100 / 5, max_hen = 100 / 3;
	ofstream out("result.txt");//�ڵ�ǰĿ¼�����ļ�
	if (out) { //�ж��ļ��Ƿ�ɹ���
		out << setw(10) << "����" << setw(10) << "ĸ��" << setw(10) << "С��";
		for (int i = 0; i < max_rst; ++i) {
			for (int j = 0; j < max_hen; ++j) {
				int k = 100 - i - j;
				if (k % 3) continue;
				if (5 * i + 3 * j + k / 3 == 100)//���ļ�д������
					out << '\n' << setw(10) << i << setw(10) << j << setw(10) << k;
			}
		}
		out.close();//�ر��ļ�
	}
	ifstream in("result.txt");//�򿪵�ǰĿ¼�µ��ļ�
	if (in) {//�ж��ļ��Ƿ�ɹ���
		string head;
		getline(in, head);
		cout << head << endl;
		int r[3];
		while (!in.eof()) {
			in >> r[0] >> r[1] >> r[2];//���ļ���ȡ����
			cout << setw(10) << r[0] << setw(10) << r[1] << setw(10) << r[2] << endl;
		}
		in.close();//�ر��ļ�
	}
	return 0;
}