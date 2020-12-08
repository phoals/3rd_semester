#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int **a;
    int i, j, n, m;
    printf("Enter number of edges: ");
    scanf("%d", &n);
    m = n;
    a = (int**)malloc(n * sizeof(int*));
    for (i = 0; i<n; i++)
    {
        a[i] = (int*)malloc(m * sizeof(int));
        for (j = 0; j<m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    FILE* f = fopen("test.dot", "w");
    fprintf(f, "graph test {\n");
    int z = 0;
    for (i = 0; i<n; i++)
    {  
        for (j = i; j<n; j++)
        {
            if (a[i][j] == 1) fprintf(f, "%d--%d;\n", i + 1, j + 1);
            z++;
        }
    }
    fprintf(f, "}");
    int p = 0.5 * (n - 1) * (n - 2);
    if (m > p) 
    {
        printf ("Graph is connected\n"); 
    }    
    else 
    {
        printf("Graph is not connected\n");
    }
    for (int i = 0; i < n; i++)
    {
        free(a[i]);
    }
    
    fclose(f);

    system("dot -Tpng test.dot -o test.png");
    system("test.png");

    return 0;
}
