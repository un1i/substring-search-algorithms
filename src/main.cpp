#include <iostream>
#include "../include/app.h"

using namespace std;

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	
	App app;
	app.run();
}