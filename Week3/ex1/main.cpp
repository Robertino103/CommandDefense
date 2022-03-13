#include "Math.cpp"

int main()
{
    Math m;
    std::cout << m.Add(20.0,60.5,54.234) << std::endl;
    std::cout << m.Add(13, 15) << std::endl;
    std::cout << m.Add(6,12,15,325,2349,122,1209) << std::endl;
    std::cout << m.Add("Mihai", "Costel") << std::endl;
}