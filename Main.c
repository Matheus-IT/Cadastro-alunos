#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "70Functions.c" //Import of functions file

int main() {
    qtd = getNum(" - Cadastrar quantos alunos? ");
    Student students[qtd];
    set_values(students);
    show_stdts(students);
    return 0;
}
