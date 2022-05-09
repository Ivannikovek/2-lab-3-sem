#include "HuffmanTree.h"

HuffmanTree::HuffmanTree() : root_(nullptr), str_(""), code_str_("") { };

void HuffmanTree::buildTree(string str) {
	PriorityQueue pq;
	str_ = str;
	for (int i = 0; i < str_.size(); i++) 
		pq.push(str_[i]);

	if (pq.size() == 1) {
		root_ = new NodePriority('\0');
		root_->left = pq.pop();
		return;
	}

	while (pq.size() != 1)
	{
		NodePriority* left = pq.pop();
		NodePriority* right = pq.pop();

		pq.push('\0', left->frequency + right->frequency, left, right);
	}

	root_ = pq.pop();
}

void HuffmanTree::printTable() const {
	if (root_ == nullptr)
		return;

	printTable("0", root_->left);
	printTable("1", root_->right);
}

void HuffmanTree::printTable(string code, NodePriority* curent) {
	if (curent == nullptr)
		return;

	if ((curent->left == nullptr) && (curent->right == nullptr)) {
		cout << curent->character << " - " << curent->frequency << ", code = " << code << endl;
		return;
	}

	printTable(code + "0", curent->left);
	printTable(code + "1", curent->right);
}

string HuffmanTree::code() {
	for (int i = 0; i < str_.size(); i++) 
		code(str_[i], "", root_);
	
	return code_str_;
}

void HuffmanTree::code(char c, string s, NodePriority* curent) {
	if (curent == nullptr)
		return;

	if (curent->character == c) {
		code_str_ = code_str_ + s;
		return;
	}

	code(c, s + "0", curent->left);
	code(c, s + "1", curent->right);
}

string HuffmanTree::decode() {
	str_ = "";
	NodePriority* buff = root_;

	for (int i = 0; i < code_str_.size(); i++) {
		if (buff->left == nullptr && buff->left == nullptr) {
			str_ = str_ + buff->character;
			buff = root_;
		}
		if (code_str_[i] == '0')
			buff = buff->left;
		if (code_str_[i] == '1')
			buff = buff->right;
	}

	if (buff != nullptr)
		str_ = str_ + buff->character;

	return str_;
}

string HuffmanTree::getCode() const {
	return code_str_;
};
string HuffmanTree::getString() const {
	return str_;
};