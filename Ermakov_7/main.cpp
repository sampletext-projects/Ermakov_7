#include <iostream>

using namespace std;

void read_mas(int* mas, int size)
{
	cout << "mas: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i << "] = ";
		cin >> mas[i];
	}
}

void write_mas(int* mas, int size)
{
	cout << "mas: ";
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
}

bool is_sorted_ascending(int* mas, int size)
{
	bool result = true;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] < mas[i - 1])
		{
			result = false;
			break;
		}
	}
	return result;
}

bool is_sorted_descending(int* mas, int size)
{
	bool result = true;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] > mas[i - 1])
		{
			result = false;
			break;
		}
	}
	return result;
}

int determine_sort_dir(int* mas, int size)
{
	int result;
	if (is_sorted_ascending(mas, size))
	{
		result = 1;
	}
	else if (is_sorted_descending(mas, size))
	{
		result = -1;
	}
	else
	{
		result = 0;
	}
	return result;
}

void print_menu()
{
	cout << "1. Ввод массива" << endl;
	cout << "2. Вывод массива" << endl;
	cout << "3. Отсортирован ли массив по возрастанию" << endl;
	cout << "4. Отсортирован ли массив по убыванию" << endl;
	cout << "5. Определить упорядоченность" << endl;
	cout << "0. Выход" << endl;
}

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "Выполнил Ермаков И.Д. студент группы УТН-111" << endl;
	cout << "Программа по манипулированию массивом с помощью функций" << endl;
	int size = 4;
	int* mas = new int[size] {1, 3, 5, 7};


	int t;
	do
	{
		print_menu();
		cin >> t;
		switch (t)
		{
		case 1:
			{
				cout << "Введите размер массива: ";
				cin >> size;

				mas = new int[size];
				read_mas(mas, size);
				break;
			}
		case 2:
			{
				if (size == -1)
				{
					cout << "Перед выводом необходимо ввести массив!" << endl;
					break;
				}
				write_mas(mas, size);
				break;
			}
		case 3:
			{
				if (size == -1)
				{
					cout << "Перед определением упорядочености необходимо ввести массив!" << endl;
					break;
				}
				bool is_sorted = is_sorted_ascending(mas, size);
				cout << "Результат проверки: " << is_sorted << endl;
				break;
			}
		case 4:
			{
				if (size == -1)
				{
					cout << "Перед определением упорядочености необходимо ввести массив!" << endl;
					break;
				}
				bool is_sorted = is_sorted_descending(mas, size);
				cout << "Результат проверки: " << is_sorted << endl;
				break;
			}
		case 5:
			{
				if (size == -1)
				{
					cout << "Перед определением упорядочености необходимо ввести массив!" << endl;
					break;
				}
				int result = determine_sort_dir(mas, size);
				cout << "Результат проверки: " << result << endl;
				break;
			}
		}
	}
	while (t != 0);


	system("pause");

	return 0;
}
