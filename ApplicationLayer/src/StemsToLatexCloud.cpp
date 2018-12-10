#include <string>
#include <iostream>
#include "FreqMaker.h"
#include "WordMapMaker.h"
#include "DocList.h"
#include "LatexMaker.h"
#include "ICloudLayout.h"

int main(int argc[], char *argv[])
{
	bool traceFlag = true;
	std::string t_val = argv[3];

	if (t_val == "trace") {
		traceFlag = true;
		std::cout << "Trace is true\n";
	} else if (t_val == "notrace") {
		traceFlag = false;
		std::cout << "Trace is false\n";
	} else {
		std::cout << "ERROR: trace option not specified, input notrace or trace after designating output filename. Example execution: <input filename> <output filename>.txt trace";
		system("pause");
		return 0;
	}
	system("pause");
	FreqMaker fm;
	DocList* doc = fm.getDocList(argv[1]);
	
	if (traceFlag)
		doc->write("freqListFile.txt");
	
	doc->sort();
	doc->removeFromList();

	WordMapMaker wmm;
	WordMap* wm = wmm.convertFreqList(doc);

	ICloudLayout* cloud = NewLayout();
	cloud->updateWordMap(wm);

	if(traceFlag)
		wm->write("wordMapFile");

	LatexMaker lm;
	lm.generateDoc(wm, argv[2]);

	return 0;
}