#include "WordListParserStub.h"
#include <string>


WordListParserStub::WordListParserStub()
{

}
WordListParserStub::~WordListParserStub()
{

}
WordList * WordListParserStub::wordListCreator(std::string text)
{
	WordList *list = new WordList();
	std::string line = Read(text);
	line.erase(std::remove_if(line.begin(), line.end(), ispunct), line.end());
	std::istringstream stm(line);
	std::string token;
	while (stm >> token) list->addWord(token);
	cout << "Actual list: ";
	list->display();
	return list;
}

std::string WordListParserStub::Read(std::string filename)
{
	string output;
	string line;
	ifstream file(filename);
	if (file.is_open()) {
		while (getline(file, line))
		{
			output += line + " ";

		}
		file.close();
	}
	else {
		cout << endl << "file not found" << endl;
	}
	cout << "Reading string input from file " << filename << "\n";
	return output;
}
