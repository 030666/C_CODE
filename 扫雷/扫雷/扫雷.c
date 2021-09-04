#define  _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10

void init(char showMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL])
{
	//初始化第一张地图
	/*for (int row = 0; row < MAX_ROW; row++)
		for (int col = 0; col < MAX_COL; col++)
			showMap[row][col] = '*';*/
	//mem=>memory 内存
	//set:设置，集合
	//memset的功能就是把一段内存上的每一个字节都设置成一个具体的值
	//二维数组的每个元素都是在一个连续的内存空间上布局的
	memset(showMap,'*',MAX_ROW*MAX_COL);
	//第一个参数表示起始位置，第二个参数表示把这段内存的值设为啥，第三个参数表示这段内存多少字节
	memset(mineMap, '0', MAX_ROW * MAX_COL);
	//随机产生十个位置作为地雷
	//先设置随机种子
	srand((unsigned int)time(0));
	int mineCount = 0;
	while (mineCount< MINE_COUNT) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mineMap[row][col] == '1') {
			continue;
		}
		mineMap[row][col] = '1';
		mineCount++;
	}

}  
//打印地图，希望这一个函数同时具备打印两种地图的功能
//取决于实参填啥
//形参名字叫做"map"不太合适，C++标准库里有一个std::map
void print(char theMap[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			printf("%c",theMap[row][col]);
		}
		printf("\n");
	}
}

void update(char showMap[MAX_ROW][MAX_COL],
    char mineMap[MAX_ROW][MAX_COL],int row,int col){
	//count表示周围的地雷个数
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++) {
		for (int c = col - 1; c <= col + 1; c++) {
			if (r < 0 || r >= MAX_ROW || c < 0 || c >= MAX_COL) {
				//此时r,c坐标超出棋盘的范围，直接跳出
				continue;
			}
			if (r == row && c == col) {
				//如果为这个点本身，不需要循环，直接下次循环
				continue;
			}
			if (mineMap[r][c] == '1') {
				count++;
			}
		}
	}
	//如果直接赋值，此时假设count是2，
	//当前row,col位置的元素就被设置成了ASCLL值为
	//2的字符而不是'2'
	showMap[row][col] ='0'+ count;
}
int main() {
	//1、创建地图并初始化
	char showMap[MAX_ROW][MAX_COL] = { 0 };
	char mineMap[MAX_ROW][MAX_COL] = { 0 };
	init(showMap, mineMap);
	int openedCount = 0;//用来表示翻开的个数
	while (1) {
		//清屏
		system("cls");
		//2、打印地图
		print(showMap);
		//为了验证update函数的正确性，先把地雷的布局也打印出来
		//printf("============================\n");
		//print(mineMap);
		//3、玩家输入坐标
		int row = 0;
		int col = 0;
		printf("请输入坐标（row,col):");
		scanf("%d %d", &row, &col);
		//进行合法性判定
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			printf("你输入的坐标有误！请重新输入！\n");
			continue;
		}
		//判断玩家输入的位置是否已经翻开
		if (showMap[row][col] != '*') {
			printf("您输入的位置已经翻开了！请重新输入！\n");
			continue;
		}
		//4、判定是否踩雷
		if (mineMap[row][col] == '1') {
			printf("您踩雷了！！！游戏结束！\n");
			break;
		}
		//5、更新showMap,显示当前位置周围有多少个雷
		update(showMap, mineMap, row, col);
		//6、进行游戏胜利的判定，统计当前一共翻开了多少个格子
		openedCount++;
		if (openedCount == MAX_ROW * MAX_COL - MINE_COUNT) {
			printf("恭喜你，获胜了！\n");
			break;
		}
	}
	system("pause");
	return 0;
}
