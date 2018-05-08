#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
 
using namespace std;

template <int MaxVal>
int GenRnd()
{
	return rand() % MaxVal;
}
int main(void)
{
	vector<int> v(10); // ������������������ �����
	vector<int> v1, v2; // ������ � ������ ����������
	vector<int> ::iterator p; // ������� ��������
	int sumV1 = 0, sumV2 = 0; // ����� ������� � ������� ����������

	// ��������� ������ ���������� ���������� � ��������� 0 - 15
	generate(v.begin(), v.end(), GenRnd<15>);

	// ������� �� ����� ���������� �������
	cout << "Vector v:\n";
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n\n";

	while(!v.empty()) // ���� ������ �� ����
	{
		sumV1 = accumulate(v1.begin(), v1.end(), 0); // ����� ������� ����������
		sumV2 = accumulate(v2.begin(), v2.end(), 0); // ����� ������� ����������

		p = max_element(v.begin(), v.end()); // ���� ������������ ������� � ������������������

		if(sumV1 >= sumV2) // ���� ����� ������� ���������� ������, ���� ����� �������
			v2.push_back(*p); // �� ������� �������� �������� �� ������ ���������
		else 
			v1.push_back(*p); // ����� ������� � ������ ���������
		v.erase(p); // ������� ������� �� ������������������
	}

	sumV1 = accumulate(v1.begin(), v1.end(), 0); // ������� �����������
	sumV2 = accumulate(v2.begin(), v2.end(), 0);

	// ������� �� ����� ���������� ������� v1
	cout << "Vector v1:\n";
	for(int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << "\n";

	cout << "sumV1: " << sumV1 << "\n" << endl;

	// ������� �� ����� ���������� ������� v2
	cout << "Vector v2:\n";
	for(int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << "\n";

	cout << "sumV2: " << sumV2 << "\n" << endl;

    system("pause");
    return 0; 
}
