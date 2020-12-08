#include <stdio.h>
#include <stdlib.h>

void create(int** ,int);
void connection(int);
void delete(int**, int);
void sort(int**, int);
void bubble(int* ,int, int*);

int main(void)
{
    int **a;
    int i, j, n;
    printf("Enter number of edges: ");
    scanf("%d", &n);
    a = (int**)malloc(n * sizeof(int*));
    for (i = 0; i<n; i++)
    {
        a[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j<n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    create(a, n);
    int var;
    int cicle = 0;
    while(cicle != 1){
        printf("Choose an option:\n1. Check if graph connected\n2. Delete an edge\n3. Sort the edges\n4. Exit\n");
        scanf("%d", &var);
        switch (var) {
            case 1:
                connection(n);
                break;
            case 2:
                delete(a, n);
                break;
            case 3:
                sort(a, n);
                break;
            case 4:
                cicle = 1;
                break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        free(a[i]);
    }
    return 0;
}

void bubble(int *num, int size, int* index)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--)
        {
            if (num[j - 1] > num[j])
            {
                int temp = num[j - 1];
                num[j - 1] = num[j];
                num[j] = temp;
                temp = index[j - 1];
                index[j - 1] = index[j];
                index[j] = temp;
            }
        }
    }
    for (int k = 0; k < size; ++k) {
        printf("%d. Edge '%d' connections ammount: %d\n", k + 1, index[k], num[k]);
    }
}

void create(int** a, int n){
    FILE* f = fopen("test.dot", "w");
    fprintf(f, "graph test {\n");
    for (int i = 0; i<n; i++)
    {
        for (int j = i; j<n; j++)
        {
            if (a[i][j] == 1) fprintf(f, "%d--%d;\n", i + 1, j + 1);
        }
    }
    fprintf(f, "}");
    fclose(f);
    /**system("dot -Tpng test.dot -o test.png");
    system("test.png");**/
}

void connection(int n){
    int p = 0.5 * (n - 1) * (n - 2);
    if (n > p)
    {
        printf ("Graph is connected\n\n\n");
    }
    else
    {
        printf("Graph is not connected\n\n\n");
    }
}

void delete(int** a, int n){
    printf("Type index of an edge you want to remove:\n");
    int x,y;
    scanf("%d", &x);
    scanf("%d", &y);
    FILE* f = fopen("test1.dot", "w");
    fprintf(f, "graph test {\n");
    for (int i = 0; i<n; i++)
    {
        for (int j = i; j<n; j++)
        {
            if (a[i][j] == 1 && i != x && j != y) fprintf(f, "%d--%d;\n", i + 1, j + 1);
        }
    }
    fprintf(f, "}");
    fclose(f);
    /**system("dot -Tpng test1.dot -o test1.png");
    system("test1.png");**/
}

void sort(int** a, int n){
    int* s = (int*)malloc(n * sizeof(int));
    int* ind = (int*)malloc(n * sizeof(int));
    for (int l = 0; l < n; ++l) ind[l] = l + 1;
    for (int k = 0; k < n; ++k) s[k] = 0;
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            s[i] = s[i] + a[i][j];
        }
    }
    bubble(s, n, ind);
    printf("\n\n");
}
