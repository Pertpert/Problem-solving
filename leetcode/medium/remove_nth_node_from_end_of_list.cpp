#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode * remove_nth_from_end(ListNode *head, int n)
{
	ListNode *fast = head;
	ListNode *slow = head;

	for(int i = 0; i < n; i++)
		fast = fast->next;

	if(fast == nullptr) return head->next;

	while(fast->next != nullptr)
	{
		fast = fast->next;
		slow = slow->next;
	}

	slow->next = slow->next->next;

	return head;
}

ListNode * initialize(vector<int> vec)
{
	ListNode *head = new ListNode();
	ListNode *current = head;

	for(int i : vec)
	{
		current = current->next = new ListNode(i);
	}

	return head->next;
}

void print_listNode(ListNode *head)
{
	ListNode *current = head;

	while (current != nullptr)
	{
		cout << current->val << ' ';
		current = current->next;
	}
	cout << '\n';
}

int main()
{
	ListNode *head = initialize({1, 2, 3, 4, 5});
	int n = 2;

	print_listNode(head);
	head = remove_nth_from_end(head, n);
	print_listNode(head);

	return 0;
}