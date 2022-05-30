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
    int a,b,in,ptr=0,n=0;
    char ret;
    printf("Enter size of Set U: ");
    scanf(" %d",&n);
    printf("Enter size of Set A: ");
    scanf(" %d",&a);
    printf("Enter size of Set B: ");
    scanf(" %d",&b);
    struct SET U[n];
    struct SET A[n];
    struct SET B[n];
    float cartisian[n][n];
    // memset(check1,0,a*sizeof(int));
    // memset(check2,0,b*sizeof(int));
    printf("Enter Set U: \n");
    for(int i=0;i<n;i++)
    {
        char x='a';
        float y=0.0;
        printf("Enter %dst element Label and value: ",i+1);
        scanf(" %c %f",&x,&y);
        U[i].element = x;
        U[i].val = y;
    }
    printf("Enter Set A: \n");
    for(int i=0;i<n;i++)
    {
        char x='a';
        float y=0.0;
        printf("Enter value of label %c: ",U[i].element);
        scanf(" %f",&y);
        A[i].element = U[i].element;
        A[i].val = y;
    }
    printf("Enter Set B: \n");
    for(int i=0;i<n;i++)
    {
        char x='a';
        float y=0.0;
        printf("Enter value of label %c: ",U[i].element);
        scanf(" %f",&y);
        A[i].element = U[i].element;
        B[i].val = y;
    }
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cartisian[i][j]=MIN(A[i].val,B[j].val);
                // printf("%f ",cartisian[i][j]);
            }
        }
    printf("\t");
    for(int i=0;i<n;i++)
    {
        printf("%c\t",U[i].element);
    }
    printf("\n   ------------------------");
    printf("\n");
    for(int i=0;i<n;i++)
        {
            printf("%c |\t",U[i].element);
            for(int j=0;j<n;j++)
            {
                printf("%0.2f\t",cartisian[i][j]);
            }
            printf("\n");
        }
    
    return 0;
}



