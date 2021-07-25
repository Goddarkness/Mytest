#include <stdio.h>
#include <stdlib.h>
void fileinput ( char file[], double a[], int *x , int *y);
void fileoutput ( char file[] , double a[] , int m ,int n);
void add( double a[], double b[], double c[],int m, int n);
void print(double a[], int m , int n);
void multiply(double a[], int am ,int an , double b[], int bm ,int bn,double c[] ,int *cm,int *cn);
int main()
{
    int am ,an,bm,bn;
    double a[1000] = {0} ;
    double b[1000] = {0} ;
    double c[1000] = {0} ;
    int cm, cn;
    char file1 [100] ={"H:\\trya.txt"};
    char file2 [100] ={"H:\\tryb.txt"};
    char file3 [100] ={"H:\\tryc.txt"};

    fileinput(file1 , a , &am ,&an);
    fileinput(file2 , b , &bm ,&bn);
    multiply(a,am,an,b,bm,bn,c,&cm,&cn);
    print(c,cm,cn);
    fileoutput( file3 , c , cm ,cn);


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
        printf("²»ÄÜ¼ÆËã");
        return;
    }

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

void fileinput ( char file[], double a[], int *x , int *y)
{
     FILE *fp;
    char c;
    int m = 0 , n=0;
    if ( (fp = fopen( file,"r")) == NULL)
    {
        printf("cannot open the file\n");
        exit(0);
    }
    int i =0;
    while( (c = fgetc(fp)) != EOF )
     {
         if (c!=32 && c !='\n' )
             a[i] = a[i]*10+ (c - '0');
         if  ( c == 32  )
           {
            i++;
           }
         if ( c == '\n')
         {
             i++;
             m++;
         }
     }

     n = i/m;
    if ( fclose(fp))
    {
        printf("cannot close this file\n");
        exit(0);
    }
    *x = m;
    *y = n;
}

void fileoutput ( char file[] , double a[] , int m ,int n)
{
    FILE *fp;
    if ( (fp = fopen(file,"w")) == NULL)
    {
        printf("cannot open the file\n");
        exit(0);
    }

   for ( int i =0 ; i < m*n ;i++)
   {
      // fputs(gcvt(a[i],10,b), fp );
       fprintf(fp, "%lf",a[i]);
       fputc ('\t',fp);
       if ( (i+1) %n == 0)
        fputc('\n',fp);

   }

      if ( fclose(fp))
    {

        printf("cannot close this file\n");
        exit(0);
    }
}

