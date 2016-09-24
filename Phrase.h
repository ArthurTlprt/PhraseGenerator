//
//  Phrase.h
//  TP1
//
//  Created by <author> on 24/09/2016.
//
//

#ifndef Phrase_h
#define Phrase_h

#include <stdio.h>
#include <string>
#include "Grammar.h"

class Phrase {
private:
  vector<string> phrase;
  void generate();
  bool isWord();
  Grammar grammar;
public:
  Phrase(Grammar grammar);
  ~Phrase();
  void print();
protected:

};


#endif /* Phrase_hpp */
