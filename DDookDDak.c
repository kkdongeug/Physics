#include <math.h>
#include <stdio.h>

void main()
{
	int number;
	double pi;
	pi = 3.14159;
	double x;
	double y;
	double r;
	double sine;
	double cosine;
	double tangent;
	int angle;
	double theta_rad;
	double theta_deg;

	printf("1. 직교좌표를 극좌표로 변환\n2. 극좌표를 직교좌표로 변환\n원하는 변환 방법을 선택하세요 :");
	scanf_s("%d", &number);

	if (number == 1)
	{
		printf("직교좌표의 x값을 입력하세요  :");
		scanf_s("%lf", &x);
		printf("\n직교좌표의 y값을 입력하세요  :");
		scanf_s("%lf", &y);
		r = sqrt(x * x + y * y);
		theta_rad = atan2(y , x);
		theta_deg = theta_rad * 180 / pi;
		printf("r = %lf, θ = %lf°", r, theta_deg);
	}


	if (number == 2)
	{
		printf("극좌표의 r값을 입력하세요  :");
		scanf_s("%lf", &r);
		printf("극좌표의 각도를 입력하세요  :");
		scanf_s("%lf", &theta_rad);
		theta_deg = theta_rad / 180. * pi;
		sine = sin(theta_deg);
		cosine = cos(theta_deg);
		tangent = tan(theta_deg);
		x = r * cosine;
		y = r * sine;

		printf("직교좌표의 x값은 %lf, 직교좌표의 y값은 %lf 입니다.", x, y);

	}

	else
	{
		printf("프로그램을 종료합니다");
	}
}