// not working
#include<stdio.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))
struct SET
{
    char element;
    float val;
};
void intersection(struct SET *A, int a, struct SET *B, int b, struct SET *C, int n)
{
    int ptr = 0;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
        {
            if (A[i].element == B[j].element)
            {
                C[ptr].element = A[i].element;
                C[ptr].val = MIN(A[i].val, B[j].val);
                ptr++;
                break;
            }
        }
    while (ptr < n)
    {
        C[ptr].element = '\0';
        C[ptr].val = 0;
        ptr++;
    }
}
void complement(struct SET *U, struct SET *C, struct SET *t1, int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        int j = 0;
        while (t1[j].element != '\0' && j < n)
        {
            if (t1[j].element == U[i].element)
            {
                flag = 1;
                break;
            }
            j++;
        }
        if (flag == 0)
        {
            C[k].element = U[i].element;
            C[k].val = 1;
            k++;
        }
        else
        {
            C[k].element = U[i].element;
            C[k].val = 1 - t1[j].val;
            k++;
        }
    }
    while (k < n)
    {
        C[k].element = '\0';
        C[k].val = 0;
        k++;
    }
}
void union_(struct SET *C1, struct SET *C2, struct SET *t2, int n)
{
    int i = 0, j = 0, ptr = 0;
    int a = 0;
    int b = 0;
    while (C1[i].element != '\0' && i < n)
    {
        a++;
        i++;
    }
    i = 0;
    while (C2[i].element != '\0' && i < n)
    {
        b++;
        i++;
    }
    // printf("%d %d\n",a,b);
    int check1[a];
    int check2[b];
    for (int i = 0; i < a; i++)
        check1[i] = 0;
    for (int i = 0; i < b; i++)
        check2[i] = 0;
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            if (C1[i].element == C2[j].element)
            {
                check1[i] = 1;
                check2[j] = 1;
                t2[ptr].element = C1[i].element;
                t2[ptr].val = MAX(C1[i].val, C2[j].val);
                ptr++;
                break;
            }
        }
    }
    for (i = 0; i < a; i++)
    {
        // printf("%d ",check1[i]);
        if (check1[i] == 0)
        {
            t2[ptr].element = C1[i].element;
            t2[ptr].val = C1[i].val;
            ptr++;
        }
    }
    printf("\n");
    for (i = 0; i < b; i++)
    {
        // printf("%d ",check2[i]);
        if (check2[i] == 0)
        {
            t2[ptr].element = C2[i].element;
            t2[ptr].val = C2[i].val;
            ptr++;
        }
    }
    while (ptr < n)
    {
        t2[ptr].element = '\0';
        t2[ptr].val = 0;
        ptr++;
    }
}
