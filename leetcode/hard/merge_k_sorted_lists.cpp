#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

void print(ListNode *head)
{
	ListNode *current = head;

	while (current != nullptr)
	{
		cout << current->val << ' ';
		current = current->next;
	}
	cout << '\n';
}

ListNode * merge_two_lists(ListNode *l1, ListNode *l2)
{
	ListNode *head = new ListNode();
	ListNode *current = head;

	while(l1 != nullptr and l2 != nullptr)
	{
		if(l1->val < l2->val)
		{
			current = current->next = l1;
			l1 = l1->next;
		}
		else
		{
			current = current->next = l2;
			l2 = l2->next;
		}
	}

	current->next = l1 != nullptr ? l1 : l2;

	return head->next;
}

ListNode * merge_k_lists(vector<ListNode *> &lists)
{
	ListNode *head = new ListNode(INT_MIN);

	for(auto list : lists)
		head = merge_two_lists(head, list);

	return head->next;
}

int main()
{
	vector<ListNode *> lists{initialize({1, 4, 5}),
							 initialize({1, 3, 4}),
							 initialize({2, 6})};

	ListNode *result = merge_k_lists(lists);

	print(result);

	return 0;
}