#pragma once
class Factorial
{
public:
    int calcular(int x)
    {
        if (x < 2) {
            return 1;
        }

        return x * calcular(x - 1);
    }
};

