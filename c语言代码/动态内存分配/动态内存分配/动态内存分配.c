#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//struct S {
//	char name;
//	int age;
//};
//
//
//
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	//struct S s1[n];   ���ܷ�n,��Ϊ�����еĸ���������һ������
//	struct S s1[50]; //50��struct S ���͵�����
//	return 0;
//}


//c������,���Դ����䳤����,�����Լ���������,Ȼ���趨����ĳ���  ����������c99�в���,�������б�������֧��


//��̬�ڴ�:��������ʹ�ö���ڴ������ʹ�ö���ڴ�

//�ڶ���ʹ�ö�̬�ڴ����
//malloc    free    calloc    realloc   

//���˽�malloc     void* malloc(size_t n)  �˺����������������ĵ�ַ,�����nΪ������ֽڸ���
//��������Ϊ��ַ����,���ص����׵�ַ,��������������ֽڸ���,��������ռ��С

//Ҫ����ͷ�ļ�
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int main() {
	//���ڴ�����10�����͵Ŀռ�
	int *p = (int*)malloc(10 * sizeof(int));
	//�����ȡ�ڴ����,�����˼�������ܳ��ܵķ�Χ,�򷵻�һ����ָ��
	if (p == NULL) {
		//��ӡ����ԭ��ķ�ʽ
		//ʹ�����������Ҫ����errno.h  ͷ�ļ�
		printf("%s\n", strerror(errno));  //strerror(errno)  �������hi���ش����ԭ��
	}
	else {
		printf("�ڴ�ռ俪�ٳɹ�\n");
		int i = 0;
		for (i = 0; i < 10; i++) {
			*(p + i) = i;
		}
		for (i = 0; i < 10; i++) {
			printf("%d\n",*(p + i));
		}


	}

	//����̬����Ŀռ䲻��ʹ�õ�ʱ��,Ҫ���ռ��ͷ�
	//free  �ͷſռ�
	free(p);
	p = NULL;
	return 0;
}






