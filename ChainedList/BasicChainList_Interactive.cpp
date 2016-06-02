#include<iostream>
#include<stdlib.h>			//�õ���׼���е�free()��system() 
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
	cout<<"����������������Ҫ�������������ֵС�ڵ����������"<<endl;
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
	
	cout<<"�������������"<<endl;
	
	while((p != NULL) && (p = p->next))
		cout<<p->data<<'\t';
		
	cout<<endl;
	
}

void findItem(Node *head)
{
	Node *p;
	p = head;
	
	int key;
	cout<<"������Ҫ���ҵĹؼ��֣�"<<'\t';
	cin>>key;
	
	while((p != NULL) && (p->data != key))
		p = p->next;
	
	if(p == NULL)
		cout<<"δ�ҵ��ؼ��� "<<key<<endl;
	else
		cout<<"�ؼ������ҵ���"<<endl;
}

void removeItem(Node *head)
{
	Node *p;
	p = head;
	
	int key;
	cout<<"��Ҫɾ����һ�"<<'\t'<<endl;
	cin>>key;
	
	while((p->next != NULL) && (p->next->data != key))
		p = p->next;
	
	if(p->next == NULL)
		cout<<"�Ҳ���Ҫɾ������"<<endl;
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
	cout<<"��Ҫ����һ��֮����룿"<<'\t'<<endl;
	cin>>key;
	
	while((p != NULL) && (p->data != key))
		p = p->next;
	
	if(p == NULL)
		cout<<"�Ҳ�����ָ���Ĺؼ��֡������뵽��β��"; 
		
	int buff;
	cout<<"������Ҫ�����ֵ��"<<'\t';
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
	
	cout<<"ѡ����ϣ����������еĲ�����"<<endl;
	cout<<"[p]	��ӡ�������"<<endl; 
	cout<<"[i]	����һ���½��"<<endl;
	cout<<"[r]	ɾ��һ�����"<<endl;
	cout<<"[f]	����һ�����"<<endl; 
	cout<<"[q]	�˳�����"<<endl;
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
