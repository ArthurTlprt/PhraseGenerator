#include <iostream>
#include <fstream>
#include <string>

#include "Grammar.h"
#include "Phrase.h"

using namespace std;

int main() {
	Grammar myprod("myfile");

	Phrase maphrase(myprod);
	maphrase.print();
	return 0;
}
