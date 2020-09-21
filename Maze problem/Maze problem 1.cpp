// Maze problem 1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<cstring>

struct Node//����ڵ�
{
	int x, y;
	int pre;
	Node(){}
	Node(int xx,int yy,int ppre):x(xx),y(yy),pre(ppre){}
};
Node q[5 * 5 + 10];//��һ��������������У���ΪҪ���·��������ֱ�ӽ��ڵ㶪��
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int visited[10][10];//����Ƿ���չ��
int maze[10][10];
bool test(int x, int y)
{
	if (x < 0 || x >= 5 || y < 0 || y >= 5)
		return false;
	if (visited[x][y])
		return false;
	if (maze[x][y])
		return false;
	return true;
}
int head = 0;
int tail = 1;

void BFS()
{
	q[head] = Node(0, 0, -1);
	visited[0][0] = 1;
	while (head < tail)//���鲻Ϊ��
	{
		Node temp = q[head];
		if (temp.x == 4 && temp.y == 4)
			return;
		for (int i = 0; i < 4; ++i)//���ĸ����򣬽�����չ
		{
			int newx = temp.x + dx[i];
			int newy = temp.y + dy[i];
			if (test(newx, newy)) {
				q[tail] = Node(newx, newy, head);
				tail++;//���
				visited[newx][newy] = 1;
			}
		}
		head++;
	}
}

void print(int v)
{
	if (q[v].pre != -1)
	{
		print(q[v].pre);
		printf("(%d,%d)\n", q[v].x, q[v].y);
	}
	
}
int main()
{
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			std::cin >> maze[i][j];
	memset(visited, 0, sizeof(visited));
	BFS();
	std::cout << "(0,0)" << std::endl;
	print(head);
	system("pause");
    return 0;
}

