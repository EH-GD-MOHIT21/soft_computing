#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int ico = 0, ico1, it = 0;
long int pop[10][10], npop[10][10], tpop[10][10];
float x[10], fx[10], m_max = 1.0;
void iter(long int[10][10], int, int);
int u_rand(int);
void tour_sel(int, int);
void cross_ov(int, int);
void mutat(int, int);
int main()
{
    int k, m, j, i, p[10], n = 0, a[10], nit;
    printf("Enter the number of Population in each iteration is : ");
    scanf("%d",&n);
    printf("Enter the number of iteration is : ");
    scanf("%d",nit);
    m = 7;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            /*if (a[i]==0)
            pop[i][j]=0;
            else
            {*/
            if ((j == 0) || (j == 1))
                pop[i][j] = u_rand(2);
            if (j > 1)
                pop[i][j] = u_rand(10);
            // a[i]=a[i]/2;
            // }
        }
    }
    printf("\nIteration  %d is :\n",it);
    iter(pop, n, m);
    it++;
    
    do
    {
        it++;
        printf("\nIteration is %d:\n",it);
        tour_sel(n, m);
        iter(pop, n, m);
        
    } while (it < nit);
    printf("\n\nAfter the %d Iteration, the Maximum Value is %d: ",ico1,m_max);
    return 0;
}
void iter(long int pp[10][10], int o, int p)
{
    int i, j;
    float sum, avg, max = 1.0;
    for (i = 0; i < o; i++)
    {
        x[i] = 0;
        for (j = 1; j < p; j++)
        {
            if (j == 1)
                x[i] = x[i] + pp[i][j];
            if (j > 1)
                x[i] = x[i] + (pp[i][j] / pow(10, j - 1));
        }
        j = 0;
        if (pp[i][j] == 0)
            x[i] = -x[i];
        fx[i] = x[i] * sin(10 * 3.14 * x[i]) + 10;
        sum = sum + fx[i];
        if (max <= fx[i])
            max = fx[i];
    }
    avg = sum / o;
    printf("\n\nS.No.\tPopulation\tX\t\tf(X)\n\n");
    for (i = 0; i < o; i++)
    {
        printf("%d\t",ico);
        ico++;
        for (j = 0; j < p; j++)
            printf("%d",pp[i][j]);
        printf("%d %d",x[i],fx[i]);
    }
    printf("%d %f %d",sum,avg,max);
    if (m_max < max)
    {
        m_max = max;
        ico1 = it;
    }
}
int u_rand(int x)
{
    int y;
    y = rand() % x;
    return (y);
}
void tour_sel(int np, int mb)
{
    int i, j, k, l, co = 0, cc;
    // time_t t;
    // srand((unsigned) time(&t));
    do
    {
        k = u_rand(np);
        do
        {
            cc = 0;
            l = u_rand(np);
            if (k == l)
                cc++;
        } while (cc != 0);
        if (fx[k] > fx[l])
        {
            for (j = 0; j < mb; j++)
                npop[co][j] = pop[k][j];
        }
        else if (fx[k] < fx[l])
        {
            for (j = 0; j < mb; j++)
                npop[co][j] = pop[l][j];
        }
        co++;
    } while (co < np);
    
    cross_ov(np, mb);
    
}
void cross_ov(int np1, int mb1)
{
    int i, j, k, l, co, temp;
    // time_t t;
    // srand((unsigned) time(&t));
    i = 0;
    do
    {
        k = rand() % 2;
        do
        {
            co = 0;
            l = u_rand(mb1);
            if (((k == 0) && (l == 0)) || ((k == 1) && (l == mb1)))
                co++;
        } while (co != 0);
        if ((k == 0) && (l != 0))
        {
            for (j = 0; j < l; j++)
            {
                temp = npop[i][j];
                npop[i][j] = npop[i + 1][j];
                npop[i + 1][j] = temp;
            }
        }
        else if ((k == 1) && (l != mb1))
        {
            for (j = l; j < mb1; j++)
            {
                temp = npop[i][j];
                npop[i][j] = npop[i + 1][j];
                npop[i + 1][j] = temp;
            }
        }
        i = i + 2;
    } while (i < np1);
    for (i = 0; i < np1; i++)
    {
        for (j = 0; j < mb1; j++)
        {
            tpop[i][j] = npop[i][j];
            // pop[i][j]=tpop[i][j];
        }
    }
    mutat(np1, mb1);
}
void mutat(int np2, int mb2)
{
    int i, j, r, temp, k, z;
    i = 0;
    do
    {
        for (k = 0; k < np2; k++)
        {
            r = 0;
            if (i != k)
            {
                for (j = 0; j < mb2; j++)
                {
                    if (tpop[i][j] == tpop[k][j])
                        r++;
                }
                if (r != mb2 - 1)
                {
                    z = u_rand(mb2);
                    if ((tpop[i][z] == 0) && ((z == 0) || (z == 1)))
                        tpop[i][z] = u_rand(2);
                    else if ((tpop[i][z] != 0) && ((z == 0) || (z == 1)))
                        tpop[i][z] = u_rand(2);
                    else
                        tpop[i][z] = u_rand(10);
                    if ((npop[k][u_rand(mb2)] == 0) && ((z == 0) || (z == 1)))
                        npop[k][u_rand(mb2)] = u_rand(2);
                    else if ((npop[k][u_rand(mb2)] != 0) && ((z == 0) || (z == 1)))
                        npop[k][u_rand(mb2)] = u_rand(2);
                    else
                        npop[k][u_rand(mb2)] = u_rand(10);
                    mutat(k, mb2);
                }
            }
        }
        i++;
    } while (i < np2);
    for (i = 0; i < np2; i++)
    {
        for (j = 0; j < mb2; j++)
        {
            pop[i][j] = tpop[i][j];
        }
    }
}