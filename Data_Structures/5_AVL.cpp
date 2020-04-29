
#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left,*right;
	int ht;
}node;

typedef struct queue
{
  node *info;
  struct queue *next;
} Queue;

Queue *front=NULL;
Queue *rear=NULL;
int size=0;

void Enqueue(node *p)
{
    Queue *temp;
    temp=(Queue*)malloc(sizeof(Queue));
    temp->info=p;
    temp->next=NULL;
    if(front==NULL)
    {
        front=rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=rear->next;
    }
    size++;
}

node *Dqueue()
{
    node *temp;
    Queue *temp1;
    if(front==NULL)
    {
        temp=NULL;
        printf("!!! Queue Empty !!!");
    }
    else
    {
      temp1=front;
      temp=temp1->info;
     if(front!=rear)
     {

        front=front->next;
     }
     else
     {
         front=rear=NULL;
     }
     size--;
    }
    free(temp1);
    return temp;

}
void levelwise(node *p)
{
    int count;
    Enqueue(p);
    do
    {
       printf("\n");
       count=size;
        while(count>0)
        {
          p=Dqueue();
          printf("%d \t",p->data);
            if(p->left!=NULL)
            {
                Enqueue(p->left);
            }
            if(p->right!=NULL)
            {
                Enqueue(p->right);
            }
            count--;
        }
        printf("\n");

    }while(size);
}

int height(node *p)
{
	int lh,rh;
	if(p==NULL)
		return(0);

	if(p->left==NULL)
		lh=0;
	else
		lh=1+p->left->ht;

	if(p->right==NULL)
		rh=0;
	else
		rh=1+p->right->ht;

	if(lh>rh)
		return(lh);

	return(rh);
}



node *rotateright(node *x)
{
	node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}

node *rotateleft(node *x)
{
	node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);

	return(y);
}

node *RR(node *p)
{
	p=rotateleft(p);
	return(p);
}

node *LL(node *p)
{
	p=rotateright(p);
	return(p);
}

node *LR(node *p)
{
	p->left=rotateleft(p->left);
	p=rotateright(p);

	return(p);
}

node *RL(node *p)
{
	p->right=rotateright(p->right);
	p=rotateleft(p);
	return(p);
}

int BF(node *p)
{
	int lh,rh;
	if(p==NULL)
		return(0);

	if(p->left==NULL)
		lh=0;
	else
		lh=1+p->left->ht;

	if(p->right==NULL)
		rh=0;
	else
		rh=1+p->right->ht;

	return(lh-rh);
}

void preorder(node *p)
{
	if(p!=NULL)
	{
		printf("%d Bf=%d\n",p->data,BF(p));
		preorder(p->left);
		preorder(p->right);
	}
}

node *insert(node *p,int x)
{
	if(p==NULL)
	{
		p=(node*)malloc(sizeof(node));
		p->data=x;
		p->left=NULL;
		p->right=NULL;
	}
	else
		if(x > p->data)
		{
			p->right=insert(p->right,x);
			if(BF(p)==-2)
            {
                if(x>p->right->data)
					{
                      p=RR(p);
                      printf("\t\t\tRR Rotation");
					}
				else
                   {
					p=RL(p);
                    printf("\t\t\tRL Rotation");
					}
            }
		}
		else
			if(x < p->data)
			{
				p->left=insert(p->left,x);
				if(BF(p)==2)
					{
					    if(x < p->left->data)
                        {
						   p=LL(p);
						   printf("\t\t\tLL Rotation");
					    }
					  else
                       {
                          p=LR(p);
						  printf("\t\t\tLR Rotation");
                       }
					}
			}

		p->ht=height(p);



		return(p);
}



void inorder(node *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		printf("%d Bf=%d\n",p->data,BF(p));
		inorder(p->right);
	}
}

int main()
{
	node *root=NULL;
	int x,n,i,op;

	do
	{

		printf("\n1.To Insert Data:");
		printf("\n2.Display:");
		printf("\n3.Exit:");
		printf("\n\nEnter Your Choice:");
		scanf("%d",&op);

		switch(op)
		{
			case 1: printf("\nEnter a data:");
					scanf("%d",&x);
					root=insert(root,x);
					levelwise(root);
					break;
			case 2: printf("\nPreorder sequence:\n");
					preorder(root);

					printf("\nInorder sequence:\n");
					inorder(root);

					printf("\n");
					break;
		}
	}while(op!=3);

	return 0;
}
