#include <stdio.h>
#define MAX 20
void sparseRep(int a[][MAX], int rows, int cols, int b[][3]);
void display(int b[][3]);
void sparseAddition(int a[][3], int b[][3], int c[][3]);
int main()
{
int rows, cols;
int mat1[MAX][MAX], mat2[MAX][MAX];
int sparse1[401][3], sparse2[401][3], result[401][3];
int i, j;
printf("Enter number of rows and columns: ");
scanf("%d%d", &rows, &cols);
printf("Enter first matrix elements:\n");
for(i = 0; i < rows; i++)
{
for(j = 0; j < cols; j++)
{
    scanf("%d", &mat1[i][j]);
}
}
sparseRep(mat1, rows, cols, sparse1);
printf("\nSparse Matrix Representation of First Matrix:\n");
display(sparse1);
printf("\nEnter second matrix elements:\n");
for(i = 0; i < rows; i++)
{
for(j = 0; j < cols; j++)
{
    scanf("%d", &mat2[i][j]);
}
}

sparseRep(mat2, rows, cols, sparse2);
printf("\nSparse Matrix Representation of Second Matrix:\n");
display(sparse2);
sparseAddition(sparse1, sparse2, result);
printf("\nSparse Matrix Addition Result:\n");
display(result);
return 0;
}
void sparseRep(int a[][MAX], int rows, int cols, int b[][3])
{
int i, j, k = 1;
b[0][0] = rows;
b[0][1] = cols;
b[0][2] = 0;
for(i = 0; i < rows; i++)
{
for(j = 0; j < cols; j++)
{
    if(a[i][j] != 0)
    {
        b[k][0] = i;
        b[k][1] = j;
        b[k][2] = a[i][j];
        k++;
        b[0][2]++;
    }
}
}
}

void display(int b[][3])
{
int i;
printf("Row\tCol\tValue\n");
for(i = 0; i <= b[0][2]; i++)
{
printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
}
}
void sparseAddition(int a[][3], int b[][3], int c[][3])
{
int i = 1, j = 1, k = 1;
c[0][0] = a[0][0];
c[0][1] = a[0][1];
c[0][2] = 0;
while(i <= a[0][2] && j <= b[0][2])
{
if(a[i][0] == b[j][0] && a[i][1] == b[j][1])
{
    int sum = a[i][2] + b[j][2];
    if(sum != 0)
    {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = sum;
        k++;
        c[0][2]++;
    }
    i++;
    j++;
}
else if(a[i][0] < b[j][0] ||
       (a[i][0] == b[j][0] && a[i][1] < b[j][1]))
{
    c[k][0] = a[i][0];
    c[k][1] = a[i][1];
    c[k][2] = a[i][2];
    k++;
    c[0][2]++;
    i++;
}
else
{
    c[k][0] = b[j][0];
    c[k][1] = b[j][1];
    c[k][2] = b[j][2];
    k++;
    c[0][2]++;
    j++;
}
}

while(i <= a[0][2])
{
c[k][0] = a[i][0];
c[k][1] = a[i][1];
c[k][2] = a[i][2];
k++;
c[0][2]++;
i++;
}

while(j <= b[0][2])
{
c[k][0] = b[j][0];
c[k][1] = b[j][1];
c[k][2] = b[j][2];
k++;
c[0][2]++;
j++;
}
}
