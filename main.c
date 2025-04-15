#include <stdio.h>
#include <math.h>

void main()
{
	double v0, theta, y0;
	double pi = 3.14159;
	double g = 9.8;
	double a = -g;

	printf("초기 높이를 입력하세요 :");
	scanf_s("%lf", &y0);
	// y0 = 140;

	printf("초기 속도를 입력하세요 :");
	scanf_s("%lf", &v0);
	// v0 = 100;

	printf("초기 각도를 입력하세요 :");
	scanf_s("%lf", &theta);
	// theta = 37;

	double v0x, v0y, theta_rad, theta_deg;

	theta_rad = theta * pi / 180;

	v0x = v0 * cos(theta_rad);
	v0y = v0 * sin(theta_rad);

	// printf("%lf, %lf, %lf\n", theta_rad, v0x, v0y);

	// a) 지면에 닿을 때 까지 걸린 시간 구하기.

	double t;

	double h;

	t = v0y / g;

	h = y0 + (g * t * t) / 2;

	// printf("%lf\n", t);

	double t_ground, t_ground2;

	double y_ground = 0;

	// y = y0 + v0y * t + 1/2 * a * t^2에서 y = 0, y0 = 140, t = t_ground, a = -9.8;
	// 따라서 0 = 140 + 60.181459*t + (-4.9)t^2에서 t의 값을 구해야 함.

	// -4.9 * t_ground * t_ground + v0y * t_ground + 140 = 0;에서 t_ground의 값을 구하기
	// 근의 공식을 사용했을 때 +루트, -루트 두 가지의 값이 나오지만 -루트는 음수가 나오므로 생략

	t_ground = ( - v0y - sqrt(v0y * v0y - 4 * -4.9 * 140)) / -9.8; // t_ground = a번 문제의 정답
	t_ground2 = ( - v0y + sqrt(v0y * v0y - 4 * -4.9 * 140)) / -9.8; // t_ground2의 값에 절대값을 씌우고 2t를 더하면 역시 a번 문제의 정답이 됨.

	// printf("%lf, %lf", t_ground, t_ground2);

	// printf("%lf", t_ground);

	// b) 절벽 아래로부터 수평거리 x를 구하여라.

	double x = t_ground * v0x;

	// printf("%lf\n", x);

	// c) 포사체가 지면에 부딪치기 직전의 속도와 수평성분을 구하여라.

	double vx, vy;

	vx = v0x ;

	vy = v0y + a * t_ground ;

	// d) 속도의 크기를 구하라.

	// printf("%lf, %lf\n", vx, vy);

	double v = sqrt(vx * vx + vy * vy);

	// printf("%lf\n", v);

	// e) 속도벡터가 수평면과 이루는 각을 구하여라.

	double theta_ground = atan2(vy, vx);

	double ang = theta_ground * 180 / pi;

	// printf("%lf", ang);

	printf("지면에 닿을 때 까지의 시간은 : %lfs\n", t_ground);

	printf("절벽 아래로부터 수평거리는 : %lfm\n", x);

	printf("포사체가 지면에 부딪치기 직전의 수평성분과 수직성분은 : %lfm/s, %lfm/s\n", vx, vy);

	printf("포사체가 지면에 닿을 때의 속도는 : %lfm/s\n", v);

	printf("속도벡터가 수평면과 이루는 각은 : %lf°\n", ang);


}