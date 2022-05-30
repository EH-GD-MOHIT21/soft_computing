#include<stdio.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))

struct SET
{
    char element;
    float val;
};

int main()
{
    int a,b,c,in,ptr=0,n=0;
    char ret;
    // printf("Enter size of Set U: ");
    // scanf(" %d",&n);
    printf("Enter size of Set A: ");
    scanf(" %d",&a);
    printf("Enter size of Set B: ");
    scanf(" %d",&b);
    printf("Enter size of Set C: ");
    scanf(" %d",&c);
    struct SET U[n];
    struct SET A[n];
    struct SET B[n];
    struct SET C[n];
    // float R1[n][n],R2[n][n];
    // memset(check1,0,a*sizeof(int));
    // memset(check2,0,b*sizeof(int));
    // printf("Enter Set U: \n");
    // for(int i=0;i<n;i++)
    // {
    //     char x='a';
    //     float y=0.0;
    //     printf("Enter %dst element Label and value: ",i+1);
    //     scanf(" %c %f",&x,&y);
    //     U[i].element = x;
    //     U[i].val = y;
    // }
    printf("Enter Set A: \n");
    for(int i=0;i<a;i++)
    {
        char x='a';
        float y=0.0;
        printf("Enter element: ");
        scanf(" %c",&x);
        A[i].element = x;
        A[i].val = y;
    }
    printf("Enter Set B: \n");
    for(int i=0;i<b;i++)
    {
        char x='a';
        float y=0.0;
        printf("Enter element and value of label: ");
        scanf(" %c",&x);
        B[i].element = x;
        B[i].val = y;
    }
    printf("Enter Set C: \n");
    for(int i=0;i<c;i++)
    {
        char x='a';
        float y=0.0;
        printf("Enter element and value of label: ");
        scanf(" %c",&x);
        C[i].element = x;
        C[i].val = y;
    }
    float R1[a][b];
    float R2[b][c];
    float R[a][c];
    printf("Enter Relation R1: \n");
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            float y=0.0;
            printf("Enter relation b/w (%c,%c): ",A[i].element,B[j].element);
            scanf(" %f",&y);
            R1[i][j]=y;
        }
    }
    printf("Enter Relation R2: \n");
    for(int i=0;i<b;i++)
    {
        for(int j=0;j<c;j++)
        {
            float y=0.0;
            printf("Enter relation b/w (%c,%c): ",B[i].element,C[j].element);
            scanf(" %f",&y);
            R2[i][j]=y;
        }
    }
    for(int i=0;i<a;i++)
        {
            for(int j=0;j<c;j++)
            {
                float temp=0;
                for(int k=0;k<b;k++)
                {
                    temp=MAX(temp,MIN(R1[i][k],R2[k][j]));
                }
                R[i][j]=temp;
            }
        }
    printf("\t");
    for(int i=0;i<c;i++)
    {
        printf("%c\t",C[i].element);
    }
    printf("\n   ------------------------");
    printf("\n");
    for(int i=0;i<a;i++)
        {
            printf("%c |\t",A[i].element);
            for(int j=0;j<c;j++)
            {
                printf("%0.2f\t",R[i][j]);
            }
            printf("\n");
        }
    
    return 0;
}

