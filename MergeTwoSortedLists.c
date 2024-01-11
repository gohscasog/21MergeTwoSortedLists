#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* InsertListNode(struct ListNode* head, int val)
{
    struct ListNode* ptr = (struct ListNode*) malloc(sizeof(struct ListNode));

    ptr->val = val;
    ptr->next = NULL;

    if(head)
    {
        ptr->next = head;
        head = ptr;
    }
    else
    {
        head = ptr;
    }

    return head;
}

struct ListNode* ReverseListNode(struct ListNode* head)
{
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    struct ListNode* prev = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if(list1 && !list2)
    {
        return list1;
    }
    
    if(list2 && !list1)
    {
        return list2;
    }
    
    struct ListNode* merged = NULL;
    struct ListNode* p1 = list1;
    struct ListNode* p2 = list2;
    
    while(p1 || p2)
    {
        if(p1 && p2)
        {
            if(p1->val == p2->val)
            {
                merged = InsertListNode(merged, p1->val);
                merged = InsertListNode(merged, p2->val);
                p1 = p1->next;
                p2 = p2->next;
            }
            else if(p1->val < p2->val)
            {
                merged = InsertListNode(merged, p1->val); 
                p1 = p1->next;
            }
            else
            {
                merged = InsertListNode(merged, p2->val);              
                p2 = p2->next;
            }
        }
        else if(p1)
        {
            merged = InsertListNode(merged, p1->val); 
            p1 = p1->next;
        }
        else
        {
            merged = InsertListNode(merged, p2->val); 
            p2 = p2->next;
        }
    }

    merged = ReverseListNode(merged);
    
    return merged;
};

int main()
{
    struct ListNode e0 = {4, NULL};
    struct ListNode e1 = {2, &e0};
    struct ListNode e2 = {1, &e1};
    struct ListNode list1[] = {e2, e1, e0};
    // struct ListNode list1[] = {e0};
    // struct ListNode* list1 = NULL;
    
    struct ListNode f0 = {4, NULL};
    struct ListNode f1 = {3, &f0};
    struct ListNode f2 = {1, &f1};
    struct ListNode list2[] = {f2, f1, f0};
    // struct ListNode list2[] = {f0};
    // struct ListNode* list2 = NULL;

    struct ListNode* mergedList = mergeTwoLists(list1, list2);

    struct ListNode* p = mergedList;
    while(p != NULL)
    {
        printf("%d\n", p->val);
        p = p->next;
    }    
    
    return 0;
}