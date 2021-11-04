#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* add_two_numbers(ListNode* l1, ListNode* l2) {
	ListNode* output = new ListNode();
	ListNode* current = output;
	
	bool carry = 0;
	while(l1 != nullptr || l2 != nullptr)
	{  
		int sum = (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + carry;
		carry = sum / 10, sum %= 10;
		
		current = current->next = new ListNode(sum);
		
		if(l1 != nullptr) l1 = l1->next;
		if(l2 != nullptr) l2 = l2->next;
	}
	
	if(carry == 1) current->next = new ListNode(1);
	
	return output->next;
}

ListNode* vec_to_list(vector<int> &vec)
{
	ListNode* output = new ListNode();
	ListNode* current = output;

	for(int i : vec)
	{
		current->next = new ListNode(i);
		current = current->next;
	}

	return output->next;
}

int main()
{
	vector<int> l1{2, 4, 3, 1, 1, 1, 1};
	vector<int> l2{5, 6, 4};

	ListNode* result = add_two_numbers(vec_to_list(l1), vec_to_list(l2));

	cout << "[";
	while(result != nullptr)
	{
		cout << result->val << (result->next != nullptr ? "," : "");
		result = result->next;
	}
	cout << "]\n";

	return 0;
}