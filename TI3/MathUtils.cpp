#pragma hdrstop
#include "MathUtils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <cmath>
bool is_prime(int32_t n)
{
	if (n < 2)  return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	int32_t lim = (int32_t) sqrt(n);
	for (uint32_t i = 3; i <= lim; i += 2)
		if (n % i == 0) return false;
	return true;
}
//Стандартный алгоритм Евклида находит d = НОД (а,b),
//тогда как расширенный алгоритм Евклида находит тройку целых x, y, d для которой ax + by = d
int32_t extended_evklid(int32_t a, int32_t b, int32_t &x, int32_t &y)
{
	if (b == 0) //Этап алгоритма Евклида, когда d найден
	{
		x = 1;
		y = 0;
		return a;   //Если в процессе работы приходим к b = 0, то a - НОД первоначальных а и b
	}
	int32_t x1, y1;
	//рекурсивно вызываем ту же функцию, но для пары a b на шаг ближе к нахождению НОД.
	//при этом мы находим уже новую пару x, y
	int32_t d = extended_evklid(b, a % b, x1, y1);
	//если провести преобразования в оригинальном выражении, подставив a -> b и b -> (a % b)
	//то в полученном выражении x и y выражаются так.
	x = y1;
	y = x1 - (a / b) * y1;
	return d;
}
// находим число x, которое при умножении на a даст единицу по модулю m
int32_t mod_inverse(int32_t a, int32_t m)
{
	int32_t x, y;
	int32_t g = extended_evklid(a, m, x, y);
	if (g != 1) return -1;          // если мы получили 1, то числа взаимно просты. Если числа взаимно просты, то число x существует
	return ((x % m) + m) % m;       // реально получить отрицательное число. Просто прибавляем шаг деления
}
//быстрое возведение в степень (модульное)
uint32_t mod_pow(uint32_t base, uint32_t exp, uint32_t mod)
{
	if (mod == 1) return 0;
	uint64_t result = 1;
	uint64_t b = base % mod; //число, которое возводим в степень
	uint32_t e = exp;  //степень, в которую возводим число
    while (e > 0) {
		if (e & 1)                          // если младший бит = 1, обновляем результат
			result = (result * b) % mod;
		b = (b * b) % mod;
		e >>= 1;
	}
	return (uint32_t)result;
}
