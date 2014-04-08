#ifndef __DATAOBJECTBASE_H
#define __DATAOBJECTBASE_H
#include "RarItem.h"
#include "RarContainer.h"

/* Inherit your data objects from this class. */
class DataObjectBase
{
public:
	/** Reads the content from the given item. If it references further items, for example
	due to an internal hierarchy, it may need access to the container itself.

		@param	item	The item the data object is read from.
		@param	container	If other items inside the container are needed, they can be accessed via this reference.
	*/
	virtual void readFromRarItem(RarItem &item, RarContainer &container) { };

	/** Writes the content into RarItem(s) and adds them to the given container.
	*/
	virtual void writeToRarContainer(RarContainer &container) { };

	static DataObjectBase createFromRarItem(RarItem &item, RarContainer &container)
	{
		if (item.action == "DemoCommand")
		{
			DemoCommand newDemoCommand;
			newDemoCommand.readFromRarItem(item, container);
			return newDemoCommand;
		}
		else
		{
			throw exception("Unknown RarItem.action");
		}
	}

};

#endif
