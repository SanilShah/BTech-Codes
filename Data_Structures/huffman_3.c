#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HUFFMAN
{
    char data;
    int freq,code[50],lenght;
    struct HUFFMAN *left,*right;
};
typedef struct HUFFMAN node;

struct linklist
{
    node *huffman;
    struct linklist *next;
};
typedef struct linklist link;

node *root=NULL,*queue[100];
link *head=NULL;
int count = 0,front = 0,rear = -1;

void addq(node *a)
{
    queue[++rear] = a;
}

node* delq()
{
    return queue[front++];
}

node* createNode(char key,int f,node *l,node *r)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->data = key;
    temp->freq = f;
    temp->left = l;
    temp->right = r;

    return temp;
}
void levelwise(node *root)
{
    node *p=root,*temp;
    temp = createNode('-',-1,NULL,NULL);
    front = 0;
    rear = -1;

    addq(root);
    addq(NULL);
    while(front < rear)
    {
        p = delq();
        if(p == NULL)
        {
            addq(NULL);
            printf("\n");
        }
        else
        {
            if(p->data != temp->data)
               printf("%c",p->data);
            else
                printf("-1");
            if(p->data != temp->data)
            {
            if(p->left!=NULL)
                addq(p->left);
            else
                addq(temp);
            if(p->right!=NULL)
                addq(p->right);
            else
                addq(temp);
            }
        }
    }
}



void sort(node *p)
{
    link *new,*q;

    new = (link*)malloc(sizeof(link));
    new->huffman = p;
    new->next = NULL;

    if(head == NULL)
        head = new;
    else
    {
        if(new->huffman->freq  < head->huffman->freq)
        {
            new->next = head;
            head = new;
        }
        else
        {
            q = head;
            while(q->next!=NULL && new->huffman->freq >= q->next->huffman->freq)
                q = q->next;
            if(q->next == NULL)
                q->next = new;
            else
            {
                new->next = q->next;
                q->next = new;
            }
        }
    }
}

void insert(char key,int f,node *l,node *r)
{
    node *temp;
    temp = createNode(key,f,l,r);
    sort(temp);
    count++;
}

void display()
{
    link *q=head;
    printf("\nCharacter\tFrequency\n");
    while(q!=NULL)
    {
        printf("   %c\t\t   %d\n",q->huffman->data,q->huffman->freq);
        q = q->next;
    }
}

void accept()
{
    char key,choice;
    int f;

    do
    {
        printf("Enter the character = ");
        fflush(stdin);
        scanf("%c",&key);
        printf("Enter the frequency = ");
        scanf("%d",&f);
        insert(key,f,NULL,NULL);
        printf("Do you want to add more?(Press Y or y)");
        fflush(stdin);
        scanf("%c",&choice);
    }while(choice == 'y' || choice == 'Y');
}

node* join()
{
    node *l,*r,*temp;

    while(count != 1)
    {
        l = head->huffman;
        head = head->next;
        r = head->huffman;
        head = head->next;
        count -= 2;
        insert('$',(l->freq + r->freq),l,r);
    }
    temp = head->huffman;
    return temp;
}

void charcode(node *p,int arr[],int index)
{
    int i = 0;

    if(p->left==NULL && p->right==NULL)
    {
        printf("%c = ",p->data);
        for(i=0; i<index; i++)
        {
            p->code[i] = arr[i];
            printf("%d",p->code[i]);
        }

        p->lenght = index;
        printf("\n");
    }
    if(p->left!=NULL)
    {
        arr[index] = 0;
        charcode(p->left,arr,index+1);
    }
    if(p->right!=NULL)
    {
        arr[index] = 1;
        charcode(p->right,arr,index+1);
    }
}

void decode()
{
    char message[20];
    node *p=root;
    int i;

    printf("Enter code = ");
    fflush(stdin);
    gets(message);
    printf("\nMessage is = ");
    for(i=0; i<strlen(message); i++)
    {
        if(message[i] == '0')
            p=p->left;
        else
            p=p->right;
        if(p->left==NULL && p->right==NULL)
        {
            printf("%c",p->data);
            p = root;
        }
    }
}

void printcode(node *p,char a)
{
    int i;
    if(p!=NULL)
    {
        if(p->data == a)
        {
            for(i=0; i<p->lenght; i++)
                printf("%d",p->code[i]);
            printf(" ");
        }
        printcode(p->left,a);
        printcode(p->right,a);
    }
}

void encode()
{
    int i;
    char str[40];

    printf("Enter the string = ");
    fflush(stdin);
    gets(str);
    printf("\nCode for %s is = ",str);
    for(i=0; i<strlen(str); i++)
        printcode(root,str[i]);
}

int main()
{
    int choice,arr[50];

    do
    {
        system("cls");
        printf("1.Add new characters\n2.View Frequency Table\n3.Generate code for characters\n");
        printf("4.Generate code for strings\n5.Decode the code\n6.Exit\n\nYour choice = ");
        scanf("%d",&choice);
        printf("\n\n\n");
        switch(choice)
        {
            case 1 : accept();
                     break;

            case 2 : display();
                     break;

            case 3 : root = join();
                     printf("\nLevelwise Huffman Tree = \n");
                     levelwise(root);
                     printf("\n\n");
                     charcode(root,arr,0);
                     break;

            case 4 : encode();
                     break;

            case 5 : decode();
                     break;

            case 6 : exit(0);
        }
        printf("\n\n");
        system("pause");
    }while(1);

    return 0;
}
