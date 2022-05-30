#include<stdio.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))
void intersection(char *A, int a, char *B, int b, char *C, int n)
{
    int ptr = 0;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
        {
            if (A[i] == B[j])
                C[ptr++] = A[i];
        }
    while (ptr < n)
    {
        C[ptr] = '\0';
        ptr++;
    }
}
void complement(char *U, char *C, char *t1, int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        int j = 0;
        while (t1[j] != '\0' && j < n)
        {
            if (t1[j] == U[i])
            {
                flag = 1;
                break;
            }
            j++;
        }
        if (flag == 0)
        {
            C[k] = U[i];
            k++;
        }
    }
    while (k < n)
    {
        C[k] = '\0';
        k++;
    }
}
void union_(char *C1, char *C2, char *t2, int n)
{
    int i = 0, j = 0, ptr = 0;
    int a = 0;
    int b = 0;
    while (C1[i] != '\0')
    {
        a++;
        i++;
    }
    i = 0;
    while (C2[i] != '\0')
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
            if (C1[i] == C2[j])
            {
                check1[i] = 1;
                check2[j] = 1;
                t2[ptr] = C1[i];
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
            t2[ptr] = C1[i];
            ptr++;
        }
    }
    printf("\n");
    for (i = 0; i < b; i++)
    {
        // printf("%d ",check2[i]);
        if (check2[i] == 0)
        {
            t2[ptr] = C2[i];
            ptr++;
        }
    }
    while (ptr < n)
    {
        t2[ptr] = '\0';
        ptr++;
    }
}
int main()
{
    int a, b, c, in, ptr = 0, n = 0;
    char ret;
    printf("Enter size of Universal Set: ");
    scanf(" %d", &n);
    printf("Enter size of Set A: ");
    scanf(" %d", &a);
    printf("Enter size of Set B: ");
    scanf(" %d", &b);
    printf("Enter size of Set C: ");
    scanf(" %d", &c);
    char U[n];
    char A[a];
    char B[b];
    char D[c];
    char C[a + b];
    int check1[a];
    int check2[b];
    // memset(check1,0,a*sizeof(int));
    // memset(check2,0,b*sizeof(int));
    printf("Enter Universal set: \n");
    for (int i = 0; i < n; i++)
    {
        char x = 'a';
        printf("Enter %dst element: ", i + 1);
        scanf(" %c", &x);
        U[i] = x;
    }
    printf("Enter Set A: \n");
    for (int i = 0; i < a; i++)
    {
        char x = 'a';
        check1[i] = 0;
        printf("Enter %dst element: ", i + 1);
        scanf(" %c", &x);
        A[i] = x;
    }
    printf("Enter Set B: \n");
    for (int i = 0; i < b; i++)
    {
        char x = 'a';
        check2[i] = 0;
        printf("Enter %dst element: ", i + 1);
        scanf(" %c", &x);
        B[i] = x;
    }
    printf("Enter Set C: \n");
    for (int i = 0; i < c; i++)
    {
        char x = 'a';
        printf("Enter %dst element: ", i + 1);
        scanf(" %c", &x);
        D[i] = x;
    }

    do
    {
        printf("\n~*~*~*~*~*~*~*~*~*~*~* MENU ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n");
        printf("1. DeMorgan's Law ~(A ^ B) = ~A U ~B\n");
        printf("2. Associative Law (A ^ B)^C = A^(B ^ C)\n");
        printf("3. Dstributive Law A ^ (B U C) = (A ^ B) U (A ^ C) \n");
        printf("4. Commutative ~B\n");
        printf("5. Exit\n");
        printf("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n");
        scanf("%d", &in);
        char t1[n];
        char C[n];
        char C1[n];
        char C2[n];
        char t2[n];
        char t3[n];
        char t4[n];
        int ptr = 0;
        switch (in)
        {
        case 1:
            // DeMorgan's Law
            for (int i = 0; i < n; i++)
            {
                t1[i] = '\0';
                t2[i] = '\0';
                t4[i] = '\0';
                C[i] = '\0';
                C1[i] = '\0';
                C2[i] = '\0';
            }
            printf("Proof: \n");
            printf("A: {");
            for (int i = 0; i < a; i++)
            {
                printf("%c ", A[i]);
                if (i != a - 1)
                    printf(",");
            }
            printf("}\n");
            printf("B: {");
            for (int i = 0; i < b; i++)
            {
                printf("%c ", B[i]);
                if (i != b - 1)
                    printf(",");
            }
            printf("}\n");
            printf("LHS: \n");
            printf("(A ^ B): ");
            intersection(A, a, B, b, t1, n);
            printf("{ ");
            for (int i = 0; i < n; i++)
            {
                printf(" %c", t1[i]);
            }
            printf("}\n");
            printf("~(A ^ B): ");
            complement(U, C, t1, n);
            printf("{ ");
            for (int i = 0; i < n; i++)
            {
                printf(" %c", C[i]);
            }
            printf("}\n");
            printf("RHS: \n");
            complement(U, C1, A, n);
            printf("~A: {");
            for (int i = 0; i < n; i++)
            {
                printf("%c ", C1[i]);
            }
            printf("}\n");
            complement(U, C2, B, n);
            printf("~B: {");
            for (int i = 0; i < n; i++)
            {
                printf("%c ", C2[i]);
            }
            printf("}\n");
            union_(C1, C2, t2, n);
            printf("~A U ~B: {");
            for (int i = 0; i < n; i++)
            {
                printf("%c ", t2[i]);
            }
            printf("}\n");
            break;
        case 2:
            // Associative Law
            for (int i = 0; i < n; i++)
            {
                t1[i] = '\0';
                t2[i] = '\0';
                C[i] = '\0';
                C1[i] = '\0';
                C2[i] = '\0';
            }
            printf("Proof: \n");
            printf("(A ^ B): {");
            intersection(A, a, B, b, t1, n);
            for (int i = 0; i < n; i++)
            {
                printf("%c ", t1[i]);
            }
            printf("}\n");
            int x = 0;
            while (t1[x] != '\0')
                x++;
            printf("(A ^ B)^C: {");
            intersection(D, c, t1, x, t2, n);
            for (int i = 0; i < n; i++)
            {
                printf("%c ", t2[i]);
            }
            printf("}\n");
            printf("RHS: \n");
            intersection(B, b, D, c, t1, n);
            printf("(B ^ C): {");
            for (int i = 0; i < n; i++)
            {
                printf("%c ", t1[i]);
            }
            printf("}\n");
            while (t1[x] != '\0')
                x++;
            intersection(A, a, t1, x, t3, n);
            printf("A^(B ^ C): {");
            for (int i = 0; i < n; i++)
            {
                printf("%c ", t3[i]);
            }
            printf("}\n");

            break;
        case 3:
            // Distributive Law
            for (int i = 0; i < n; i++)
            {
                t1[i] = '\0';
                t2[i] = '\0';
                t4[i] = '\0';
                C[i] = '\0';
                C1[i] = '\0';
                C2[i] = '\0';
            }
            printf("Proof: \n");
            printf("LHS: \n");
            printf("(B U C): {");
            union_(B, D, t1, n);
            x = 0;
            while (t1[x] != '\0')
                x++;
            for (int i = 0; i < x; i++)
                printf("%c ", t1[i]);
            printf("}\n");
            printf("A ^ (B U C): {");
            intersection(A, a, t1, x, t2, n);
            for (int i = 0; i < n; i++)
            {
                printf("%c ", t2[i]);
            }
            printf("}\n");
            printf("RHS: \n");
            printf("(A ^ B): ");
            intersection(A, a, B, b, t1, n);
            printf("{ ");
            for (int i = 0; i < n; i++)
            {
                printf("%c ", t1[i]);
            }
            printf("}\n");
            intersection(A, a, D, c, t3, n);
            printf("(A ^ C): ");
            printf("{ ");
            for (int i = 0; i < n; i++)
            {
                printf("%c ", t3[i]);
            }
            printf("}\n");
            union_(t1, t3, t4, n);
            printf("(A ^ B) U (A ^ C): ");
            printf("{ ");
            for (int i = 0; i < n; i++)
            {
                printf("%c ", t4[i]);
            }
            printf("}\n");
            break;
        case 4:
            for (int i = 0; i < n; i++)
            {
                t1[i] = '\0';
                t2[i] = '\0';
                t4[i] = '\0';
                C[i] = '\0';
                C1[i] = '\0';
                C2[i] = '\0';
            }
            printf("Proof: \n");
            printf("LHS: \n");
            intersection(A, a, B, b, t1, n);
            printf("(A ^ B): ");
            printf("{ ");
            for (int i = 0; i < n; i++)
            {
                printf("%c ", t1[i]);
            }
            printf("}\n");
            intersection(B, b, A, a, t2, n);
            printf("(B ^ A): ");
            printf("{ ");
            for (int i = 0; i < n; i++)
            {
                printf("%c ", t2[i]);
            }
            printf("}\n");
            break;
        case 5:
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
