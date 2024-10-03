#include <stdio.h>
#include <conio.h>

int main() {
    float mnums[3][6];         
    float promMateria[6];   
    float promAlumno[3];     
    
    for (int i = 0; i < 3; i++) {
        printf("-----------Para el alumno %d-----------\n", i + 1);
        for (int j = 0; j < 6; j++) {
            do {
                printf("Ingrese la calificacion de la materia %d:", j + 1);
                scanf("%f", &mnums[i][j]);  
                
                if (mnums[i][j] < 0 || mnums[i][j] > 10) {
                    printf("La calificacion ingresada es invalida. Debe estar entre 0 y 10.\n");
                }
            } while (mnums[i][j] < 0 || mnums[i][j] > 10);
        }
        printf("\n");
    }

    // Calificaciones de todos los alumnos.
    printf("\nCalificaciones de los alumnos por Materia:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%.2f\t", mnums[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Calculos por materia
    for (int j = 0; j < 6; j++) {
        float suma = 0;  
        float maxMateria = mnums[0][j];  
        float minMateria = mnums[0][j]; 
        int AproMateria = 0; 
        int ReproMateria = 0; 
        
        for (int i = 0; i < 3; i++) {  
            suma += mnums[i][j];  
            if (mnums[i][j] > maxMateria) {
                maxMateria = mnums[i][j];
            }
            if (mnums[i][j] < minMateria) {
                minMateria = mnums[i][j];
            }
            if (mnums[i][j] >= 6) { 
                AproMateria++;
            } else {
                ReproMateria++;
            }
        }
        
        promMateria[j] = suma / 3;  
        printf("Nota Maxima de la Materia %d: %0.2f\n", j + 1, maxMateria);
        printf("Nota Minima de la Materia %d: %0.2f\n", j + 1, minMateria);
        printf("Los Alumnos Reprobados de la Materia %d son: %d\n", j + 1, ReproMateria);
        printf("Los Alumnos Aprobados de la Materia %d son: %d\n", j + 1, AproMateria);
        printf("\n");
    }

 
    printf("\nPromedio por materia:\n");
    for (int j = 0; j < 6; j++) {
        printf("Materia %d: %.2f\n", j + 1, promMateria[j]);
    }

    printf("\n");
    
    // Calculos por alumno
    for (int i = 0; i < 3; i++) {
        float suma = 0;  
        float maxAlumno = mnums[i][0];  
        float minAlumno = mnums[i][0];  

        for (int j = 0; j < 6; j++) { 
            suma += mnums[i][j];  
            if (mnums[i][j] > maxAlumno) {
                maxAlumno = mnums[i][j];
            }
            if (mnums[i][j] < minAlumno) {
                minAlumno = mnums[i][j];
            }
        }

        promAlumno[i] = suma / 6;  
        printf("Nota Maxima del alumno %d: %.2f\n", i + 1, maxAlumno);
        printf("Nota Minima del alumno %d: %.2f\n", i + 1, minAlumno);
    }

    printf("\nPromedio por alumno:\n");
    for (int i = 0; i < 3; i++) {
        printf("Alumno %d: %.2f\n", i + 1, promAlumno[i]);
    }

    printf("\n");
    printf("Codigo realizado por Milena Guzman y Paula Andrade\n");
    getch () ;
    return 0;
}
