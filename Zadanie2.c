#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

double PI(int N)
 {
    double sum = 0;
    double fraction;
    for(int i = 1; i <= N; i++)
    {
        fraction = pow(-1, i - 1) / (2 * i - 1);
        sum += fraction;
    }

    return 4 * sum;
}

int main()
{
    int proces;
    printf("Ilosc procesow: ");
    scanf("%d", &proces);

    for (int i = 0; i < proces; i++)
    {
        if (fork() == 0)
        {
            srand(time(NULL) ^ (getpid() << 16));
            int N = (rand() % (5000 - 100 + 1)) + 100;

            printf("Dla N = %d, PI: %f\n", N, PI(N));
            exit(0);
        }

    }


    return 0;

}
