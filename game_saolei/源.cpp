#include "stdio.h"
#include "graphics.h"
#include "windows.h"
#include "time.h" //��������л��õ���
void apply( );
void draw(int map[][12], IMAGE *img);
int main( )
{
	

	apply();


	system("pause");
	return 0;
}
void apply()
{
	//����
	int map[12][12] = {0};//ɨ��������Ҫ����
	//��ֹ����Խ��
	int m, n;
	int	i, j;
	srand((unsigned)time(NULL));//��ĵ��������
	for (n=0;n<10; )
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
	draw(map,img);

}

void draw(int map[][12],   IMAGE *img)//��ͼ
{
	for (int i=1;i<=10;i++)
	{
		for (int j=1;j<=10;j++)
		{
			if (map[i][j]>=20)
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[11]);
			}
			switch (map[i][j])
			{
			case  -1:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[9]);//��������
				break;
			}
			case  0:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[0]);
				break;
			}
			case  1:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[1]);
				break;
			}
			case  2:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[2]);
				break;
			}
			case  3:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[3]);
				break;
			}
			case  4:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[4]);
				break;
			}
			case  5:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[5]);
				break;
			}
			case  6:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[6]);
				break;
			}
			case  7:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[7]);
				break;
			}
			case  8:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[8]);
				break;
			}
			case  9:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[9]);
				break;
			}
			default:
				putimage(50 * (i - 1), 50 * (j - 1), &img[10]);
				break;
			}
		}
		
	}
	
}