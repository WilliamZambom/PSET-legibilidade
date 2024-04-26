/* IDENTIFICAÇÃO DO ESTUDANTE:
 * Preencha seus dados e leia a declaração de honestidade abaixo. NÃO APAGUE
 * nenhuma linha deste comentário de seu código!
 *
 *    Nome completo:William Zambom Pianzola Abreu
 *    Matrícula: 202414773
 *    Turma: CC1Mb
 *    Email: wilzambom@gmail.com
 *
 * DECLARAÇÃO DE HONESTIDADE ACADÊMICA:
 * Eu afirmo que o código abaixo foi de minha autoria. Também afirmo que não
 * pratiquei nenhuma forma de "cola" ou "plágio" na elaboração do programa,
 * e que não violei nenhuma das normas de integridade acadêmica da disciplina.
 * Estou ciente de que todo código enviado será verificado automaticamente
 * contra plágio e que caso eu tenha praticado qualquer atividade proibida
 * conforme as normas da disciplina, estou sujeito à penalidades conforme
 * definidas pelo professor da disciplina e/ou instituição.
 */

// Comece aqui seu programa
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Variaveis L: letra, P: palavras, F: fras
int conta();

// Função main
int main(void)
{
    string comprimento = get_string("Texto\n");

    int L = 0, F = 0, P = 1;
    int indice;

    for (int i = 0, length = strlen(comprimento); i < length; i++)
    {
        if (isalpha(comprimento[i]))
        {
            L++;
        }
        else if (isblank(comprimento[i]))
        {
            P++;
        }
        else if (ispunct(comprimento[i]))
        {
            F++;
        }
    }

    indice = conta(L, F, P);

    if (indice < 1)
    {
        printf("Abaixo do Grau 1\n");
    }
    else if (indice > 16)
    {
        printf("16+\n");
    }
    else
    {
        printf("Grau %i\n", indice);
    }
    return 0;
}

int conta(int L, int F, int P)
{
    float mediaL = ((float) L / P) * 100;
    float mediaF = ((float) F / P) * 100;

    int indice = round(0.0588 * mediaL - 0.296 * mediaF - 15.8);
    return indice;
}
