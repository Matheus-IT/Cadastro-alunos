#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Structures.c" //Import of structures file
#define averaging(grade) (float)((grade[0]) + (grade[1]) + (grade[2]))/3

//Global structures:
Greatest_grade greatest_grade;
Greatest_average greatest_average;
Smallest_average smallest_average;

int qtd = NULL; //Global variable

//Funtions:
void remove_br(char n[]) {
    int length = strlen(n)-1;
    n[length] = '\0';
}

void tirar_virgula(char str[]) {
    int length = strlen(str)-1;
    for (int c = 0; c < length; c++) {
        if (str[c] == ',') {
            str[c] = '.';
        }
    }
}

bool isNumber(char str[]) {
    int length = strlen(str)-1;
    tirar_virgula(str); //Trocar virgula por ponto
    for (int c = 0; c < length; c++) {
        if (str[c] == '.') { //Abrir excessão para ponto
            continue;
        } else {
            if (str[c] >= '0' && str[c] <= '9')
                continue;
            else
                return false;
        }
    }
    return true;
}

float getNum(char msg[]) {
    float n = 0;
    char str[256] = "!number";
    
    //Avaliar se é um número ou não e retornar se for um valor aceitado:
    while (!isNumber(str)) {
        setbuf(stdin, NULL);
        printf("%s", msg);
        fgets(str, 256, stdin);
        if (isNumber(str)) {
            n = atof(str);
            return n;
        } else {
            printf(" - Entrada invalida!");
        }
    }
}

void set_values(Student std[]) {
    for (int c = 0; c < qtd; c++) {
        //Set the name:
        setbuf(stdin, NULL);
        printf(" - Digite o nome do %d aluno: ", c+1);
        fgets(std[c].name, 40, stdin);
        remove_br(std[c].name); //Removes \n
        //Set the grades:
        for (int count = 0; count < 3; count++) {
            printf(" - Digite a %d nota de %s: ", count+1, std[c].name);
            scanf(" %f", &std[c].grade[count]);
            //Calculate if the first grade of each guy is the greatest:
            if (c == 0) { //O primeiro já vai entrar tendo a maior
                greatest_grade.value = std[c].grade[0];
                strcpy(greatest_grade.name, std[c].name);
            } else if ((count == 0) && (std[c].grade[0] > greatest_grade.value)) { //Se esse aluno tem a maior primeira nota
                greatest_grade.value = std[c].grade[0];
                strcpy(greatest_grade.name, std[c].name);
            }
        }
        std[c].average = averaging(std[c].grade); //Average calculation
        //Calculate if the average of each guy is the greatest or the smallest:
        if (c == 0) { //O primeiro já vai entrar tendo o maior e menor
            greatest_average.value = std[c].average;
            strcpy(greatest_average.name, std[c].name);
            smallest_average.value = std[c].average;
            strcpy(smallest_average.name, std[c].name);
        } else if (std[c].average > greatest_average.value) { //Evaluating if each guy has the greatest_average
            greatest_average.value = std[c].average;
            strcpy(greatest_average.name, std[c].name);
        } else if (std[c].average < smallest_average.value) { //Evaluating if each guy has the smallest_average
            smallest_average.value = std[c].average;
            strcpy(smallest_average.name, std[c].name);
        }
        //Evaluate if each guy has passed or not:
        if (std[c].average >= 6) {
            std[c].result = true; //Passou! :)
        } else {
            std[c].result = false; //Reprovou! :(
        }
    }
}

void show_stdts(Student std[]) {
    printf("------------------------------\n");
    printf("            Result            \n");
    for (int c = 0; c < qtd; c++) {
        printf("------------------------------\n");
        printf(" %d Student: %s \n", c+1, std[c].name);
        printf("   Grades: %4.2f, %4.2f, %4.2f \n", std[c].grade[0], std[c].grade[1], std[c].grade[2]);
        printf("   Average: %4.2f \n", std[c].average);
        if (std[c].result == true) {
            printf("   Aluno Aprovado! Parabens! \n");
        } else {
            printf("   Aluno Reprovado, Tente novamente :( \n");
        }
        printf("------------------------------\n");
    }
    printf("------------------------------\n");
    printf("   Greatest first grade:\n");
    printf("   Name: %s First Grade: %4.2f \n", greatest_grade.name, greatest_grade.value);
    printf("------------------------------\n");
    printf("   Greatest average:\n");
    printf("   Name: %s Average: %4.2f \n", greatest_average.name, greatest_average.value);
    printf("------------------------------\n");
    printf("   Smallest average:\n");
    printf("   Name: %s Average: %4.2f \n", smallest_average.name, smallest_average.value);
    printf("------------------------------\n");
}
