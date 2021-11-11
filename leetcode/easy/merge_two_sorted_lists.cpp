#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode * merge_two_list(ListNode *l1, ListNode *l2)
{
	ListNode *head = new ListNode();
	ListNode *current = head;

	while(l1 != nullptr && l2 != nullptr)
	{
		if(l1->val < l2->val)
		{
			current = current->next = new ListNode(l1->val);
			l1 = l1->next;
		}
		else
		{
			current = current->next = new ListNode(l2->val);
			l2 = l2->next;
		}
	}

	while(l1 != nullptr)
	{
		current = current->next = new ListNode(l1->val);
		l1 = l1->next;
	}

	while(l2 != nullptr)
	{
		current = current->next = new ListNode(l2->val);
		l2 = l2->next;
	}

	return head->next;
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

int main()
{
	vector<int> l_vec{1, 2, 4};
	vector<int> r_vec{1, 3, 4};

	ListNode *l1 = initialize(l_vec);
	ListNode *l2 = initialize(r_vec);

	ListNode *result = merge_two_list(l1, l2);

	print(result);

	return 0;
}