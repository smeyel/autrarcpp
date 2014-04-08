#ifndef __RARCONTAINER_H
#define __RARCONTAINER_H
#include <vector>
#include <assert.h>
#include "RarItem.h"

/** Represents a list of RarItem objects, ready to be
sent (or received). JSON serialization and deserialization is
controlled by this class. */
class RarContainer
{
	/** Vector of items in the container. */
	std::vector<RarItem> items;
public:
	RarContainer()
	{
		items.clear();
	}

	/** Adds a copy of the item to the container.
		@param item	RarItem to be copied and added to the container.
	*/
	void add(RarItem item)
	{
		items.push_back(item);
	}

	RarItem &operator[](int index)
	{
		assert(index >= 0);
		assert(index < items.size());
		return items[index];
	}

	/** Writes the container to an output stream. */
	void serialize(ostream &targetStream);

	/** Reads the container from an input stream. */
	void deserialize(istream &sourceStream);
};

#endif
