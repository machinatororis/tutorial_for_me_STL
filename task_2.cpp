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
	vector<int> v(10); // последовательность чисел
	vector<int> v1, v2; // первый и второй подмассивы
	vector<int> ::iterator p; // создаем итератор
	int sumV1 = 0, sumV2 = 0; // суммы первого и второго подмассива

	// заполняем вектор случайными значениями в интервале 0 - 15
	generate(v.begin(), v.end(), GenRnd<15>);

	// выводим на экран содержимое вектора
	cout << "Vector v:\n";
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n\n";

	while(!v.empty()) // пока вектор не пуст
	{
		sumV1 = accumulate(v1.begin(), v1.end(), 0); // сумма первого подмассива
		sumV2 = accumulate(v2.begin(), v2.end(), 0); // сумма второго подмассива

		p = max_element(v.begin(), v.end()); // ищем максимальный элемент в последовательности

		if(sumV1 >= sumV2) // если сумма первого подмассива больше, либо равна второму
			v2.push_back(*p); // то положим значение элемента во второй подмассив
		else 
			v1.push_back(*p); // иначе положим в первый подмассив
		v.erase(p); // удаляем элемент из последовательности
	}

	sumV1 = accumulate(v1.begin(), v1.end(), 0); // подсчет результатов
	sumV2 = accumulate(v2.begin(), v2.end(), 0);

	// выводим на экран содержимое вектора v1
	cout << "Vector v1:\n";
	for(int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << "\n";

	cout << "sumV1: " << sumV1 << "\n" << endl;

	// выводим на экран содержимое вектора v2
	cout << "Vector v2:\n";
	for(int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << "\n";

	cout << "sumV2: " << sumV2 << "\n" << endl;

    system("pause");
    return 0; 
}
