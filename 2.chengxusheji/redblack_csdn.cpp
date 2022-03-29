#include <iostream>
using namespace std;
int w, h;
int startI, startJ;
char room[25][25];
int cnt;
int sx[4] = {0, 0, -1, 1};
int sy[4] = {-1, 1, 0, 0};
void dfs(int x, int y)
{
	cnt++;
	room[x][y] = '#';
	for (int i = 0; i < 4; i++)
	{
		int nx = x + sx[i];
		int ny = y + sy[i];
		if (nx >= 0 && nx < h && ny >= 0 && ny < w && room[nx][ny] == '.')
		{
			dfs(nx, ny);
		}
	}
}
int main()
{
	cin >> w >> h;
	cnt = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> room[i][j];
			if (room[i][j] == '@')
			{
				startI = i;
				startJ = j;
			}
		}
	}
	dfs(startI, startJ);
	cout << cnt << endl;
	return 0;
}
