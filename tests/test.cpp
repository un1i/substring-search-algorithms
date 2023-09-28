#include <iostream>
#include "test.h"
#include "../include/kmp.h"
#include "../include/rabin_karp.h"

void Test::run_tests() {
	test_repeat_input1();
	std::cout << "\n\n";
	test_random_input();
	std::cout << "\n\n";
	test_repeat_input2();
}

void Test::test_repeat_input1() {
	std::string text = "", sample = "ab";
	std::array<clock_t, 2> time;
	
	for (int i = 0; i < 1000; i++)
		text += "ab";
	std::cout << "1 тест:\nтекст - (ab)^1000*k, образец - (ab)^k, k = 1..1001, шаг - 10\n";
	std:: cout << "k\tКМП\tРабин Карп\n";

	for (int k = 0; k < 101; k++) {
		time = get_time(text, sample);

		std::cout << k * 10 + 1 << '\t' << time[0] << '\t' << time[1] << '\n';

		for (int i = 0; i < 10; i++)
			sample += "ab";
		for (int i = 0; i < 10000; i++)
			text += "ab";
	}
}

void Test::test_random_input() {
	std::string text = "", sample = "ab";
	std::string letters = "ab";
	std::array<clock_t, 2> time;

	std::cout << "2 тест:\nтекст - 1000001 случайных символы из алфавита {a, b}, образец - (a)^m, m = 1..1000001, шаг - 10000\n";
	std::cout << "m\tКМП\tРабин Карп\n";

	for (int m = 1; m <= 1000001; m += 10000) {
		std::string sample('a', m);
		text = "";

		for (int i = 0; i <= 1000001; i++)
			text += letters[rand() % letters.size()];

		time = get_time(text, sample);

		std::cout << m << '\t' << time[0] << '\t' << time[1] << '\n';

	}
}

void Test::test_repeat_input2() {
	std::string text = "aaaaab", sample = "aaaaa";
	std::array<clock_t, 2> time;

	std::cout << "3 тест:\nтекст - (aaaaab)^h, образец - aaaaa, h = 1..1000001, шаг - 10000\n";
	std::cout << "h\tКМП\tРабин Карп\n";

	for (int h = 0; h < 101; h++) {
		time = get_time(text, sample);
		std::cout << h * 10000 + 1 << '\t' << time[0] << '\t' << time[1] << '\n';
		for (int i = 0; i < 10000; i++)
			text += "aaaaab";
	}
}

std::array<clock_t, 2> Test::get_time(std::string& text, std::string& sample) {
	clock_t start, kmp_time, rk_time;
	std::vector <int> res;
	std::unordered_map<char, int> alphabet = { {'a', 0}, {'b', 1} };

	start = clock();
	kmp(text, sample, res);
	kmp_time = clock() - start;

	start = clock();
	rabin_karp(text, sample, alphabet);
	rk_time = clock() - start;

	return std::array<clock_t, 2> {kmp_time, rk_time};
}