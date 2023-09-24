#include <iostream>
#include "../include/app.h"
#include "../include/kmp.h"
#include "../include/rabin_karp.h"

using namespace std;

void App::run(){
	cout << "Введите количество букв в алфавите: ";
	cin >> alph_size;
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
		cout << "1 - запустить алгоритмы поиска фрагмента в тексте\n2 - отобразить текст и фрагмент\n3 - изменить входные данные\n0 - выход\n";
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
	cout << "Введите строку:\n";
	cin >> str;
}

void App::random_enter(string& str) {
	size_t len;
	cout << "Введите длину строки: ";
	cin >> len;
	//Ввести нужные буквы
	str = "";
	for (int i = 0; i < len; i++)
		str += 'a' + rand() % 26;
}

void App::repeat_enter(string& str) {
	size_t repetitions;
	string tmp;
	str = "";
	cout << "Введите строку, которую нужно повторить:\n";
	cin >> tmp;
	cout << "Введите количество повторений: ";
	cin >> repetitions;
	for (int i = 0; i < repetitions; i++)
		str += tmp;
}

void App::print_input_data() {
	cout << "Текст:\n" << text << "\n\n";
	cout << "Фрагмент:\n" << sample << "\n\n";
}

void App::change_input_data() {
	size_t way;
	cout << "1 - изменить алфавит\n2 - изменить текст\n3 - изменить фрагмент";
	cin >> way;
	switch (way)
	{
	case 1: {
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
	rk_res = rabin_karp(text, sample, alph_size);
	rk_time = clock() - start_time;

	cout << "Алгоритм Кнута-Морриса-Пратта:\nКоличество фрагментов в тексте: " << kmp_res << "\nВремя работы: " << kmp_time << "ms.\n\n";
	cout << "Алгоритм Рабина-Карпа: \nКоличество фрагментов в тексте: " << rk_res << "\nВремя работы: " << rk_time << "ms.\n\n";
}



