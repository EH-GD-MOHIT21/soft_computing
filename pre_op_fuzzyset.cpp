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
    int a, b, in, ptr = 0;
    char ret;
    printf("Enter size of Set A: ");
    scanf(" %d", &a);
    printf("Enter size of Set B: ");
    scanf(" %d", &b);
    struct SET A[a];
    struct SET B[b];
    struct SET C[a + b];
    int check1[a];
    int check2[b];
    // memset(check1,0,a*sizeof(int));
    // memset(check2,0,b*sizeof(int));

    printf("Enter Set A: \n");
    for (int i = 0; i < a; i++)
    {
        char x = 'a';
        float y = 0.0;
        check1[i] = 0;
        printf("Enter %dst element Label and value: ", i + 1);
        scanf(" %c %f", &x, &y);
        A[i].element = x;
        A[i].val = y;
    }
    printf("Enter Set B: \n");
    for (int i = 0; i < b; i++)
    {
        char x = 'a';
        float y = 0.0;
        check2[i] = 0;
        printf("Enter %dst element Label and value: ", i + 1);
        scanf(" %c %f", &x, &y);
        B[i].element = x;
        B[i].val = y;
    }

    do
    {
        printf("\n~*~*~*~*~*~*~*~*~*~*~* MENU ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n");
        printf("1. Union A U B\n");
        printf("2. Intersection A ^ B\n");
        printf("3. Complement(A) ~A\n");
        printf("4. Complement(B) ~B\n");
        printf("5. Print A, B\n");
        printf("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n");
        scanf("%d", &in);
        switch (in)
        {
        case 1:
            ptr = 0;
            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < b; j++)
                {
                    if (A[i].element == B[j].element)
                    {
                        check1[i] = 1;
                        check2[j] = 1;
                        C[ptr].element = A[i].element;
                        C[ptr].val = MAX(A[i].val, B[j].val);
                        ptr++;
                    }
                }
            }
            for (int i = 0; i < a; i++)
            {
                if (check1[i] == 0)
                {
                    C[ptr].element = A[i].element;
                    C[ptr].val = A[i].val;
                    ptr++;
                }
            }
            for (int i = 0; i < b; i++)
            {
                if (check2[i] == 0)
                {
                    C[ptr].element = B[i].element;
                    C[ptr].val = B[i].val;
                    ptr++;
                }
            }
            printf("Union A U B: ");
            printf("{ ");
            for (int i = 0; i < ptr; i++)
            {
                printf("%c : %0.2f", C[i].element, C[i].val);
                if (i != ptr - 1)
                    printf(" , ");
            }
            printf("}\n");
            break;
        case 2:
            ptr = 0;
            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < b; j++)
                {
                    if (A[i].element == B[j].element)
                    {
                        C[ptr].element = A[i].element;
                        C[ptr].val = MIN(A[i].val, B[j].val);
                        ptr++;
                    }
                }
            }
            printf("Intersection A ^ B: ");
            printf("{ ");
            for (int i = 0; i < ptr; i++)
            {
                printf("%c : %0.2f", C[i].element, C[i].val);
                if (i != ptr - 1)
                    printf(" , ");
            }
            printf("}\n");
            break;
        case 3:
            printf("Complement(A) ~A: { ");
            for (int i = 0; i < a; i++)
            {
                printf("%c : %0.2f", A[i].element, 1 - A[i].val);
                if (i != a - 1)
                    printf(" , ");
            }
            printf("}\n");
            break;
        case 4:
            printf("Complement(B) ~B: { ");
            for (int i = 0; i < a; i++)
            {
                printf("%c : %0.2f", B[i].element, 1 - B[i].val);
                if (i != a - 1)
                    printf(" , ");
            }
            printf("}\n");
            break;
        case 5:

            printf("A: { ");
            for (int i = 0; i < a; i++)
            {
                printf("%c : %0.2f", A[i].element, A[i].val);
                if (i != a - 1)
                    printf(" , ");
            }
            printf("}\n");
            printf("B: { ");
            for (int i = 0; i < b; i++)
            {
                printf("%c : %0.2f", B[i].element, B[i].val);
                if (i != b - 1)
                    printf(" , ");
            }
            printf("}\n");
            break;
        default:
            break;
            printf("}");
        }
        printf("Do you want to exit? Press 'q' : ");
        scanf(" %c", &ret);
    } while (ret != 'q');
    return 0;
}