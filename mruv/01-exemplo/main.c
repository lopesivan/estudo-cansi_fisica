#include <stdio.h>
#include <stdlib.h>

typedef double Scalar;

typedef struct
{
    Scalar s0; /* posição inicial (m)   */
    Scalar v0; /* velocidade inicial (m/s) */
} Estado;

/* MRUV: s = s0 + v0*t + a*t²/2 */
static Scalar posicao(const Estado *e, Scalar a, Scalar t)
{
    return e->s0 + e->v0 * t + a * t * t / 2.0;
}

int main(void)
{
    const Estado e = {.s0 = 30.0, .v0 = 20.0};
    const Scalar a = 9.8;
    const Scalar t = 3.2;

    printf("S = %.3f\n", posicao(&e, a, t));

    return EXIT_SUCCESS;
}

