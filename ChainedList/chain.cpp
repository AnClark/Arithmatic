/******************		��������ϰ		 ******************
	 ʼ�ղ�Ҫ����ʲô��ָ�룡ָ�벻���ڽ�㣡 
	 �á�->�����������ָ�룬ʵ���ϲ�������ָ����ָ�Ľ�� 
	 ���������У�ָ��ʼ�ն���һ�������������ڵ��ַ�ı����� 
	2016��6��1�� 
***********************************************************/ 

#include<iostream>
#include<stdlib.h>
using namespace std;

/********	����ṹ��	*******/ 
struct Node
{
	int data;
	Node *next;	
};


/********	����������	*******/ 
Node *create(){
	Node *head;			//����ͷָ�� ������ͷ��㣩 
	Node *tail;			//����βָ�� ������β�ڵ㣩 
	Node *p;			//����ָ��	�������½�㣩 
	head = new Node;	//��ʼ�������ͷ 
	tail = head;		//��β��� 
	
	cout<<"������ϣ���������������С�ڵ������ʾ����"<<endl;
	int n;
	while((cin>>n) && (n>0)){
		p = new Node;		//�����½�㣬��Ϊ�µ�β�ڵ� 
		p->data = n;		//�������� 
		tail->next = p;		//��βָ����ָ��������µ�β�ڵ�  
		tail = p;			//��βָ��ָ���µ�β�ڵ� 
	}
	tail->next = NULL;
	
	return head;
}


/********	��ӡ����	*******/ 
void print_LinkedList(Node *head){
	Node *p = head;
	
	cout<<"����������£�"<<endl;
	
	while((p != NULL) && (p = p->next))
		cout<<p->data<<'\t';
}

/********	��������Ԫ��	*******/ 
bool findItem(Node *head, int key){

	
}


/********	ɾ��������		*******/ 
void deleteItem(Node *head){
	//ɾ��������Ľ�㣬Ҫ�� �ҵ�Ҫɾ��������һ���ڵ� 
	//�˴���p������������˵�ġ���һ���ڵ㡱�� 
	Node *p;
	p = head;
	
	int key;
	cout<<endl<<"������������Ҫɾ��������";
	cin>>key;
	
	//���������������ҵ���ɾ������ 
	while((p->next != NULL) && (p->next->data != key))
		p = p->next;
		
	//��ʽ��ɾ������ 
	Node *tmp;			//����һ����ʱָ�룬ָ���ɾ������ 
	tmp = p->next;		//�˴�p->next ��Ϊ��ɾ�������p��Ϊ��ɾ������֮ǰһ�� 
	p->next = tmp->next;	//������������ 
	free(tmp);			//�ͷ��ڴ�ռ� 
}



int main()
{
	Node *myHead;
	myHead = create();
	print_LinkedList(myHead); 
	deleteItem(myHead);
	print_LinkedList(myHead); 
	
	return 0;
}
