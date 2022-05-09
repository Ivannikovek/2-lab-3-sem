#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() : size_(0), tail_(nullptr), head_(nullptr) { };

void PriorityQueue::push(char c) {
	if (head_ == nullptr) {
		head_ = new NodePriority(c);
		tail_ = head_;
		size_++;
		return;
	}

	NodePriority* buff = head_;
	while (buff)
	{
		if (buff->character == c) {
			buff->frequency++;
			sort();
			return;
		}
		buff = buff->next;
	}

	buff = tail_;
	NodePriority* add = new NodePriority(c);
	add->previous = buff;
	buff->next = add;
	tail_ = add;
	size_++;
}

void PriorityQueue::push(char character, int frequency, NodePriority* left, NodePriority* right) {
	if (head_ == nullptr) {
		head_ = new NodePriority(character);
		tail_ = head_;
		head_->frequency = frequency;
		head_->left = left;
		head_->right = right;
		size_++;
		return;
	}

	NodePriority* buff = tail_;
	NodePriority* add = new NodePriority(character);
	add->previous = buff;
	buff->next = add;
	tail_ = add;
	add->left = left;
	add->right = right;
	add->frequency = frequency;
	size_++;
	sort();
}

void PriorityQueue::sort() {
	for (int i = 0; i < size_; i++) {
		NodePriority* left = head_;
		NodePriority* right = head_->next;
		for (int j = 0; j < size_ - 1; j++) {
			if (left->frequency > right->frequency) {
				swap(left, right);
				left = right->next;
				right = left->next;
				continue;
			}
			left = left->next;
			right = right->next;
		}
	}
}

void PriorityQueue::swap(NodePriority* l, NodePriority* r) {
	NodePriority* buff = r->next;
	r->next = l;
	l->next = buff;

	buff = l->previous;
	l->previous = r;
	r->previous = buff;

	if (r->previous)
		r->previous->next = r;
	else
		head_ = r;

	if (l->next)
		l->next->previous = l;
	else
		tail_ = l;
}

NodePriority* PriorityQueue::pop() {
	if (head_ == nullptr)
		return nullptr;
	NodePriority* p = head_;

	if (head_->next) {
		head_ = head_->next;
		head_->previous = nullptr;
	}
	else {
		head_ = nullptr;
		tail_ = nullptr;
	}

	p->next = nullptr;
	size_--;
	return p;
}

int PriorityQueue::size() const {
	return size_; 
};