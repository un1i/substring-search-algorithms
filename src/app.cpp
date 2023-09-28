#include <iostream>
#include "../include/app.h"
#include "../include/kmp.h"
#include "../include/rabin_karp.h"
#include "../tests/test.h"

using namespace std;

void App::run(){
	enter_alphabet();
	cout << "Введите текст:\n";
	enter_string(txt);
	cout << "Введите фрагмент, который нужно найти в тексте:\n";
	enter_string(smp);

	menu();
}

void App::menu() {
	size_t way;
	int ex = 1;
	bool leave = false;
	while (ex) {
		system("cls");
		cout << "1 - запустить алгоритмы поиска фрагмента в тексте\n2 - отобразить текст и фрагмент\n3 - изменить входные данные\n4 - запустить тесты\n0 - выход\n";
		cin >> way;
		switch (way)
		{
		case 1: {
			system("cls");
			run_algorithms();
			break;
		}
		case 2: {
			system("cls");
			print_input_data();
			break;
		}
		case 3: {
			system("cls");
			change_input_data();
			break;
		}
		case 4: {
			system("cls");
			Test::run_tests();
			break;
		}
		default: {
			leave = true;
			break;
		}
		}

		if (leave)
			break;
		cout << "1 - продолжить\n0 - выход\n";
		cin >> ex;
	}
}

void App::enter_string(str_types type) {
	size_t way;
	string tmp;
	cout << "1 - самостоятельный ввод\n2 - случайный ввод на основе выбранных букв\n3 - ввод на основе повторения некторого слова\n";
	cin >> way;
	switch (way)
	{
	case 1: {
		standard_enter(tmp);
		break;
	}
	case 2: {
		random_enter(tmp);
		break;
	}
	case 3: {
		repeat_enter(tmp);
		break;
	}
	default: {
		standard_enter(tmp);
		break;
	}
	}

	if (type == txt)
		text = tmp;
	else
		sample = tmp;
}

void App::standard_enter(string& str) {
	bool check;
	do {
		cout << "Введите строку:\n";
		cin >> str;
		check = check_str(str);
		if (!check)
			cout << "Некоторые символы строки не соответствуют алфавиту!\n";
	} while (!check);
}

void App::random_enter(string& str) {
	size_t len, quantity;
	string letters = "";
	char c;
	bool check;
	int way;

	cout << "Введите длину строки: ";
	cin >> len;
	cout << "1 - использовать все буквы для составления слова\n2 - выбрать определенные буквы\n";
	cin >> way;
	if (way == 2) {
		print_alphabet();
		cout << "Введите количество букв, которые нужно использовать для составления слова: ";
		cin >> quantity;
		do {
			cout << "Введите буквы через пробел:\n";
			for (int i = 0; i < quantity; i++) {
				cin >> c;
				letters += c;
			}
			check = check_str(letters);
			if (!check)
				cout << "Некоторые буквы не входят в алфавит!\n";
		} while (!check);
	}
	else
		for (auto element : alphabet)
			letters += element.first;

	str = "";
	for (int i = 0; i < len; i++)
		str += letters[rand() % letters.size()];
}

void App::repeat_enter(string& str) {
	size_t repetitions;
	string tmp;
	str = "";
	standard_enter(tmp);
	cout << "Введите количество повторений: ";
	cin >> repetitions;
	for (int i = 0; i < repetitions; i++)
		str += tmp;
}

void App::print_input_data() {
	print_alphabet();
	cout << "\nТекст:\n" << text << "\n\n";
	cout << "Фрагмент:\n" << sample << "\n\n";
}

void App::change_input_data() {
	size_t way;
	cout << "1 - изменить алфавит\n2 - изменить текст\n3 - изменить фрагмент\n";
	cin >> way;
	switch (way)
	{
	case 1: {
		enter_alphabet();
		cout << "После изменения алфавита необходимо сменить текст и фрагмент.\n";
		enter_string(txt);
		enter_string(smp);
		break;
	}
	case 2: {
		system("cls");
		enter_string(txt);
		break;
	}
	case 3: {
		system("cls");
		enter_string(smp);
		break;
	}
	default:
		break;
	}
}

void App::run_algorithms() {
	clock_t start_time, kmp_time, rk_time;
	size_t kmp_res, rk_res;
	vector<int> res;

	start_time = clock();
	kmp_res = kmp(text, sample, res);
	kmp_time = clock() - start_time;

	start_time = clock();
	rk_res = rabin_karp(text, sample, alphabet);
	rk_time = clock() - start_time;

	cout << "Алгоритм Кнута-Морриса-Пратта:\nКоличество фрагментов в тексте: " << kmp_res << "\nВремя работы: " << kmp_time << "ms.\n\n";
	cout << "Алгоритм Рабина-Карпа: \nКоличество фрагментов в тексте: " << rk_res << "\nВремя работы: " << rk_time << "ms.\n\n";
}

void App::enter_alphabet() {
	size_t alph_size;
	char c;
	int way;
	alphabet.clear();
	cout << "Введите количество букв в алфавите (от 1 до 93): ";
	cin >> alph_size;
	cout << "1 - ввести буквы алфавита самостоятельно\n2 - заполнить алфавит случайными символами\n";
	cin >> way;
	if (way == 1) {
		cout << "Введите бувы алфавита через пробел:\n";
		for (int i = 0; i < alph_size; i++) {
			cin >> c;
			alphabet[c] = i;
		}
	}
	else {
		while (alphabet.size() < alph_size) {
			c = 33 + rand() % 93;
			if (!alphabet.count(c))
				alphabet[c] = alphabet.size();
		}
	}
}

bool App::check_str(const string& str) {
	for (int i = 0; i < str.size(); i++)
		if (!alphabet.count(str[i]))
			return false;
	return true;
}

void App::print_alphabet() {
	cout << "Алфавит:\n";
	for (auto element : alphabet)
		cout << element.first << ' ';
	cout << '\n';
}



