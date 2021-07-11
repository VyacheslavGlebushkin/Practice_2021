#include <iostream>

using namespace std;
int const mas = 1000;
int source[mas];
int dest[mas];

int CompareMas(int* source, int* dest, int size) { //Функция сравнения массивов
	for (int i = 0; i < size; i++) { //Сравнивать члены массивов пока i < size
		if (source[i] != dest[i]) //Если члены не совпали по значению
			return -1;
	}
	return 0;
}

int testCompareMas() {
	int a[] = { 1,2,3,4,5,6 };
	int b[] = { 1,2,3,4,5,6 };
	if (CompareMas(a, b, 6) != 0) //Если то, что должно быть верным, неверно, сообщи об этом
		return -1;
	int an[7] = { 1,2,3,4,5,6,7 };
	int bn[6] = { 1,2,3,4,5,6 };
	int dn = 7;
	int cn = 6;
	if (dn == cn) {
		if (CompareMas(an, bn, cn) == 0) //Если то, что должно быть неверным, верно, сообщи об этом
			return -1;
	}
	int ak[] = { 1,2,3,4,5,6 };
	int bk[] = { 1,2,3,4,5,6,7,8,9 };
	if (CompareMas(ak, bk, 8) == 0) //Если то, что должно быть неверным, верно, сообщи об этом
		return -1;
	int aj[] = { 7,8,3,2,5,6 };
	int bj[] = { 1,2,3,4,5,6,5 };
	if (CompareMas(aj, bj, 3) == 0) //Если то, что должно быть неверным, верно, сообщи об этом
		return -1;
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n1, n2;
	cout << "Введите размер массива source: ";
	cin >> n1;
	cout << "Введите размер массива dest: ";
	cin >> n2;
	cout << endl << "P.S. При введении количества элементов массива большего, чем его заданный размер, лишние элементы отбрасываются" << endl;
	cout << endl << "Введите элементы массива source: " << endl;
	for (int i = 0; i < n1; i++) {
		cin >> source[i];
	}
	cout << "Введите элементы массива dest: " << endl;
	for (int i = 0; i < n2; i++) {
		cin >> dest[i];
	}
	if (testCompareMas() == 0)
		cout << "Тест пройден" << endl;
	else cout << "Тест не пройден" << endl;
	if (n1 == n2) {
		if (CompareMas(source, dest, n1) == 0) cout << "Равны";
		else cout << "Не равны";
	}
	else cout << "Не равны" << endl;
}