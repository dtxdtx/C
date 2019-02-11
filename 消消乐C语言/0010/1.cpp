
#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#pragma comment(lib,"Winmm.lib")
#include <Mmsystem.h>

int gamestatus=0;
int grade;
int step;
int map[10][10]={0};

IMAGE image[9];
IMAGE img_bj;
IMAGE img_ru;
IMAGE img_game;
IMAGE img_pause;
IMAGE img_back;
IMAGE img_pro;
IMAGE pause_img;

typedef struct S
{
	char name[20];
	int grade;
}S;

void loading()
{
	loadimage(&image[0],".\\资源文件1807004631丁霆霄\\1.jpg",50,50);
	loadimage(&image[1],".\\资源文件1807004631丁霆霄\\2.jpg",50,50);
	loadimage(&image[2],".\\资源文件1807004631丁霆霄\\3.jpg",50,50);
	loadimage(&image[3],".\\资源文件1807004631丁霆霄\\4.jpg",50,50);
	loadimage(&image[4],".\\资源文件1807004631丁霆霄\\5.jpg",50,50);
	loadimage(&image[5],".\\资源文件1807004631丁霆霄\\6.jpg",50,50);
	loadimage(&image[6],".\\资源文件1807004631丁霆霄\\7.jpg",50,50);
	loadimage(&image[7],".\\资源文件1807004631丁霆霄\\8.jpg",50,50);
	loadimage(&image[8],".\\资源文件1807004631丁霆霄\\9.jpg",50,50);
	loadimage(&img_bj,".\\资源文件1807004631丁霆霄\\背景图片.jpg",600,600);
	loadimage(&img_ru,".\\资源文件1807004631丁霆霄\\游戏规则.jpg",600,600);
	loadimage(&img_game,".\\资源文件1807004631丁霆霄\\游戏背景.jpg",600,600);
	loadimage(&img_pause,".\\资源文件1807004631丁霆霄\\暂停.jpg",50,50);
	loadimage(&img_back,".\\资源文件1807004631丁霆霄\\返回.jpg",100,100);
	loadimage(&img_pro,".\\资源文件1807004631丁霆霄\\提示.jpg",50,50);
	loadimage(&pause_img,".\\资源文件1807004631丁霆霄\\暂停背景.jpg",600,600);
}

int start_menu()
{
	initgraph(600,600);
	mciSendString("open .\\资源文件1807004631丁霆霄\\背景.mp3 alias bkmusic", NULL, 0, NULL);
	mciSendString("play bkmusic repeat", NULL, 0, NULL);
	putimage(0,0,&img_bj);
	setbkmode(TRANSPARENT);
	MOUSEMSG msg;
	while(1)
	{
		settextcolor(BLACK);
		settextstyle(50,0,_T("黑体"));
		outtextxy(200,180,"开始游戏");
		outtextxy(220,250,"排行榜");
		outtextxy(200,320,"游戏规则");
		outtextxy(250,390,"退出");
		setlinecolor(RGB(253,236,166));
		setlinestyle(PS_SOLID|PS_ENDCAP_ROUND,5);
		msg=GetMouseMsg();
		setfillcolor(RGB(254,234,210));
		if (msg.x>=200&&msg.x<=400&&msg.y>=180&&msg.y<=230)
		{
			fillrectangle(200,180,400,230);
			if (msg.uMsg==WM_LBUTTONUP)return 1;
		}
		else if (msg.x>=200&&msg.x<=400&&msg.y>=250&&msg.y<=300)
		{
			fillrectangle(200,250,400,300);
			if (msg.uMsg==WM_LBUTTONUP)return 2;
		}
		else if (msg.x>=200&&msg.x<=400&&msg.y>=320&&msg.y<=370)
		{
			fillrectangle(200,320,400,370);
			if (msg.uMsg==WM_LBUTTONUP)return 3;
		}
		else if (msg.x>=200&&msg.x<=400&&msg.y>=390&&msg.y<=440)
		{
			fillrectangle(200,390,400,440);
			if (msg.uMsg==WM_LBUTTONUP)return 4;
		}
		else
		{
			setfillcolor(RGB(255,202,24));
			fillrectangle(200,180,400,230);
			fillrectangle(200,250,400,300);
			fillrectangle(200,320,400,370);
			fillrectangle(200,390,400,440);
		}
	}
}

int pause_menu()
{
	cleardevice();
	putimage(0,0,&pause_img);
	setbkmode(TRANSPARENT);
	setlinestyle(PS_SOLID|PS_ENDCAP_ROUND,5);
	setlinecolor(RGB(94,74,61));
	settextcolor(RGB(243,217,214));
	settextstyle(50,0,_T("黑体"));
	MOUSEMSG msg;
	while(1)
	{
		outtextxy(70,250,"继");
		outtextxy(70,300,"续");
		outtextxy(70,350,"游");
		outtextxy(70,400,"戏");
		outtextxy(430,300,"退");
		outtextxy(430,350,"出");
		msg=GetMouseMsg();
		if (msg.x>=70&&msg.x<=120&&msg.y>=250&&msg.y<=450)
		{
			setfillcolor(WHITE);
			fillrectangle(70,250,120,450);
			if (msg.uMsg==WM_LBUTTONUP)return 1;
		}
		else if (msg.x>=430&&msg.x<=480&&msg.y>=250&&msg.y<=450)
		{	
			setfillcolor(WHITE);
			fillrectangle(430,250,480,450);
			if (msg.uMsg==WM_LBUTTONUP)return 0;
		}
		else
		{
			setfillcolor(RGB(94,74,61));
			fillrectangle(70,250,120,450);
			fillrectangle(430,250,480,450);
		}
	}
}

void startup()
{
	step=10;
	grade=0;
	int num;
	int clear();
	do 
	{
		for (int i=0;i<10;i++)
		{
			for (int j=0;j<10;j++)
			{
				map[i][j]=rand()%9+1;
			}
		}
		num=clear();
	} while (num!=0);
}

void draw()
{
	putimage(0,0,&img_game);
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
		{
			putimage(i*50,j*50,&image[map[i][j]-1]);
		}
	}
	char s[20],arr[20];
	settextcolor(BLACK);
	settextstyle(20,0,_T("黑体"));
	sprintf(s,"得分：%d",grade);
	outtextxy(50,550,s);
	sprintf(arr,"剩余步数：%d",step);
	outtextxy(450,550,arr);
	putimage(550,0,&img_pause);
	putimage(550,50,&img_pro);
	Sleep(200);
}

int clear()
{
	int num=0;
	int record[10][10];
	int k,l;
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
		{
			if (map[i][j]==0)
			{
				continue;
			}
			for (k=1;j+k<=9&&map[i][j+k]==map[i][j];k++);
			{
				if (k>=3)
				{
					for (int q=0;q<k;q++)
					{
						record[i][j+q]=0;
					}
					if (k==5)
					{
						for (int a=0;a<10;a++)
						{
							for(int b=0;b<10;b++)
							{
								if (map[a][b]==map[i][j])
								{
									record[a][b]=0;
								}
							}
						}
					}
				}
			}
			for (l=1;i+l<=9&&map[i+l][j]==map[i][j];l++);
			{
				if (l>=3)
				{
					for (int q=0;q<l;q++)
					{
						record[i+q][j]=0;
					}
					if (l==5)
					{
						for (int a=0;a<10;a++)
						{
							for(int b=0;b<10;b++)
							{
								if (map[a][b]==map[i][j])
								{
									record[a][b]=0;
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
			if(record[i][j]==0)
			{
				map[i][j]=0;
				num++;
			}
	}
	if(num>=3)
	{
		char cmdString1[100] = "open ";
		strcat(cmdString1,".\\资源文件1807004631丁霆霄\\消除.wav");
		strcat(cmdString1," alias tmpmusic");
		mciSendString((LPCTSTR)"close tmpmusic", NULL, 0, NULL);
		mciSendString((LPCTSTR)cmdString1, NULL, 0, NULL);
		mciSendString((LPCTSTR)"play tmpmusic", NULL, 0, NULL);
	}
	return num;
}

void drop()
{
	int i,j,k;
	for (i=0;i<10;i++)
	{
		for (j=9;j>=0;j--)
		{
			while (map[i][j]==0)
			{
				for (k=j;k>0;k--)
				{
					map[i][k]=map[i][k-1];
				}
				map[i][0]=rand()%9+1;
			}
		}
	}

}

void random()
{
	int flag=0;
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
		{
			if (i<=8&&map[i][j]==map[i+1][j])
			{
				if ((i<=7&&j<=8&&map[i+2][j+1]==map[i][j])||(i<=7&&j>=1&&map[i+2][j-1]==map[i][j])||(i>=1&&j<=8&&map[i-1][j+1]==map[i][j])||(i>=1&&j>=1&&map[i-1][j-1]==map[i][j])
					||(i<=6&&map[i+3][j]==map[i][j])||(i>=2&&map[i-2][j]==map[i][j]))
					flag++;
			}
			if (j<=8&&map[i][j]==map[i][j+1])
			{
				if ((i<=8&&j<=7&&map[i+1][j+2]==map[i][j])||(j<=7&&i>=1&&map[i-1][j+2]==map[i][j])||(i<=8&&j>=1&&map[i+1][j-1]==map[i][j])||(i>=1&&j>=1&&map[i-1][j-1]==map[i][j])
					||(j<=6&&map[i][j+3]==map[i][j])||(j>=2&&map[i][j-2]==map[i][j]))
					flag++;
			}
			if ((i<=7&&map[i][j]==map[i+2][j])&&(i<=8&&j<=8&&map[i+1][j+1]==map[i][j]||(i<=8&&j>=1&&map[i+1][j-1]==map[i][j])))
				flag++;
			if ((j<=7&&map[i][j]==map[i][j+2])&&(i<=8&&j<=8&&map[i+1][j+1]==map[i][j]||(i>=1&&j<=8&&map[i-1][j+1]==map[i][j])))
				flag++;
		}
	}
	if(flag==0)
	{
		for (int i=0;i<10;i++)
		{
			for (int j=0;j<10;j++)
			{
				map[i][j]=rand()%9+1;
			}
		}
		int num;
		num=clear();
		do 
		{
			drop();
			num=clear();
		} while (num!=0);
	}
}

void prompt()
{
	setlinecolor(RGB(217,178,179));
	setlinestyle(PS_SOLID|PS_ENDCAP_ROUND,3);
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
		{
			if (map[i][j]==map[i+1][j])
			{
				if (i<=7&&j<=8&&map[i+2][j+1]==map[i][j])
				{
					rectangle((i+2)*50,(j+1)*50,(i+3)*50,(j+2)*50);
					rectangle((i+2)*50,j*50,(i+3)*50,(j+1)*50);
					Sleep(1000);
					return;
				}
				if (i<=7&&j>=1&&map[i+2][j-1]==map[i][j])
				{
					rectangle((i+2)*50,(j-1)*50,(i+3)*50,j*50);
					rectangle((i+2)*50,j*50,(i+3)*50,(j+1)*50);
					Sleep(1000);
					return;
				}
				if (i>=1&&j<=8&&map[i-1][j+1]==map[i][j])
				{
					rectangle((i-1)*50,(j+1)*50,i*50,(j+2)*50);
					rectangle((i-1)*50,j*50,i*50,(j+1)*50);
					Sleep(1000);
					return;
				}
				if (i>=1&&j>=1&&map[i-1][j-1]==map[i][j])
				{
					rectangle((i-1)*50,(j-1)*50,i*50,j*50);
					rectangle((i-1)*50,j*50,i*50,(j+1)*50);
					Sleep(1000);
					return;
				}
				if (i<=6&&map[i+3][j]==map[i][j])
				{
					rectangle((i+3)*50,j*50,(i+4)*50,(j+1)*50);
					rectangle((i+2)*50,j*50,(i+3)*50,(j+1)*50);
					Sleep(1000);
					return;
				}
				if (i>=2&&map[i-2][j]==map[i][j])
				{
					rectangle((i-2)*50,j*50,(i-1)*50,(j+1)*50);
					rectangle((i-1)*50,j*50,i*50,(j+1)*50);
					Sleep(1000);
					return;
				}
			}
			if (j<=8&&map[i][j]==map[i][j+1])
			{
				if (i<=8&&j<=7&&map[i+1][j+2]==map[i][j])
				{
					rectangle((i+1)*50,(j+2)*50,(i+2)*50,(j+3)*50);
					rectangle(i*50,(j+2)*50,(i+1)*50,(j+3)*50);
					Sleep(1000);
					return;
				}
				if (i>=1&&j<=7&&map[i-1][j+2]==map[i][j])
				{
					rectangle((i-1)*50,(j+2)*50,i*50,(j+3)*50);
					rectangle(i*50,(j+2)*50,(i+1)*50,(j+3)*50);
					Sleep(1000);
					return;
				}
				if (j>=1&&i<=8&&map[i+1][j-1]==map[i][j])
				{
					rectangle((i+1)*50,(j-1)*50,(i+2)*50,j*50);
					rectangle(i*50,(j-1)*50,(i+1)*50,j*50);
					Sleep(1000);
					return;
				}
				if (i>=1&&j>=1&&map[i-1][j-1]==map[i][j])
				{
					rectangle((i-1)*50,(j-1)*50,i*50,j*50);
					rectangle(i*50,(j-1)*50,(i+1)*50,j*50);
					Sleep(1000);
					return;
				}
				if (j<=6&&map[i][j+3]==map[i][j])
				{
					rectangle(i*50,(j+3)*50,(i+1)*50,(j+4)*50);
					rectangle(i*50,(j+2)*50,(i+1)*50,(j+3)*50);
					Sleep(1000);
					return;
				}
				if (j>=2&&map[i][j-2]==map[i][j])
				{
					rectangle(i*50,(j-2)*50,(i+1)*50,(j-1)*50);
					rectangle(i*50,(j-1)*50,(i+1)*50,j*50);
					Sleep(1000);
					return;
				}
			}
			if (i<=7&&j<=8&&map[i][j]==map[i+2][j]&&map[i+1][j+1]==map[i][j])
			{
				rectangle((i+1)*50,j*50,(i+2)*50,(j+1)*50);
				rectangle((i+1)*50,(j+1)*50,(i+2)*50,(j+2)*50);
				Sleep(1000);
				return;
			}
			if (i<=7&&j>=1&&map[i][j]==map[i+2][j]&&map[i+1][j-1]==map[i][j])
			{
				rectangle((i+1)*50,j*50,(i+2)*50,(j+1)*50);
				rectangle((i+1)*50,(j-1)*50,(i+2)*50,j*50);
				Sleep(1000);
				return;
			}
			if (j<=7&&i<=8&&map[i][j]==map[i][j+2]&&map[i+1][j+1]==map[i][j])
			{
				rectangle(i*50,(j+1)*50,(i+1)*50,(j+2)*50);
				rectangle((i+1)*50,(j+1)*50,(i+2)*50,(j+2)*50);
				Sleep(1000);
				return;
			}
			if (j<=7&&i>=1&&map[i][j]==map[i][j+2]&&map[i-1][j+1]==map[i][j])
			{
				rectangle(i*50,(j+1)*50,(i+1)*50,(j+2)*50);
				rectangle((i-1)*50,(j+1)*50,i*50,(j+2)*50);
				Sleep(1000);
				return;
			}
		}
	}
}

void save()
{
	closegraph();
	system("cls");
	FILE *fp;
	S people;
	printf("你的名字:");
	scanf("%s",&people.name);
	people.grade=grade;
	fp=fopen(".\\资源文件1807004631丁霆霄\\rand.txt","a");
	if (fp==NULL)
	{
		printf("无法打开文件\n");
		system("pause");
		exit(1);
	}
	fprintf(fp,"%s\t%d\n",people.name,people.grade);
	fclose(fp);
}

void readrand()
{
	closegraph();
	system("cls");
	FILE *fp;
	S mem[100],max;
	int i=0,j=0;
	int f;
	fp=fopen(".\\资源文件1807004631丁霆霄\\rand.txt","rt+");
	if (fp==NULL)
	{
		printf("暂无数据\n");
		system("pause");
		gamestatus=0;
		return;
	}
	do
	{
		f=fscanf(fp,"%s%d",mem[i].name,&mem[i].grade);
		i++;
	}while(i<100&&f!=EOF);
	for (int p=0;p<i-1;p++)
	{
		for (int q=0;q<i-1-p;q++)
		{
			if (mem[q].grade<mem[q+1].grade)
			{
				max=mem[q+1];
				mem[q+1]=mem[q];
				mem[q]=max;
			}
		}
	}
	while (j<i-1)
	{		
		printf("%d\t%s\t%d\n",j+1,mem[j].name,mem[j].grade);
		j++;
	}
	fclose(fp);
	system("pause");
	gamestatus=0;
	system("exit");
}

void rule()
{
	cleardevice();
	putimage(0,0,&img_ru);
	putimage(500,0,&img_back);
	MOUSEMSG msg;
	while(1)
	{
		msg=GetMouseMsg();
		if ((msg.x>=500&&msg.x<=600&&msg.y>=0&&msg.y<=100)&&(msg.uMsg==WM_LBUTTONUP))
		{
			gamestatus=0;
			return;
		}
	}
}

void UpdataWithoutInput()
{
	int num=0;
	num=clear();
	grade+=num;
	do
	{
		draw();
		drop();
		draw();
		num=clear();
		grade+=num;
	}while(num>=3);
	random();
}

void UpdateWithInput()
{
	int t=0;
	int num=0;
	int x1,x2,y1,y2;
	int flag=0;
	MOUSEMSG msg,msg1,msg2;
	msg1.x=0;
	msg2.x=0;
	while (msg1.x==0||msg2.x==0)
	{
		msg=GetMouseMsg();
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			msg1=msg;
			break;
		case WM_LBUTTONUP:
			msg2=msg;
			break;
		}
		if (msg2.x!=0&&msg1.x==0)
		{
			return;
		}
		if (msg.x>=500&&msg.x<=600&&msg.y>=0&&msg.y<=50)
		{

			if (msg.uMsg==WM_LBUTTONUP)
			{
				gamestatus=pause_menu();
				return;
			}
		}
		else if (msg.x>=550&&msg.x<=600&&msg.y>=50&&msg.y<=100)
		{
			if(msg.uMsg==WM_LBUTTONUP)
				{
					prompt();
					return;
				}
		}

	}
	x1=msg1.x/50;
	x2=msg2.x/50;
	y1=msg1.y/50;
	y2=msg2.y/50;
	if(x1==x2&&y1==y2)return;
	if (((x1 == x2&&y1 == y2 + 1) ||(x1 == x2&&y1 == y2 - 1) ||(x1 == x2 - 1 && y1 == y2) ||(x1 == x2 + 1 && y1 == y2))&&x1<=9&&y1<=9&&x2<=9&&y2<=9)
	{
		t=map[x1][y1];
		map[x1][y1]=map[x2][y2];
		map[x2][y2]=t;
		draw();
		num=clear();
		grade+=num;
		/*if (num<3)
		{
			map[x2][y2]=map[x1][y1];
			map[x1][y1]=t;
		}*/
	}
	if (num>=3)
	{
		step--;
		if (num==4||num==7)
		{
			if (x1==x2)
			{
				for (int i=0;i<10;i++)
				{
					map[x1][i]=0;
				}
			}
			if (y1==y2)
			{
				for (int i=0;i<10;i++)
				{
					map[i][y1]=0;
				}
			}
			grade+=10;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	loading();
	while(1)
	{
		if(gamestatus==0)
		{
			gamestatus=start_menu();
		}
		if(gamestatus==1)
		{
			cleardevice();
			startup();
			do
			{
				
				if(MouseHit())
					UpdateWithInput();
				if(gamestatus==0)
					break;
				UpdataWithoutInput();
			}while(step!=0);

			if(gamestatus==1)
			{
				save();
				gamestatus=0;
			}
		}
		if (gamestatus==2)
		{
			readrand();
		}
		if (gamestatus==3)
		{
			rule();
		}
		if(gamestatus==4)
		{
			return 0;
		}
	}
}
