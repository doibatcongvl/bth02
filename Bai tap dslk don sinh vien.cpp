#include<stdio.h>
#include<math.h>
int main()
{
	int n, flag = 1;
	printf("Nhap vao so nguyn duong n: ");
	scanf("%d", &n);
	if(n<2) {
		flag = 0;
	} else {
		for (int i=2; i <= sqrt(n); i++) {
			if (n%i == 0) {
				flag = 0;
				break;
			}
		}
	}
	if (flag) printf("%d la SNT.\n", n);
	else printf("%d kp la SNT.\n", n);
	return 0;
}
