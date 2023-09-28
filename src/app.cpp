#include <iostream>
#include "../include/app.h"
#include "../include/kmp.h"
#include "../include/rabin_karp.h"
#include "../tests/test.h"

using namespace std;

void App::run(){
	enter_alphabet();
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
		cout << "1 - ��������� ��������� ������ ��������� � ������\n2 - ���������� ����� � ��������\n3 - �������� ������� ������\n4 - ��������� �����\n0 - �����\n";
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
	bool check;
	do {
		cout << "������� ������:\n";
		cin >> str;
		check = check_str(str);
		if (!check)
			cout << "��������� ������� ������ �� ������������� ��������!\n";
	} while (!check);
}

void App::random_enter(string& str) {
	size_t len, quantity;
	string letters = "";
	char c;
	bool check;
	int way;

	cout << "������� ����� ������: ";
	cin >> len;
	cout << "1 - ������������ ��� ����� ��� ����������� �����\n2 - ������� ������������ �����\n";
	cin >> way;
	if (way == 2) {
		print_alphabet();
		cout << "������� ���������� ����, ������� ����� ������������ ��� ����������� �����: ";
		cin >> quantity;
		do {
			cout << "������� ����� ����� ������:\n";
			for (int i = 0; i < quantity; i++) {
				cin >> c;
				letters += c;
			}
			check = check_str(letters);
			if (!check)
				cout << "��������� ����� �� ������ � �������!\n";
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
	cout << "������� ���������� ����������: ";
	cin >> repetitions;
	for (int i = 0; i < repetitions; i++)
		str += tmp;
}

void App::print_input_data() {
	print_alphabet();
	cout << "\n�����:\n" << text << "\n\n";
	cout << "��������:\n" << sample << "\n\n";
}

void App::change_input_data() {
	size_t way;
	cout << "1 - �������� �������\n2 - �������� �����\n3 - �������� ��������\n";
	cin >> way;
	switch (way)
	{
	case 1: {
		enter_alphabet();
		cout << "����� ��������� �������� ���������� ������� ����� � ��������.\n";
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

	cout << "�������� �����-�������-������:\n���������� ���������� � ������: " << kmp_res << "\n����� ������: " << kmp_time << "ms.\n\n";
	cout << "�������� ������-�����: \n���������� ���������� � ������: " << rk_res << "\n����� ������: " << rk_time << "ms.\n\n";
}

void App::enter_alphabet() {
	size_t alph_size;
	char c;
	int way;
	alphabet.clear();
	cout << "������� ���������� ���� � �������� (�� 1 �� 93): ";
	cin >> alph_size;
	cout << "1 - ������ ����� �������� ��������������\n2 - ��������� ������� ���������� ���������\n";
	cin >> way;
	if (way == 1) {
		cout << "������� ���� �������� ����� ������:\n";
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
	cout << "�������:\n";
	for (auto element : alphabet)
		cout << element.first << ' ';
	cout << '\n';
}



