#ifndef __DEMOCOMMAND_H
#define __DEMOCOMMAND_H
#include <assert.h>
#include "RarItem.h"
#include "DataObjectBase.h"

class DemoCommand : public DataObjectBase
{
	double x;
	double y;
	double alpha;

public:
	DemoCommand()
	{
		this->x = 0;
		this->y = 0;
		this->alpha = 0;
	}

	virtual void readFromRarItem(RarItem &item, RarContainer &container)
	{
		assert(item.type == "Config2D");
		assert(item.values.size() == 3);
		this->x = item.values[0];
		this->y = item.values[1];
		this->alpha = item.values[2];
	}

	virtual void writeToRarContainer(RarContainer &container)
	{
		RarItem newItem;
		newItem.action = string("DemoCommand");
		newItem.type = string("Config2D");
		newItem.values.push_back(this->x);
		newItem.values.push_back(this->y);
		newItem.values.push_back(this->alpha);
		container.add(newItem);
	}
};

#endif
