#include <stdio.h>
#include <math.h>
#define MAX 8

void ImprimirStack();
void MoveStackUp();
void LimpiarUltimo();
void MoveStackDown();
void IngresarNumero();
void LeerOpcionGeneral(char op);

float stack[MAX];
char *cadena_error = "";
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
    // printf("\033[2J");
    printf("\n---------------> Calculadora <---------------\n\n");
    for (int i = MAX - 1; i >= 0; i--)
    {
        printf("%d. %f \n", (i + 1), stack[i]);
    }

    printf("\nElija una opcion:\n\n   1. Ingresar Numero\n   2. Seleccionar Operacion\n   3. Limpiar Ultimo\n   4. Limpiar Todo\n   E. Salir\n %s", cadena_error);
}

void IngresarNumero()
{
    float nm;
    printf("Que numero desea Ingresar: ");
    scanf(" %f", &nm);

    if (top < MAX - 1) // Verifica que haya espacio en el stack
    {
        cadena_error = "";
        MoveStackUp();
        stack[0] = nm;
        top++;
    }
    else
    {
        cadena_error = "\033[1;31m Ya no puedes ingresar mas numeros! La pila esta llena.\033[0m\n";
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
    top--;
    cadena_error = "";
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
    case '3':
        LimpiarUltimo();
    default:
        break;
    }
}