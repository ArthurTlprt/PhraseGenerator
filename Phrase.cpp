//
//  Phrase.cpp
//  TP1
//
//  Created by <author> on 24/09/2016.
//
//

#include "Phrase.h"
#include "Grammar.h"
#include <iostream>
#include <string>
#include <time.h>

Phrase::Phrase(Grammar grammar) {
  this->grammar = grammar;
}

void Phrase::print() {
  this->phrase = grammar.getAxiome();
  Phrase::generate();
  for(auto item: phrase) {
    std::cout << item;
  }
  std::cout << endl;
}

bool Phrase::isWord() {
  for(auto it: phrase) {
    std::cout << it << std::endl;
    if(it.find("<") != -1){
      return false;
    }
  }
  return true;
}
void Phrase::generate() {
  int rd;
  srand (time(NULL));
  for(unsigned int i=0; i < phrase.size(); i++) {
    rd = rand() %  grammar.getProductions()[phrase[i]].size();
    phrase[i] = grammar.getProductions()[phrase[i]][rd];
  }
}

Phrase::~Phrase() {}
