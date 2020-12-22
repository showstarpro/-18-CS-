#include "def.h"
#include "stu.h"
#include "string.h"

char Filename[] = "./data.txt";

int  main(void) {
	Glist GList[10];//��ͼ����
	int now = 0;//��ǰ������ͼ
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
		printf("��ѡ����Ĳ���[0~18]:");
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
			if (CreateCraph(GList[now].G, V, VR) == ERROR) printf("�������ݴ��޷�����");
			else printf("�����������ɹ���\n");
			getchar(); getchar();
			break;
		case 2:
			if (DestroyGraph(GList[now].G) == OK) printf("����ͼ���ٳɹ�!\n");
			else printf("����ͼ����ʧ�ܣ�\n");
			getchar(); getchar();
			break;
		case 3:
			printf("������Ҫ���ҵĶ���Ĺؼ��֣�");
			scanf("%d", &key);
			locate = LocateVex(GList[now].G, key);
			printf("%d %s\n", GList[now].G.vertices[locate].data.key, GList[now].G.vertices[locate].data.others);
			getchar(); getchar();
			break;
		case 4:
			printf("������Ҫ��ֵ�Ķ���Ĺؼ��֣�");
			scanf("%d", &key);
			printf("�������޸ĺ�����ݣ�");
			scanf("%d%s", &value.key, value.others);
			s = PutVex(GList[now].G, key, value);
			if (s) printf("�޸ĳɹ�\n");
			else printf("�޸�ʧ��\n");
			getchar(); getchar();
			break;
		case 5:
			printf("������Ҫ��ѯ��һ�ڽӵ�Ĺؼ��֣� ");
			scanf("%d", &key);
			s = FirstAdjVex(GList[now].G, key);
			if (s == -1)printf("����ʧ��\n");
			else
			{
				printf("%d%s", GList[now].G.vertices[s].data.key, GList[now].G.vertices[s].data.others);
			}
			getchar(); getchar();
			break;
		case 6:
			printf("������Ҫ����ڽӵ㶥��ؼ��֣�");
			scanf("%d", &key);
			printf("������Ҫ�ڽӵ�Ĺؼ��֣�");
			scanf("%d", &w);
			s = NextAdjVex(GList[now].G, key, w);
			if (s == -1)printf("����ʧ��\n");
			else
			{
				printf("%d%s", GList[now].G.vertices[s].data.key, GList[now].G.vertices[s].data.others);
			}
			getchar(); getchar();
			break;
		case 7:
			printf("������Ҫ����Ķ���:\n");
			scanf("%d%s", &value.key, value.others);
			s= InsertVex(GList[now].G,value);
			if (s == OK)
			{
				printf("��������ɹ�");
			}
			else printf("�������ʧ��");
			getchar(); getchar();
			break;
		case 8:
			printf("������Ҫɾ������Ĺؼ��֣�");
			scanf("%d", &key);
			s = DeleteVex(GList[now].G, key);
			if (s == OK)
			{
				printf("ɾ�������ɹ�");
			}
			else printf("ɾ������ʧ��");
			getchar(); getchar();
			break;
		case 9:
			printf("������Ҫ����Ļ���\n");
			scanf("%d%d", &key, &w);
			s = InsertArc(GList[now].G, key, w);
			if (s == OK) printf("����ɹ�\n");
			else printf("����ʧ��\n");
			getchar(); getchar();
			break;
		case 10:
			printf("������Ҫɾ���Ļ���\n");
			scanf("%d%d", &key, &w);
			s = DeleteArc(GList[now].G, key, w);
			if (s == OK) printf("ɾ���ɹ�\n");
			else printf("ɾ��ʧ��\n");
			getchar(); getchar();
			break;
		case 11:
			printf("��ȱ���ͼ�Ľ����\n");
			DFSTraverse(GList[now].G, visit);
			getchar(); getchar();
			break;
		case 12:
			printf("��ȱ���ͼ�Ľ����\n");
			BFSTraverse(GList[now].G,visit);
			getchar(); getchar();
			break;
		case 13:
			s = SaveGraph(GList[now].G, Filename);
			if (s == OK) printf("�洢�ɹ�\n");
			else printf("�洢ʧ��\n");
			getchar(); getchar();
			break;
		case 14:
			s = LoadGraph(GList[now].G, Filename);
			if (s == OK) printf("��ȡ�ɹ�\n");
			else printf("��ȡʧ��\n");
			getchar(); getchar();
			break;
		case 16:
			printf("��������Ҫ��ӵ�ͼ������:");
			getchar();
			scanf("%c", &name);
			s = addGraph(GList, name);
			if (s == OK) printf("��ӳɹ�");
			else printf("���ʧ��");
			getchar(); getchar();
			break;
		case 17:
			printf("��������Ҫɾ����ͼ������:");
			getchar();
			scanf("%c", &name);
			s = deleteGraph(GList, name);
			if (s == OK) printf("ɾ���ɹ�");
			else printf("ɾ��ʧ��");
			getchar(); getchar();
			break;
		case 15:
			printf("��������Ҫ������ͼ�����֣�");
			getchar();
			scanf("%c", &name);
			now = workGraph(GList, name);
			if (now != -1) printf("�����ɹ�");
			else printf("����ʧ��");
			getchar(); getchar();
			break;
		case 0:
			break;
		}//end of switch
	}//end of while
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
	return 0;
}//end of main()
