#include <iostream>
using namespace std;

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
class MyLinkedList {
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		val = 0;
		next = NULL;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		//此时，链表中仅含有头结点
		if ((this->val == 0) && (this->next == NULL))
		{return -1;}
		
		MyLinkedList* now_node = new MyLinkedList();
		now_node = this->next;

		int final_val = -1;
		for (int i = 0; i <= index; i++)
		{
			//若为空，则直接返回 -1
			if (now_node == NULL)
				return -1;

			final_val = now_node->val;
	
			if (i == index)
				return final_val;
			now_node = now_node->next;
		}
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		MyLinkedList* new_head = new MyLinkedList();
		new_head->val = val;
		new_head->next = this->next;
		this->next = new_head;
		
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		MyLinkedList* new_tail = new MyLinkedList();
		MyLinkedList* temp = this; //temporary node for traversal
		new_tail->val = val;
		//获取最后一个节点
		while (temp->next != NULL)
		{temp = temp->next;}
		temp->next = new_tail;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		MyLinkedList* new_node = new MyLinkedList();
		new_node->val = val;

		MyLinkedList* temp_node = new MyLinkedList();
		
		//求取list的长度
		int list_len = 0;
		temp_node = this->next;
		while (temp_node != NULL)
		{
			temp_node = temp_node->next;
			list_len++;
		}
		
		if (index > list_len)//index大于list长度，直接返回
			return;
		if (index == 0)
		{addAtHead(val);}
		else{
			temp_node = this->next;
			for (int i = 0; i <index-1; i++)
			{
				temp_node = temp_node->next;
			}
			new_node->next = temp_node->next;
			temp_node->next = new_node;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		
		if (this->next == NULL)
			return;

		if (index == 0)
		{
			this->next = this->next->next;
			return;
		}

		MyLinkedList* temp_node = new MyLinkedList();
		temp_node = this->next;
		for (int i = 1;i < index; i++)
		{
			if (temp_node != NULL)
				temp_node = temp_node->next;
			else
				break;
		}
		if (temp_node!=NULL && temp_node->next!=NULL)
			temp_node->next = temp_node->next->next;
	}

	/* print the value of the linked list  */
	void printVal() {
		MyLinkedList* temp_node = new MyLinkedList;
		temp_node = this->next;
		while (temp_node != NULL)
		{
			cout << temp_node->val<<" ";
			temp_node = temp_node->next;
		}
		cout << endl;
	}
	
private:
	int val;
	MyLinkedList* next;

};



/**
* Your MyLinkedList object will be instantiated and called as such:
* MyLinkedList obj = new MyLinkedList();
* int param_1 = obj.get(index);
* obj.addAtHead(val);
* obj.addAtTail(val);
* obj.addAtIndex(index,val);
* obj.deleteAtIndex(index);
*/
#endif // !LINKED_LIST_H_
