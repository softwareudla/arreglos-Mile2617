#include <stdio.h>
#include <conio.h>

int main() {
    float mnums[3][6];         
    float promMateria[6];   
    float promAlumno[3];  
    char nombres[3][20];
    char materias[6][20]= {"Matematica", "Biologia", "Literatura", "Fisica", "Musica", "Teatro"};
    for (int i = 0; i < 3; i++)
    {
        printf("Nombre %d: ",i+1);
        fflush(stdin);
        fgets(nombres[i],20,stdin);
        //scanf("%s",&nombres[i]);
    }
    
    for (int i = 0; i < 3; i++) {
        printf("-----------Para el alumn@ %s-----------\n", nombres[i]);
        for (int j = 0; j < 6; j++) {
            do {
                printf("Ingrese la calificacion de la materia %s:", materias[j]);
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
        printf("Nota Maxima de la Materia %s: %0.2f\n", materias[j], maxMateria);
        printf("Nota Minima de la Materia %s: %0.2f\n", materias[j], minMateria);
        printf("Los Alumnos Reprobados de la Materia %s son: %d\n", materias[j], ReproMateria);
        printf("Los Alumnos Aprobados de la Materia %s son: %d\n", materias[j], AproMateria);
        printf("\n");
    }

 
    printf("\nPromedio por materia:\n");
    for (int j = 0; j < 6; j++) {
        printf("Materia %s: %.2f\n", materias[j], promMateria[j]);
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
        printf("Nota Maxima del alumno %s: %.2f\n", nombres[i], maxAlumno);
        printf("Nota Minima del alumno %s: %.2f\n", nombres[i], minAlumno);
    }

    printf("\nPromedio por alumno:\n");
    for (int i = 0; i < 3; i++) {
        printf("Alumno %s: %.2f\n", nombres[i], promAlumno[i]);
    }

    printf("\n");
    printf("Codigo realizado por Milena Guzman y Paula Andrade\n");
    getch () ;
    return 0;
}
