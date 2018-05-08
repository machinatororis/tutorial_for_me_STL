int main() 
{ 
	vector<float> v(5);
	vector<float> ::iterator p; // создаем итератор 
	int prev = 0; // для хранения предыдущего элемента вектора
	int i = 0; // счетчик

	// инициализируем вектор
	for (i = 0; i < v.size(); i++)
		v[i] = i;

	// выводим на экран содержимое вектора
	cout << "Vector v:\n";
	for(i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n\n";

	// процесс вставки среднего арифметического
	for(p = v.begin(); p != v.end() - 1; p++)
	{
		prev = *p;
		p++;
		p = v.insert(p, ((*p) + (prev)) / 2);
	}


	// выводим на экран содержимое вектора после вставки
	cout << "Vector v after insert:\n";
	for(i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n\n";

    return 0;
}
