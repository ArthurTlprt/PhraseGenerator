
#ifndef DEF_GRAMMAR
#define DEF_GRAMMAR

#include <string>
#include <vector>
#include <map>

using namespace std;


class Grammar {
	public:
		Grammar();
		Grammar(string fileName);
		map<string, vector<string> > getProductions();
		vector<string> getAxiome(){ return axiome; }
		string getProduction(string);
	private:
		string fileName;
		vector<string> axiome;
		map<string, vector<string> > productions;
		void readFile();
};

#endif
