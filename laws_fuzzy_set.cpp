#include <stdio.h>
#include <conio.h>

int main()
{
    int i, k = 1, ch, count = 0, x;
    float A[5], B[5], alpha, height, height2;
    printf("\n Enter the values of membership function for set A \n");

    for (i = 0; i < 5; i++)
    {
        printf("\n %d \t", i);
        scanf("\t %f", &A[i]);
    }
    printf("\n Enter the values of membership function for set B \n");

    for (i = 0; i < 5; i++)
    {
        printf("\n %d \t", i);
        scanf("\t %f", &B[i]);
    }
k:
    printf("\n Enter your choice\n\n 1. Membership function and elements. \n 2. Support of fuzzy set. \n 3. Singleton fuzzy set. \n 4. Alpha Cut. \n 5. Crossover point. \n 6. Union of A and B. \n 7. Intersection of A and B. \n 8. Degree of equality. \n 9. SubsetHood. \n 10. Height of fuzzy set.\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
    {
        printf("\n The mf and elements of fuzzy set A is \n");
        for (i = 0; i < 5; i++)
        {
            printf("%d \t %5.2f \n", i, A[i]);
        }
        printf("\n\n The mf and elements of fuzzy set B is \n");
        for (i = 0; i < 5; i++)
        {
            printf("%d \t %5.2f \n", i, B[i]);
        }
        break;
    }

    case 2:
        printf("\n The support of fuzzy set A is");
        for (i = 0; i < 5; i++)
        {
            if (A[i] > 0.0)
            {
                printf("\n %d", i);
            }
        }
        printf("\n The support of fuzzy set B is");
        for (i = 0; i < 5; i++)
        {
            if (B[i] > 0.0)
            {
                printf("\n %d", i);
            }
        }
        break;

    case 3:
        printf("\n The Singleton of fuzzy set A is");
        for (i = 0; i < 5; i++)
        {
            if (A[i] == 1.0)
            {
                printf("\n %d", i);
                count++;
            }
        }
        if (count == 0)
        {
            printf(" NIL");
        }
        count = 0;
        printf("\n The Singleton of fuzzy set B is");
        for (i = 0; i < 5; i++)
        {
            if (B[i] == 1.0)
            {
                printf("\n %d", i);
                count++;
            }
        }
        if (count == 0)
        {
            printf("  NIL");
        }
        break;

    case 4:
        printf("\n Enter the alpha value\n");
        scanf("%f", &alpha);
        printf("\n Alpha cut values for set A are \n{");
        for (i = 0; i < 5; i++)
        {
            if (A[i] >= alpha)
            {
                printf("  %5.2f,", A[i]);
            }
        }
        printf("}\n");
        printf("\n\n Alpha cut value for set B is\n{");
        for (i = 0; i < 5; i++)
        {
            if (B[i] >= alpha)
            {
                printf("  %5.2f,", B[i]);
            }
        }
        printf("}\n");
        break;

    case 5:
        for (i = 0; i < 5; i++)
        {
            if (A[i] == 0.5)
            {
                printf("\nCrossover point for A \t %d", i);
                count++;
            }
        }
        if (count == 0)
        {
            printf("\nNo crossover point for A");
        }
        count = 0;
        for (i = 0; i < 5; i++)
        {
            if (B[i] == 0.5)
            {
                printf("\nCrossover point for B \t %d", i);
                count++;
            }
        }
        if (count == 0)
        {
            printf("\nNo crossover point for B");
        }
        break;

    case 6:
        printf("\n The Union of A and B is ");
        for (i = 0; i < 5; i++)
        {
            if (A[i] >= B[i])
            {
                printf("\n %d \t \t %f", i, A[i]);
            }
            else
            {
                printf("\n %d \t \t %f", i, B[i]);
            }
        }
        break;

    case 7:
        printf("\n The intersection of sets A and B is ");
        for (i = 0; i < 5; i++)
        {
            if (A[i] >= B[i])
            {
                printf("\n %d \t \t %f", i, B[i]);
            }
            else
            {
                printf("\n %d \t \t %f", i, A[i]);
            }
        }
        break;

    case 8:
        count = 0;
        for (i = 0; i < 5; i++)
        {
            if (A[i] == B[i])
            {
                count++;
            }
        }
        if (count == 5)
            printf("\n Equality between set A and B verified");
        else
            printf("\n Non Equality between sets A and B found");
        break;

    case 9:
        for (i = 0; i < 5; i++)
        {
            if (A[i] < B[i])
            {
                count++;
                x++;
            }
        }
        if (count == 5)
        {
            printf("\n Set A is subset of set B");
        }
        count = 0;

        for (i = 0; i < 5; i++)
        {
            if (A[i] > B[i])
            {
                count++;
            }
        }
        if (count == 5)
        {
            printf("\n Set B is subset of set A");
        }

        if (count < 5 || x < 5)
            printf("\n No subset found");
        break;

    case 10:
        printf("\n \nThe height of fuzzy set A is");
        for (i = 0; i < 4; i++)
        {
            if (A[i] > A[i + 1])
            {
                height = A[i];
            }
            else
            {
                height = A[i + 1];
            }

            if (B[i] > B[i + 1])
            {
                height2 = B[i];
            }
            else
            {
                height2 = B[i + 1];
            }
        }

        printf("\n %f", height);
        printf("\n\n The height of fuzzy set B is");
        printf("\n %f", height2);
        break;

    default:
        printf("\n Enter correct choice");
        break;
    }
    x = 1;
    printf("\n Do you want to continue ???\t (0/1)\n");
    scanf("%d", &x);
    if (x == 1)
    {
        goto k;
    }

    getch();
    return 0;
}