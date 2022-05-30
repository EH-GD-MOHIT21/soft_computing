#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))
int main()
{
    int a,b,in,ptr=0,n=0;
    char ret;
    printf("Enter size of Universal Set: ");
    scanf(" %d",&n);
    printf("Enter size of Set A: ");
    scanf(" %d",&a);
    printf("Enter size of Set B: ");
    scanf(" %d",&b);
    char U[n];
    char A[a];
    char B[b];
    char C[a+b];
    int check1[a];
    int check2[b];
    // memset(check1,0,a*sizeof(int));
    // memset(check2,0,b*sizeof(int));
    printf("Enter Universal set: \n");
    for(int i=0;i<n;i++)
    {
        char x='a';
        printf("Enter %dst element: ",i+1);
        scanf(" %c",&x);
        U[i]= x;
    }
    printf("Enter Set A: \n");
    for(int i=0;i<a;i++)
    {
        char x='a';
        check1[i]=0;
        printf("Enter %dst element: ",i+1);
        scanf(" %c",&x);
        A[i]= x;
    }
    printf("Enter Set B: \n");
    for(int i=0;i<b;i++)
    {
        char x='a';
        check2[i]=0;
        printf("Enter %dst element Label and value: ",i+1);
        scanf(" %c",&x);
        B[i]=x;
    }
    
    do{
        printf("\n~*~*~*~*~*~*~*~*~*~*~* MENU ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n");
        printf("1. Union A U B\n");
        printf("2. Intersection A ^ B\n");
        printf("3. Complement(A) ~A\n");
        printf("4. Complement(B) ~B\n");
        printf("5. Print A, B\n");
        printf("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n");
        scanf("%d",&in);
        switch(in)
        {
         case 1:
                ptr=0;
                for(int i=0;i<a;i++){
                    for(int j=0;j<b;j++)
                    {
                        if(A[i] == B[j]){
                            check1[i]=1;
                            check2[j]=1;
                            C[ptr]=A[i];
                            ptr++;
                            }
                    }
                }
                for(int i=0;i<a;i++)
                {
                    if(check1[i]==0)
                        {
                            C[ptr]=A[i];
                            ptr++;
                        }
                }
                for(int i=0;i<b;i++)
                {
                    if(check2[i]==0)
                        {
                            C[ptr] = B[i];
                            ptr++;
                        }
                }
                printf("Union A U B: ");
                printf("{ ");
                for(int i=0;i<ptr;i++)
                {
                    printf(" %c",C[i]);
                        if(i!=ptr-1)
                            printf(" , ");
                }
                printf("}\n");
                break;
            case 2:
                ptr=0;
                for(int i=0;i<a;i++){
                    for(int j=0;j<b;j++)
                    {
                        if(A[i] == B[j]){
                            C[ptr]=A[i];
                            ptr++;
                            }
                    }
                }
                printf("Intersection A ^ B: ");
                printf("{ ");
                for(int i=0;i<ptr;i++)
                {
                    printf("%c",C[i]);
                        if(i!=ptr-1)
                            printf(" , ");
                }
                printf("}\n");
                break;
            case 3:
                printf("Complement(A) ~A: { ");
                for(int j=0;j<n;j++){   
                    int flag=0;
                    for(int i=0;i<a;i++)
                        {
                            if(U[j]==A[i])
                            {
                                flag=1;
                                break;
                            }
                        }
                        if(flag==0)
                        {
                            
                            printf("%c",U[j]);
                            if(j!=n-1)
                                printf(" , ");
                        }
                    }
                printf("}\n");
                break;
            case 4:
                printf("Complement(B) ~B: { ");
                for(int j=0;j<n;j++){   
                    int flag=0;
                    for(int i=0;i<b;i++)
                        {
                            if(U[j]==B[i])
                            {
                                flag=1;
                                break;
                            }
                        }
                        if(flag==0)
                        {
                            
                            printf("%c",U[j]);
                            if(j!=n-1)
                                printf(" , ");
                        }
                    }
                printf("}\n");
                break;
            case 5: 

                printf("A: { ");
                for(int i=0;i<a;i++)
                    {
                        printf("%c",A[i]);
                        if(i!=a-1)
                            printf(" , ");
                    }
                printf("}\n");
                printf("B: { ");
                for(int i=0;i<b;i++)
                    {
                        printf("%c",B[i]);
                        if(i!=b-1)
                            printf(" , ");
                    }
                printf("}\n");
                break;
            default:
                break;
                printf("}");
        }
    printf("Do you want to exit? Press 'q' : ");
    scanf(" %c",&ret);
    }
    while(ret!='q');
    return 0;
}