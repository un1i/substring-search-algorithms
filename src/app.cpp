#include <iostream>
#include "../include/app.h"
#include "../include/kmp.h"
#include "../include/rabin_karp.h"

using namespace std;

void App::run(){
	cout << "������� ���������� ���� � ��������: ";
	cin >> alph_size;
	cout << "������� �����:\n";
	enter_string(txt);
	cout << "������� ��������, ������� ����� ����� � ������:\n";
	enter_string(smp);

	menu();
}

void App::menu() {
	size_t way;
	int ex = 1;
	bool leave = false;
	while (ex) {
		system("cls");
		cout << "1 - ��������� ��������� ������ ��������� � ������\n2 - ���������� ����� � ��������\n3 - �������� ������� ������\n0 - �����\n";
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
		cout << "1 - ����������\n0 - �����\n";
		cin >> ex;
	}
}

void App::enter_string(str_types type) {
	size_t way;
	string tmp;
	cout << "1 - ��������������� ����\n2 - ��������� ���� �� ������ ��������� ����\n3 - ���� �� ������ ���������� ��������� �����\n";
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
	cout << "������� ������:\n";
	cin >> str;
}

void App::random_enter(string& str) {
	size_t len;
	cout << "������� ����� ������: ";
	cin >> len;
	//������ ������ �����
	str = "";
	for (int i = 0; i < len; i++)
		str += 'a' + rand() % 26;
}

void App::repeat_enter(string& str) {
	size_t repetitions;
	string tmp;
	str = "";
	cout << "������� ������, ������� ����� ���������:\n";
	cin >> tmp;
	cout << "������� ���������� ����������: ";
	cin >> repetitions;
	for (int i = 0; i < repetitions; i++)
		str += tmp;
}

void App::print_input_data() {
	cout << "�����:\n" << text << "\n\n";
	cout << "��������:\n" << sample << "\n\n";
}

void App::change_input_data() {
	size_t way;
	cout << "1 - �������� �������\n2 - �������� �����\n3 - �������� ��������";
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

	cout << "�������� �����-�������-������:\n���������� ���������� � ������: " << kmp_res << "\n����� ������: " << kmp_time << "ms.\n\n";
	cout << "�������� ������-�����: \n���������� ���������� � ������: " << rk_res << "\n����� ������: " << rk_time << "ms.\n\n";
}



