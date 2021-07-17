#include <stdio.h>
#include <stdlib.h>
void add( double a[], double b[], double c[],int m, int n);
void print(double a[], int m , int n);
void multiply(double a[], int am ,int an , double b[], int bm ,int bn,double c[] ,int *cm,int *cn);
int main()
{   int am ,an,bm,bn;
    printf("请输入矩阵规模\n");
    scanf("%d%d",&am,&an);
    double a[am*an];
    int i,k;
    for ( i = 0 ; i<am ; i++)
    {
        for ( k=0 ; k<an ;k++)
        {
            printf("请输入%d行%d列的元素\n",i+1,k+1);
            scanf("%lf",&a[i*an+k]);
        }
    }
    printf("请输入矩阵规模\n");
    scanf("%d%d",&bm,&bn);
    double b [bm*bn];
    for ( i = 0 ; i<bm ; i++)
    {
        for ( k=0 ; k<bn ;k++)
        {
            printf("请输入%d行%d列的元素\n",i+1,k+1);
            scanf("%lf",&b[i*bn+k]);
        }
    }
  //  print(b,q,p);
    printf("\n");
    double c[100000] = {0} ;
    int cm, cn;
    multiply(a,am,an,b,bm,bn,c,&cm,&cn);
    print(c,cm,cn);


    return 0;
}
void add( double a[],double b[],double c[],int m ,int n)
{

      //int   i =  sizeof(a)/sizeof(a[0]) - 1;
      for ( int i = 0 ; i < m ;i++)
      {
          for ( int j = 0 ; j<n ; j++)
            c[i*n+j] = a[i*n+j] + b[i*n+j];
      }
}

void print(double a[],int m ,int n)
{
    if ( m==0 || n==0 )
        printf("\n");
    else
   {
    int i,j;
    for ( i = 0; i < m ; i++ )
    {
        for ( j=0 ; j<n; j++)
        {
            printf("\t%lf",a[i*n+j]);
        }
        printf("\n");
    }
   }
}

void multiply(double a[], int am ,int an , double b[], int bm ,int bn,double c[] ,int *cm,int *cn)
{
    if ( an != bm)
    {
        *cm=0;
        *cn=0;
        printf("不能计算");
    }
    else

       {
        int i ,j;
        for ( i = 0 ; i<am ; i++ )
        {
            for ( j = 0 ; j < bn ; j++)
            {
                for ( int k =0 ; k < an ; k++)
                    c[i*bn+j] = c[i*bn+j]+a[i*an+k]*b[k*bn+j];
            }
        }

        *cm = am;
        *cn = bn;
       }
}
