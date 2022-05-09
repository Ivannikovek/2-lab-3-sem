#include <iostream>
#include "HuffmanTree.h"

using std::cout;
using std::cin;
using std::endl;


int main() {
	HuffmanTree test;

	string str;

	getline(cin, str);

	test.buildTree(str);

	test.printTable();

	cout << "Code string:" << endl;
	cout << test.code() << endl;

	cout << "Decode string:" << endl;
	cout << test.decode() << endl;

	cout << "Compresion = " << float(test.getString().size() * 8) / float(test.getCode().size()) << endl;
	return 0;
}