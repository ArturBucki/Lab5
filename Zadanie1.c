#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

double function(double x)
 {
    return 4 * x - 6 * x + 5;
}

double count(double a, double b, int numberOfTrapezoids)
 {
    double sum = 0;
    double h = (b - a) / numberOfTrapezoids;
    sum += (function(a) + function(b)) / 2;
    for(int i = 1; i < numberOfTrapezoids; i++)
    {
        sum += function(a + i * h);
    }

    return sum * h;
}

int main()
 {
    int p;
    printf("Ilosc procesow: ");
    scanf("%d", &p);

    for (int i = 0; i < p; i++)
        {
        if (fork() == 0) {
            srand(time(NULL) ^ (getpid() << 16));

            double a = rand() % 20;
            double b = rand() % 20;

            while (b <= a)
            {
                b = rand() % 20;
            }

            int numberOfTrapezoids = (rand() % (20 - 1 + 1)) + 1;


            printf("a: %f, b: %f, ilosc trapezow: %d\n", a, b, numberOfTrapezoids);
            printf("Wartosc calki wynosi: %f\n\n", count(a, b, numberOfTrapezoids));

            exit(0);
        }

    }



    return 0;

}
