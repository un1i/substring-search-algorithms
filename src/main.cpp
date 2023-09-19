#include <iostream>
#include "../include/kmp.h"

using namespace std;

int main() {
	vector<int> res;
	cout << kmp("bcddsjalfbcd", "abcd", res) << std::endl;
	for (int el : res)
		cout << el << ' ';
}