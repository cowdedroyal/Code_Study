#include "create_calculate.h"
#include <thread>
using namespace std;

int main()
{
	create_calculate cc;
	create_calculate::Clock ct;
	cc.calculate();
	thread t2(&create_calculate::correct, &cc);
	t2.detach();
	thread t1(&create_calculate::Clock::timing, &ct); // 因为是嵌套的类所以有两::
	t1.join();
	return 0; // 返回
}
