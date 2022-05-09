#include "pch.h"
#include "HuffmanTree.h"

TEST(HuffmanTree, buildTree) {
	HuffmanTree test;
	test.buildTree("beadbdddbaddaecbde");

	NodePriority* buff = test.getRoot();

	ASSERT_EQ(buff->frequency, 18);
	ASSERT_EQ(buff->left->frequency, 7);
	ASSERT_EQ(buff->right->frequency, 11);
}

TEST(HuffmanTree, code) {
	HuffmanTree test;
	test.buildTree("beadbdddbaddaecbde");

	ASSERT_EQ(test.code().size(), 40);
}

TEST(HuffmanTree, decode) {
	HuffmanTree test;
	test.buildTree("beadbdddbaddaecbde");
	test.code();

	ASSERT_STREQ(test.decode().c_str(), "beadbdddbaddaecbde");
}

TEST(PriorityQueue, push) {
	string str = "beadbdddbaddaecbde";

	PriorityQueue test;

	for (int i = 0; i < str.size(); i++) {
		test.push(str[i]);
	};

	ASSERT_EQ(test.size(), 5);
}

TEST(PriorityQueue, pop) {
	string str = "beadbdddbaddaecbde";

	PriorityQueue test;

	for (int i = 0; i < str.size(); i++) {
		test.push(str[i]);
	};

	ASSERT_EQ(test.pop()->character, 'c');
	ASSERT_EQ(test.pop()->character, 'e');
	ASSERT_EQ(test.pop()->character, 'a');
	ASSERT_EQ(test.pop()->character, 'b');
	ASSERT_EQ(test.pop()->character, 'd');
	ASSERT_EQ(test.pop(), nullptr);
}