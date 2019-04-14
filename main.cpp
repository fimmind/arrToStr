#include <iostream>

using namespace std;

int getStrLength(int num)
{
    if(num == 0)
        return 1;

    int len = 1;
    if(num < 0)
    {
        ++len;
        num = -num;
    }

    while(num % 10 == 0)
    {
        ++len;
        num /= 10;
    }
    while(num /= 10)
        ++len;

    return len;
}

char* toString(int num)
{
    int len = getStrLength(num);
    char* res = new char[len + 1]; // 1 couse of '\0'
    int offset = 0;

    if(num < 0)
    {
        res[offset++] = '-';
        num = -num;
    }

    for(int i = len - 1; i > 0; i++)
    {
        res[i] = 48 + num % 10;
        num /= 10;
    }

    res[len] = '\0';

    return res;
}

template<class T>
char* toString(T* array, int size)
{
    int len = 2 * size; // 2 + 2 * (size - 1) + 1 // Brackes and ", "s
    for(int i = 0; i < size; i++)
        len += getStrLength(array[i]);

    char* res = new char[len + 1]; // 1 couse of '\0'
    res[0] = '[';

    int offset = 1;
    char* strNum;
    for(int i = 0; i < size; i++)
    {
        if(i)
        {
            res[offset++] = ',';
            res[offset++] = ' ';
        }

        strNum = toString(array[i]);

        char ch = strNum[0];
        for(int strNumI = 0; ch != '\0';)
        {
            res[offset++] = ch;
            ch = strNum[++strNumI];
        }

        delete[] strNum;
    }

    cout << offset - len;

    res[len - 1] = ']';
    res[len] = '\0';
    return res;
}


ostream& operator<<(ostream& os, char* str)
{
    char ch = str[0];
    for(int i = 0; ch != '\0';)
    {
        cout << ch;
        ch = str[++i];
    }
    return os;
}


#define size 10
int main(int argc, char* argv[])
{
    int array[size];
    for(int i = 0; i < size; i++)
        array[i] = i;


    // cout << toString(10) << endl;

    char* strArr = toString(array, size);

    cout << strArr << endl;

    delete[] strArr;
    

    return 0;
}
