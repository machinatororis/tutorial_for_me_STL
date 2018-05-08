#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <numeric>
 
using namespace std;

template <int MaxVal>
int GenRnd()
{
	return rand() % MaxVal;
}

template<typename T> // ����� ����� ��������� ������ �� ��� ����������
void f(T &v, T &v1, T &v2, typename T::const_iterator &p)
{
	vector<int> ::iterator pBegin; // ������� ��������
	pBegin = v.begin(); // ������ �������� �� ������ �������

	while(pBegin != p) // ��������� ������ ���������
	{
		v1.push_back(*pBegin);
		pBegin = pBegin + 1; // ���������� �� ���� �������
	}
	// ������� �� ����� ���������� ������� v1
	cout << "Vector v1:\n";
	for(int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << "\n";
	while(p != v.end()) // ��������� ������ ���������
	{
		v2.push_back(*p);
		p = p + 1; // ���������� �� ���� �������
	}
	// ������� �� ����� ���������� ������� v2
	cout << "Vector v2:\n";
	for(int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << "\n";
}

int main(void)
{
    vector<int> v(5); // ������������������ �����
	vector<int> v1, v2, vDiff; // ������ � ������ ����������
	vector<int> ::iterator p; // ������� ��������
	int sumIdeal = 0, sumV1 = 0, sumV2 = 0; // ����� ������� � ������� ����������
	int i = 0, index = 0, difference = 0, differenceIdeal;  

	// ��������� ������ ���������� ���������� � ��������� 0 - 15
	generate(v.begin(), v.end(), GenRnd<15>);

	// ������� �� ����� ���������� �������
	cout << "Vector v:\n";
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n\n";

	sumIdeal = (accumulate(v.begin(), v.end(), 0)) / 2; // ��������� ��������� �������

	differenceIdeal = sumIdeal; // ���� ������������, ��� ��������� ������� ���� ����������� ����������� ��������

	sort(v.begin(), v.end()); // ��������� ������ �� ����������� ��� next_permutation
	
    while (next_permutation(v.begin(), v.end())) // ������������
    {
		p = v.begin(); // ������ �������� �� ������ �������
		sumV1 = 0, sumV2 = 0; // �������� ����� ����� ���������� ������������

		while (sumV1 < sumIdeal) // �������� �����, ��������� � ���������
		{
			sumV1 = sumV1 + *p; // ��������� �������� �������
			p = p + 1; // ���������� �� ���� �������
		}

		sumV2 = accumulate(p, v.end(), 0); // ������� ����� ������� ����������

		if (sumV1 != sumV2) // ���� ����� �������� �� �����
		{
			difference = abs(sumV1 - sumV2); // ���������� ������� ���� ��� ����� �����

			if (difference < differenceIdeal) // ���� ����������� ������� ����
			{
				differenceIdeal = difference;
				vDiff = v; // ���������� ������������������ � ����������� �������� ����
				index = distance(v.begin(), p); // ���������� ������� �������, �� ������� ������������
			}
		}

		if (sumV1 == sumV2)
		{
			f(v, v1, v2, p); // ����� ������ �� ��� ����������
			break; // ���������� ������������, �� ��� ����� ��������� ������
		}
    }

	if (sumV1 != sumV2) // ���� �� �� ����� �������� ������� ����������
	{
		p = vDiff.begin() + index; // ������������� �������� �� �� �����, ��� ����� ��������� ������
		f(vDiff, v1, v2, p); // ����� ������ �� ��� ����������
	}

    system("pause");
    return 0; 
}


