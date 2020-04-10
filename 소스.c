#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void random(int arr[])
{

	for (int i = 0; i < 3; i++)
		arr[i] = rand() % 10;
	/*for (int i = 0; i < 3; i++)
		printf("%d ", arr[i]);
	printf("\n");*/
}

void scan(int ar[], int num)
{
	printf("%d��°/���ڸ� �Է��ϼ���: ", num);
	for (int i = 0; i < 3; i++)
		scanf("%d", &ar[i]);
}

int strike(int code[], int decode[])
{
	int countstrike = 0;
	for (int j = 0; j < 3; j++)
		if (code[j] == decode[j])
			countstrike++;
	return countstrike;
}

int ball(int code[], int decode[])
{
	int countball = 0;
	for (int j = 0; j < 3; j++)
		for (int k = 0; k < 3; k++)
			if (code[j] == decode[k] && j != k)
				countball++;
	return countball;
}

int main(void)
{
	srand(time(NULL));
	int code[3], decode[3];
	int i = 0, num = 1, game = 1;
	while (1)
	{
		num = 1;
		if (game != 0)
		{
			random(code);
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					if (code[j] == code[k] && j != k)
					{
						random(code);
						j = 0;
					}
					else;
			printf("0~9���� �ߺ����� �ʰ� 3���� �Է����ּ��� \n");
			scan(decode, num);
			while (1)
			{
				if (decode[0] == 2 && decode[1] == 2 && decode[2] == 7)
				{
					printf("Key is ");
					for (int i = 0; i < 3; i++)
						printf("%d ", code[i]);
					printf("\n");
					scan(decode, num);
				}
				else if (code[0] != decode[0] || code[1] != decode[1] || code[2] != decode[2])
				{
					i = 0;
					for (int j = 0; j < 3; j++)
						for (int k = j + 1; k < 3; k++)
						{
							if (decode[j] == decode[k])
							{
								printf("�ߺ��� ���ڰ� �ֽ��ϴ�. \n");
								scan(decode, num);
								j = 0;
								i = 1;
							}
							else if (decode[j] > 9 || decode[k] > 9)
							{
								printf("9�� ���� ���ڰ� �����մϴ�. \n");
								scan(decode, num);
								j = 0;
								i = 1;
							}
							else;
						}
					if (i == 0)
					{
						num++;
						printf("��: %d, ��Ʈ����ũ: %d \n", ball(code, decode), strike(code, decode));
						scan(decode, num);
					}
				}
				else
						break;
			}
			printf("����! \n");
			printf("�ٽ��ϱ� : 1, ����: 0 \n");
			scanf("%d", &game);
		}
		else if (game == 0)
			break;
	}
	return 0;
}