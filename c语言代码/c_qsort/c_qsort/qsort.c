#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>



//qsort������������
//int cmp(const void* a, const void* b) {
//	return (*(int*)a - *(int*)b);
//}
//
//int main() {
//	//qsort ʹ��  ��������,�˺�����������
//	//qsort()   ��һ��λ������������,�ڶ���������Ԫ�ظ���,�����������ŵ���Ԫ����ռ�ֽڵĸ���,���ĸ������űȽϺ���
//	int arr[8] = { 8,3,7,6,9,4,5,12 };
//	qsort(arr, 8, sizeof(int), cmp);
//	int i = 0;
//	for (i = 0; i < 8; i++) {
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}




//qsort�Խṹ�������

typedef struct Stu{
	char name[30];
	int chinese;
	int math;
	int english;
} Student;

int cmp(const void* a, const void* b) {
	Student* c = (Student*)a;
	Student* d = (Student*)b;
	int result = c->math - d->math;
	return result;
	
}


int main() {
	Student student[5] = {
		{"jj",12,35,78},
		{"ss",5,68,77},
		{"ssss",778,12,44},
		{"qq",6,7,8},
		{"yy",8,9,6}
	};

	qsort(student, sizeof(student) / sizeof(Student), sizeof(Student), cmp);
	//printf("%d   ", sizeof(student));  // 220
	//printf("%d  ", sizeof(Student));   //44
		for (int i = 0; i < 5; i++) {
			printf("%d   , %s ,%d    , %d    ", student[i].math, student[i].name, student[i].english, student[i].chinese );
			printf("\n");
	}

	//printf("%s  %d", student[0].name, student[0].english);
	return 0;
}