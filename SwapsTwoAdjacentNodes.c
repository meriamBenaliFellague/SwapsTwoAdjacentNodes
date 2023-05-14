#include<stdio.h>
#include<stdlib.h>

struct ListNode{
	int data;
	struct ListNode *next;
};
struct ListNode *head=NULL,*p,*q,*r,*t;int count=0;

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
		if(count==0){
			if(p->next->next==NULL){
			q=p->next;
			q->next=p;
			head=q;
			p->next=NULL;
			return swapsTwoAdjacentNode(head);
			}else{
			q=p->next;
			r=q->next;
			q->next=p;
			head=q;
			p->next=r;
			t=p;
			p=p->next;count++;
			return swapsTwoAdjacentNode(head);
			}
		}else{
			q=p->next;
			if(p->next->next!=NULL){
				r=q->next;
				t->next=q;
				q->next=p;
				p->next=r;
				t=p;
				p=p->next;
				count++;
				return swapsTwoAdjacentNode(head);
			}else{
				t->next=q;
				q->next=p;
				p->next=NULL;
			    return swapsTwoAdjacentNode(head);	
			}
        }
}
}
