#include "cached_runner.h"

// TODO: 필요한 함수 구현

CachedRunner::CachedRunner(Cache &cache)
{
    this->cache = cache;
    hits_num = 0;
    miss_num = 0;
}

// 파일의 숫자를 전부 곱하여 반환한다
double CachedRunner::multiply(std::string filename)
{
    double re_value;
    if (!cache.get(filename, re_value))
    {
        miss_num++;
        return multiply(filename);
    }
    hits_num++;
    return re_value;
}

// 파일에서 가장 긴 팰린드롬을 찾아 인덱스를 반환한다
int CachedRunner::palindrome(std::string filename)
{
    int re_value;
    if(!cache.get(filename, re_value))
    {
        miss_num++;
        return palindrome(filename);
    }
    hits_num++;
    return re_value;
}

// 캐시에 히트한 횟수를 반환한다
int CachedRunner::hits()
{
    return hits_num;
}

// 캐시에 미스한 횟수를 반환한다
int CachedRunner::misses()
{
    return miss_num;
}