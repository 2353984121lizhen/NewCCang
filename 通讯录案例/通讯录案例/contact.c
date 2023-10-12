#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void InitContact(struct Contact* ps) {
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0; //����ͨѶ¼ֻ��0��Ԫ��
}

void AddContact(struct Contact* ps) {
	if (ps->size == MAX) {
		printf("ͨѶ¼����,�޷�����\n");
	}
	else {
		printf("����������");
		scanf("%s", ps->data[ps->size].name);
		printf("����������");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("��ӳɹ�\n");
	}
}

void  ShowContact(const struct Contact* ps) {
	if (ps->size == 0) {
		printf("ͨѶ¼Ϊ��\n");
	}
	else {
		int i = 0;

		//����
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n ", "����", "����", "�Ա�", "�绰", "��ַ");
		//����
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
	printf("��������Ҫɾ���˵�����\n");
	scanf("%s",name);
	//����
	int pos = FindByName(ps,name);  //�ҵ��������������±�,�Ҳ�������-1
	if (pos ==  -1) {
		printf("Ҫɾ�����˲�����\n");
	}
	else {
		int j = 0;
		for (j = pos; j < ps->size - 1; j++) {
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}


void SearchContact(const struct Contact* ps) {
	printf("��������Ҫ�����˵�����\n");
	char name[MAX];
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1) {
		printf("��Ҫ���ҵ�����˲�����");
	}
	else {
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n ", "����", "����", "�Ա�", "�绰", "��ַ");
			printf("%-10s\t%-4d\t%-5s\t%-12s\t%-20s\n ", ps->data[pos].name, ps->data[pos].age, ps->data[pos].sex,
				ps->data[pos].tele, ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps) {
	printf("������Ҫ�޸��˵�����\n");
	char name[MAX];
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1) {
		printf("Ҫ�޸��˵����ֲ�����\n");
	}
	else {
		printf("������Ҫ�޸ĵ�����");
		scanf("%s", ps->data[pos].name);
		printf("������Ҫ�޸ĵ�����");
		scanf("%d", &(ps->data[pos].age));
		printf("������Ҫ�޸ĵ��Ա�");
		scanf("%s", ps->data[pos].sex);
		printf("������Ҫ�޸ĵĵ绰");
		scanf("%s", ps->data[pos].tele);
		printf("������Ҫ�޸ĵĵ�ַ");
		scanf("%s", ps->data[pos].addr);

		
		printf("�޸ĳɹ�\n");
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
	printf("��������������Ĺ���\n");
	printf(" 1.����������  2. ����������");
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




