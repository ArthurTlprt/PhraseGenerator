#include <iostream>
#include <fstream>
#include <string>

#include "Grammar.h"
#include "Phrase.h"

using namespace std;

int main() {
	//TP1
	Grammar myprod("grammaires/expressions");
	Phrase maphrase(myprod);
	maphrase.print();

	//TP2

	//Exo1
	Grammar grammarTdExo2("grammaires/tdExo2");
	Phrase motTdExo2(grammarTdExo2);
	motTdExo2.print();

	Grammar grammarTdExo4("grammaires/tdExo4");
	Phrase motTdExo4(grammarTdExo4);
	motTdExo4.print();

	Grammar grammarPalyn("grammaires/palyn");
	Phrase motPalyn(grammarPalyn);
	motPalyn.print();

	//Exo2
	Grammar grammarId("grammaires/id");
	Phrase motId(grammarId);
	motId.print();

	//Exo3
	Grammar grammarMathexp("grammaires/mathexp");
	Phrase motMathexp(grammarMathexp);
	motMathexp.print();

	return 0;
}
