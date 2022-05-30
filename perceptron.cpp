#include <stdio.h>
#include<conio.h>
int main(){
    int x[4][2],target[4];
    float w[2],wc[2];
    int i,j,k=0,h=1,out=0;
    float s=0,b=0,bc=0,alpha=0;
    float theta;
    int epoch=0;
    // clrscr();
    printf("Enter the value of theta and alpha: ");
    scanf("%f %f",&theta,&alpha);
    printf("Enter number of Epochs: ");
    scanf("%d",&epoch);
    for(i=0;i<4;i++)
    {
        // printf("Enter the value of %d Input row [x1,x2] and Target [y]: ",i);
        // scanf("%d %d %d",&x[i][0],&x[i][1],&target[i]);
        w[i]=0;
        wc[i]=0;
    }
    x[0][0]=1,x[0][1]=1,target[0]=1;
    x[1][0]=1,x[1][1]=0,target[1]=-1;
    x[2][0]=0,x[2][1]=1,target[2]=-1;
    x[3][0]=0,x[3][1]=0,target[3]=-1;
    b=0;
    bc=0;
    w[0]=0;
    w[1]=0;
    wc[0]=0;
    wc[1]=0;
    
    printf("\n Input \t\t Net \t Output \t Target \t weight change \t weight \n");
    printf("---------------------------------------------------------\n");
    mew:
        printf("Epoch %d\n",h++);
        printf("------------------------------------------------------\n");
        for(i=0;i<4;i++)
        {
            printf("[ ");
            for(j=0;j<2;j++)
            {
                printf("%d ",x[i][j]);
                s+=(float)x[i][j]*w[j];
            }
            printf("]\t\t");
            s+=b;
            printf("%.2f\t",s);
            if(s>theta)
                out = 1;
            else if(s<-theta)
                out = -1;
            else
                out = 0;
            printf("%d\t",out);
            printf("%d\t",target[i]);
            s=0;
            if(out==target[i])
            {
                printf("[");
                for(j=0;j<2;j++)
                {
                    wc[j]=0;
                    bc=0;
                    printf("%.2f ",wc[j]);
                }
                printf("%.2f ",bc);
                printf("]\t");
                printf("[");
                for(j=0;j<2;j++)
                {
                   printf("%.2f ",w[j]);
                }
                k+=1;
                b+=bc;
                printf("%.2f ",b);
                printf("]\t");
            }
            else
            {
                printf("[");
                for(j=0;j<2;j++)
                {
                    wc[j]=x[i][j]*target[i]*alpha;
                    w[j]+=wc[j];
                    printf("%.2f ",wc[j]);
                    wc[j]=0;
                    
                }
                bc=target[i]*alpha;
                b+=bc;
                printf("%.2f ",bc);
                printf("]\t");
                printf("[");
                for(j=0;j<=1;j++)
                {
                    printf("%.2f ",w[j]);
                    
                }  
                printf("%.2f\t",b);
                printf("]\t");
                
            }
            printf("\n");
            
        }
        printf("-----------------------------------------\n");
        printf("\n");
        if(h==epoch+1){
            printf("\n Final Weights \n");
            for(j=0;j<2;j++){
                printf("w[%d]=%.2f\t",j,w[j]);
            }
            printf("Bias b = %.2f",b);
        }
}
