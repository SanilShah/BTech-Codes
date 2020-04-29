#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max1 10

struct BST
{
   int data;
   struct BST *Left;
   struct BST *Right;

};


BST* inorder_successor(BST* curr)
{
	while(curr->Left != NULL)
    {
		curr = curr->Left;
	}
	return curr;
}


struct BST *p,*q,*r,*root=NULL,*root1=NULL,*New,*New1,*stack1[max1],*temp,*Queue[max1];
int flag=0,c=0,top=-1,rear=-1,front1=-1,cnt=0,k=0;

void push(struct BST *r)
{
    if(top==max1-1)
    {
	printf("stack is full");
    }
    else
    {
	top++;
	stack1[top]=r;

    }
}

struct BST * pop()
{
    struct BST * nodeD;
  if(top==-1)
  {

      return 0;
  }
  else
  {
      nodeD=stack1[top];
      top--;
  }
  return nodeD;
}

void Enqueue(struct BST *r)
{
 if(rear==max1-1)
  {
    printf("Queue is Full");
  }
 else
  {
    if(front1==-1)
    {
      front1=0;
      rear++;
      Queue[rear]=r;
    }
   else
    {
      rear++;
      Queue[rear]=r;
    }

  }
}


struct BST * Dequeue()
{
 if(front1==-1)
  {
    printf("Queue is Empty");
  }
 else
  {
    q=Queue[front1];
    front1++;
  }
}

void inorder_recursive(struct BST *p)
{
  if(p!=NULL)
   {
     inorder_recursive(p->Left);
     printf("%d ",p->data);
     inorder_recursive(p->Right);
   }
}

void inorder_recursive2(struct BST *p)
{
  if(p!=NULL)
   {
     inorder_recursive(p->Left);
     printf(" ");
     inorder_recursive(p->Right);
   }
}

struct BST * accept()
{
  int k;
  New=(struct BST *)malloc(sizeof(struct BST));
  printf("Enter the data:-");
  scanf("%d",&k);
  New->data=k;
  New->Left=NULL;
  New->Right=NULL;
  return New;

}


void createBST()
{

 do{
    cnt++;
    flag=0;
    New=accept();
    if(root==NULL)
    {
	root=New;

    }
    else
    {
	p=root;
	while(p!=NULL && flag==0)
	{
	    if(p->data > New->data && p->Left==NULL)
	    {
	      p->Left=New;
	      p=root;
	      flag=1;
	    }
	    else if(p->data < New->data && p->Right==NULL)
	    {
		p->Right=New;
		p=root;
		flag=1;

	    }
	    else if(p->data > New->data && p->Left!=NULL)
	    {
		p=p->Left;
	    }
	    else
	    {
		p=p->Right;
	    }
	}

     }printf("Do you want to add one more record(Yes-1/No-0):-");
     scanf("%d",&c);
     if(c==0)
     {
	printf("\n");
     }

   }while(c==1);
}


struct BST * acceptM(struct BST *r)
{
 New1=(struct BST *)malloc(sizeof(struct BST));
 New1->data=r->data;
 New1->Left=NULL;
 New1->Right=NULL;
 return New1;
}

void create_mirror(struct BST *r)
{

    flag=0;
    New1=acceptM(r);
    if(root1==NULL)
    {
	root1=New1;
    }
    else
    {
	q=root1;
	while(q!=NULL && flag==0)
	{
	    if(q->data > New1->data && q->Right==NULL)
	    {
	      q->Right=New1;
	      q=root1;
	      flag=1;
	    }
	    else if(q->data < New1->data && q->Left==NULL)
	    {
		q->Left=New1;
		q=root1;
		flag=1;

	    }
	    else if(q->data > New1->data && q->Right!=NULL)
	    {
		q=q->Right;
	    }
	    else
	    {
		q=q->Left;
	    }

	}

    }

}

void Levelwise(struct BST *root)
{
 Enqueue(root);
   while(front1<=rear)
     {
       temp=Dequeue();
       printf("%d ",temp->data);

       if(temp->Left!=NULL)
	{
	 Enqueue(temp->Left);
	}
       if(temp->Right!=NULL)
	{
	 Enqueue(temp->Right);
	}
    }
}


void DFS(struct BST *p)
{
push(p);
   while(top!=-1 && k<cnt)
     {
       temp=pop();
       printf("%d ",temp->data);
       k++;

     if(temp->Left!=NULL)
      {
	 q=temp;
	 push(temp->Left);
      }
     else if(temp->Right==NULL && temp->Left==NULL)
      {
	 if(q->Right!=NULL)
	  {
	   push(q->Right);
	   q=q->Right;
	  }
	else
	  {
	   push(p->Right) ;
	  }
      }
     else
	{
	  q=temp;
	  push(temp->Right);
	}
    }
}


void mirror_recursive(struct BST *p)
{
 if(p!=NULL)
  {
   temp=p->Left;
   p->Left=p->Right;
   p->Right=temp;
   mirror_recursive(p->Left);
   mirror_recursive(p->Right);
  }
}


void mirror_non_recursive(struct BST *root)
{
 Enqueue(root);
   while(front1<=rear)
     {
       temp=Dequeue();

       r=temp->Left;
       temp->Left=temp->Right;
       temp->Right=r;

       if(temp->Left!=NULL)
	{
	 Enqueue(temp->Left);
	}
       if(temp->Right!=NULL)
	{
	 Enqueue(temp->Right);
	}
    }

}


void mirror_new(struct BST *p)
{
 if(p!=NULL)
  {
   create_mirror(p);
   mirror_new(p->Left);
   mirror_new(p->Right);
  }
}

BST* deleteNode(struct BST* root, int key)
{
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->Left = deleteNode(root->Left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->Right = deleteNode(root->Right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->Left == NULL)
        {
            BST *temp = root->Right;
            free(root);
            return temp;
        }
        else if (root->Right == NULL)
        {
            BST *temp = root->Left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        BST* temp = inorder_successor(root->Right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->Right = deleteNode(root->Right, temp->data);
    }
    return root;
}

void Deletion(struct BST *p)
{
int key;
printf("Enter the Number which you want to Delete:");
scanf("%d",&key);
 if(p->data==key)
 {
   root=p->Right;
   r=p->Right;
   r->Left=inorder_successor(r);
  p->Left=NULL;
  p->Right=NULL;
  free(p);
 }
 else
 {
  while(p->data!=key)
  {
   if(p->data>key)
    {
      q=p;
      p=p->Left;
    }
   else
    {
      q=p;
      p=p->Right;
    }
   }
 }

 if(q->data > p->data && p->Left==NULL && p->Right==NULL)
  {
    q->Left=NULL;
    free(p);
  }
 else if(q->data < p->data && p->Left==NULL && p->Right==NULL)
  {
    q->Right=NULL;
    free(p);
  }
 else if(q->data > p->data && p->Left==NULL && p->Right!=NULL)
 {
    q->Left=p->Right;
    p->Right=NULL;
    free(p);
 }
 else if(q->data < p->data && p->Left==NULL && p->Right!=NULL)
 {
    q->Right=p->Right;
    p->Right=NULL;
    free(p);
 }
 else if(q->data > p->data && p->Left!=NULL && p->Right==NULL)
 {
   q->Left=p->Left;
   p->Left=NULL;
   free(p);
 }
 else if(q->data < p->data && p->Left!=NULL && p->Right==NULL)
 {
   q->Right=p->Left;
   p->Left=NULL;
   free(p);
 }
 else if(q->data > p->data && p->Left!=NULL && p->Right!=NULL)
 {
  q->Left=p->Right;
  r=p->Right;
  r->Left=inorder_successor(r);
  p->Left=NULL;
  p->Right=NULL;
  free(p);
  }
  else
  {
  q->Right=p->Right;
  r=p->Right;
  r->Left=inorder_successor(r);
  p->Left=NULL;
  p->Right=NULL;
  free(p);
  }

}



int main()
{
int choice;
 do{
    printf("\n=====================================\n");
    printf("\t** BST Operations. **\n");
    printf("======================================");
    printf("\n1.Create BST.\n2.Level-wise Printing.\n3.Depth First Search.\n4.Delete Node.\n5.Mirror Image(Recursive).\n6.Mirror Image(Non-Recursive).\n7.Mirror Image(New Tree).\n8.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
       case 1:
	   createBST();
	   break;

       case 2:
	    Levelwise(root);
	    break;

       case 3:
	     DFS(root);
	     break;

       case 4:
         int key;
         printf("Enter the Number which you want to Delete:");
         scanf("%d",&key);
	     root=deleteNode(root,key);
	     break;

       case 5:
	     mirror_recursive(root);
	     printf("\nIn-order of Mirror Image of BST:-");
	     inorder_recursive(root);
	     break;

       case 6:
	     mirror_non_recursive(root);
	     printf("\nIn-order of Mirror Image of BST:-");
	     inorder_recursive(root);
	     break;

       case 7:
	     mirror_new(root);
	     printf("\nIn-order of Original BST:-");
	     inorder_recursive(root);
	     printf("\nIn-order of Mirror Image of BST:-");
	     inorder_recursive(root1);
	     break;

       case 8:
	     exit(0);

       default:
	     printf("Invalid Choice...");

    }

  }while(1);
return 0;
}
