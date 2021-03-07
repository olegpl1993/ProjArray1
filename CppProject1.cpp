#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void makeNullArray(int* const arr, const int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
}

void makeArray(int* const arr, const int size) {
	for (int x = 0; x < size; x++)
	{
		arr[x] = rand() % 100;
	}
}

void writeArray(int* const arr, const int size) {
	for (int x = 0; x < size; x++)
	{
		cout <<*(arr + x) << " ";
	}
	cout << endl;
}

void push_back(int*& arr, int &size, int newValue) {
	int* newArr = new int[size+1];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[size] = newValue;
	size++;
	delete[] arr;
	arr = newArr;
}

void pop_back(int*& arr, int& size, int how = 1) {
	int* newArr = new int[size - how];
	for (int i = 0; i < size - how; i++)
	{
		newArr[i] = arr[i];
	}
	size = size - how;
	delete[] arr;
	arr = newArr;
}

void push_front(int*& arr, int& size, int newValue) {
	int* newArr = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		newArr[i+1] = arr[i];
	}
	newArr[0] = newValue;
	size++;
	delete[] arr;
	arr = newArr;
}

void pop_front(int*& arr, int& size, int how = 1) {
	int* newArr = new int[size - how];
	for (int i = 0; i < size - how; i++)
	{
		newArr[i] = arr[i + how];
	}
	size = size - how;
	delete[] arr;
	arr = newArr;
}


int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));


	int size;
	cout << "Укажите размер массива ";
	cin >> size;
	int* love = new int[size];
	int valueArray;

	for (;;){
		cout << "Введите для заполнения массива:\n 1 случайными числами\n 2 последовательность"<<endl;
		cin >> valueArray;

		if (valueArray == 1) {
			makeArray(love, size);
			break;
		}
		if (valueArray == 2) {
			makeNullArray(love, size);
			break;
		}
		cout << "Такого варианта нет" <<endl;
	}

	writeArray(love, size);
	
	int move;
	cout << "Выберите действие: \n 1 добавить число в конец массива \n 2 удалить число в конце массива \n 3 добавить число в начале массива \n 4 удалить число в начале массива \n 5 для завершения работы с массивом" << endl;
	for (;;) {
		cin >> move;

		if (move == 1) {
			cout << endl << "Введите число которое вы хотите добавить ";
			int x;
			cin >> x;
			push_back(love, size, x);
			writeArray(love, size);
			cout << "Выберите следующие действие ";
			continue;
		}
		if (move == 2) {
			cout << endl << "Введите количество чисел которые нужно убрать ";
			int x;
			cin >> x;
			pop_back(love, size, x);
			writeArray(love, size);
			cout << "Выберите следующие действие ";
			continue;
		}
		if (move == 3) {
			cout << endl << "Введите число которое вы хотите добавить ";
			int x;
			cin >> x;
			push_front(love, size, x);
			writeArray(love, size);
			cout << "Выберите следующие действие ";
			continue;
		}
		if (move == 4) {
			cout << endl << "Введите количество чисел которые нужно убрать ";
			int x;
			cin >> x;
			pop_front(love, size, x);
			writeArray(love, size);
			cout << "Выберите следующие действие ";
			continue;
		}
		if (move == 5) {
			cout << "\nИтоговый вариант массива\n"<<endl;
			writeArray(love, size);
			break;
		}

		cout << "Такого варианта нет" << endl;
	}

	delete[] love;

	system("pause");
	return 0;
}