#ifndef _PRIORITY_QUEUE_

#define _PRIORITY_QUEUE_

#include "NodePriority.h"

class PriorityQueue
{
public:
	PriorityQueue();
	void push(char c);
	void push(char character, int frequency, NodePriority* left, NodePriority* right);

	NodePriority* pop();
	int size() const;

private:
	void sort();
	void swap(NodePriority* l, NodePriority* r);
	int size_;
	NodePriority* head_;
	NodePriority* tail_;
};

#endif //! _PRIORITY_QUEUE_