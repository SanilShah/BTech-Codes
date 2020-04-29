#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct inThread
{
    int data,lth,rth;
    struct inThread *left,*right;
};
typedef struct inThread node;

node *header;

node* createNode()
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	printf("Enter integer data : ");
	scanf("%d",&temp->data);
	temp->left=temp->right=NULL;
	temp->lth=temp->rth=1;
	return temp;
}

node* addNode(node *root)
{
	node *new,*p;
	int flag;

	new=createNode();

	if( header->lth == 1 )
	{
		root=new;

		header->left = new;
		header->lth = 0;

		new->left = new->right = header;
		new->lth = new->rth = 1;
	}
	else
	{
		flag=0;
		p=root;

		while(flag!=1)
		{
			if(new->data < p->data)
			{
				if(p->lth == 1)
				{
					new->right=p;
					new->left=p->left;
					p->lth=0;
					p->left=new;
					new->lth=new->rth=1;
					flag=1;
				}
				else
					p=p->left;
			}
			else
			{
				if(p->rth == 1)
				{
					new->left=p;
					new->right=p->right;
					p->rth=0;
					p->right=new;
					new->lth=new->rth=1;
					flag=1;
				}
				else
					p=p->right;
			}
		}
	}

	return root;
}

void inorder(node *root)
{
	node *p=root;

	printf("In-order : ");

	while(p!=header)
	{
		while(p->lth!=1)
			p=p->left;
		printf("%d ",p->data);

		while(p->rth!=0)
		{
			p=p->right;

			if(p->right==header)
			  break;

		    printf("%d ",p->data);
		}
		p=p->right;
	}
}

void preorder(node *root)
{
	node *p=root;

	printf("In-order : ");

    while(p!=header)
    {
    	while(p->lth!=1)
    	{
    		printf("%d ",p->data);
    		p=p->left;
    	}
	printf("%d ",p->data);

    	while(p->rth!=0)
    	{
    		p=p->right;
    		if(p==header)
    			break;
    	}
    	p=p->right;
    }
}

void postorder(node *root)
{
	node *p=root;
	int temp[50],i=0;

	do
	{
		while(p->rth!=1)
		{
			temp[i++]=p->data;
			p=p->right;
		}
		temp[i++]=p->data;

		while(p->lth!=0)
			p=p->left;
		if(p!=header)
			p=p->left;
	}while(p!=header);

    printf("Post-order : ");
    i--;
    while(i>-1)
	printf("%d ",temp[i--]);
}

int main()
{
    node *root=NULL;
    int choice;

    system("cls");

    header=(node*)malloc(sizeof(node));
    header->data=65535;
    header->left=header;
    header->right=header;
    header->lth=header->rth=1;

    do
    {
	printf("\nInorder Threaded binary Tree\n\n");
	printf("1.Add a node\n2.Inorder traversal\n");
	printf("3.Preorder traversal\n4.Postorder traversal\n");
	printf("5.Exit\n\nYour choice : ");
	scanf("%d",&choice);


	switch(choice)
		{
			case 1 : root=addNode(root);
			    	 break;

			case 2 : inorder(root);
			  		 break;

			case 3 : preorder(root);
		     		 break;

		    case 4 : postorder(root);
		             break;

			case 5 : exit(0);

        	default : printf("\n\nInvaild choice!!!!!!!!!!!!");
            	      break;
    	}
    printf("\n\n");
    system("pause");
    system("cls");

    }while(1);
}
