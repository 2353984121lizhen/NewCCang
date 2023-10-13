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
//	//struct S s1[n];   不能放n,因为数组中的个数必须是一个常量
//	struct S s1[50]; //50个struct S 类型的数据
//	return 0;
//}


//c语言中,可以创建变长数组,就是自己输入数字,然后设定数组的长度  不过这是在c99中才有,不是所有编译器都支持


//动态内存:就是你想使用多大内存你就能使用多大内存

//在堆区使用动态内存分配
//malloc    free    calloc    realloc   

//先了解malloc     void* malloc(size_t n)  此函数就是向堆区申请的地址,后面的n为申请的字节个数
//返回类型为地址类型,返回的市首地址,括号里面填的是字节个数,就是申请空间大小

//要引用头文件

//int main() {
//	//向内存申请10个整型的空间
//	int *p = (int*)malloc(10 * sizeof(int));
//	//如果求取内存过大,超过了计算机所能承受的范围,则返回一个空指针
//	if (p == NULL) {
//		//打印错误原因的方式
//		//使用这个函数需要引用errno.h  头文件
//		printf("%s\n", strerror(errno));  //strerror(errno)  这个函数hi返回错误的原因
//	}
//	else {
//		printf("内存空间开辟成功\n");
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
//	//当动态申请的空间不再使用的时候,要将空间释放
//	//free  释放空间
//	free(p);
//	p = NULL;
//	return 0;
//}
//

//  colloc  函数
//int main() {
//	//使用calloc开辟空间
//	//这个函数的用法,前面一个数字填元素的个数,后面一个填元素所占的字节个数
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
//	//释放空间
//	//free函数用来释放开辟的动态空间
//	free(p);
//	p = NULL;
//	/*主要是 malloc 和 calloc 的区别。 calloc 会申请内存，并
//	全初始化为0；而 malloc 只申请内存，并不作初始化。 所以 calloc 的执行会比 malloc 稍微费时，因为它多了初始化的步骤*/
//	return 0;
//}



//realloc
//调整动态开辟内存空间大小
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
//	//使用malloc开辟的20个字节
//	//假设20个字节不够使用了,需要40个字节
//	//使用realloc
//	int* p2 = (int*)realloc(p, 40);
//
//	//realloc 使用注意事项
//	//p = (int*)realloc(p, 40);
//	//1.如果p指向的空间有足够的空间可以追加,则直接追加,返回p
//	//2.如果p之后没有足够的空间追加,则realloc重新找一块满足需求的空间开辟,并把原来的数据拷贝过来
//	//释放掉旧的空间,最后返回新开辟的空间地址
//	//3.得用一个新的变量来接受realloc函数的返回值
//	//4.使用开辟内存函数之后,一定要进行判断
//	if (p2 != NULL) {
//		p = p2;
//	}
//	//释放内存
//	free(p);
//	p = NULL;
//	p2 = NULL;
//
//}



//对动态空间的内存越界访问
//
//int main() {
//	int* p = (int*)malloc(5 * sizeof(int));
//	if (p == NULL) {
//		return 0;
//	}
//	else {
//		int i = 0; 
//		//for (i = 0; i < 10; i++) {  //越界访问
//		//	*(p + i) = i;
//		//}  //就会出现错误
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


//对非动态内存进行释放也会报错
// 程序也会崩掉
//int main() {
//	int a = 10;
//	int* p = &a;
//	*p = 20;
//	free(p);
//	p = NULL;
//	return 0;
//}