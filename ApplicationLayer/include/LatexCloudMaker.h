#ifndef TOTEXFILE_H
#define TOTEXFILE_H

class LatexCloudMaker {
public:
	LatexCloudMaker();
	virtual ~LatexCloudMaker();
	virtual void toTexFile(String filename);
};

#endif