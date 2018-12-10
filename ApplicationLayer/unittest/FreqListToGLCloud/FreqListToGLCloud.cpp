#include <iostream>
#include <string>
#include "DocList.h"
#include "FreqList.h"
#include "WordMapMaker.h"
#include "ICloudLayout.h"
#include "FishEyeLayout.h" 
#include "IRenderFactory.h"
#include "IRenderUtil.h"
#include "IRenderMaker.h"
#include "GLFactory.h" 
#include "GLUtil.h" 
#include "GLMaker.h" 

using namespace std;

// NOTE: FreqMaker is included in the diagram but only works with StemList? We're using DocList->WordMapMaker directly.
// NOTE: Add test data to "Input.txt" before running

int main(int argc, char *argv[]) { // takes two arguments: freqListFileName, GLCloudOutputFileName
	// read arguments
	cout << "Test" << endl;
	std::string freqListFileName = argv[1];
	cout << "FreqListFileName: " + freqListFileName << endl;
	std::string GLCloudOutputFileName = argv[2];
	cout << "GLCloudOutputFileName: " + GLCloudOutputFileName << endl;
	
	//doclist -> populate from file
	cout << "Populating DocList from FreqList (file)" << endl;
	FreqList newFreqList;
	DocList newDoc(freqListFileName, &newFreqList);
	newDoc.read(freqListFileName);
	cout << "See 'TestDocList.txt' to verify" << endl;
	newDoc.write("TestDocList.txt");

	//wordmapmaker -> populate wordmap from doclist
	cout << "Populating WordMap from DocList using WordMapMaker" << endl;
	WordMapMaker newWordMapMaker;
	WordMap *newWordMap;
	newWordMap = newWordMapMaker.convertFreqList(&newDoc);
	cout << "See 'TestWordMapMaper.txt' to verify" << endl;
	newWordMap->write("TestWordMapMaker.txt");

	//icloudlayout -> modify the wordmap
	cout << "Modifying the WordMap with a layout" << endl;
	ICloudLayout* layout = new FishEyeLayout();
	layout->updateWordMap(newWordMap);
	cout << "See 'TestCloudLayout.txt' to verify" << endl;
	newWordMap->write("TestCloudLayout.txt");

	//irenderfactory -> create glfactory
	cout << "Creating a GLFactory" << endl;
	IRenderFactory* newFactory = new GLFactory();
	//irendermaker -> create glmaker
	cout << "Creating GLMaker via GLFactory (stub)" << endl;
	IRenderMaker* newMaker = newFactory->NewRenderMaker();
	//glmaker -> output GLCloud to file
	newMaker->generateDoc(newWordMap, GLCloudOutputFileName);
	cin.get();
	return 0;
}