#include <string>
#include <vector>

const int MOD = 1000097;

size_t rabin_karp(const std::string& text, const std::string& sample, size_t alphabet_size);

int modular_exp(int number, int deg);

bool char_verification(const std::string& sample, const std::string& text, int start);