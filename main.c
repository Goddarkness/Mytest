#include <stdio.h>
#include <stdlib.h>
void plus ( double a[][3] , double b[][3],double c[][3]);
void zhuanzhi ( double a[][3]);
void multiply ( double a[][3], double b[][3],double c[][3]);
void ni ( double a[][3] );
int main()
{
    double a[3][3]={{1,2,3},{1,2,3},{1,2,3}};
    double b[3][3]= {{1,2,3},{1,2,3},{1,2,3}};
    double c[3][3]={0};
    int i , j;
    multiply(a,b,c);
    for ( i = 0 ; i < 3 ;i++)
    {
        for ( j = 0 ; j<3 ; j++ )
        {
            printf("\t%lf",c[i][j]);
        }
        printf("\n");
    }


    return 0;
}
void plus ( double a[][3] , double b[][3],double c[][3])
{
    int i,j;
    for ( j =0 ; j<3 ; j++ )
    {
        for ( i = 0 ; i<3 ; i++)
            c[j][i] = a[j][i] + b[j][i];
    }

}
void zhuanzhi(double a[][3])
{
    int i,j;
    for ( i = 0 ; i < 3 ; i++ )
    {
         for ( j = 0 ; j < i+1 ; j++)
         {
             int t;
            t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
         }
    }
}

void multiply ( double a[][3], double b[][3],double c[][3])
{
    int i,j;
    for ( i = 0 ; i < 3 ; i++)
    {
        for ( j = 0 ; j < 3 ; j++)
        {
            for (  int k =0 ; k < 3 ;k++)
                c[i][j] = c[i][j] + a[i][k] * b[k][j];

        }
    }
}

/*void ni ( double a[][3] )
{
    double b[3][3];
    int i,j;
    for ( i=0 ; i<3 ; i++ )
        for ( j = 0 ; j < 3 ; j++)
    {
        for (  int n =0 ; n < 3 ; n++)

    }
}
*/
