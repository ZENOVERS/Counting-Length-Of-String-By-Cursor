#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#pragma warning (disable : 4996)


int Getx(void)
{
	CONSOLE_SCREEN_BUFFER_INFO curInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	return curInfo.dwCursorPosition.X;
}

int Gety(void)
{
	CONSOLE_SCREEN_BUFFER_INFO curInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	return curInfo.dwCursorPosition.Y;
}

int main()
{
	system("mode con cols=130 lines=25"); //�ܼ� ���� 122, ���� 25
	system("title Counting Length Of String By Cursor");

	char c = '\0';
	int len = 0, F_len = 0, pre_y = 0;

	while (1)
	{
		while (Gety() <= pre_y) //Ŀ�� Y��ǥ�� ���� ��ǥ���� Ŭ �� ����
		{
			len = Getx(); //lne ������ ���콺 Ŀ�� ��ǥ �Ҵ�

			if (Getx() >= 120) //���� Ŀ���� �ܼ� ���� �����ϸ� Ŀ���� �� �̻� �������� �ʱ� ������ ���๮�ڸ� ����Ͽ� X��ǥ ����
				puts("");

			c = getch();

			if (c == 13)//����Ű�� �ԷµǸ� ����
				break;

			printf("%c", c);
		}

		F_len += len;
		pre_y++;
		len = 0;

		if (c == 13)
			break;
	}

	printf("\n\n\n%d\n\n\n", F_len);
	system("pause");

	return 0;
}