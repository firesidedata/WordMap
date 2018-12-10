#ifndef WORDLISTPARSERSTUB_H
#define WORDLISTPARSERSTUB_H
#include <string>
#include "WordList.h"
class WordListParserStub {
public:
	WordListParserStub();
	~WordListParserStub();
	virtual WordList* wordListCreator(std::string text);
	virtual std::string Read(std::string filename);

};
#endif
