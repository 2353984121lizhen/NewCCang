#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
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

//int main() {
//	//���ڴ�����10�����͵Ŀռ�
//	int *p = (int*)malloc(10 * sizeof(int));
//	//�����ȡ�ڴ����,�����˼�������ܳ��ܵķ�Χ,�򷵻�һ����ָ��
//	if (p == NULL) {
//		//��ӡ����ԭ��ķ�ʽ
//		//ʹ�����������Ҫ����errno.h  ͷ�ļ�
//		printf("%s\n", strerror(errno));  //strerror(errno)  �������hi���ش����ԭ��
//	}
//	else {
//		printf("�ڴ�ռ俪�ٳɹ�\n");
//		int i = 0;
//		for (i = 0; i < 10; i++) {
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++) {
//			printf("%d\n",*(p + i));
//		}
//
//
//	}
//
//	//����̬����Ŀռ䲻��ʹ�õ�ʱ��,Ҫ���ռ��ͷ�
//	//free  �ͷſռ�
//	free(p);
//	p = NULL;
//	return 0;
//}
//

//  colloc  ����
//int main() {
//	//ʹ��calloc���ٿռ�
//	//����������÷�,ǰ��һ��������Ԫ�صĸ���,����һ����Ԫ����ռ���ֽڸ���
//	int* p= (int*)calloc(10,sizeof(int));
//	if (p == NULL) {
//		printf("%s\n", strerror(errno));
//	}
//	else {
//		int i = 0;
//		for (i = 0; i < 10; i++) {
//			printf("%d ", *(p + i));
//		}
//	}
//	//�ͷſռ�
//	//free���������ͷſ��ٵĶ�̬�ռ�
//	free(p);
//	p = NULL;
//	/*��Ҫ�� malloc �� calloc ������ calloc �������ڴ棬��
//	ȫ��ʼ��Ϊ0���� malloc ֻ�����ڴ棬��������ʼ���� ���� calloc ��ִ�л�� malloc ��΢��ʱ����Ϊ�����˳�ʼ���Ĳ���*/
//	return 0;
//}



//realloc
//������̬�����ڴ�ռ��С
//int main() {
//	int *p = (int*)malloc(20);
//	if (p == NULL) {
//		printf("%s\n", strerror(errno));
//	}
//	else {
//		int i = 0;
//		for (i = 0; i < 10; i++) {
//			*(p + i) = i;
//		}
//	}
//	//ʹ��malloc���ٵ�20���ֽ�
//	//����20���ֽڲ���ʹ����,��Ҫ40���ֽ�
//	//ʹ��realloc
//	int* p2 = (int*)realloc(p, 40);
//
//	//realloc ʹ��ע������
//	//p = (int*)realloc(p, 40);
//	//1.���pָ��Ŀռ����㹻�Ŀռ����׷��,��ֱ��׷��,����p
//	//2.���p֮��û���㹻�Ŀռ�׷��,��realloc������һ����������Ŀռ俪��,����ԭ�������ݿ�������
//	//�ͷŵ��ɵĿռ�,��󷵻��¿��ٵĿռ��ַ
//	//3.����һ���µı���������realloc�����ķ���ֵ
//	//4.ʹ�ÿ����ڴ溯��֮��,һ��Ҫ�����ж�
//	if (p2 != NULL) {
//		p = p2;
//	}
//	//�ͷ��ڴ�
//	free(p);
//	p = NULL;
//	p2 = NULL;
//
//}



//�Զ�̬�ռ���ڴ�Խ�����
//
//int main() {
//	int* p = (int*)malloc(5 * sizeof(int));
//	if (p == NULL) {
//		return 0;
//	}
//	else {
//		int i = 0; 
//		//for (i = 0; i < 10; i++) {  //Խ�����
//		//	*(p + i) = i;
//		//}  //�ͻ���ִ���
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


//�ԷǶ�̬�ڴ�����ͷ�Ҳ�ᱨ��
// ����Ҳ�����
//int main() {
//	int a = 10;
//	int* p = &a;
//	*p = 20;
//	free(p);
//	p = NULL;
//	return 0;
//}