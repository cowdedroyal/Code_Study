#include "CStudent.h"

int main()
{
	int StNum = 0;
	cout << "������ѧ����������";
	cin >> StNum;
	CStudent *css = new CStudent[StNum];
	CProcess cpr;
	cout << "��Ԫ���������ʽ��" << endl;
	cout << setw(8) << "����" << "\t" << "�ɼ�" << "\t" << "�ȼ�" << endl;
	for (int i = 0; i < StNum; i++)
	{
		Display(css[i]);
	}
	cout << endl;
	cout << "��Ԫ��������ʽ��" << endl;
	cout << setw(8) << "����" << "\t" << "�ɼ�" << "\t" << "�ȼ�" << endl;
	for (int i = 0; i < StNum; i++)
	{
		cpr.Transform(css[i]);
		cpr.Display(css[i]);
	}
	return 0;
}