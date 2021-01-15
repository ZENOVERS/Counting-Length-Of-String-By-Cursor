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
	system("mode con cols=130 lines=25"); //콘솔 가로 122, 세로 25
	system("title Counting Length Of String By Cursor");

	char c = '\0';
	int len = 0, F_len = 0, pre_y = 0;

	while (1)
	{
		while (Gety() <= pre_y) //커서 Y좌표가 이전 좌표보다 클 시 종료
		{
			len = Getx(); //lne 변수에 마우스 커서 좌표 할당

			if (Getx() >= 120) //만약 커서가 콘솔 끝에 도달하면 커서가 더 이상 증가하지 않기 때문에 개행문자를 출력하여 X좌표 리셋
				puts("");

			c = getch();

			if (c == 13)//엔터키가 입력되면 종료
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