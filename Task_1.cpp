int main() 
{ 
	vector<float> v(5);
	vector<float> ::iterator p; // ������� �������� 
	int prev = 0; // ��� �������� ����������� �������� �������
	int i = 0; // �������

	// �������������� ������
	for (i = 0; i < v.size(); i++)
		v[i] = i;

	// ������� �� ����� ���������� �������
	cout << "Vector v:\n";
	for(i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n\n";

	// ������� ������� �������� ���������������
	for(p = v.begin(); p != v.end() - 1; p++)
	{
		prev = *p;
		p++;
		p = v.insert(p, ((*p) + (prev)) / 2);
	}


	// ������� �� ����� ���������� ������� ����� �������
	cout << "Vector v after insert:\n";
	for(i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n\n";

    return 0;
}
