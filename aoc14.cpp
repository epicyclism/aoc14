//
// g++ -O3 -std=c++17 -fconstexpr-loop-limit=24000000 -o aoc14 aoc14.cpp
//
//
#include <iostream>
#include <array>
#include <algorithm>
#include <string>

template<typename C> constexpr int step(int n, C& w, int cnt)
{
        return (n + w[n] + 1) % cnt;
}

template<unsigned sz> constexpr auto generate() -> std::array<char, sz>
{
        std::array<char, sz> wking{};

        int cnt = 0;
        wking[cnt++] = 3 ;
        wking[cnt++] = 7;
        int e1 = 0;
        int e2 = 1;
        while (cnt < sz-1)
        {
                int n = wking[e1] + wking[e2];
                if (n < 10)
                        wking[cnt++] = n;
                else
                {
                        wking[cnt++] = n / 10;
                        wking[cnt++] = n % 10;
                }
                // step elves
                e1 = step(e1, wking, cnt);
                e2 = step(e2, wking, cnt);
        }
        return wking;
}

constexpr auto swking = generate<24000000>();

void pt1(int n)
{
    auto it = std::begin(swking) + n;
    for(int i = 0; i < 10; ++i)
    {
        std::cout << +(*it);
        ++it;
    }
}

template<typename I> void pt2(I b, I e)
{
    auto it = std::search(std::begin(swking), std::end(swking), b, e);
    if (it == std::end(swking))
        std::cout << "not found\n";
    else
        std::cout << std::distance( std::begin(swking), it) << "\n";
}

int main(int ac, char**av)
{
    if ( ac < 2 )
    {
        std::cout << "usage: aoc14 <input> [[input2]...[inputn]]\n\n";
        return -1;
    }
    int arg = 1;
    while(arg < ac)
    {
        std::string s(av[arg]);
        int p = std::stoi(s);
        std::cout << s << "\n";
        std::cout << "pt1 - ";
        pt1(p);
        std::transform(std::begin(s), std::end(s), std::begin(s), [](auto c){ return c - '0';});
        std::cout << "\npt2 - ";
        pt2(std::begin(s), std::end(s));
        ++arg;
    }
}
