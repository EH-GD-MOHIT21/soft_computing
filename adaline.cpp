#include <stdio.h>
#include<conio.h>
int main(){
    int x[4][2],tar[4];
    float wc[2],w[2],e=0,er=0,yin=0,alpha=0.2,b=0.2,bc=0,t=0;
    int i,j,k,q=1;
    for(i=0;i<4;i++)
        {
            // printf("Enter %d input and target: \n",i);
            // printf("----------------------------\n");
            for(j=0;j<2;j++)
            {
                // printf("Enter %c: ",'a'+j);
                // scanf("%d",&x[i][j]);
                w[i]=0.2;
                wc[i]=0;
            }
            // printf("Enter target: ");
            // scanf("%d",&(tar[i]));
            // printf("\n");       
        }
    x[0][0]=1,x[0][1]=1,tar[0]=1;
    x[1][0]=1,x[1][1]=-1,tar[1]=1;
    x[2][0]=-1,x[2][1]=1,tar[2]=1;
    x[3][0]=-1,x[3][1]=-1,tar[3]=-1;
    printf("\n Input \t\t Net \t Error \t Target \t weight change \t weight \n");
    printf("---------------------------------------------------------\n");
    mew:
        er=0,e=0;
        yin=0;
        printf("\n Epoch: %d\n",q);
        printf("------------------------------------------------------\n");
        for(i=0;i<4;i++)
        {
            t=tar[i];
            printf("[");
            for(j=0;j<2;j++)
            {
                yin = yin+x[i][j]*w[j];
                printf("%d ",x[i][j]);
            }
            printf("]\t\t");
            yin+=b;
            bc=0;
            printf("%0.2f\t",yin);
            e=(float)tar[i]-yin;
            er=er+e*e;
            yin=0;
            printf("%0.2f\t",e);
            printf("%d\t",tar[i]);
            printf("[");
            for(k=0;k<2;k++)
            {
                wc[k]=x[i][k]*e*alpha;
                printf("%0.2f ",wc[k]);
                w[k]+=wc[k];
            }
            bc=e*alpha;
            printf("%0.2f ",bc);
            printf("]\t");
            b=b+bc;
            printf("[");
            for(k=0;k<2;k++)
            {
                printf("%0.2f ",w[k]);
            }
            printf("%0.2f ",b);
            printf("]\t");        
        printf("\n");
        }
        printf("Error: %f",er);
        printf("\n-----------------------------------------\n");
        if(er<=1.0 || q>20)
        {
            printf("\n Final Weights \n");
                for(j=0;j<2;j++)
                {
                    printf("w[%d]=%.2f\t",j,w[j]);
                }
            printf("Bias b = %.2f",b);
        }
        else{
            e=0;
            er=0;
            yin=0;
            q=q+1;
            goto mew;
        }
    return 0;
}