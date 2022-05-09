#ifndef _HUFFMAN_TREE_

#define _HUFFMAN_TREE_

#include <string>
#include <iostream>
#include "NodePriority.h"
#include "PriorityQueue.h"

using std::string;
using std::cout;
using std::endl;

class HuffmanTree
{
public:
	HuffmanTree();
	void buildTree(string str);
	void printTable() const;
	string decode();
	string code();

	string getCode() const;
	string getString() const;

private:
	static void printTable(string code, NodePriority* curent);
	void code(char c, string s, NodePriority* curent);
	string str_;
	string code_str_;
	NodePriority* root_;
};

#endif // !_HUFFMAN_TREE_