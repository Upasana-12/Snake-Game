#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<dos.h>
using namespace std;
int score=0;
void print(char**);

class food
{
	public:
	int fx,fy;
	char fvalue;
	food()
	{
		fx=7;
		fy=34;
		fvalue='F';
	}
	void food_gen()
	{
		fx=rand()%8+1;
		fy=rand()%8+1;
	}
};
class snake
{
	public:
	int sx,sy;
	char svalue;
	static void initialise(vector<snake> &s)
	{
		int i=0,c=4;
		while(i<4)
		{
			snake s1;
			s1.sx=4;
			s1.sy=c++;
			if(i==0)
			{
				s1.svalue='T';
			}
			else if(i==3)
			{
				s1.svalue='H';
			}
			else
			{
				s1.svalue='#';
			}
			s.push_back(s1);
			i++;
		}

	}
};
void change_every(char** board,vector<snake> &s,food f)
{
   int k;
   for(k=0;k<s.size();k++)
   {
   	  board[s[k].sx][s[k].sy]=s[k].svalue;
   }
   board[f.fx][f.fy]=f.fvalue;
}


int move(char **board,vector<snake> &s,char ch,food &f)
{
	int i,j;
	int l=s.size()-1;
	int px=s[l].sx,swapx;
	int py=s[l].sy,swapy;
	if(ch=='d')
	{
		s[l].sy++;
		if(s[l].sy==79)
		return 0;
	}
	else if(ch=='a')
	{
		s[l].sy--;
		if(s[l].sy==0)
		return 0;
	}
	else if(ch=='w')
	{
		s[l].sx--;
		if(s[l].sx==0)
		return 0;
	}
	else if(ch=='s')
	{
		s[l].sx++;
		if(s[l].sx==39)
		return 0;
	}
	else
	{
		return 1;
	}
	for(i=l-1;i>=0;i--)
	{
		swapx=s[i].sx;
		swapy=s[i].sy;
		s[i].sx=px;
		s[i].sy=py;
		if(s[i].sx==s[l].sx&&s[i].sy==s[l].sy)
		return 0;
		px=swapx;
		py=swapy;
	}
	if(s[l].sx==f.fx&&s[l].sy==f.fy)
	{
		snake s1;
		s1.sx=px;
		s1.sy=py;
		s1.svalue='T';
		s[0].svalue='#';
		s.insert(s.begin(),s1);
		f.food_gen();
		score++;
	}
	board[px][py]=' ';
	return 1;
}

void print(char** board)
{
	int i,j;
	for(i=0;i<40;i++)
	{
		for(j=0;j<80;j++)
		{
			cout<<board[i][j];
		}
		cout<<endl;
	}
	
}
void initialise_board(char** board)
{
	int i,j;
    for(i=0;i<40;i++)
	{
		for(j=0;j<80;j++)
		{
			if(i==0 || i==39 || j==0 || j==79)
			board[i][j]='*';
			else
			board[i][j]=' ';
		}
	}
}
int main()
{
	char ch,ch1;
	food f;
	vector<snake> s;
	snake::initialise(s);
	ch='d',ch1='d';
	char *board=new char[40];
		int i,j;
		for(i=0;i<40;i++)
		{
			board[i]=new char[80];
		}
		intiatlise_board(board);

	while(1)
		{
			if(kbhit())
			{
				ch=getch();
			}
			
			if((ch=='a'&& ch1!='d')||(ch=='s'&& ch1!='w')||(ch=='d'&& ch1!='a')||(ch=='w'&&ch1!='s'))
			{
				if(move(board,s,ch,f))
				{
					change_every(board,s,f);
					print(board);
					ch1=ch;
				}
				else
				{
					change_every(board,s,f);
					print(board);
					printf("\nScore:         %d",score);
					printf("~~~~~~~~~~Game Over~~~~~~~~~~");
					break;
				}
			}
			else
			{
				if(move(board,s,ch1,f))
				{
					change_every(board,s,f);
					print(board);
				}
				else
				{
					change_every(board,s,f);
					print(board);
					printf("\nScore:         %d",score);
					printf("~~~~~~~~~~Game Over~~~~~~~~~~~");
					break;
				}
			}
			Sleep(50);
			system("CLS");
	    }	
}
