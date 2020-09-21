// Birthday Cake.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int N, M;
int min_area = 1 << 30;
int area = 0;//当前的总面积
int minv[21];

int Minv(int m)//1~m层的最小体积之和
{
	if (minv[m] != -1)
		return minv[m];
	if (m == 0)
		minv[m]= 0;
	else
		minv[m] = m*m*m + Minv(m - 1);
	return minv[m];
}
void Dfs(int v, int m, int r, int h)
{
	if (m == 0)
	{

		if (v)return;
		else {
			min_area = min(area, min_area);
			return;
		}
	}
	if (v <= 0) return;
	if (area + 2 * v / r > min_area) {
		return;
	}//最小表面积剪枝，最优性剪枝
	if (v < minv[m]) {
		return;
	}//可行性剪枝，剩余体积小于最小体积
	if (r < m || h < m) {
		return;
	}//可行性剪枝，再往上搭，高度已经无法安排，或者半径已经无法安排
	for (int rr = r; rr >= m; --rr)
	{
		if (m == M) {
			area = rr*rr;
		}
		for (int hh = h; hh >= m; --hh)
		{
			area += 2 * rr*hh;
			
			Dfs(v - rr*rr*hh, m - 1, rr - 1, hh - 1);
			area -= 2 * rr*hh;
		}
	}
}
int main()
{
	std::cout << "Enter N(N<=1000):";
	std::cin >> N;
	std::cout << "Enter M(M<=20):";
	std::cin >> M;
	memset(minv, -1, sizeof(minv));
	Minv(M);
	int R = int(sqrt(double(N) - minv[M - 1]));
	int H = int((double(N) - minv[M - 1]) / (M*M));
	Dfs(N, M, R, H);
	if (min_area == 1 << 30)
		std::cout << 0 << std::endl;
	else std::cout << min_area <<std:: endl;
	system("pause");
    return 0;
}

