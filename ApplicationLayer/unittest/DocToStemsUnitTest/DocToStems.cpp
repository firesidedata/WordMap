#include <string>
#include <iostream>
#include <fstream>
#include "WordListParserStub.h"
#include "StemMaker.h"
#include "StemmedList.h"

using namespace std;

//This is only a main 
int main(int argc, string argv[])
{
    //Takes command line input of input file name,
    //stop list file name, and stemmed list file name
	//Precondition: Read ascii input file
    string inputFileName = argv[0];
    string stemFileName = argv[1];
    string stopFileName = argv[2];

	//Takes input file and turns it into wordList object
	WordListParserStub wordLPS = WordListParserStub();
	string ofWords = wordLPS.Read(inputFileName);
	WordList *newWordList = wordLPS.wordListCreator(ofWords);

	//creates word list object for stem file
	WordListParserStub wordLPSS = WordListParserStub();
	string ofStems = wordLPSS.Read(stemFileName);
	WordList *newStemList = wordLPS.wordListCreator(ofStems);

	//Takes a word list item and turns it into a stem object
	StemMaker stemmer = StemMaker();
	stemmer.setStopList(stopFileName);
	StemmedList stemList = stemmer.getStems(newStemList);
	stemList.writeToFile(stemFileName);

}
