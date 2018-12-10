#ifndef DOCLIST_H
#define DOCLIST_H

#include <string>
using namespace std;

class FreqList;
class WordCount;

class DocList
{
	private:
		string filename;
		FreqList *fl;
	public:
		//Default Constructor
		DocList();

		//Overloaded Doclist Constructor
		DocList(string, FreqList*);

		//Default Destructor
		virtual ~DocList();

		//Read a FreqList out of a file
        //@params string is the name of the file
        virtual void read(string); //*fl=new FreqList(string)

		//Writes a FreqList to a file
		virtual void write(string);

		//Getter for Frequency List
		virtual FreqList getFreqList();

		//Setter for Frequency List
		virtual void setFreqList(FreqList*);

		//Getter for File Name
		virtual string getFileName();

		//Setter for File Name
		virtual void setFileName(string);
    
        //basic methods for manipulating list. Will return values from FreqList
        virtual void addToList(std::string s); //return fl.addToList()
        virtual void removeFromList();
        virtual WordCount firstOfList();
		virtual WordCount lastOfList();
		virtual size_t sizeOfList();
		virtual WordCount atListPosition(int i);
		virtual void sort();
    
};
#endif

