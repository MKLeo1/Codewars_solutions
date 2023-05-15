// https://www.codewars.com/kata/52f787eb172a8b4ae1000a34
long zeros(long n)
{
    int result{};

    for (int i = 5; n / i >= 1; i *= 5)
    {
        result += n / i;
    }
    return result;
}