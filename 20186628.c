#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


struct date
{
	int year;
	int month;
	int day;
};
typedef struct date date;
struct info
{
	char name[10];
	date bday;
	char gender[5];
	int number[11];
};
typedef struct info info;

void info_scan(info *ptr, int index);
void info_print(info *ptr, int index);
void sort_name(info *ptr, int index);
void sort_bday(info *ptr, int index);

int main()
{
	int input;
	printf("�Է��� ������ ������ �Է�:");
	scanf_s("%d", &input);

	info *ptr = (info *)calloc(input, sizeof(info));

	
	if (ptr == NULL)
	{
		printf("�޸� �Ҵ翡 ������ �ֽ��ϴ�.\n");
		exit(1);
	}

	for (int i = 0; i < input; i++)
	{
		info_scan(ptr + i, i);
	}

	printf("---�Է¼� ���---\n");
	for (int i = 0; i < input; i++)
	{
		info_print(ptr + i, i);
	}

	sort_name(ptr, input);
	printf("---�̸��� ���---\n");
	for (int i = 0; i < input; i++)
	{
		info_print(ptr + i, i);
	}

	sort_bday(ptr, input);
	printf("---������ϼ� ���---\n");
	for (int i = 0; i < input; i++)
	{
		info_print(ptr + i, i);
	}
	free(ptr);
	return 0;
}
void info_scan(info *ptr, int index)
{
	printf("������ �Է� %d��°\n", index + 1);
	printf("�̸�:");
	scanf("%s", ptr->name);
	printf("�������(XXXX-XX-XX����):");
	scanf("%d-%d-%d", &ptr->bday.year, &ptr->bday.month, &ptr->bday.day);
	printf("����:");
	scanf("%s", ptr->gender);
	printf("��ȭ��ȣ(�����ھ���):");
	scanf("%c%c%c%c%c%c%c%c%c%c%c", &ptr->number[0], &ptr->number[1], &ptr->number[2], &ptr->number[3], &ptr->number[4], &ptr->number[5], &ptr->number[6], &ptr->number[7], &ptr->number[8], &ptr->number[9], &ptr->number[10]);

	getchar();
}

void info_print(info *ptr, int index)
{
	printf("������ ��� %d��°\n", index + 1);
	printf("%-8s:%s\n", "�̸�", *(ptr->name));
	printf("%-8s:%d/%0d/%0d\n", "�������", ptr->bday.year, ptr->bday.month, ptr->bday.day);
	printf("%-8s:%s\n", "����", ptr->gender);
	printf("%-8s:%d%d%d-%d%d%d%d-%d%d%d%d\n", ptr->number[0], ptr->number[1], ptr->number[2], ptr->number[3], ptr->number[4], ptr->number[5], ptr->number[6], ptr->number[7], ptr->number[8], ptr->number[9], ptr->number[10]);
	return;
}
void sort_name(info *ptr, int index)	// �̸� ��������
{
	info tmp;
	for (int m = 0; m < index - 1; m++)
	{
		for (int n = 0; n < index - m; n++)
		{
			if (strcmp(((ptr + n - 1)->name), ((ptr + n)->name)))
			{
				tmp = *(ptr + n - 1);
				*(ptr + n - 1) = *(ptr + n);
				*(ptr + n) = tmp;
			}
		}
	}
	return;
}

void sort_bday(info *ptr, int index) // ������� �ø�����
{
	info tmp;
	for (int i = 0; i < index - 1; i++)
	{
		for (int j = 0; j < index - 1 - i; j++)
		{
			if ((ptr + j)->bday.year > (ptr + j + 1)->bday.year)
			{
				tmp = *(ptr + j);
				*(ptr + j) = *(ptr + j + 1);
				*(ptr + j + 1) = tmp;
			}
			else if ((ptr + j)->bday.year == (ptr + j + 1)->bday.year)
			{
				if ((ptr + j)->bday.month > (ptr + j + 1)->bday.month)
				{
					tmp = *(ptr + j);
					*(ptr + j) = *(ptr + j + 1);
					*(ptr + j + 1) = tmp;
				}
				else if ((ptr + j)->bday.month == (ptr + j + 1)->bday.month)
				{
					if ((ptr + j)->bday.day > (ptr + j + 1)->bday.day)
					{
						tmp = *(ptr + j);
						*(ptr + j) = *(ptr + j + 1);
						*(ptr + j + 1) = tmp;
					}
				}
			}
		}
	}
	return;
}