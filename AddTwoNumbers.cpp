/*
* author: dongchagnzhang
* mail: dongchang.zhang@outlook.com
* time: 2016.09
*/
#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// code for leetcode from here

class Solution
{
  public:
    /*
    * 传入两个逆序数字的链表
    * 返回上述链表的和（同样逆序）
    */
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // 如果有空指针
        if (nullptr == l1)
            return l2;
        else if (nullptr == l2)
            return l1;

        int last = 0;
        // 头指针 和 每次申请节点的指针
        ListNode *head = nullptr, *tmp = nullptr;
        // 用于寻找结尾
        ListNode *current = nullptr;
        // 遍历 l1
        ListNode *current1 = l1;
        // 遍历 l2
        ListNode *current2 = l2;

        while (nullptr != current1 || nullptr != current2)
        {
            // 根据两个链表是否为空判断
            if (nullptr != current1 && nullptr != current2)
            {
                // 注意进位 1.要算进加和 2.也要算进下一个进位位
                tmp = new ListNode((current1->val + current2->val + last) % 10);
                last = (current1->val + current2->val + last) / 10;
                current1 = current1->next;
                current2 = current2->next;
            }
            else if (nullptr == current1 && nullptr != current2)
            {
                tmp = new ListNode((current2->val + last) % 10);
                last = (current2->val + last) / 10;
                current2 = current2->next;
            }
            else if (nullptr != current1 && nullptr == current2)
            {
                tmp = new ListNode((current1->val + last) % 10);
                last = (current1->val + last) / 10;
                current1 = current1->next;
            }
            // 插入该点到结尾
            // 是第一个点
            if (head == nullptr)
            {
                head = tmp;
            }
            // 不是
            else
            {
                current = head;
                while (current->next != nullptr)
                {
                    current = current->next;
                }
                current->next = tmp;
            }
        }
        // 最后如果有一个进位 且两个链表均空 将进位位插入到结果链表中
        if (last != 0)
        {
            tmp = new ListNode(last);
            current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = tmp;
        }
        // 返回结果头指针
        return head;
    }
};
// end here

// for test here
int main()
{
    Solution s;
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(8);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(0);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    auto tmp = s.addTwoNumbers(l1, l2);
    auto current = tmp;
    while (current != nullptr)
    {
        cout << current->val;
        current = current->next;
           }
    cout << endl;
    return 0;
}
// test end