#include <iostream>
using namespace std;
int main() {
	constexpr int sz = 8;
	int que[sz] = { 0 };//ÿһ�лʺ󶼴ӵ�0�п�ʼ�ڷ�
	int i = 0;//�ӵ�0�п�ʼ�ڷ�
	while (i >= 0) {
		int k = 0;
		while (k<i) {//���ǰ�����лʺ��Ƿ�͵�i�лʺ��ͻ
			if (que[k] != que[i] && (abs(que[i] - que[k]) != abs(i - k)))
				++k;//��k�к͵�i�лʺ�û�г�ͻ
			else
				break;//��k�к͵�i�лʺ������ͻ���˳���ת����15��
		}
		if (k < i) {//��⵽��ͻ
			++que[i];//������ͻ���ƶ���i�лʺ󵽵�ǰλ�õ���һ��
			while (que[i] == sz) {//��ǰ�����г��Զ�ʧ�ܣ���Ҫ����
				que[i] = 0; //���õ�ǰ�лʺ�λ��
				--i;//���ݵ���һ��
				if (i < 0)
					break; //������ݵ���0��֮ǰ���������У�ת����24��
				++que[i];//ǰһ�лʺ����һ��
			}
			continue; //���¼���Ƿ���ǰ���Ѱ��Żʺ��ͻ��ת����7��
		}
		else { //û�м�⵽��ͻ��������һ�лʺ�
			++i;//�ƶ�����һ��
			if (i < sz)
				continue; //������һ�лʺ��Ѱ����ڵ�0�У�ת����7��
			cout << "�ҵ�һ��������";//�����ҵ�һ�����������
			for (k = 0; k<sz; ++k)
				cout << que[k];
			cout << endl;
			break; //�������У�ת����37��
		}
	}
	return 0;
}