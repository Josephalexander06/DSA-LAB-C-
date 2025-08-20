#include <stdio.h>

#define MAXTERMS 20

typedef struct
{
	int row;
	int col;
	int value;
} sparse;

int main()
{
	int i = 0, j = 0, k = 0;
	int rows, cols, terma, termb;
	sparse a[MAXTERMS], b[MAXTERMS], result[2 * MAXTERMS];

	printf("Enter the row of matrix: ");
	scanf("%d", &rows);

	printf("Enter the colunms of matrix: ");
	scanf("%d", &cols);

	printf("\nEnter the terms of First matrix: : ");
	scanf("%d", &terma);

	for (int i = 0; i < terma; i++)
	{
		printf("Enter the row,colunm and value of %d: ", i + 1);
		scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
	}

	printf("\nEnter the terms of Second matrix: ");
	scanf("%d", &termb);

	for (int i = 0; i < termb; i++)
	{
		printf("Enter the terms of row,colunm and value of %d: ", i + 1);
		scanf("%d %d %d", &b[i].row, &b[i].col, &b[i].value);
	}

	while (i < terma && j < termb)
	{
		if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col))
		{
			result[k++] = a[i++];
		}
		else if (a[i].row > b[j].row || (a[i].row == b[j].row && a[i].col > b[j].col))
		{
			result[k++] = b[j++];
		}
		else
		{
			int val = a[i].value + b[j].value;
			if (val != 0)
			{
				result[k].row = a[i].row;
				result[k].col = a[i].col;
				result[k].value = val;
				k++;
			}
			i++;
			j++;
		}
	}
	while (i < terma)
	{
		result[k++] = a[i++];
	}
	while (j < termb)
	{
		result[k++] = b[j++];
	}

	printf("\nResult of addition:\n");
	printf("Rows\tColunms\tVaule\n");
	for (int i = 0; i < k; i++)
	{
		printf("%d\t%d\t%d\n", result[i].row, result[i].col, result[i].value);
	}

	for (int i = 0; i < k; i++)
	{
		int temp = result[i].row;
		result[i].row = result[i].col;
		result[i].col = temp;
	}
	printf("\nTranspose of the result:\n");
	printf("Rows\tColunms\tValue\n");
	for (int i = 0; i < k; i++)
	{
		printf("%d\t%d\t%d\n", result[i].row, result[i].col, result[i].value);
	}
}