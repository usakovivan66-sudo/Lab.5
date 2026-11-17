#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h> 



void task_23();
void task_28();
void task_30();
void task_49();
void task_86();
void task_147();

int main()
{

	int taskNumber;
	while (1)
	{
		printf("Enter task number (23, 28, 30, 49, 86, 147) or 0 to exit: ");
		if (scanf_s("%d", &taskNumber) != 1)
		{
			printf("Invalid input. Please enter a valid task number.\n");
			while (getchar() != '\n');
			continue;
		}
		if (taskNumber == 0)
		{
			printf("Exiting the program.\n");
			break;
		}
		switch (taskNumber)
		{
		case 23:
			task_23();
			break;
		case 28:
			task_28();
			break;
		case 30:
			task_30();
			break;
		case 49:
			task_49();
			break;
		case 86:
			task_86();
			break;
		case 147:
			task_147();
			break;
		default:
			printf("Invalid task number. Please try again.\n");
			break;
		}
	}
	return 0;
}

void task_23()
{
	printf("Task 23.\n");

	int number[35];
	long long sum = 0;

	printf("Enter the number of books in each of the 35 sections of the library:\n ");

	for (int i = 0; i < 35; i++)
	{
		printf("Section %d: ", i + 1);
		if (scanf_s("%d", &number[i]) != 1 || number[i] < 0)
		{
			printf("Invalid input. Please enter a valid number.\n");
			while (getchar() != '\n');
			i--; 
			continue;
		}
		sum += number[i];
	}
	if(sum < 100000 || sum > 999999)
	{
		printf("The total number of books is not a six-digit number: %lld\n\n", sum);
	}
	else
	{
		printf("The total number of books is a six-digit number: %lld\n\n", sum);
	}
	return;
}

void task_28() //Дана послідовність цілих чисел a1, a2, ..., aп. З'ясувати, яке число зустрічається раніше - позитивне або негативне.

{
	printf("Task 28.\n");

	int n = 0;
	while (1)
	{
		printf("Enter the number of integers in the sequence (n > 0): ");
		if (scanf_s("%d", &n) != 1 || n <= 0)
		{
			printf("Invalid input. Please enter a positive integer.\n");
			while (getchar() != '\n');
			continue;
		}
		break;
	}

	int* sequence = (int*)malloc(n * sizeof(int));
	if (sequence == NULL)
	{
		printf("Memory allocation failed.\n");
		return;
	}

	printf("Enter the integers in the sequence:\n");
	for (int i = 0; i < n; i++)
	{
		printf("Element %d: ", i + 1);
		if (scanf_s("%d", &sequence[i]) != 1)
		{
			printf("Invalid input. Please enter a valid integer.\n");
			while (getchar() != '\n');
			i--;
			continue;
		}
	}

	int firstPositive = -1;
	int firstNegative = -1;

	for (int i = 0; i < n; i++)
	{
		if (sequence[i] > 0)
		{
			if (firstPositive == -1)
			{
				firstPositive = i;
			}
		}
		else if (sequence[i] < 0)
		{
			if (firstNegative == -1)
			{
				firstNegative = i;
			}
		}
	}

	if (firstPositive == -1)
	{
		printf("No positive numbers found in the sequence.\n");
	}
	else if (firstNegative == -1)
	{
		printf("No negative numbers found in the sequence.\n");
	}
	else
	{
		if (firstPositive < firstNegative)
		{
			printf("The first positive number appears before the first negative number.\n");
		}
		else
		{
			printf("The first negative number appears before the first positive number.\n");
		}
	}
	free(sequence);

	return;
}

void task_30() //Дано послідовність натуральних чисел a1, a2, ..., aп. Створити масив із парних чисел цієї послідовності. Якщо таких чисел немає, вивести повідомлення про цей факт.
{
	printf("Task 30.\n");

	int n = 0;
	while (1)
	{
		printf("Enter the number of natural numbers in the sequence (n > 0): ");
		if (scanf_s("%d", &n) != 1 || n <= 0)
		{
			printf("Invalid input. Please enter a positive integer.\n");
			while (getchar() != '\n');
			continue;
		}
		break;
	}

	int* sequence = (int*)malloc(n * sizeof(int));
	if (sequence == NULL)
	{
		printf("Memory allocation failed.\n");
		return;
	}

	printf("Enter the integers in the sequence:\n");
	for (int i = 0; i < n; i++)
	{
		printf("Element %d: ", i + 1);
		if (scanf_s("%d", &sequence[i]) != 1 || sequence[i] <= 0)
		{
			printf("Invalid input. Please enter a natural number.\n");
			while (getchar() != '\n');
			i--;
			continue;
		}
	}

	int evenCount = 0;

	for (int i = 0; i < n; i++)
	{
		if (sequence[i] % 2 == 0)
		{
			evenCount++;
		}
	}

	if (evenCount == 0)
	{
		printf("No even numbers found in the sequence.\n");
	}
	else
	{
		int* evenNumbers = (int*)malloc(evenCount * sizeof(int));
		if (evenNumbers == NULL)
		{
			printf("Memory allocation failed.\n");
			return;
		}

		int evenIndex = 0;
		for (int i = 0; i < n; i++)
		{
			if (sequence[i] % 2 == 0)
			{
				evenNumbers[evenIndex++] = sequence[i];
			}
		}

		printf("Even numbers in the sequence:\n");
		for (int i = 0; i < evenCount; i++)
		{
			printf("%d ", evenNumbers[i]);
		}
		printf("\n");

		free(evenNumbers);
	}

	free(sequence);

	return;
}

void task_49()
{
	printf("Task 49.\n");
	
	int N = 0;
	while (1)
	{
		printf("Enter the number of natural numbers in the sequence (n > 0): ");
		if (scanf_s("%d", &N) != 1 || N <= 0)
		{
			printf("Invalid input. Please enter a positive integer.\n");
			while (getchar() != '\n');
			continue;
		}
		break;
	}

	double* sequence = (double*)malloc(N * sizeof(double));
	if (sequence == NULL)
	{
		printf("Memory allocation failed.\n");
		return;
	}

	printf("Enter the real numbers in the sequence:\n");
	for (int i = 0; i < N; i++)
	{
		printf("Element %d: ", i + 1);
		if (scanf_s("%lf", &sequence[i]) != 1)
		{
			printf("Invalid input. Please enter a real number.\n");
			while (getchar() != '\n');
			i--;
			continue;
		}
	}

	double product = 1.0;

	for (int i = 0; i < N; i++)
	{
		product *= sequence[i];
	}

	double abs_product = fabs(product);
	double result = pow(abs_product, 1.0 / N);
	printf("The N-th root of the absolute value of the product of the numbers is: %.4lf\n", result);
	free(sequence);


	return;
}

void task_86() //Дана послідовність дійсних чисел, що закінчується числом 10000.
//Кількість чисел у послідовності не менше двох. Визначити, чи є послідовність упорядкованою за зростанням.
//У разі негативної відповіді визначити порядковий номер першого числа, яке порушує таку впорядкованість.
{
	printf("Task 86.\n");

	int capacity = 10;
	int count = 0;

	double* sequence = (double*)malloc(capacity * sizeof(double));
	if(sequence == NULL)
	{
		printf("Memory allocation failed.\n");
		return;
	}

	printf("Enter the real numbers in the sequence (enter 10000 to end):\n");
	while (1)
	{
		double number;
		printf("Element %d: ", count + 1);
		if (scanf_s("%lf", &number) != 1)
		{
			printf("Invalid input. Please enter a real number.\n");
			while (getchar() != '\n');
			continue;
		}
		if (number == 10000)
		{
			break;
		}
		if (count == capacity)
		{
			capacity *= 2;
			double* temp = (double*)realloc(sequence, capacity * sizeof(double));
			if (temp == NULL)
			{
				printf("Memory reallocation failed.\n");
				free(sequence);
				return;
			}
			sequence = temp;
		}
		sequence[count++] = number;
	}

	if (count < 2)
	{
		printf("The sequence must contain at least two numbers.\n");
		free(sequence);
		return;
	}

	int is_sorted = 1;
	int error_index = 0;

	for (int i = 1; i < count; i++)
	{
		if (sequence[i] < sequence[i - 1])
		{
			is_sorted = 0;
			error_index = i;
			break;
		}
	}

	if (is_sorted)
	{
		printf("The sequence is sorted in ascending order.\n");
	}
	else
	{
		printf("The sequence is not sorted in ascending order.\n");
		printf("The first number that violates the ordering is at position %d.\n", error_index + 1);
	}

	free(sequence);
	return;
}

void task_147() 
{
	printf("Task 147.\n");

	int n = 0;
	while (1)
	{
		printf("Enter the number of integers in the array (n > 0): ");
		if (scanf_s("%d", &n) != 1 || n <= 0)
		{
			printf("Invalid input. Please enter a positive integer.\n");
			while (getchar() != '\n');
			continue;
		}
		break;
	}

	int* array = (int*)malloc(n * sizeof(int));
	if (array == NULL)
	{
		printf("Memory allocation failed.\n");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		printf("Element %d: ", i + 1);
		if (scanf_s("%d", &array[i]) != 1)
		{
			printf("Invalid input. Please enter a valid integer.\n");
			while (getchar() != '\n');
			i--;
			continue;
		}
	}

	int m = array[0];
	int M = array[0];
	for (int i = 1; i < n; i++)
	{
		if (array[i] < m)
		{
			m = array[i];
		}
		if (array[i] > M)
		{
			M = array[i];
		}
	}
	printf("Minimum element m: %d\n", m);
	printf("Maximum element M: %d\n", M);
	
	printf("Integers in the interval (%d; %d) that are not in the array:\n", m, M);
	bool found_any = false;
	for (int target = m + 1; target < M; target++)
	{
		bool found = false;
		for (int i = 0; i < n; i++)
		{
			if (array[i] == target)
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			printf("%d ", target);
			found_any = true;
		}
	}
	if (!found_any)
	{
		printf("No integers found in the interval.\n");
	}
	printf("\n");
	free(array);
	return;
}

