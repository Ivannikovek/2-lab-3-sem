#ifndef _NODE_PRIORITY_

#define _NODE_PRIORITY_

struct NodePriority {
	NodePriority(char c) : frequency(1), character(c), right(nullptr), left(nullptr), next(nullptr), previous(nullptr) {};

	int frequency; 
	char character; 

	NodePriority* left;
	NodePriority* right;

	NodePriority* next;
	NodePriority* previous;
};

#endif //!_NODE_PRIORITY_