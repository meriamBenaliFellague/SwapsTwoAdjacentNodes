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
	int nbrNode,input;
	nbrNode=ReadNumberOfNode();
	for(int i=0;i<nbrNode;i++){
		input=ReadInput();
		AddNodeEnd(input);
	}
	p=head;
    display(swapsTwoAdjacentNode(head));
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

void display(struct ListNode *head){
	p=head;
	while(p!=NULL){
		printf("%d\n",p->data);
		p=p->next;
	}
}

struct ListNode *swapsTwoAdjacentNode(struct ListNode *head){
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
