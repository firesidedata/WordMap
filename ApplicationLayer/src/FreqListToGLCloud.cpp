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

int main(int argc, char *argv[]) { // takes one argument: freqListFileName
	// read argument
	if (argv[1] == 0) {
		cout << "Input file name is not set." << endl;
		cin.get();
		return 0;
	}
	string GLCloudOutputFileName = "Output.txt";
	string freqListFileName = argv[1];
	cout << "FreqListFileName: " + freqListFileName << endl;
	
	//doclist -> populate from file
	cout << "Populating DocList from FreqList (file)" << endl;
	FreqList newFreqList;
	DocList newDoc(freqListFileName, &newFreqList);
	newDoc.read(freqListFileName);

	//wordmapmaker -> populate wordmap from doclist
	cout << "Populating WordMap from DocList using WordMapMaker" << endl;
	WordMapMaker newWordMapMaker;
	WordMap *newWordMap;
	newWordMap = newWordMapMaker.convertFreqList(&newDoc);

	//icloudlayout -> modify the wordmap
	cout << "Modifying the WordMap with a layout" << endl;
	ICloudLayout* layout = new FishEyeLayout();
	layout->updateWordMap(newWordMap);

	//irenderfactory -> create glfactory
	cout << "Creating a GLFactory" << endl;
	IRenderFactory* newFactory = new GLFactory();
	//irendermaker -> create glmaker
	cout << "Creating GLMaker via GLFactory" << endl;
	IRenderMaker* newMaker = newFactory->NewRenderMaker();
	//glmaker -> output GLCloud to file
	cout << "Generating GLCloud" << endl;
	newMaker->generateDoc(newWordMap, GLCloudOutputFileName);
	cin.get();
	return 0;
}