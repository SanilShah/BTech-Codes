/*1) Create a binary tree and perform 3 types of traversals non-recursively,
     and calculate their leaf nodes and height of tree.
 Roll No.: 41
 Name: Sanil Shah
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} node;


node *lstack[MAX];
int top=0;
int cnt=0;
int cnt2=0;
int a[100];
int i,j;


void push(node *pushnode)
{
    if(top==MAX)
    {
        printf("Stack full.\n");
    }
    else
    {
        top++;
        lstack[top]=pushnode;
    }
}
node *pop()
{
    node *popnode;
    if(top==-1)
    {
        return 0;
    }
    else
    {
        popnode=lstack[top];
        top--;
    }
    return popnode;
}

node *create()
{
    node *p;
    int x;
    int ichoice2;
    printf("Enter data(-1 to set to NULL):");
    scanf("%d",&x);
    cnt++;
    if(x==-1)
    {
        cnt--;
        return NULL;
    }
    p=(node*)malloc(sizeof(node));
    p->data=x;
    printf("Enter left child of %d:\n",x);
    p->left=create();
    printf("Enter right child of %d:\n",x);
    p->right=create();
    return p;
}

void pre_orderR(node *lp)
{
   // printf("\n");
    if(lp!=NULL)
    {
        printf("%d",lp->data);
        pre_orderR(lp->left);
        pre_orderR(lp->right);
    }
}
void pre_order(node *lp)
{
    do
    {
        while(lp!=NULL)
        {
            printf("%d",lp->data);
            if(lp->right!=NULL)
                push(lp->right);
            lp=lp->left;
        }
        lp=pop();

    }
    while(top!=-1);
}

void leaf_count(node *lp)
{
    int leafcount=0;
    do
    {
        while(lp!=NULL)
        {
            if(lp->right==NULL&&lp->left==NULL)
                {
                    printf("%d",lp->data);
                    leafcount++;
                }
            if(lp->right!=NULL)
                push(lp->right);
            lp=lp->left;
        }
        lp=pop();

    }
    while(top!=-1);
    printf("\nLeaf Count:%d",leafcount);
}

void in_order(node *lp)
{
    do
    {
        while(lp!=NULL)
        {
            push(lp);
            lp=lp->left;
        }
        lp=pop();
        if(lp!=NULL)
            printf("%d",lp->data);
        lp=lp->right;
    }
    while(top!=-1);
}

void post_order(node *lp)
{
    do
    {
        while(lp!=NULL)
        {
            a[i]=lp->data;
            i++;
            if(lp->left!=NULL)
                push(lp->left);
            lp=lp->right;
        }
        lp=pop();
    }
    while(top!=-1);
}

int height(node *lp)
{
    if(lp==NULL)
        return 0;
    else
    {
         int left_height=height(lp->left);
         int right_height=height(lp->right);

        if(left_height>right_height)
            return (left_height+1);
        else
            return (right_height+1);
    }
}

int main()
{
    int ichoice,x=0;
    node *lroot;
    printf("Tree creation starts...\n");
    lroot=create();
    printf("Tree creation ends...\n");
    printf("count1=%d\n",cnt);
    do
    {
    printf("\n\n\n");
    printf("\n======= MENU =======\n");
    printf("1)Pre-order.\n2)In-order.\n3)Post-order.\n4)Exit\n5)Height of Tree.\n6)Leaf-Count.\n\n");
    printf("Enter choice :");
    scanf("%d",&ichoice);
    printf("====================\n\n");
    switch(ichoice)
    {
    case 1:
        {
            printf("\nPre_order:");
            top=0;
            pre_order(lroot);
            break;
        }
    case 2:
        {
            printf("\nIn_order:");
            top=0;
            in_order(lroot);
            break;
        }
    case 3:
        {
            printf("\nPost_order:");
            top=0;
            post_order(lroot);
            for(j=i-1;j>=0;j--)
            {
                printf("%d",a[j]);
            }
            break;
        }
    case 4:
        {
            x=1;
            break;
        }
    case 5:
        {
            printf("\nHeight:%d",height(lroot));
            break;
        }
    case 6:
        {
            printf("\nLeaf Nodes:");
            leaf_count(lroot);
            break;
        }
    default:
         {
             printf("Wrong choice. Re-enter.\n");
         }
    }
    }
    while(x==0);
    getch();
}


