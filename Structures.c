#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Sctructures:
typedef struct {
    float value;
    char name[40];
} Greatest_grade;

typedef struct {
    float value;
    char name[40];
} Greatest_average;

typedef struct {
    float value;
    char name[40];
} Smallest_average;

typedef struct {
    char name[40];
    float grade[3], average;
    bool result; //true = passed, false = failed
} Student;
