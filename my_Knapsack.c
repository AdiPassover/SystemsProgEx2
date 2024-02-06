#include <stdio.h>
#define MAXIMUM_WEIGHT 20
#define MAXIMUM_ITEMS 5
#define MAXIMUM_LEN 20
int knapSack(int weights[], int values[], int selected_bool[]);
int main()
{
    // Your code here
    char items[MAXIMUM_ITEMS][MAXIMUM_LEN] = {0};
    int weights[MAXIMUM_ITEMS] = {0};
    int values[MAXIMUM_ITEMS] = {0};
    int selected_bool[MAXIMUM_ITEMS] = {0};
    for (size_t i = 0; i < MAXIMUM_ITEMS; i++)
    {
        scanf("%s", items[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }

    int max = knapSack(weights, values, selected_bool);
    printf("Maximum profit: %d\n", max);
    printf("Items that give the maximum profit: [");
    int first = 1;
    for (size_t i = 0; i < MAXIMUM_ITEMS; i++)
    {
        if (selected_bool[i] == 1)
        {
            if (first)
            {
                first = 0;
                printf("%s", items[i]);
            }

            else printf(", %s", items[i]);
        }
    }
    printf("]\n");

    return 0;
}
int knapSack(int weights[], int values[], int selected_bool[])
{
    // Your code here
    int matrix[MAXIMUM_ITEMS + 1][MAXIMUM_WEIGHT + 1] = {0};
    for (size_t i = 0; i <= MAXIMUM_ITEMS; i++)
    {
        for (size_t j = 0; j <= MAXIMUM_WEIGHT; j++)
        {
            if (i == 0 || j == 0)
            {
                matrix[i][j] = 0;
            }
            else if (weights[i - 1] <= j)
            {
                if (values[i - 1] + matrix[i - 1][j - weights[i - 1]] > matrix[i - 1][j])
                    matrix[i][j] = values[i - 1] + matrix[i - 1][j - weights[i - 1]]; // make the choice
                else
                    matrix[i][j] = matrix[i - 1][j];
            }
            else
            {
                matrix[i][j] = matrix[i - 1][j];
            }
            
        }
    }
    
    int maxInd = 0;
    int max = 0;
    for (size_t i = 0; i < MAXIMUM_WEIGHT + 1; i++) // traceing back to find the selected items
    {
        if (matrix[MAXIMUM_ITEMS][i] > max)
        {
            max = matrix[MAXIMUM_ITEMS][i];
            maxInd = i;
        }
    }
    for (size_t i = MAXIMUM_ITEMS; i > 0; i--)
    {
        if (matrix[i][maxInd] != matrix[i - 1][maxInd])
        {
            selected_bool[i - 1] = 1;
            maxInd -= weights[i - 1];
        }
    }

    return max;
}
