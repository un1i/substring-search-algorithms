#include <vector>
#include "../include/kmp.h"

std::vector<int> get_prefix(const std::string& str);

size_t kmp(const std::string& text, const std::string& sample, std::vector<int>& res){
	int j = 0;
	size_t counter = 0;
	std::vector<int> prefix = get_prefix(sample);
	res.resize(text.size());

	for (int i = 0; i < text.size(); i++) {
		while (j > 0 && text[i] != sample[j])
			j = prefix[j - 1];
		if (text[i] == sample[j])
			j++;
		res[i] = j;
		if (j == sample.size()) {
			counter++;
			j = prefix[j - 1];
		}
	}
	return counter;
}

std::vector<int> get_prefix(const std::string& str){
	std::vector<int> res(str.size());
	int j = 0;
	res[0] = 0;

	for (int i = 1; i < str.size(); i++) {
		while (j > 0 && str[i] != str[j])
			j = res[j - 1];
		if (str[i] == str[j])
			j++;
		res[i] = j;
	}

	return res;
}
