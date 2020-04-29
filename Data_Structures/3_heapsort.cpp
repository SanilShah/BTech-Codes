/*
    C Program to sort an array using heap sort algorithm(MAX)
    Roll NO.41
 */
#include<stdio.h>
#include<conio.h>

int main()
{
    int heap[10], no, i, j, c, root, temp;
    printf("\t*** Heap Sort (MAX heap) ***\n");
    printf("\nEnter no of elements :");
    scanf("%d", &no);
    printf("\nEnter the nos :\n");
    for (i = 0; i < no; i++)
       scanf("%d", &heap[i]);
    printf("/*From root to last leaf node.*/\n");
    for (i = 1; i < no; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;
            if (heap[root] < heap[c])   // to create MAX heap array
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }

    printf("Heap array : ");
    for (i = 0; i < no; i++)
        printf("%d\t", heap[i]);
    printf("\n");
    for (j = no - 1; j >= 0; j--)
    {
        temp = heap[0];
        heap[0] = heap[j];    // swap max element with rightmost leaf element
        heap[j] = temp;
        root = 0;
        do
        {
            c = 2 * root + 1;
            if ((heap[c] < heap[c + 1]) && c < j-1)
                c++;
            if (heap[root]<heap[c] && c<j)
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            printf("           : ");
            for (i = 0; i < no; i++)
                printf("%d\t", heap[i]);
            printf("\n");
            root = c;
        } while (c < j);
    }
    printf("\nSorted array : ");
    for (i = 0; i < no; i++)
       printf("\t%d", heap[i]);
    printf("\n\n");
    return 0;
}
