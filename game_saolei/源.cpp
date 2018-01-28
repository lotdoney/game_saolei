#include "stdio.h"
#include "graphics.h"
#include "windows.h"
#include "time.h" //��������л��õ���
void apply( );
void draw(int map[ ][12], IMAGE *img);
int play(int map[][12]);
int win;//��ʾ�����ĸ���
void sweep(int map[][12], int x, int y);//�ع񷭿�
HWND hwnd;
int main( )
{
	do 
	{
		apply();
	//	if (MessageBox(hwnd,"����һ�֣�","�˳�!",MB_RETRYCANCEL)==IDCANCEL)
		//{
			//break;
		//}

	} while (1);


	return 0;
}
void apply()
{
	//MessageBox(hwnd, "��ʼ��Ϸ", "begin", MB_OK);
	//����
	int map[12][12] = {0};//ɨ��������Ҫ����
	//��ֹ����Խ��
	int m, n;
	int	i, j;
	srand((unsigned)time(NULL));//��ĵ��������
	for (n=0;n<1; )
	{
		//������ײ���1-10��������Ϊ�����±�
		i = 1 + rand( )%10;	
		j = 1 + rand( )%10;
		if (map[i][j]==0)
		{
			//��-1������
			map[i][j] = -1;//��һ����ֵ������==
			n++;//��֤������10���ף�Ҫ�Ƿ���ǰ�治һ����֤����ʮ��
		}
	}
	for (i=1;i<=10;i++)
	{
		for (j=1;j<=10;j++)
		{
			if (map[i][j]!=-1)//�����׵�������ж�
			{
				//������Χ�ķ���
				for (m=i-1;m<=i+1;m++)
				{
					for (n=j-1;n<=j+1;n++)
					{
						if (map[m][n]==-1)//�жϳ���Χ����
						{
							map[i][j]++;
						}
					}
				}
			}
		}
	}

	initgraph(500,500);//����ͼ�񴰿�
	//initgraph��c++��ʹ��
	IMAGE img[12];//����ͼƬ
	loadimage(&img[0], "0.jpg",50,50);
	loadimage(&img[1], "1.jpg", 50, 50);
	loadimage(&img[2], "2.jpg", 50, 50);
	loadimage(&img[3], "3.jpg", 50, 50);
	loadimage(&img[4], "4.jpg", 50, 50);
	loadimage(&img[5], "5.jpg", 50, 50);
	loadimage(&img[6], "6.jpg", 50, 50);
	loadimage(&img[7], "7.jpg", 50, 50);
	loadimage(&img[8], "8.jpg", 50, 50);
	loadimage(&img[9], "��.jpg", 50, 50);
	loadimage(&img[10], "��ͼ.jpg", 50, 50);
	loadimage(&img[11], "���.jpg", 50, 50);
	win = 0;//��ʼ��ʤ������
	while (1)
	{
		draw(map, img);
		if (play(map)==9)//��ʾ�㿪��һ����
		{
			draw(map, img);
			MessageBox(hwnd, "you lost", "BOOM", MB_OK);
			return;
		}
		if (win==99)
		{
			draw(map, img);
			
			MessageBox(hwnd, "you win", "WINNER", MB_OK);
			
		//	return;
		}
		
	}
	
}

void draw(int map[][12],  IMAGE *img)//��ͼ
{
	for (int i=1;i<=10;i++)
	{
		
		for (int j=1;j<=10;j++)
		{
			if (map[i][j]>=20)
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[11]);
				continue;
			}
			switch (map[i][j])//���������+10
				//���������ʱ��ſ�ʼ��ʾͼ��
			{
			case  -1+10:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[9]);//��������
				break;
			}
			case  0+10:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[0]);
				break;
			}
			case  1 + 10:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[1]);
				break;
			}
			case  2 + 10:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[2]);
				break;
			}
			case  3 + 10:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[3]);
				break;
			}
			case  4 + 10:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[4]);
				break;
			}
			case  5 + 10:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[5]);
				break;
			}
			case  6 + 10:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[6]);
				break;
			}
			case  7 + 10:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[7]);
				break;
			}
			case  8 + 10:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[8]);
				break;
			}
			case  9 + 10:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[9]);
				break;
			}
			case 29:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[11]);
				break;
			}
				
			default:
				putimage(50 * (i - 1), 50 * (j - 1), &img[10]);
				break;
			}
		}
		
	}
	
}
int play(int map[ ][12])//������
{
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg( );//��ȡ�����Ϣ
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN://����������
		if (map[m.x/50+1][m.y/50+1]>9)
		{
			continue;//����9��ʾ�Ѿ��㿪�˳�
		}
		if (map[m.x/50+1][m.y/50+1]==0)
		{
			//��дһ������
			sweep(map,m.x/ 50 + 1, m.y / 50+1);
		}
		else
		{
			map[m.x / 50 + 1][m.y / 50 + 1] += 10;
			win++;
		}
		return 	map[m.x / 50 + 1][m.y / 50 + 1];
		break;

		case WM_RBUTTONDOWN://��ʾ����Ҽ����
			if (map[m.x / 50 + 1][m.y / 50 + 1]<20)
			{
				map[m.x / 50 + 1][m.y / 50 + 1] += 30;
			}
			else if (map[m.x / 50 + 1][m.y / 50 + 1] <= 20)
			{
				map[m.x / 50 + 1][m.y / 50 + 1] -= 30;
			}
			else 
			{
			continue;
			}
			return map[m.x / 50 + 1][m.y / 50 + 1];
			break;
		}
	}

}
void sweep(int map[][12], int x, int y) 
{
	map[x][y] = 10;
	win++;
	int i, j;
	for (i=x-1;i<=x+1;i++)
	{
		for (j=y-1;j<y+1;j++)
		{
			if (i>=1&&i<=10&&j>=1&&j<=10)//����Խ��
			{
				if (map[i][j]<9)//û�з���
				{
					if (map[i][j]==0)
					{
						sweep(map, i, j);//�ݹ�㿪��Χ
					}
					else if (map[i][j]==-1)
					{
						continue;
					}
					else // ���ܷ�������Ϊ�գ������еݹ����
					{
						map[i][j] += 10;
						win++;
					}
					
				}
			}
		}
	}
	return ;
}