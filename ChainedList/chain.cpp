/******************		链表再练习		 ******************
	 始终不要忘记什么是指针！指针不等于结点！ 
	 用“->”运算符操作指针，实质上操作的是指针所指的结点 
	 链表运算中，指针始终都是一个存放着链表各节点地址的变量。 
	2016年6月1日 
***********************************************************/ 

#include<iostream>
#include<stdlib.h>
using namespace std;

/********	链表结构体	*******/ 
struct Node
{
	int data;
	Node *next;	
};


/********	创建新链表	*******/ 
Node *create(){
	Node *head;			//定义头指针 （不是头结点） 
	Node *tail;			//定义尾指针 （不是尾节点） 
	Node *p;			//工作指针	（不是新结点） 
	head = new Node;	//初始化链表表头 
	tail = head;		//首尾相接 
	
	cout<<"输入你希望构成链表的数。小于等于零表示结束"<<endl;
	int n;
	while((cin>>n) && (n>0)){
		p = new Node;		//创建新结点，作为新的尾节点 
		p->data = n;		//填入数据 
		tail->next = p;		//将尾指针所指结点链到新的尾节点  
		tail = p;			//将尾指针指向新的尾节点 
	}
	tail->next = NULL;
	
	return head;
}


/********	打印链表	*******/ 
void print_LinkedList(Node *head){
	Node *p = head;
	
	cout<<"输出链表如下："<<endl;
	
	while((p != NULL) && (p = p->next))
		cout<<p->data<<'\t';
}

/********	查找链表元素	*******/ 
bool findItem(Node *head, int key){

	
}


/********	删除链表项		*******/ 
void deleteItem(Node *head){
	//删除单链表的结点，要求 找到要删除结点的上一个节点 
	//此处的p，就是我们所说的“上一个节点”。 
	Node *p;
	p = head;
	
	int key;
	cout<<endl<<"接下来输入你要删除的数：";
	cin>>key;
	
	//遍历整个链表，以找到待删除的项 
	while((p->next != NULL) && (p->next->data != key))
		p = p->next;
		
	//正式的删除过程 
	Node *tmp;			//定义一个临时指针，指向待删除的项 
	tmp = p->next;		//此处p->next 即为待删除的项，而p则为待删除的项之前一项 
	p->next = tmp->next;	//重新链接链表 
	free(tmp);			//释放内存空间 
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
