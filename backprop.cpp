#include <stdio.h>
#include<conio.h>
#include<math.h>
float bipolar_sigmoid(float x){
    return (1-exp(-x))/(1+exp(-x));
}

int main()
{
    int x[4][2],tar[4];
    float v[2][2],b[3],a;
    float vc[2][2],w[2],wc[2],alpha=0.2,er,er_sum,yin,y,dy,dz[2],z[2],zin[2],bc[2];
    float delin[2],del[2];
    int i,j,k,epoch=100;
    x[0][0]=1,x[0][1]=1,tar[0]=-1;
    x[1][0]=1,x[1][1]=-1,tar[1]=1;
    x[2][0]=-1,x[2][1]=1,tar[2]=1;
    x[3][0]=-1,x[3][1]=-1,tar[3]=-1;
    
    v[0][0]=0.6;
    v[1][0]=-0.1;
    v[0][1]=-0.3;
    v[1][1]=0.4;
    w[0]=0.4;
    w[1]=0.1;
    b[0]=0.3;
    b[1]=0.5;
    b[2]=-0.2;    
    printf("-------------------------------------------------------------------------\n");
    epoch=1;
    while(1)
    {
        printf("Epoch %d: ",epoch++);
        er=0;
        er_sum=0;
        for(i=0;i<=3;i++)
        {
            k=0;
            do{
                zin[k]=0;
                for(j=0;j<=1;j++)
                {
                    zin[k]+=x[i][j]*v[j][k];
                }
                zin[k]+=b[k];
                k+=1;
            }while(k<=1);
            for(j=0;j<=1;j++)
            {
                z[j]=bipolar_sigmoid(zin[j]);
                dz[j]=0.5*((1+z[j])*(1-z[j]));
            }
            yin=0;
            for(j=0;j<=1;j++)
            {
                yin+=z[j]*w[j];
            }
            yin+=b[2];
            y=bipolar_sigmoid(yin);
            dy = ((1+y)*(1-y))*0.5;
            er = (tar[i]-y)*dy;
            er_sum += 0.25*((tar[i]-y)*(tar[i]-y));
            for(j=0;j<2;j++)
            {
                wc[j]=alpha*er*z[j];
                // w[j]+=wc[j];
                // wc[j]=0;
            }
            b[2]+=alpha*er;

            for(j=0;j<2;j++)
            {
                delin[j] = er * w[j];
                del[j] = delin[j] * dz[j];
                // bc[j] = alpha * del[j];
            }
            for(k=0;k<2;k++)
            {   for(j=0;j<2;j++)
                {
                    vc[j][k]=alpha*del[k]*x[i][j];
                    v[j][k]+=vc[j][k];
                    vc[j][k]=0;
                }
                bc[k]=alpha*del[k];
                b[k]+=bc[k];
                bc[k]=0;
            }
            for(j=0;j<2;j++)
            {
                // wc[j]=alpha*er*z[j];
                w[j]+=wc[j];
                wc[j]=0;
            }
            
        }
        printf("%f\n",er_sum);
        printf("%0.3f %0.3f %0.3f %0.3f %0.3f %0.3f\n",v[0][0],v[0][1],v[1][0],v[1][1],w[0],w[1]);
        if(er_sum<=1 ||epoch>1500)
            break;
    }
    printf("Final weights: \n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("V%d%d: %0.3f\n",i+1,j+1,v[i][j]);
        }
        printf("Bias%d:  %0.3f\n",i+1,b[i]);
    }
    for(j=0;j<2;j++)
    {
        printf("W%d%d: %f",j+1,1,w[j]);
    }
    printf("Bias: %f\n",b[2]);
    int inp1,inp2;
    printf("Prediction: \n");
    printf("Input x1,x2: ");
    scanf("%d %d",&inp1,&inp2);
    zin[0]=v[0][0]*inp1+v[1][0]*inp2+b[0];
    zin[1]=v[0][1]*inp1+v[1][1]*inp2+b[1];
    z[0]=bipolar_sigmoid(zin[0]);
    z[1]=bipolar_sigmoid(zin[1]);
    yin=z[0]*w[0]+z[1]*w[1]+b[2];
    // printf("%d",yin);
    y=bipolar_sigmoid(yin);
    printf("output: %0.2f\n",y);
    return 0;
}