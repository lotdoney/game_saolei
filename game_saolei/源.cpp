#include "stdio.h"
#include "graphics.h"
#include "windows.h"
#include "time.h" //随机函数中会用到的
void apply( );
void draw(int map[ ][12], IMAGE *img);
int play(int map[][12]);
int win;//表示翻开的个数
void sweep(int map[][12], int x, int y);//地柜翻开
HWND hwnd;
int main( )
{
	do 
	{
		apply();
	//	if (MessageBox(hwnd,"再来一局？","退出!",MB_RETRYCANCEL)==IDCANCEL)
		//{
			//break;
		//}

	} while (1);


	return 0;
}
void apply()
{
	//MessageBox(hwnd, "开始游戏", "begin", MB_OK);
	//埋雷
	int map[12][12] = {0};//扫描区域需要辅助
	//防止数组越界
	int m, n;
	int	i, j;
	srand((unsigned)time(NULL));//真的的随机种子
	for (n=0;n<1; )
	{
		//随机埋雷产生1-10的数，即为数组下标
		i = 1 + rand( )%10;	
		j = 1 + rand( )%10;
		if (map[i][j]==0)
		{
			//用-1代表雷
			map[i][j] = -1;//是一个赋值，不是==
			n++;//保证产生了10个雷，要是放在前面不一定保证会埋十个
		}
	}
	for (i=1;i<=10;i++)
	{
		for (j=1;j<=10;j++)
		{
			if (map[i][j]!=-1)//不是雷的情况下判断
			{
				//遍历周围的方块
				for (m=i-1;m<=i+1;m++)
				{
					for (n=j-1;n<=j+1;n++)
					{
						if (map[m][n]==-1)//判断出周围的雷
						{
							map[i][j]++;
						}
					}
				}
			}
		}
	}

	initgraph(500,500);//建立图像窗口
	//initgraph在c++中使用
	IMAGE img[12];//加载图片
	loadimage(&img[0], "0.jpg",50,50);
	loadimage(&img[1], "1.jpg", 50, 50);
	loadimage(&img[2], "2.jpg", 50, 50);
	loadimage(&img[3], "3.jpg", 50, 50);
	loadimage(&img[4], "4.jpg", 50, 50);
	loadimage(&img[5], "5.jpg", 50, 50);
	loadimage(&img[6], "6.jpg", 50, 50);
	loadimage(&img[7], "7.jpg", 50, 50);
	loadimage(&img[8], "8.jpg", 50, 50);
	loadimage(&img[9], "雷.jpg", 50, 50);
	loadimage(&img[10], "地图.jpg", 50, 50);
	loadimage(&img[11], "标记.jpg", 50, 50);
	win = 0;//初始化胜利条件
	while (1)
	{
		draw(map, img);
		if (play(map)==9)//表示点开了一个雷
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

void draw(int map[][12],  IMAGE *img)//画图
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
			switch (map[i][j])//鼠标左键点击+10
				//当鼠标点击的时候才开始显示图标
			{
			case  -1+10:
			{
				putimage(50 * (i - 1), 50 * (j - 1), &img[9]);//绘制坐标
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
int play(int map[ ][12])//鼠标操作
{
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg( );//获取鼠标消息
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN://鼠标左键按下
		if (map[m.x/50+1][m.y/50+1]>9)
		{
			continue;//大于9表示已经点开退出
		}
		if (map[m.x/50+1][m.y/50+1]==0)
		{
			//另写一个函数
			sweep(map,m.x/ 50 + 1, m.y / 50+1);
		}
		else
		{
			map[m.x / 50 + 1][m.y / 50 + 1] += 10;
			win++;
		}
		return 	map[m.x / 50 + 1][m.y / 50 + 1];
		break;

		case WM_RBUTTONDOWN://表示鼠标右键点击
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
			if (i>=1&&i<=10&&j>=1&&j<=10)//不能越界
			{
				if (map[i][j]<9)//没有翻开
				{
					if (map[i][j]==0)
					{
						sweep(map, i, j);//递归点开周围
					}
					else if (map[i][j]==-1)
					{
						continue;
					}
					else // 不能翻开，不为空，不进行递归操作
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