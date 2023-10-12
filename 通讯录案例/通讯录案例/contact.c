#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void InitContact(struct Contact* ps) {
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0; //设置通讯录只有0个元素
}

void AddContact(struct Contact* ps) {
	if (ps->size == MAX) {
		printf("通讯录已满,无法增加\n");
	}
	else {
		printf("请输入名字");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("添加成功\n");
	}
}

void  ShowContact(const struct Contact* ps) {
	if (ps->size == 0) {
		printf("通讯录为空\n");
	}
	else {
		int i = 0;

		//标题
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n ", "名字", "年龄", "性别", "电话", "地址");
		//数据
		for ( i = 0; i < ps->size; i++)
		{
			printf("%-10s\t%-4d\t%-5s\t%-12s\t%-20s\n ", ps->data[i].name, ps->data[i].age, ps->data[i].sex,
				ps->data[i].tele, ps->data[i].addr);
		}
	}
}

static int FindByName(const struct Contact * ps,char name[MAX]) {
	int i = 0;
	for (i = 0; i < ps->size; i++) {
		if (0 == (strcmp(ps->data[i].name, name))) {
			return i;
		};
	}
	return -1;
}

void DelContact(struct Contact* ps) {
	char name[MAX_NAME];
	printf("请输入你要删除人的名字\n");
	scanf("%s",name);
	//查找
	int pos = FindByName(ps,name);  //找到返回名字所在下标,找不到返回-1
	if (pos ==  -1) {
		printf("要删除的人不存在\n");
	}
	else {
		int j = 0;
		for (j = pos; j < ps->size - 1; j++) {
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}


void SearchContact(const struct Contact* ps) {
	printf("请输入你要查找人的名字\n");
	char name[MAX];
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1) {
		printf("你要查找的这个人不存在");
	}
	else {
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n ", "名字", "年龄", "性别", "电话", "地址");
			printf("%-10s\t%-4d\t%-5s\t%-12s\t%-20s\n ", ps->data[pos].name, ps->data[pos].age, ps->data[pos].sex,
				ps->data[pos].tele, ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps) {
	printf("请输入要修改人的名字\n");
	char name[MAX];
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1) {
		printf("要修改人的名字不存在\n");
	}
	else {
		printf("请输入要修改的名字");
		scanf("%s", ps->data[pos].name);
		printf("请输入要修改的年龄");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入要修改的性别");
		scanf("%s", ps->data[pos].sex);
		printf("请输入要修改的电话");
		scanf("%s", ps->data[pos].tele);
		printf("请输入要修改的地址");
		scanf("%s", ps->data[pos].addr);

		
		printf("修改成功\n");
	}
}

int age_cmp(const void* a, const void* b) {
	struct PeoInfo* c = (struct PeoInfo*)a;
	struct PeoInfo* d = (struct PeoInfo*)b;
	//int ret = c->age - d->age;
	int ret = (*c).age - (*d).age;
	return ret;
}

int name_cmp(const void* a, const void* b) {
	struct PeoInfo* c = (struct PeoInfo*)a;
	struct PeoInfo* d = (struct PeoInfo*)b;
	//int ret = c->age - d->age;
	int ret = strcmp(c->name,d->name);
	return ret;
}

void SortContact(struct Contact* ps) {
	printf("请输入你想排序的规则\n");
	printf(" 1.按年龄排序  2. 按名字排序");
	int choice = 0;
	scanf("%d", &choice);


	//printf("%p\n", ps->data);
	//printf("%s\n", ps->data[0].name);
	//printf("%d\n", ps->size);
	if (choice == 1) {
	qsort(ps->data, ps->size, sizeof(struct PeoInfo), age_cmp);
	}
	else if (choice == 2) {
		qsort(ps->data, ps->size, sizeof(struct PeoInfo),name_cmp);
		}
}




