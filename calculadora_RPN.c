#include <stdio.h>
#include <math.h>
#define MAX 8

void ImprimirStack();
void MoveStackUp();
void LimpiarUltimo();
void MoveStackDown();
void IngresarNumero();
void LeerOpcionGeneral(char op);
void Operar();

float stack[MAX];
int top = -1;

int main()
{
    char op;
    ImprimirStack();

    do
    {
        scanf(" %c", &op);
        LeerOpcionGeneral(op);
    } while (op != 'e' & op != 'E');
}

void ImprimirStack()
{
    printf("\033[2J");
    printf("\n---------------> Calculadora <---------------\n\n");
    for (int i = MAX - 1; i >= 0; i--)
    {
        printf("%d. %f \n", (i + 1), stack[i]);
    }

    printf("\nElija una opcion:\n\n   1. Ingresar Numero\n   2. Seleccionar Operacion\n   3. Limpiar Ultimo\n   4. Limpiar Todo\n   E. Salir\n\n");
}
void IngresarNumero()
{
    float nm;
    printf("Que numero desea Ingresar: ");
    scanf(" %f", &nm);

    if (top < MAX - 1) // Verifica que haya espacio en el stack
    {
        MoveStackUp();
        stack[0] = nm;
        top++;
    }
    else
    {
        printf("Error: Stack lleno. No se puede agregar más números.\n");
    }

    ImprimirStack();
}
void LimpiarUltimo()
{
    for (int i = 0; i < MAX - 1; i++)
    {
        stack[i] = stack[i + 1];
    }

    stack[MAX - 1] = 0;
    ImprimirStack();
}
void MoveStackUp()
{
    for (int i = top + 1; i > 0; i--)
    {
        stack[i] = stack[i - 1];
    }
}
void LeerOpcionGeneral(char op)
{
    ImprimirStack();

    switch (op)
    {
    case '1':
        IngresarNumero();
        break;
    case '2':
        Operar();
        break;
    case '3':
        LimpiarUltimo();
    default:
        break;
    }
}
void Operar()

{
    char op;
    printf("Operacion peracion desea Realizar (+ , - , * , / , c(cos(1.)) , s(sen(1.) , t(tan(1.) , p(potencia(2.^1.)) , r(raiz(1.))");
    scanf(" %c", &op);

    switch (op)
    {
    case '+':
        stack[1] = stack[0] + stack[1];
        LimpiarUltimo();
        break;
    case '-':
        stack[1] = stack[1] - stack[0];
        LimpiarUltimo();
        break;
    case '*':
        stack[1] = stack[1] * stack[0];
        LimpiarUltimo();
        break;
    case '/':
        stack[1] = stack[1] / stack[0];
        LimpiarUltimo();
        break;
    default:
        break;
    }
}