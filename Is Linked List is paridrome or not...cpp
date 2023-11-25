#include<iostream>
using namespace std;
struct node 
{
	int data;
	struct node * next;
};
class linkedList
{
private:
    node *head;
public:
    linkedList()
    {
        head = NULL;
    }
    void addNode (int x)
    {
    	if (head==NULL)
    	{
    		node * temp = new node () ;
    		head=temp;
    		temp->data = x;
    		temp ->next= NULL;
		}
		else
		{
			node * temp = new node ();
			node * ptr=head;
			while (ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;
			temp->data=x;
			temp->next=NULL;
		}
	}
	void print ()
	{
		if(head==NULL)
		{
			cout<<"Linked List is empty"<<endl;
		}
		else
		{
			node * temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<endl;
				temp=temp->next;
			}
		}
	}
	bool isPalindrome()
	{
		node * slow =head;
		node * fast =head;
		while(fast!=NULL && fast->next!=NULL)
		{
			slow=slow->next;
			fast=fast->next->next;
		}
		if(fast!=NULL && fast->next==NULL)
		{
			slow=slow->next;
		}
		node * prev=NULL;
		while(slow!=NULL && slow->next!=NULL)
		{
			node * temp=slow->next;
			slow->next=prev;
			prev=slow;
			slow=temp;
		}
		slow->next=prev;
		
	 fast=head;
	while(slow!=NULL && fast!=NULL)
	{
		if(slow->data != fast->data)
		{
			return false;
		}
		slow=slow->next;
		fast=fast->next;
	}
	return true;
	}
};

main()
{
	linkedList s;
	int n,x;
	cout<<"Enter number of nodes in Linked List="<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter node data="<<endl;
		cin>>x;
		s.addNode(x);
	}
	cout<<"Linked List Data="<<endl;
	s.print();
	if(s.isPalindrome())
	{
		cout<<"Linked List is Palidrome....!"<<endl;
	}
	else
	{
		cout<<"Linked List is not Palidrome ....!"<<endl;
	}
}
