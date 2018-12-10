#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <string>

class WordCount
{
private:
	std::string word;
	int count;
public:
	WordCount();
	WordCount(std::string s);
	virtual std::string getWord();
	virtual void setWord(std::string w);
	virtual int getWordCount();
	virtual void setWordCount(int c);
	virtual std::string asString();
	virtual void fromString(std::string s);
	~WordCount();
};
#endif