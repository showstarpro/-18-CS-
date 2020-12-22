#include "def.h"
#include "stu.h"
#include "string.h"

char Filename[] = "./data.txt";

int  main(void) {
	Glist GList[10];//多图数组
	int now = 0;//当前操作的图
	char name;
	int op = 1;
	VertexType V[30];
	KeyType VR[100][2];
	int key=0;
	int locate = 0;
	VertexType value ;
	int s = 0;
	int w = 0;
	int gi = 0;
	printf("\n");
	while (op) {
		//system("cls");	printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("-------------------------------------------------\n");
		printf("	  1. CreateCraph	10.DeleteVex\n");
		printf("	  2. DestroyGraph	11.DFSTraverse\n");
		printf("	  3. LocateVex		12.BFSTraverse \n");
		printf("	  4. PutVex			13.SaveGraph\n");
		printf("	  5. FirstAdjvex	14.LoadGraph\n");
		printf("	  6. NextAdjvex		15.WorkGraph\n");
		printf("	  7. InsertVex		16.AddGraph\n");
		printf("      8. DeleteVex		17.DeleteGraph\n");
		printf("      9. InsertVex\n");
		printf("	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("请选择你的操作[0~18]:");
		scanf("%d", &op);
		switch (op) {
		case 1:
			gi = 0;
			do {
				scanf("%d%s", &V[gi].key, V[gi].others);
			} while (V[gi++].key != -1);
			gi = 0;
			do {
				scanf("%d%d", &VR[gi][0], &VR[gi][1]);
			} while (VR[gi++][0] != -1);
			if (CreateCraph(GList[now].G, V, VR) == ERROR) printf("输入数据错，无法创建");
			else printf("二叉树创建成功！\n");
			getchar(); getchar();
			break;
		case 2:
			if (DestroyGraph(GList[now].G) == OK) printf("无向图销毁成功!\n");
			else printf("无向图销毁失败！\n");
			getchar(); getchar();
			break;
		case 3:
			printf("输入你要查找的顶点的关键字：");
			scanf("%d", &key);
			locate = LocateVex(GList[now].G, key);
			printf("%d %s\n", GList[now].G.vertices[locate].data.key, GList[now].G.vertices[locate].data.others);
			getchar(); getchar();
			break;
		case 4:
			printf("输入你要赋值的顶点的关键字：");
			scanf("%d", &key);
			printf("输入你修改后的内容：");
			scanf("%d%s", &value.key, value.others);
			s = PutVex(GList[now].G, key, value);
			if (s) printf("修改成功\n");
			else printf("修改失败\n");
			getchar(); getchar();
			break;
		case 5:
			printf("输入你要查询第一邻接点的关键字： ");
			scanf("%d", &key);
			s = FirstAdjVex(GList[now].G, key);
			if (s == -1)printf("查找失败\n");
			else
			{
				printf("%d%s", GList[now].G.vertices[s].data.key, GList[now].G.vertices[s].data.others);
			}
			getchar(); getchar();
			break;
		case 6:
			printf("输入你要获得邻接点顶点关键字：");
			scanf("%d", &key);
			printf("输入你要邻接点的关键字：");
			scanf("%d", &w);
			s = NextAdjVex(GList[now].G, key, w);
			if (s == -1)printf("查找失败\n");
			else
			{
				printf("%d%s", GList[now].G.vertices[s].data.key, GList[now].G.vertices[s].data.others);
			}
			getchar(); getchar();
			break;
		case 7:
			printf("输入你要插入的顶点:\n");
			scanf("%d%s", &value.key, value.others);
			s= InsertVex(GList[now].G,value);
			if (s == OK)
			{
				printf("插入操作成功");
			}
			else printf("插入操作失败");
			getchar(); getchar();
			break;
		case 8:
			printf("输入你要删除顶点的关键字：");
			scanf("%d", &key);
			s = DeleteVex(GList[now].G, key);
			if (s == OK)
			{
				printf("删除操作成功");
			}
			else printf("删除操作失败");
			getchar(); getchar();
			break;
		case 9:
			printf("输入你要插入的弧：\n");
			scanf("%d%d", &key, &w);
			s = InsertArc(GList[now].G, key, w);
			if (s == OK) printf("插入成功\n");
			else printf("插入失败\n");
			getchar(); getchar();
			break;
		case 10:
			printf("输入你要删除的弧：\n");
			scanf("%d%d", &key, &w);
			s = DeleteArc(GList[now].G, key, w);
			if (s == OK) printf("删除成功\n");
			else printf("删除失败\n");
			getchar(); getchar();
			break;
		case 11:
			printf("深度遍历图的结果：\n");
			DFSTraverse(GList[now].G, visit);
			getchar(); getchar();
			break;
		case 12:
			printf("广度遍历图的结果：\n");
			BFSTraverse(GList[now].G,visit);
			getchar(); getchar();
			break;
		case 13:
			s = SaveGraph(GList[now].G, Filename);
			if (s == OK) printf("存储成功\n");
			else printf("存储失败\n");
			getchar(); getchar();
			break;
		case 14:
			s = LoadGraph(GList[now].G, Filename);
			if (s == OK) printf("读取成功\n");
			else printf("读取失败\n");
			getchar(); getchar();
			break;
		case 16:
			printf("请输入你要添加的图的名字:");
			getchar();
			scanf("%c", &name);
			s = addGraph(GList, name);
			if (s == OK) printf("添加成功");
			else printf("添加失败");
			getchar(); getchar();
			break;
		case 17:
			printf("请输入你要删除的图的名字:");
			getchar();
			scanf("%c", &name);
			s = deleteGraph(GList, name);
			if (s == OK) printf("删除成功");
			else printf("删除失败");
			getchar(); getchar();
			break;
		case 15:
			printf("请输入你要操作的图的名字：");
			getchar();
			scanf("%c", &name);
			now = workGraph(GList, name);
			if (now != -1) printf("操作成功");
			else printf("操作失败");
			getchar(); getchar();
			break;
		case 0:
			break;
		}//end of switch
	}//end of while
	printf("欢迎下次再使用本系统！\n");
	return 0;
}//end of main()
