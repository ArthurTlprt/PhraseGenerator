#include <iostream>
#include <fstream>
#include <string>

#include "Grammar.h"
#include "Phrase.h"

using namespace std;

int main() {
	Grammar myprod("expressions");
	Phrase maphrase(myprod);
	maphrase.print();

	Grammar grammarTdExo2("tdExo2");
	Phrase motTdExo2(grammarTdExo2);
	motTdExo2.print();

	Grammar grammarTdExo4("tdExo4");
	Phrase motTdExo4(grammarTdExo4);
	motTdExo4.print();

	return 0;
}
