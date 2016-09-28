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


Phrase::Phrase(Grammar grammar) {
  this->grammar = grammar;
}

void Phrase::print() {
  this->phrase = grammar.getAxiome();
  Phrase::generate();
  cout << "debut :";
  for(auto item: phrase) {
    std::cout << item;
  }
  std::cout << ": fin" << endl;
}

bool Phrase::isWord(string item) {
  if(item.find("<") != string::npos) {
      return false;
  }
  return true;
}

void Phrase::generate() {
  bool go = true;
  while(go == true) {
    go = false;
    for(unsigned int i=0; i < phrase.size(); i++) {
      if(!isWord(phrase[i])) {
        go = true;
        unsigned int nonTerminalTaille = phrase[i].find(">") - phrase[i].find("<") +1;
        string nonTerminal = phrase[i].substr(phrase[i].find("<"), nonTerminalTaille);
        std::cout << "nonTerminal" << nonTerminal << std::endl;
        std::cout << "getProduction" << grammar.getProduction(nonTerminal) << std::endl;
        phrase[i].replace(phrase[i].find("<"), nonTerminalTaille, grammar.getProduction(nonTerminal));
      }
    }
  }
}

Phrase::~Phrase() {}
