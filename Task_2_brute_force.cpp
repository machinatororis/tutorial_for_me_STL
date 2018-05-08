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

template<typename T> // здесь будем разбивать массив на два подмассива
void f(T &v, T &v1, T &v2, typename T::const_iterator &p)
{
	vector<int> ::iterator pBegin; // создаем итератор
	pBegin = v.begin(); // ставим итератор на начало массива

	while(pBegin != p) // заполняем первый подмассив
	{
		v1.push_back(*pBegin);
		pBegin = pBegin + 1; // сдвигаемся на один элемент
	}
	// выводим на экран содержимое вектора v1
	cout << "Vector v1:\n";
	for(int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << "\n";
	while(p != v.end()) // заполняем второй подмассив
	{
		v2.push_back(*p);
		p = p + 1; // сдвигаемся на один элемент
	}
	// выводим на экран содержимое вектора v2
	cout << "Vector v2:\n";
	for(int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << "\n";
}

int main(void)
{
    vector<int> v(5); // последовательность чисел
	vector<int> v1, v2, vDiff; // первый и второй подмассивы
	vector<int> ::iterator p; // создаем итератор
	int sumIdeal = 0, sumV1 = 0, sumV2 = 0; // суммы первого и второго подмассива
	int i = 0, index = 0, difference = 0, differenceIdeal;  

	// заполняем вектор случайными значениями в интервале 0 - 15
	generate(v.begin(), v.end(), GenRnd<15>);

	// выводим на экран содержимое вектора
	cout << "Vector v:\n";
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n\n";

	sumIdeal = (accumulate(v.begin(), v.end(), 0)) / 2; // идеальная полусумма массива

	differenceIdeal = sumIdeal; // пока предполагаем, что идеальная разница сумм подмассивов максимально огромная

	sort(v.begin(), v.end()); // сортируем массив по возрастанию для next_permutation
	
    while (next_permutation(v.begin(), v.end())) // перестановки
    {
		p = v.begin(); // ставим итератор на начало массива
		sumV1 = 0, sumV2 = 0; // обнуляем суммы после предыдущей перестановки

		while (sumV1 < sumIdeal) // набираем сумму, стремимся к идеальной
		{
			sumV1 = sumV1 + *p; // суммируем элементы массива
			p = p + 1; // сдвигаемся на один элемент
		}

		sumV2 = accumulate(p, v.end(), 0); // считаем сумму второго подмассива

		if (sumV1 != sumV2) // если суммы массивов не равны
		{
			difference = abs(sumV1 - sumV2); // запоминаем разницу сумм без учета знака

			if (difference < differenceIdeal) // ищем минимальную разницу сумм
			{
				differenceIdeal = difference;
				vDiff = v; // запоминаем последовательность с минимальной разницей сумм
				index = distance(v.begin(), p); // запоминаем элемент вектора, на котором остановились
			}
		}

		if (sumV1 == sumV2)
		{
			f(v, v1, v2, p); // делим массив на два подмассива
			break; // прекращаем перестановки, мы уже нашли идеальный случай
		}
    }

	if (sumV1 != sumV2) // если мы не нашли идеально ровного разделения
	{
		p = vDiff.begin() + index; // устанавливаем итератор на то место, где нужно разделить массив
		f(vDiff, v1, v2, p); // делим массив на два подмассива
	}

    system("pause");
    return 0; 
}


