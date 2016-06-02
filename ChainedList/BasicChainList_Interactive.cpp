#include<iostream>
#include<stdlib.h>			//用到标准库中的free()和system() 
using namespace std;

struct Node
{
	int data;
	Node *next;	
};


Node *createList()
{
	Node *head, *tail, *p;
	head = new Node();
	tail = head;
	
	int buff;
	cout<<"创建链表——输入你要加入链表的数，值小于等于零结束："<<endl;
	while((cin>>buff) && (buff>0)){
		p = new Node;
		p->data = buff;
		tail->next = p;
		tail = p;
	}
	tail->next = NULL;
	
	return head;
}

void printList(Node *head)
{
	Node *p;
	p = head;
	
	cout<<"接下来输出链表："<<endl;
	
	while((p != NULL) && (p = p->next))
		cout<<p->data<<'\t';
		
	cout<<endl;
	
}

void findItem(Node *head)
{
	Node *p;
	p = head;
	
	int key;
	cout<<"输入你要查找的关键字："<<'\t';
	cin>>key;
	
	while((p != NULL) && (p->data != key))
		p = p->next;
	
	if(p == NULL)
		cout<<"未找到关键字 "<<key<<endl;
	else
		cout<<"关键字已找到。"<<endl;
}

void removeItem(Node *head)
{
	Node *p;
	p = head;
	
	int key;
	cout<<"你要删除哪一项？"<<'\t'<<endl;
	cin>>key;
	
	while((p->next != NULL) && (p->next->data != key))
		p = p->next;
	
	if(p->next == NULL)
		cout<<"找不到要删除的项"<<endl;
	else
	{
		Node *tmp = p->next;
		p->next = tmp->next;
		free(tmp);
	}
}

void insertItem(Node *head)
{
	Node *p;
	p = head;
	
	int key;
	cout<<"你要在哪一项之后插入？"<<'\t'<<endl;
	cin>>key;
	
	while((p != NULL) && (p->data != key))
		p = p->next;
	
	if(p == NULL)
		cout<<"找不到你指定的关键字。将插入到链尾。"; 
		
	int buff;
	cout<<"输入你要插入的值："<<'\t';
	cin>>buff;
				
	Node *tmp = new Node;
	tmp->data = buff;
	tmp->next = p->next;
	p->next = tmp;
}

void Interface(Node *head)
{
	char opr;
	
menu:
	system("cls");
	
	cout<<"选择你希望对链表进行的操作："<<endl;
	cout<<"[p]	打印输出链表"<<endl; 
	cout<<"[i]	插入一个新结点"<<endl;
	cout<<"[r]	删除一个结点"<<endl;
	cout<<"[f]	查找一个结点"<<endl; 
	cout<<"[q]	退出程序"<<endl;
	cin>>opr;
	
	switch(opr){
		case 'p':
			printList(head);
			break;
		case 'i':
			printList(head);
			insertItem(head);
			printList(head);
			break;
		case 'r':
			printList(head);
			removeItem(head);
			printList(head);
			break;
		case 'f':
			findItem(head);
			printList(head);
			break;
		case 'q':
			return;
		default:
			printList(head);
	}
	system("pause");
	
	goto menu;
	
	
}

int main()
{
	Node *fyHead = createList();
	Interface(fyHead);
	
	return 0;
}
