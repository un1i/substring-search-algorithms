#include "../include/rabin_karp.h"

size_t rabin_karp(const std::string& text, const std::string& sample, size_t alph_sz	) {
	int counter = 0;
	int highest_digit = modular_exp(alph_sz, sample.size() - 1);
	int sample_hash = 0;
	int substr_hash = 0;
	int limit = 0;

	for (int i = 0; i < sample.size(); i++) {
		sample_hash = (sample_hash * alph_sz + sample[i]) % MOD;
		substr_hash = (substr_hash * alph_sz + text[i]) % MOD;
	}

	limit = text.size() - sample.size() + 1;
	for (int i = 0; i < limit; i++) {
		if (sample_hash == substr_hash && char_verification(sample, text, i))
			counter++;
		if (i < limit - 1)
			substr_hash = ((substr_hash - text[i] * highest_digit) * alph_sz + text[i + sample.size()]) % MOD;
	}

	return counter;
}

int modular_exp(int number, int deg) {
	int ans = 1;
	while (deg > 0) {
		if (deg % 2)
			ans = (long long) ans * number % MOD;
		number = (long long) number * number % MOD;
		deg /= 2;

	}
	return ans % MOD;
}

bool char_verification(const std::string& sample, const std::string& text, int start) {
	for (int i = 0; i < sample.size(); i++)
		if (sample[i] != text[start + i])
			return false;
	return true;
}