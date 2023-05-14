#include<stdio.h>
#include<stdlib.h>
struct ListNode{
	int data;
	struct ListNode *next;
};
struct ListNode *head=NULL,*p,*q,*r;

int ReadNumberOfNode();
int ReadInput();
void AddNodeEnd(int y);
struct ListNode *swapsTwoAdjacentNode(struct ListNode *head);
void display(struct ListNode *head);

int main(){
	int nbrNode,input,s;
	nbrNode=ReadNumberOfNode();
	for(int i=0;i<nbrNode;i++){
		input=ReadInput();
		AddNodeEnd(input);
	}
	p=head;
    display(swapsTwoAdjacentNode(head));
}

int ReadNumberOfrevers()
{int l;
  printf("enter number of reverse: ");
  scanf("%d",&l);
  return l;
}

int ReadNumberOfNode()
{int b;
  printf("enter the number of node: ");
  scanf("%d",&b);
  return b;
}

int ReadInput()
{int y;
  printf("enter number: ");
  scanf("%d",&y);
  return y;
}

void AddNodeEnd(int y)
{q=head;
  p=(struct ListNode*)malloc(sizeof(struct ListNode));
  p->data=y;
  if(head==NULL)
  {
    p->next=NULL;
    head=p;
  }else
  {
    while(q->next!=NULL){
    	q=q->next;
	}
	q->next=p;
	p->next=NULL;
  }
}


int length(struct ListNode *head){
	if(head==NULL){
		printf("The list is empty");
		return -1;                 
	}else{
		p=head;int c=0;
		while(p!=NULL){
			c++;
			p=p->next;
		}
		return c;
	}
}

void display(struct ListNode *head){
	p=head;
	while(p!=NULL){
		printf("%d\n",p->data);
		p=p->next;
	}
}

struct ListNode *swapsTwoAdjacentNode(struct ListNode *head){int s;
	if(p->next==NULL){
		return head;
	}else{
		s=p->data;
		p->data=p->next->data;
		p->next->data=s;
		if(p->next->next==NULL){
			p=p->next;
		}else{
			p=p->next->next;
		}
		return swapsTwoAdjacentNode(head);
   }
}
