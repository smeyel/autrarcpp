#ifndef __RARITEM_H
#define __RARITEM_H
#include <string>
#include <vector>
using namespace std;

/** Elementar RarItem to store the information of a DataObjectBase. */
class RarItem
{
public:
	RarItem()
	{
		this->action = string("");
		this->subject = string("");
		this->subjectID = -1;
		this->type = string("");
		this->values.clear();
		this->messageID = -1;
		this->timestamp = 0;
		this->binarySize = 0;
		this->binaryData = NULL;
		this->text = string("");
		this->parentMessageID = -1;
	}

	string action;
	string subject;
	int subjectID;
	string type;
	vector<double> values;
	int messageID;
	long long timestamp;
	int binarySize;
	void *binaryData;
	string text;
	int parentMessageID;
};

#endif
