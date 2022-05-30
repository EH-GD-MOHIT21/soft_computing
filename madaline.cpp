#include <stdio.h>
#include<conio.h>
// Pending positive net input??
int main()
{
    int x[4][2],tar[4];
    float w[2][2],a,o[2];
    float wc[2][2],zin[2],yin=0;
    float b[2],bc[2],alpha=0.5,er=0,b3=0.5,v1=0.5,v2=0.5,z1=0,z2=0;
    int i,j,c=0,in,d,epoch=1,y;
    x[0][0]=1,x[0][1]=1,tar[0]=-1;
    x[1][0]=1,x[1][1]=-1,tar[1]=1;
    x[2][0]=-1,x[2][1]=1,tar[2]=1;
    x[3][0]=-1,x[3][1]=-1,tar[3]=-1;
    /*for(i=0;i<4;i++)
        {
            printf("Enter x1,x2,target: ");
            scanf("%d %d %d",&x[i][0],&x[i][1],&tar[i]);
        }*/
    printf("Enter Weights: \n");
    for(i=0;i<2;i++)
        {
        for(j=0;j<2;j++)
        {
            printf("W%d%d: ",i+1,j+1);
            scanf("%f",&a);
            w[i][j]=a;
            wc[i][j]=0;
        }
        printf("Bias b%d: ",i+1);
        scanf("%f",&b[i]);
        zin[i]=0;
    }
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("Input\t\tzin1\t\tzin2\t\tyin\t\ty\t\tTarget\t\t w11\tw21\tb1\tw12\tw22\tb2\tError\n");
    printf("----------------------------------------------------------------------------------------------------\n");
    mew:
        printf("Epoch %d\n",epoch);
        printf("----------------------\n");
        er=0;
        for(i=0;i<=3;i++)
        {
            
            printf("[%d %d]\t\t",x[i][0],x[i][1]);
            for(in=0;in<=1;in++)
            {
                zin[in]=0;
                for(j=0;j<2;j++)
                {
                    zin[in]+=x[i][j]*w[j][in];
                }
                zin[in]+=b[in];
                printf("%f\t\t",zin[in]);
            }
            c=0;
            d=1;
            if(zin[c]>=0)
                z1=1;
            else
                z1=-1;
            if(zin[d]>=0)
                z2=1;
            else    
                z2=-1;
            yin = z1*v1+z2*v2+b3;
            printf("%.3f\t\t",yin);
            
            
            if(yin>=0)
                y=1;
            else
                y=-1;
            printf("%d\t\t",y);
            printf("%d\t\t",tar[i]);
            if(y==tar[i])
            {
                for(in=0;in<2;in++)
                {
                    for(j=0;j<=1;j++)
                    {
                        wc[in][j]=0;
                        w[in][j]+=wc[in][j];
                    }
                    bc[in]=0;
                }
                yin=0;
                
            }
            else{
                for(in=0;in<=1;in++)
                    {
                        o[in]=tar[i]-zin[in];
                        er+=o[in]*o[in];
                        // zin[in]=0;
                    }
                float zin1 =zin[0];
                float zin2 = zin[1];
                if(zin1<0)zin1*=-1;
                if(zin2<0)zin2*=-1;
                int fin[2];
                fin[0]=0;
                fin[1]=0;
                if(zin1<zin2)fin[0]=1;
                else fin[1]=1;
                for(in=0;in<2;in++)
                {
                    for(j=0;j<=1;j++)
                    {
                        wc[j][in]=alpha*o[in]*x[i][j];
                        // printf("wc%d%d=%.3f\t",in,j,wc[in][j]);
                        if(zin[in]<0 && tar[i]==-1)
                            continue;
                        else if(tar[i]==1)
                        {
                            if(fin[in]==1)
                                w[j][in]+=wc[j][in];
                            continue;
                        }
                        w[j][in]+=wc[j][in];
                        // printf("w=%.3f\t",w[in][j]);
                        wc[j][in]=0;
                        
                    }
                }
                    for(in=0;in<=1;in++)
                    {
                        bc[in]=alpha*o[in];
                        if(zin[in]<0 && tar[i]==-1)
                            continue;
                        else if(tar[i]==1)
                        {
                           if(fin[in]==1)
                                b[in]+=bc[in];
                                continue;
                            
                        }
                        b[in]+=bc[in];
                        // printf("\nb%d=%.3f",in,b[in]);
                        bc[in]=0;
                    }
                yin=0; 
            }
            for(int i=0;i<2;i++)
                {
                for(int j=0;j<2;j++)
                {
                    printf("%0.3f\t",w[j][i]);
                }
                printf("%.3f\t",b[i]);
            }
            
            printf("%.2f",er);
            printf("\n");
        }
        
        epoch++;
        if(er<=1 || epoch>30)
        {
            printf("Final Weight: \n");
            for(i=0;i<=1;i++)
            {
                for(j=0;j<=1;j++)
                {
                    printf("W%d%d: %.3f\n",i+1,j+1,w[i][j]);
                }
            }
        }
        else{
            yin=0;
            for(in=0;in<=1;in++)
            {
                bc[in]=0;
                zin[in]=0;
            }
            er=0;
            goto mew;
        }
        //Checking the Network
        for(in=0;in<=1;in++)
            {
                zin[in]=0;
                for(j=0;j<2;j++)
                {
                    zin[in]+=1*w[j][in];
                }
                zin[in]+=b[in];
                printf("%f\t\t",zin[in]);
            }
            c=0;
            d=1;
            if(zin[c]>=0)
                z1=1;
            else
                z1=-1;
            if(zin[d]>=0)
                z2=1;
            else    
                z2=-1;
            yin = z1*v1+z2*v2+b3;
            printf("%.3f\t\t",yin);
            
            for(in=0;in<=1;in++)
            {
                o[in]=tar[i]-zin[in];
                er+=o[in]*o[in];
                zin[in]=0;
            }
            if(yin>=0)
                y=1;
            else
                y=-1;
            printf("\n Output: %d",y);
    return 0;
}