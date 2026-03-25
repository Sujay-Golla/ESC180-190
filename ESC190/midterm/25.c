#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* f(char **files, int n){
    char **students = (char**)malloc(sizeof(char*));
    int num_students = 0;
    int **scores = (int**)malloc(sizeof(int*));
    for(int i = 0; i < n; i++){
        FILE *fp = fopen(files[i], "r");
        char buffer[256];
        while(fgets(buffer, sizeof(buffer), fp) != NULL){
            char *num = strtok(buffer, " ");
            char *avg = strtok(NULL, "\n");
            int score = atoi(avg);

            for (int j = 0; j < num_students; j++) {
                if (strcmp(students[j], num) == 0) {
                    scores[j] = realloc(scores[j], sizeof(int)+1);
                    *scores[j] += score;
                    break;
                } else if (j == num_students - 1 and strcmp(students[j], num) != 0) {
                    students = (char**)realloc(students, (num_students + 1) * sizeof(char*));
                    scores = (int**)realloc(scores, (num_students + 1) * sizeof(int*));
                    students[num_students] = strdup(num);
                    scores[num_students] = (int*)malloc(sizeof(int));
                    *scores[num_students] = score;
                    num_students++;
                }
            }
        }
        fclose(fp);
    }
    int highest_avg = 0;
    char *top_student = NULL;
    for (int i = 0; i < num_students; i++) {
        int avg_score;
        int num_scores = 0;
        for (int j = 0; j < n; j++) {
            avg_score += *scores[i];
            num_scores++;
        }
        avg_score /= num_scores;
        if (avg_score > highest_avg) {
            highest_avg = avg_score;
            top_student = students[i];
        }
    }
    return top_student;
}

int main() {
    // Write C code here
    
}