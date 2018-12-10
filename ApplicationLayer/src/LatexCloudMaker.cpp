#include "WordList.h"
#include "WordMap.h"
#include "StemMaker.h"
#include "StemmedList.h"
#include "FreqMaker.h"
#include "DocList.h"
#include "WordMapMaker.h"
#include "WordListParser.h"
#include "ICloudLayout.h"
#include "LatexMaker.h"
#include <iostream>
#include <fstream>

//LatexCloudMaker.cpp(command line params : inputFileName, stopFileName, tracing flag)

int main(int argc, char *argv[])
{
	std::string inputFileName, stopFileName;
	bool tracing = false;

	inputFileName = argv[1];
	stopFileName = argv[2];
	if (argv[3] == "t")
		tracing = true;

	WordListParser parser; // created wordlist parser
	std::string convert = parser.Read(inputFileName + ".txt");
	WordList* allWords = parser.wordListCreator(convert); // create wordlist using the parser

	StemMaker stemMaker; //create stemmaker
	stemMaker.setStopList(stopFileName); // write to the stop file name

	StemmedList* stems = stemMaker.getStems(allWords); //generate stemmed list with the word list we previously created

	if (tracing == true)
		stems->writeToFile(inputFileName + "_stems.txt"); // write to the file and change the name of the file to show its stems

	//-----------------------------------------------------------------------------------------------------------------------------------------------

	FreqMaker freqMaker; // create freqency maker

	DocList* docList = freqMaker.getDocList(stems); // create doclist with the stem list using freq maker, doclist is a
													 // freqlist with the associated filename that we created earlier
	if (tracing == true) // if we are tracing
		docList->write(inputFileName + "_freq.txt"); // write to a file that is a freqlist

	//-----------------------------------------------------------------------------------------------------------------------------------------------

	docList->sort(); // sort by frequency
	docList->removeFromList();

	WordMapMaker wordMapMaker; // create wordmap
	WordMap* wordMap = wordMapMaker.convertFreqList(docList);//make a wordmap with the sorted doclist of frequencies

	if (tracing == true) // if he have tracing
		wordMap->write(inputFileName + "_map.txt"); // write current junk to a map file

	//-----------------------------------------------------------------------------------------------------------------------------------------------
	
	ICloudLayout* cloud = NewLayout(); // replace with a call to the factory method
	cloud->updateWordMap(wordMap); // set the layout that we are going to use

	LatexMaker latex; // create the latexmaker so we can later pass it our current doc
	latex.generateDoc(wordMap, inputFileName + ".tex"); // create the final doc
}