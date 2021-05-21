#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define random(x) (rand()%x)
#define MAX_N 100
#define SIZE 8
#define STAT_POS_Y 128
#define STAT_POS_X 128
#define WIN_LENGTH 640
#define WIN_HEIGHT 640
//�Զ�����������
enum DIR
{
	UP = 72, RIGHT = 77,LEFT = 75,DOWN = 80
};
struct  Point
{
	int pos_x;
	int pos_y;
};
struct  Snack
{
	int n;//��ǰ����
	DIR dir;//�ߵķ���
	struct Point point[MAX_N];//�ߵ�����
};
//ȫ�ֱ�������
struct Snack snack;//��
int food_x;//ʳ������
int food_y;//ʳ������
int FAIL;//�Ƿ�ʧ�ܱ���
IMAGE background;
//��������
int Start_Page(void);
void Initialize_snack(void);
void Draw_snack(void);
int Game(void);
void keypro(void);



int main()
{

	srand((int)time(0));
	initgraph(WIN_LENGTH, WIN_HEIGHT);
	int player_choose=Start_Page();
	if (player_choose==0)
	{
		//��ʼ��Ϸ
		Initialize_snack();
		Game();
	}
	if (player_choose==1)
	{
		return 0;//�˳���Ϸ
	}
	if (player_choose==2)
	{
		//����
		cleardevice();
		IMAGE START;
		loadimage(&START, L"start.jpg", WIN_LENGTH, WIN_HEIGHT);
		putimage(0, 0, &START);
		settextcolor(RED);
		settextstyle(32, 0, L"����");
		setbkmode(TRANSPARENT);
		outtextxy(200, 200, L"�����ˣ�����");
		outtextxy(200, 250, L"����ʱ�䣺2019");
		outtextxy(200, 300, L"��ԴЭ�飺BSD  ");
		outtextxy(200, 350, L"�汾��1.0  ");

	}



	_getch();
	return 0;
}

int Start_Page()//��ʼ����
{
	setbkmode(TRANSPARENT); //���屳��Ϊ��
	IMAGE START;
	loadimage(&START, L"start.jpg",WIN_LENGTH,WIN_HEIGHT);//��ʼ���汳��ͼƬ
	putimage(0, 0, &START);
	settextcolor(GREEN);
	settextstyle(32, 0, L"����");
	outtextxy(300, 440, L"��ʼ��Ϸ");
	settextcolor(RED);
	outtextxy(300, 500, L"�˳���Ϸ");
	outtextxy(300, 560, L"  ����  ");
	int key_value; //����ֵ
	int key = 0;//ѡ�ֵ
	do
	{
		key_value = _getch();
		if (key_value == 72)
		{
			key--;
			if (key == -1){ key++; }
		}
		if (key_value == 80)
		{
			key++;
			if (key == 3){ key--; }
		}
		switch (key)
		{
		case 0:
			settextcolor(GREEN);
			settextstyle(32, 0, L"����");
			outtextxy(300, 440, L"��ʼ��Ϸ");
			settextcolor(RED);
			outtextxy(300, 500, L"�˳���Ϸ");
			outtextxy(300, 560, L"  ����  ");
			break;
		case 1:
			settextcolor(RED);
			settextstyle(32, 0, L"����");
			outtextxy(300, 440, L"��ʼ��Ϸ");
			settextcolor(GREEN);
			outtextxy(300, 500, L"�˳���Ϸ");
			settextcolor(RED);
			outtextxy(300, 560, L"  ����  ");
			break;
		case 2:
			settextcolor(RED);
			settextstyle(32, 0, L"����");
			outtextxy(300, 440, L"��ʼ��Ϸ");
			outtextxy(300, 500, L"�˳���Ϸ");
			settextcolor(GREEN);
			outtextxy(300, 560, L"  ����  ");

		default:
			break;
		}

	} while (key_value != 13);
	return key;
}
void Initialize_snack()//��ʼ������
{
	
	snack.n = 5;
	snack.dir = RIGHT;
	snack.point[0].pos_x = STAT_POS_X;
	snack.point[0].pos_y = STAT_POS_Y;
	snack.point[1].pos_x = STAT_POS_X - SIZE;
	snack.point[1].pos_y = STAT_POS_Y;
	snack.point[2].pos_x = STAT_POS_X - SIZE * 2;
	snack.point[2].pos_y = STAT_POS_Y;
	snack.point[3].pos_x = STAT_POS_X - SIZE * 3;
	snack.point[3].pos_y = STAT_POS_Y;
	snack.point[4].pos_x = STAT_POS_X - SIZE * 4;
	snack.point[4].pos_y = STAT_POS_Y;
	 food_x = WIN_LENGTH / 2;
	 food_y = WIN_HEIGHT / 2;
	//��ʼһ����ڵ��ߣ�ʳ������
	 loadimage(&background, L"background.jpg", WIN_LENGTH, WIN_HEIGHT);
	 //��Ϸ����ı���ͼ
}
void Draw_snack() //������
{
	
	
	for (int i = 0; i <snack.n; i++)
	{
		setfillcolor(RGB(random(256), random(256), random(256)));//ɫ�������
		fillcircle(snack.point[i].pos_x, snack.point[i].pos_y, SIZE / 2);
	}
	char node[4]; _itoa_s(100-snack.n, node, 10);

	outtextxy(600, 60,node[0]);
	outtextxy(620, 60, node[1]);
}
int snack_move(DIR dir)//�ߵ��ƶ�
{
	struct Point temp;//��ͷ���긱��
	temp.pos_x = snack.point[0].pos_x;
	temp.pos_y = snack.point[0].pos_y;
	
		
	snack.point[1].pos_y = snack.point[0].pos_y;
	switch (dir)
	{
	case UP:
		snack.point[0].pos_y = snack.point[0].pos_y-SIZE/2;
		break;
	case RIGHT:
		snack.point[0].pos_x = snack.point[0].pos_x + SIZE/2;
		break;
	case LEFT:
		snack.point[0].pos_x = snack.point[0].pos_x - SIZE/2;
		break;
	case DOWN:
		snack.point[0].pos_y = snack.point[0].pos_y + SIZE/2;
		break;
	default:
		break;
	}
	for (int i = 1; i <snack.n; i++)
	{
		if (snack.point[i].pos_x == snack.point[0].pos_x&&snack.point[i].pos_y == snack.point[0].pos_y)
		{
			outtextxy(WIN_LENGTH / 2, WIN_HEIGHT / 2, L"������,ҧ�����Լ�");
			return 1;//��ʾ�Ե��Լ�
			
		}
	}
	
	for (int i = snack.n-1; i >1; i--)//�ƶ�
	{
		snack.point[i].pos_x = snack.point[i - 1].pos_x;
		snack.point[i].pos_y = snack.point[i - 1].pos_y;

	}
	snack.point[1].pos_x = temp.pos_x;
	snack.point[1].pos_y = temp.pos_y;
	return 0;//û�Ե��Լ�
}
int Game()//��Ϸ������
{
	while (1)
	{
		while (!_kbhit())
		{
			putimage(0, 0, &background);
			if (food_x == snack.point[0].pos_x&&food_y == snack.point[0].pos_y)//�Ե�ʳ��
			{
				food_x = SIZE*random(WIN_LENGTH / SIZE);
				food_y = SIZE*random(WIN_HEIGHT / SIZE);
				snack.n++;
				if (snack.n == 100)//�ߴﵽ��󳤶�
				{
					break;
				}
				if (snack.point[snack.n - 2].pos_x == snack.point[snack.n - 1].pos_x)
				{
					if (snack.point[snack.n - 2].pos_y > snack.point[snack.n - 1].pos_y)
					{
						snack.point[snack.n].pos_x = snack.point[snack.n - 1].pos_x;
						snack.point[snack.n].pos_y = snack.point[snack.n - 1].pos_y - SIZE;
					}
					else
					{
						snack.point[snack.n].pos_x = snack.point[snack.n - 1].pos_x;
						snack.point[snack.n].pos_y = snack.point[snack.n - 1].pos_y + SIZE;
					}
				}
				else
				{
					if (snack.point[snack.n - 2].pos_x > snack.point[snack.n - 1].pos_x)
					{
						snack.point[snack.n].pos_x = snack.point[snack.n - 1].pos_x - SIZE;
						snack.point[snack.n].pos_y = snack.point[snack.n - 1].pos_y;
					}
					else
					{
						snack.point[snack.n].pos_x = snack.point[snack.n - 1].pos_x + SIZE;
						snack.point[snack.n].pos_y = snack.point[snack.n - 1].pos_y;
					}
				}

			}

			FAIL = snack_move(snack.dir);
			if (FAIL)
			{
				return 0;
			}
			setfillcolor(GREEN);
			fillcircle(food_x, food_y, SIZE);
			Draw_snack();
			if (snack.point[0].pos_x<0)break;
			if (snack.point[0].pos_y<0)break;
			if (snack.point[0].pos_x>WIN_LENGTH)break;
			if (snack.point[0].pos_y>WIN_HEIGHT)break;

			Sleep(50);
		}
		if (snack.n == 100)	break;
		if (snack.point[0].pos_x<0)break;
		if (snack.point[0].pos_y<0)break;
		if (snack.point[0].pos_x>WIN_LENGTH)break;
		if (snack.point[0].pos_y>WIN_HEIGHT)break;
		keypro();

	}
	if (snack.n != 100)
	{
		outtextxy(WIN_LENGTH / 2, WIN_HEIGHT / 2, L"������,ײǽ����");
	}
	else
	{
		outtextxy(WIN_LENGTH / 2, WIN_HEIGHT / 2, L"��Ӯ�˴ﵽ��󳤶�100");
	}

}
void keypro()
{
	DIR key = (DIR)_getch();
	switch (key)
	{
	case UP:
		if (snack.dir!=DOWN)
		snack.dir = UP;
		break;
	case RIGHT:
		if (snack.dir != LEFT)
		snack.dir = RIGHT;
		break;
	case LEFT:
		if (snack.dir != RIGHT)
		snack.dir = LEFT;
		break;
	case DOWN:
		if (snack.dir != UP)
		snack.dir = DOWN;
		break;
	default:

		break;
	}
}


//BUG �������ƶ���ʱ����һ����ʾ���ָ������ƶ�����
//BUG:ż��/����ʳ����ʧ����Ϸ�޷�����
